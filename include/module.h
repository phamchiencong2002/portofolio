#ifndef MODULE_H
#define MODULE_H

#include "graph.h"
#include "dijkstra.h"
#include <string>

class Module {
public:
    static Graph loadFormFromPGM(const std::string& filename);
    static void saveFormToPGM(const Graph& graph, const std::string& filename);
    static Graph computeDistanceImage(const Graph& graph);
    static void saveDistanceImageToPGM(const Graph& graph, const std::string& filename);
    static std::pair<int, int> projectPixel(const std::vector<int>& predecessor, int targetX, int targetY, int width);
    static Graph unionDistanceImages(const Graph& graph1, const Graph& graph2);
    static std::pair<int, int> projectPixelOnUnion (const std::vector<int>& predecessor1, const std::vector<int>& predecessor2, int targetX, int targetY, int width);
};

#endif // MODULE_H
