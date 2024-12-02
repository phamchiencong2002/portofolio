#include "ShapeProcessor.h"
#include <iostream>
#include <limits>

ShapeProcessor::ShapeProcessor() : image(nullptr), graph(nullptr) {}

ShapeProcessor::~ShapeProcessor() {
    delete image;
    delete graph;
}

bool ShapeProcessor::loadForm(const std::string& filename) {
    delete image;
    image = new Image();
    if (image->loadFromFile(filename)) {
        return true;
    }
    return false;
}

bool ShapeProcessor::saveForm(const std::string& filename) {
    if (!image) return false;
    return image->saveToFile(filename);
}

void ShapeProcessor::calculateDistanceMap() {
    delete graph;
    graph = new Graph(*image);
    graph->calculateDistanceMap();
}

bool ShapeProcessor::saveDistanceMap(const std::string& filename) {
    if (!graph) {
        std::cout << "No distance map to save.\n";
        return false;
    }
    Image distanceImage(image->getWidth(), image->getHeight());
    for (int i = 0; i < image->getWidth() * image->getHeight(); ++i) {
        distanceImage.setIntensity(i, graph->projectPixel(i / image->getWidth(), i % image->getWidth()));
    }
    if (distanceImage.saveToFile(filename)) {
        std::cout << "Distance map saved to " << filename << ".\n";
        return true;
    }
    std::cout << "Failed to save distance map.\n";
    return false;
}

bool ShapeProcessor::savePredecessors(const std::string& filename) {
    if (!graph) return false;
    return graph->savePredecessorsToFile(filename);
}

bool ShapeProcessor::loadPredecessors(const std::string& filename) {
    if (!graph) return false;
    return graph->loadPredecessorsFromFile(filename);
}

void ShapeProcessor::projectPixel(int row, int col) {
    if (!graph) return;
    int closestIndex = graph->projectPixel(row, col);
    int closestRow = closestIndex / image->getWidth();
    int closestCol = closestIndex % image->getWidth();
    std::cout << "Closest pixel: (" << closestRow << ", " << closestCol << ")\n";
}

void ShapeProcessor::calculateUnionDistanceMap(ShapeProcessor& other) {
    if (!graph || !other.graph) return;
}
