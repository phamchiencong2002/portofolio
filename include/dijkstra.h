#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graph.h"
#include <vector>
#include <limits>
#include <queue>

class Dijkstra {
public:
    static std::pair<std::vector<int>, std::vector<int>> calculateDistanceImage(const Graph& graph);
};

#endif // DIJKSTRA_H
