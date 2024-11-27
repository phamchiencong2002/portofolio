#ifndef _GRAPH_H_
#define _GRAPH_H_

#include "image.h"
#include <vector>

class Graph {
    public:
        int width;
        int height;

        Graph(const Image& image);
        std::vector<int> getNeighbors(int i, int j) const;
        Image unionDistanceImages(const Image& img1, const Image&);
};

#endif