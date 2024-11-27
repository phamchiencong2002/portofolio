#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <vector>
#include <string>

class Image{
    public:
        int width;
        int height;
        int maxIntensity;
        std::vector<int> pixels;

        Image(int w = 0, int h = 0, int maxI = 255);
        bool loadFromFile(const std::string& file);
        bool saveToFile(const std::string& filename) const;

        int getPixel(int i, int j) const;
        void setPixel(int i, int j, int value);
        void print() const; // for debugging
};

#endif