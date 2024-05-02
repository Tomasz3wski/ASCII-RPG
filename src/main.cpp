#include <iostream>
#include "display.h"

int main() {

    Menu Menu;
    Menu.Display();

int choice;
std::cout << "Choose an option: ";
std::cin >> choice;

switch (choice) {
    case 1:
        clearscreen();
        std::cout << "Started a new game.\n";
        break;
    case 2:
        clearscreen();
        std::cout << "Loaded the game.\n";
        break;
    case 3:
        clearscreen();
        std::cout << "Author: Your Name Here.\n";
        break;
    case 4:
        clearscreen();
        std::cout << "Exiting the game.\n";
        break;
    default:
        std::cout << "Invalid option. Please choose again.\n";

        clearscreen();
        Menu.Display();
        break;
}

return 0;
};