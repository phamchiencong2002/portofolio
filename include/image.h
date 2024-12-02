#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

class Image {
public:
    Image(int width = 0, int height = 0);
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;
    void display() const;

    int getIndex(int row, int col) const;
    int getIntensity(int index) const;
    void setIntensity(int index, int value);

    int getWidth() const;
    int getHeight() const;

    void setPixel(int row, int col, int value);
    int getPixel(int row, int col) const;

private:
    int width, height;
    std::vector<int> pixels;
};

#endif
