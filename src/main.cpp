#include "module.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Load Form\n"
              << "2. Save Form\n"
              << "3. Compute Distance Image\n"
              << "4. Save Distance Image\n"
              << "0. Exit\n"
              << "Enter your choice: ";
}

int main() {
    Graph graph(0, 0), distanceImage(0, 0);
    bool running = true;

    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;

        try {
            if (choice == 1) {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                graph = Module::loadFormFromPGM(filename);
                std::cout << "Form loaded successfully.\n";
                graph.display();
            } else if (choice == 2) {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                Module::saveFormToPGM(graph, filename);
                std::cout << "Form saved successfully.\n";
            } else if (choice == 3) {
                distanceImage = Module::computeDistanceImage(graph);
                std::cout << "Distance image computed.\n";
                distanceImage.display();
            } else if (choice == 4) {
                std::string filename;
                std::cout << "Enter filename: ";
                std::cin >> filename;
                Module::saveDistanceImageToPGM(distanceImage, filename);
                std::cout << "Distance image saved.\n";
            } else if (choice == 0) {
                running = false;
            } else {
                std::cerr << "Invalid choice.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << e.what() << "\n";
        }
    }

    return 0;
}
