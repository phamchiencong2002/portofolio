#include "image.h"
#include <iostream>
#include <fstream>

Image::Image(int width, int height) : width(width), height(height) {
    pixels.resize(width * height, 255);
}

bool Image::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    std::string line;
    std::getline(file, line); // Skip P2
    file >> width >> height;
    int maxValue;
    file >> maxValue;

    pixels.resize(width * height);
    for (int i = 0; i < width * height; ++i) {
        file >> pixels[i];
    }
    return true;
}

bool Image::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    file << "P2\n" << width << " " << height << "\n255\n";
    for (int i = 0; i < width * height; ++i) {
        file << pixels[i] << " ";
        if ((i + 1) % width == 0) file << "\n";
    }
    return true;
}

void Image::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << pixels[getIndex(i, j)] << " ";
        }
        std::cout << "\n";
    }
}

int Image::getIndex(int row, int col) const {
    return row * width + col;
}

int Image::getIntensity(int index) const {
    return pixels[index];
}

void Image::setIntensity(int index, int value) {
    pixels[index] = value;
}

int Image::getWidth() const {
    return width;
}

int Image::getHeight() const {
    return height;
}

void Image::setPixel(int row, int col, int value) {
    pixels[getIndex(row, col)] = value;
}

int Image::getPixel(int row, int col) const {
    return pixels[getIndex(row, col)];
}
