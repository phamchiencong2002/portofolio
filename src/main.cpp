#include "image.h"
#include "dijkstra.h"
#include "graph.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Load Image\n"
              << "2. Save Image\n"
              << "3. Compute Distance Image\n"
              << "4. Project Pixel\n"
              << "5. Union of Distance Images\n"
              << "0. Exit\n"
              << "Enter your choice: ";
}

int main() {
    Image image;
    Image distanceImage;
    std::vector<int> distance, predecessor;

    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            std::string filename;
            std::cout << "Enter filename to load: ";
            std::cin >> filename;
            if (image.loadFromFile(filename)) {
                std::cout << "Image loaded successfully.\n";
                image.print();
            } else {
                std::cerr << "Failed to load image.\n";
            }
        } else if (choice == 2) {
            std::string filename;
            std::cout << "Enter filename to save: ";
            std::cin >> filename;
            if (image.saveToFile(filename)) {
                std::cout << "Image saved successfully.\n";
            } else {
                std::cerr << "Failed to save image.\n";
            }
        } else if (choice == 3) {
            auto result = Dijkstra::calculateDistanceImage(image);
            distance = result.first;
            predecessor = result.second;

            std::cout << "Distance image calculated.\n";
        } else if (choice == 0) {
            break;
        } else {
            std::cerr << "Invalid choice!\n";
        }
    }

    return 0;
}
