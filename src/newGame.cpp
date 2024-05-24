#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>
#include <windows.h>
#include "../include/newGame.h"
#include "../include/menuHandler.h"
#include "../include/utilities/Colors.h"
#include "../include/character.h"
#include "../include/map.h"
#include "../include/game.h"

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
            while (true) {
                clearscreen();
                std::cout << "You have selected " << character->getName() << ".\n";
                std::cout << "Description: " << character->getDescription() << "\n";
                std::cout << "Starting weapon: " << character->getWeaponName() << "\n";
                character->displaySpecialAbility();
                std::cout << "\nDo you want to choose this class? (Y/N)\n";

                char confirmation = _getch();
                if (confirmation == 'Y' || confirmation == 'y') {
                    clearscreen();
                    std::string name;
                    std::cout << "Enter the name of your character: ";
                    std::cin >> name;
                    character->setName(name);

                    clearscreen();
                    character->displayStats();
                    
                    system("timeout 5");

                    runGame();
                    return;
                } else if (confirmation == 'N' || confirmation == 'n') {
                    startNewGame();
                    return;
}}}}

