#include <iostream>
#include <vector>
#include "../include/newGame.h"
#include "../include/menuHandler.h"
#include "../include/utilities/Colors.h"

void startNewGame() {
    std::vector<std::string> classes = {"Mage", "Knight", "Hunter", "Return"};

    clearscreen();
    int selectedClass = displayMenu(classes);
    
    switch (selectedClass) {
        case 0:
            std::cout << "You have selected Mage.\n";
            break;
        case 1:
            std::cout << "You have selected Knight.\n";
            break;
        case 2:
            std::cout << "You have selected Hunter.\n";
            break;
        case 3: 
            return;
    }

    system("timeout 5");
}

