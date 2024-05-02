#include "display.h"
#include <iostream>
#include <windows.h>
#include "utilities/Colors.h"

void clearscreen(){
        system("cls");
};

void setColor(int color) {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, color);
};

void setDefaultColor(){
        setColor(WHITE);
};

void Menu::Display() {

clearscreen();
setColor(BLUE);        
std::cout << "      _     ____   ____ ___ ___   ____  ____   ____ \n";
std::cout << "     / \\   / ___| / ___|_ _|_ _| |  _ \\|  _ \\ / ___|\n";
std::cout << "    / _ \\  \\___ \\| |    | | | |  | |_) | |_) | |  _ \n";
std::cout << "   / ___ \\  ___) | |___ | | | |  |  _ <|  __/| |_| |\n";
std::cout << "  /_/   \\_\\|____/\\_____|___|___| |_| \\_\\_|    \\____|\n";
std::cout << "                                                    \n";
        std::cout << "\n\n";
setDefaultColor();

std::cout << "1. New Game\n";
std::cout << "2. Load Game\n";
std::cout << "3. Author\n";
std::cout << "4. Exit Game\n";
int choice;
std::cout << "Choose an option: ";
std::cin >> choice;
};