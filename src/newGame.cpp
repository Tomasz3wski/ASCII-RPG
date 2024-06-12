#include <iostream>
#include <vector>
#include <memory>
#include <conio.h>
#include <windows.h>
#include <format>
#include <sstream>
#include "../include/newGame.h"
#include "../include/menuHandler.h"
#include "../include/utilities/Colors.h"
#include "../include/character.h"
#include "../include/map.h"
#include "../include/game.h"
#include "../include/display.h"
#include "../include/enemy.h"

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
        int width = 50;
            while (true) {
                clearscreen();
                displayLogo();
                displayWithBorder("You have selected " + character->getName() + ".", width);
                displayWithBorder("Description: " + character->getDescription(), width);
                displayWithBorder("Starting weapon: " + character->getWeaponName(), width);
                displayWithBorder("Do you want to choose this class? (Y/N)", width);

                char confirmation = _getch();
                if (confirmation == 'Y' || confirmation == 'y') {
                    clearscreen();
                    displayLogo();
                    std::string name;
                    setColor(LIGHT_RED);
                    std::cout << '+' + std::string(width - 2, '-') + '+' << std::endl;
                    setDefaultColor();
                    std::cout << "Enter the name of your character: ";
                    std::cin >> name;
                    character->setName(name);

                    clearscreen();
                    setColor(LIGHT_RED);
                    std::cout << '+' + std::string(width - 2, '-') + '+' << std::endl;
                    setDefaultColor();
                    character->displayStats();
                    setColor(LIGHT_RED);
                    std::cout << '+' + std::string(width - 2, '-') + '+' << std::endl;
                    setDefaultColor();

                    system("timeout 5");

                    runGame(std::move(character));
                    return;
                } else if (confirmation == 'N' || confirmation == 'n') {
                    startNewGame();
                    return;
}}}}

std::vector<std::string> splitText(const std::string& text, int width) {
    std::istringstream words(text);
    std::string word;
    std::vector<std::string> lines;
    std::string currentLine;

    while (words >> word) {
        if (currentLine.length() + word.length() + 1 > static_cast<size_t>(width)) {
            lines.push_back(currentLine);
            currentLine = word;
        } else {
            if (!currentLine.empty()) {
                currentLine += " ";
            }
            currentLine += word;
        }
    }

    if (!currentLine.empty()) {
        lines.push_back(currentLine);
    }

    return lines;
}

void displayWithBorder(const std::string& content, int width) {
    std::vector<std::string> lines = splitText(content, width - 2);
    std::string border = '+' + std::string(width - 2, '-') + '+';

    setColor(LIGHT_RED);
    std::cout << border << std::endl;
    
    for (const auto& line : lines) {
        std::cout << '|';
        setDefaultColor();
        std::cout << std::format("{:<{}}", line, width - 2);
        setColor(LIGHT_RED);
        std::cout << '|' << std::endl;
    }

    std::cout << border << std::endl;
    setDefaultColor();
}