#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

/**
 * @brief Represents a grayscale image.
 *
 * Provides methods to load and save images in the PGM format and access/modify pixel data.
 */
class Image {
private:
    int width;                  ///< Width of the image
    int height;                 ///< Height of the image
    int maxIntensity;           ///< Maximum intensity (usually 255)
    std::vector<int> pixels;    ///< Flattened 1D array storing pixel intensities

    /**
     * @brief Convert 2D coordinates to a 1D index.
     *
     * @param row Row index (0-based)
     * @param col Column index (0-based)
     * @return The global 1D index corresponding to (row, col).
     */
    int to1DIndex(int row, int col) const;

public:
    /**
     * @brief Default constructor to create an empty image.
     */
    Image();

    /**
     * @brief Constructor to create an image with specific dimensions.
     *
     * @param width Width of the image
     * @param height Height of the image
     * @param maxIntensity Maximum intensity of the image (default is 255)
     */
    Image(int width, int height, int maxIntensity = 255);

    /**
     * @brief Load an image from a PGM file.
     *
     * @param filename Name of the PGM file to load.
     * @return True if the image is loaded successfully, false otherwise.
     */
    bool loadFromFile(const std::string& filename);

    /**
     * @brief Save the image to a PGM file.
     *
     * @param filename Name of the PGM file to save to.
     * @return True if the image is saved successfully, false otherwise.
     */
    bool saveToFile(const std::string& filename) const;

    /**
     * @brief Get the intensity of a pixel at specific coordinates.
     *
     * @param row Row index (0-based)
     * @param col Column index (0-based)
     * @return The intensity value of the pixel (0-255).
     */
    int getPixel(int row, int col) const;

    /**
     * @brief Set the intensity of a pixel at specific coordinates.
     *
     * @param row Row index (0-based)
     * @param col Column index (0-based)
     * @param value The intensity value to set (0-255).
     */
    void setPixel(int row, int col, int value);

    /**
     * @brief Display the image in a human-readable format (for debugging).
     */
    void display() const;

    /**
     * @brief Get the width of the image.
     * @return Width of the image.
     */
    int getWidth() const;

    /**
     * @brief Get the height of the image.
     * @return Height of the image.
     */
    int getHeight() const;

    /**
     * @brief Get the maximum intensity of the image.
     * @return Maximum intensity of the image.
     */
    int getMaxIntensity() const;
};

#endif // IMAGE_H
