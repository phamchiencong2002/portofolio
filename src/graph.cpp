#include "graph.h"
#include <limits>
#include <fstream>

Graph::Graph(const Image& image) : image(image) {
    distanceMap.resize(image.getWidth() * image.getHeight(), std::numeric_limits<int>::max());
    predecessors.resize(image.getWidth() * image.getHeight(), -1);
}

void Graph::calculateDistanceMap() {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

    for (std::size_t i = 0; i < distanceMap.size(); ++i) {
        if (image.getIntensity(i) == 0) {
            distanceMap[i] = 0;
            pq.push({0, i});
        }
    }

    int directions[8][2] = {
        {0, -1}, {1, -1}, {1, 0}, {1, 1}, 
        {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
    };
    int costs[8] = {2, 3, 2, 3, 2, 3, 2, 3};

    while (!pq.empty()) {
        //int currentDist = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        int row = current / image.getWidth();
        int col = current % image.getWidth();

        for (int i = 0; i < 8; ++i) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];
            int cost = costs[i];

            if (newRow >= 0 && newRow < image.getHeight() &&
                newCol >= 0 && newCol < image.getWidth()) {
                int neighbor = image.getIndex(newRow, newCol);

                if (distanceMap[current] + cost < distanceMap[neighbor]) {
                    distanceMap[neighbor] = distanceMap[current] + cost;
                    predecessors[neighbor] = current;
                    pq.push({distanceMap[neighbor], neighbor});
                }
            }
        }
    }
}

Image Graph::reconstructBinaryImage() const {
    Image binary(image.getWidth(), image.getHeight());
    for (std::size_t i = 0; i < distanceMap.size(); ++i) {
        binary.setIntensity(i, distanceMap[i] == 0 ? 0 : 255);
    }
    return binary;
}

Image Graph::unionDistanceMaps(const Graph& other) const {
    Image result(image.getWidth(), image.getHeight());
    for (std::size_t i = 0; i < distanceMap.size(); ++i) {
        result.setIntensity(i, std::min(distanceMap[i], other.distanceMap[i]));
    }
    return result;
}

int Graph::projectPixel(int row, int col) const {
    int index = image.getIndex(row, col);
    return predecessors[index];
}

bool Graph::savePredecessorsToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) return false;

    for (int i : predecessors) {
        file << i << " ";
    }
    return true;
}

bool Graph::loadPredecessorsFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) return false;

    for (int& i : predecessors) {
        file >> i;
    }
    return true;
}
