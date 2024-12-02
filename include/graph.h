#ifndef GRAPH_H
#define GRAPH_H

#include "image.h"
#include <vector>
#include <queue>

class Graph {
public:
    Graph(const Image& image);
    void calculateDistanceMap();
    void calculateShortestPaths();

    Image reconstructBinaryImage() const;
    Image unionDistanceMaps(const Graph& other) const;
    int projectPixel(int row, int col) const;

    bool savePredecessorsToFile(const std::string& filename) const;
    bool loadPredecessorsFromFile(const std::string& filename);

private:
    const Image& image;
    std::vector<int> distanceMap;
    std::vector<int> predecessors;

    int getNeighbor(int index, int direction) const;
};

#endif
