#include "graph.h"
#include <iostream>
#include <iomanip>

Graph::Graph(int width, int height) : width(width), height(height), data(width * height, 255) {}

int Graph::to1DIndex(int i, int j) const {
    return i * width + j;
}

int Graph::getWidth() const {
    return width;
}

int Graph::getHeight() const {
    return height;
}

int Graph::getIntensity(int i, int j) const {
    return data[to1DIndex(i, j)];
}

void Graph::setIntensity(int i, int j, int value) {
    data[to1DIndex(i, j)] = value;
}

void Graph::display() const {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            std::cout << std::setw(4) << getIntensity(i, j) << " ";
        }
        std::cout << "\n";
    }
}
