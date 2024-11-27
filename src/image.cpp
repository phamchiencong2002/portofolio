#include "image.h"
#include <fstream>
#include <iostream>
#include <iomanip>

Image::Image(int w, int h, int maxI) : width(w), height(h), maxIntensity(maxI), pixels(w * h,0) {}

bool Image::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cerr << "Error opening file: " << filename << std::endl;
        return false;
    }

    std::string line, format;
    std::getline(file, format);
    if (format != "P2") {
        std::cerr << "Unsupported format: " << format << std::endl;
        return false;
    }
    file >> width >> height >> maxIntensity;
    pixels.resize(width * height);

    for(int i=0;i<width * height; i++)
    {
        file >> pixels[i];
    }
    file.close();
    return true;
}

bool Image::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()){
        std::cerr << "Error writing to file: " << filename << std::endl;
        return false;
    }

    file << "P2\n" << width << " " << height << "\n" << maxIntensity << "\n";
    for (int i = 0; i < width * height; i++)
    {
        file << pixels[i] << " ";
        if ((i+1) % width == 0) file << "\n";
    }
    
    file.close();
    return true;
}

int Image::getPixel(int i, int j) const {
    return pixels[i * width + j];
}

void Image::setPixel(int i, int j, int valeur) {
    pixels[i * width + j] = valeur;
}

void Image::print() const {
    for (int i=0;i<height;i++)
    {
        for (int j=0;j<width;j++)
        {
            std::cout << std::setw(3) << getPixel(i,j) << " ";
        }
        std::cout << std::endl;
    }
}