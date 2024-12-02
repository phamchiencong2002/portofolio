#include "image.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

Image::Image() : width(0), height(0), maxIntensity(255) {}

Image::Image(int width, int height, int maxIntensity)
    : width(width), height(height), maxIntensity(maxIntensity), pixels(width * height, 255) {}

int Image::to1DIndex(int row, int col) const {
    return row * width + col;
}

bool Image::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << "\n";
        return false;
    }

    std::string format;
    file >> format;
    if (format != "P2") {
        std::cerr << "Error: Unsupported file format. Expected P2.\n";
        return false;
    }

    file >> width >> height >> maxIntensity;
    pixels.resize(width * height);

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file >> pixels[to1DIndex(i, j)];
        }
    }

    file.close();
    return true;
}

bool Image::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not write to file " << filename << "\n";
        return false;
    }

    file << "P2\n";
    file << width << " " << height << "\n";
    file << maxIntensity << "\n";

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            file << pixels[to1DIndex(i, j)] << " ";
        }
        file << "\n";
    }

    file.close();
    return true;
}

int Image::getPixel(int row, int col) const {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        throw std::out_of_range("Error: Pixel coordinates out of bounds.");
    }
    return pixels[to1DIndex(row, col)];
}

void Image::setPixel(int row, int col, int value) {
    if (row < 0 || row >= height || col < 0 || col >= width) {
        throw std::out_of_range("Error: Pixel coordinates out of bounds.");
    }
    pixels[to1DIndex(row, col)] = value;
}

void Image::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << std::setw(3) << getPixel(i, j) << " ";
        }
        std::cout << "\n";
    }
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

int Image::getMaxIntensity() const {
    return maxIntensity;
}
