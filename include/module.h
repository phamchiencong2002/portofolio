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
};

#endif // MODULE_H
