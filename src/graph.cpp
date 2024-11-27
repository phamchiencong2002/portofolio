#include "graph.h"

Graph::Graph(const Image& image) : width(image.width), height(image.height) {}

std::vector<int> Graph::getNeighbors(int i, int j) const {
    std::vector<int> neighbors;
    
    int directions[8][2] = {
        {0, -1}, {1, -1}, {1, 0}, {1, 1},
        {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
    };

    for (auto& dir : directions)
    {
        int ni= i + dir[0];
        int nj = j + dir[1];
        if (ni >= 0 && nj >= 0 && ni < height && nj < width) {
            neighbors.push_back(ni * width + nj);
        }
 
    }
    return neighbors;
}