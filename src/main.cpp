#include "ShapeProcessor.h"
#include <iostream>

void displayMenu() {
    std::cout << "1. Load Form\n2. Save Form\n3. Calculate Distance Map\n4. Save Distance Map\n5. Exit\n";
}

int main() {
    ShapeProcessor processor;
    while (true) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string filename;
                std::cin >> filename;
                processor.loadForm(filename);
                break;
            }
            case 2: {
                std::string filename;
                std::cin >> filename;
                processor.saveForm(filename);
                break;
            }
            case 3:
                processor.calculateDistanceMap();
                break;
            case 4: {
                std::string filename;
                std::cin >> filename;
                processor.saveDistanceMap(filename);
                break;
            }
            case 5:
                return 0;
        }
    }
    return 0;
}
