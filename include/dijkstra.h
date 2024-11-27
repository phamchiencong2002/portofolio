#ifndef _DIJKSTRA_H_
#define _DIJKSTRA_H_

#include "image.h"
#include <vector>
#include <queue>
#include <limits>

class Dijkstra {
    public:
        static std::pair<std::vector<int>, std::vector<int>>
        calculateDistanceImage(const Image& inputImage);
};

#endif