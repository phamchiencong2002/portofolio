#include "dijkstra.h"

std::pair<std::vector<int>, std::vector<int>> Dijkstra::calculateDistanceImage(const Image& inputImage) {
    int width = inputImage.width;
    int height = inputImage.height;
    int size = width * height;
    const int INF = std::numeric_limits<int>::max();

    std::vector<int> distance(size, INF);
    std::vector<int> predecessor(size, -1);

    std::queue<int> queue;

    for(int i = 0; i< height; i++)
    {
        for (int j =0; j < width; j++)
        {
            int index = i * width + j;
            if (inputImage.getPixel(i, j) == 0) {
                distance[index] = 0;
                queue.push(index);
            }
        }
    }

    // Directions: left, right, up, down, diagonals
    int directions[8][2] = {
        {0, -1}, {0, 1}, {-1, 0}, {1, 0},
        {-1, -1}, {-1, 1}, {1, -1}, {1, 1}
    };

    while(!queue.empty())
    {
        int current = queue.front();
        queue.pop();

        int x = current / width;
        int y = current % width;
        
        for (auto& dir : directions)
        {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (nx >= 0 && ny >= 0 && nx < height && ny < width){
                int neighborIndex = nx * width + ny;
                int weight = (dir[0] == 0 || dir[1] == 0) ? 2 : 3;

                if (distance[current] + weight < distance[neighborIndex])
                {
                    distance[neighborIndex] = distance[current] + weight;
                    predecessor[neighborIndex] = current;
                    queue.push(neighborIndex);
                }
            }
        }
    }
    return {distance, predecessor};
}