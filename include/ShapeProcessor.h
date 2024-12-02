#ifndef SHAPEPROCESSOR_H
#define SHAPEPROCESSOR_H

#include "image.h"
#include "graph.h"
#include <string>

class ShapeProcessor {
public:
    ShapeProcessor();
    ~ShapeProcessor();

    bool loadForm(const std::string& filename);
    bool saveForm(const std::string& filename);
    void calculateDistanceMap();
    bool saveDistanceMap(const std::string& filename);
    bool savePredecessors(const std::string& filename);
    bool loadPredecessors(const std::string& filename);
    void projectPixel(int row, int col);
    void calculateUnionDistanceMap(ShapeProcessor& other);

private:
    Image* image;
    Graph* graph;
};

#endif
