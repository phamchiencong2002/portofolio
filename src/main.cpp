/*#include "module.h"
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
*/

#include "module.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Load Form (PGM File)\n"
              << "2. Save Form\n"
              << "3. Compute Distance Image\n"
              << "4. Save Distance Image\n"
              << "5. Compute Union of Two Distance Images\n"
              << "6. Project Pixel onto Form\n"
              << "7. Project Pixel onto Union of Forms\n"
              << "8. Save union image"
              << "0. Exit\n"
              << "Enter your choice: ";
}

int main() {
    Graph graph1(0, 0), graph2(0, 0), distanceImage1(0, 0), distanceImage2(0, 0), unionImage(0, 0);
    std::vector<int> predecessor1, predecessor2;
    bool running = true;

    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;

        try {
            if (choice == 1) {
                // Load Form
                std::string filename;
                std::cout << "Enter filename to load form: ";
                std::cin >> filename;
                graph1 = Module::loadFormFromPGM(filename);
                std::cout << "Form loaded successfully:\n";
                graph1.display();
            } else if (choice == 2) {
                // Save Form
                std::string filename;
                std::cout << "Enter filename to save form: ";
                std::cin >> filename;
                Module::saveFormToPGM(graph1, filename);
                std::cout << "Form saved successfully.\n";
            } else if (choice == 3) {
                // Compute Distance Image
                distanceImage1 = Module::computeDistanceImage(graph1);
                std::cout << "Distance image computed:\n";
                distanceImage1.display();
            } else if (choice == 4) {
                // Save Distance Image
                std::string filename;
                std::cout << "Enter filename to save distance image: ";
                std::cin >> filename;
                Module::saveFormToPGM(distanceImage1, filename);
                std::cout << "Distance image saved successfully.\n";
            } else if (choice == 5) {
                // Compute Union of Two Distance Images
                std::string filename1;
                std::cout << "Enter filename to load first form: ";
                std::cin >> filename1;
                graph1 = Module::loadFormFromPGM(filename1);
                distanceImage1 = Module::computeDistanceImage(graph1);

                std::string filename2;
                std::cout << "Enter filename to load second form: ";
                std::cin >> filename2;
                graph2 = Module::loadFormFromPGM(filename2);
                distanceImage2 = Module::computeDistanceImage(graph2);

                unionImage = Module::unionDistanceImages(distanceImage1, distanceImage2);
                std::cout << "Union of distance images computed:\n";
                unionImage.display();
            } else if (choice == 6) {
                // Project Pixel onto Form
                auto [distance1, predecessor1] = Dijkstra::calculateDistanceImage(graph1);
                int x, y;
                std::cout << "Enter pixel coordinates to project (x y): ";
                std::cin >> x >> y;
                auto nearest = Module::projectPixel(predecessor1, x, y, graph1.getWidth());
                std::cout << "Nearest black pixel: (" << nearest.first << ", " << nearest.second << ")\n";
            } else if (choice == 7) {
                // Project Pixel onto Union of Forms
                auto [distance1, predecessor1] = Dijkstra::calculateDistanceImage(graph1);
                auto [distance2, predecessor2] = Dijkstra::calculateDistanceImage(graph2);
                int x, y;
                std::cout << "Enter pixel coordinates to project onto union (x y): ";
                std::cin >> x >> y;
                auto nearestUnion = Module::projectPixelOnUnion(predecessor1, predecessor2, x, y, graph1.getWidth());
                std::cout << "Nearest black pixel in the union: (" << nearestUnion.first << ", " << nearestUnion.second << ")\n";
            } 
            else if (choice == 8) {
                // Save Union Image
                std::string filename;
                std::cout << "Enter filename to save union image: ";
                std::cin >> filename;
                Module::saveFormToPGM(unionImage, filename);
                std::cout << "Union image saved successfully.\n";
            }

            else if (choice == 0) {
                running = false;
                std::cout << "Exiting...\n";
            } else {
                std::cerr << "Invalid choice. Please try again.\n";
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n";
        }
    }

    return 0;
}
