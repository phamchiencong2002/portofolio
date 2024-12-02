#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph {
private:
    int width;
    int height;
    std::vector<int> data;

    int to1DIndex(int i, int j) const;

public:
    Graph(int width, int height);

    int getWidth() const;
    int getHeight() const;
    int getIntensity(int i, int j) const;
    void setIntensity(int i, int j, int value);

    void display() const;
};

#endif // GRAPH_H
