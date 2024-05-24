#include <iostream>
#include <vector>
#include "../include/newGame.h"
#include "../include/menuHandler.h"
#include "../include/utilities/Colors.h"
#include "../include/character.h"

void startNewGame() {
    std::vector<std::string> classes = {"Mage", "Knight", "Hunter", "Return"};

    clearscreen();
    int selectedClass = displayMenu(classes);
    std::unique_ptr<Character> character;

    switch (selectedClass) {
        case 0:
            character = std::make_unique<Mage>();
            break;
        case 1:
            character = std::make_unique<Knight>();
            break;
        case 2:
            character = std::make_unique<Hunter>();
            break;
        case 3: 
            return;
    }

    if (character) {
            clearscreen();
            std::cout << "You have selected " << character->getName() << ".\n";
            std::cout << "Starting weapon: " << character->getWeaponName() << "\n";
            character->displaySpecialAbility();
            system("timeout 5");
}
}

