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
            if (distance[index] > 255) 
                {distance[index] = 255;} 
            distanceGraph.setIntensity(i, j, distance[index]);
        }
    }

    return distanceGraph;
}



std::pair<int, int> Module::projectPixel(const std::vector<int>& predecessor, int targetX, int targetY, int width)

{

int index = targetX * width + targetY;

while (predecessor[index] != -1)

{

index = predecessor[index];

}

return {index / width, index % width};

}



// Compute the union of two distance images

Graph Module::unionDistanceImages(const Graph& graph1, const Graph& graph2)
{
    if (graph1.getWidth() != graph2.getWidth() || graph1.getHeight() != graph2.getHeight())
    {
        throw std::runtime_error("Error: Graph dimensions must match for union.");
        std::cout << graph1.getWidth() << " " << graph1.getHeight() << " " << graph2.getWidth() << " " << graph2.getHeight();
    }
    Graph unionGraph(graph1.getWidth(), graph1.getHeight());
    for (int i=0; i < graph1.getHeight();i++)
    {
        for (int j=0; j<graph1.getWidth();j++)
        {
            int value1 = graph1.getIntensity(i, j);
            int value2 = graph2.getIntensity(i, j);
            unionGraph.setIntensity(i, j, std::min(value1, value2));
        }
    }
    return unionGraph;
}



// Project a pixel onto the union of two forms

std::pair<int, int> Module::projectPixelOnUnion(

const std::vector<int>& predecessor1,

const std::vector<int>& predecessor2,

int targetX, int targetY, int width

)

{

auto project1 = projectPixel(predecessor1, targetX, targetY, width);

auto project2 = projectPixel(predecessor2, targetX, targetY, width);



int distance1 = std::abs(project1.first - targetX) + std::abs(project1.second - targetY);

int distance2 = std::abs(project2.first - targetX) + std::abs(project2.second - targetY);



return (distance1 < distance2) ? project1 : project2;

}