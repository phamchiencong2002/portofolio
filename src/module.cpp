#include "module.h"
#include <fstream>
#include <stdexcept>
#include <iostream>

Graph Module::loadFormFromPGM(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not open file " + filename);
    }

    std::string format;
    file >> format;
    if (format != "P2") {
        throw std::runtime_error("Error: Unsupported file format (must be P2)");
    }

    int width, height, maxIntensity;
    file >> width >> height >> maxIntensity;

    Graph graph(width, height);
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int intensity;
            file >> intensity;
            graph.setIntensity(i, j, intensity);
        }
    }

    file.close();
    return graph;
}

void Module::saveFormToPGM(const Graph& graph, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Error: Could not write to file " + filename);
    }

    file << "P2\n";
    file << graph.getWidth() << " " << graph.getHeight() << "\n";
    file << 255 << "\n";

    for (int i = 0; i < graph.getHeight(); ++i) {
        for (int j = 0; j < graph.getWidth(); ++j) {
            file << graph.getIntensity(i, j) << " ";
        }
        file << "\n";
    }

    file.close();
}

Graph Module::computeDistanceImage(const Graph& graph) {
    auto [distance, predecessor] = Dijkstra::calculateDistanceImage(graph);

    Graph distanceGraph(graph.getWidth(), graph.getHeight());
    for (int i = 0; i < graph.getHeight(); ++i) {
        for (int j = 0; j < graph.getWidth(); ++j) {
            int index = i * graph.getWidth() + j;
            distanceGraph.setIntensity(i, j, distance[index]);
        }
    }

    return distanceGraph;
}

void Module::saveDistanceImageToPGM(const Graph& graph, const std::string& filename) {
    saveFormToPGM(graph, filename);
}
