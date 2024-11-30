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

Image Graph::unionDistanceImages(const Image& img1, const Image& img2)
{
    if (img1.width != img2.width || img1.height != img2.height)
    {
        throw std::invalid_argument("Image dimensions must match for union.");
    }

    Image result(img1.width, img1.height, img1.maxIntensity);
    
    for(int i=0; i<img1.height; i++)
    {
        for(int j=0; j < img1.width; j++)
        {
            int d1 = img1.getPixel(i, j);
            int d2 = img2.getPixel(i, j);
            result.setPixel(i, j, std::min(d1, d2));
        }
    }
    return result;
}