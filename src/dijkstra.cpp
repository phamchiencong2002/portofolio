#include "dijkstra.h"

std::pair<std::vector<int>, std::vector<int>> Dijkstra::calculateDistanceImage(const Graph& graph) {
    const int INF = std::numeric_limits<int>::max();
    int width = graph.getWidth();
    int height = graph.getHeight();
    int size = width * height;

    std::vector<int> distance(size, INF);
    std::vector<int> predecessor(size, -1);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    // Initialize distances and priority queue for all zero-intensity pixels

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (graph.getIntensity(i, j) == 0) {
                int index = i * width + j;
                distance[index] = 0;
                predecessor[index] = index;
                pq.push({0, index});
            }
        }
    }
    // Directions and weights for 8-connectivity

    int directions[8][2] = {
        {0, -1}, {1, -1}, {1, 0}, {1, 1},
        {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}
    };
    int weights[8] = {2, 3, 2, 3, 2, 3, 2, 3};

    while (!pq.empty()) {
        auto [currentDist, currentIndex] = pq.top();
        pq.pop();

        if (currentDist > distance[currentIndex]) {
            continue;
        }

        int i = currentIndex / width;
        int j = currentIndex % width;

        for (int d = 0; d < 8; ++d) {
            int ni = i + directions[d][0];
            int nj = j + directions[d][1];

            if (ni >= 0 && ni < height && nj >= 0 && nj < width) {
                int neighborIndex = ni * width + nj;
                int weight = weights[d];
                int newDist = distance[currentIndex] + weight;

                if (newDist < distance[neighborIndex]) {
                    distance[neighborIndex] = newDist;
                    predecessor[neighborIndex] = currentIndex;
                    pq.push({newDist, neighborIndex});
                }
            }
        }
    }
    return {distance, predecessor};
}
