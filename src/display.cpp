#include <iostream>
#include <windows.h>
#include <format>
#include "../include/display.h"
#include "../include/utilities/Colors.h"
#include "../res/resource.h"
#include <conio.h>

void SetConsole(int width, int height) {
//title
SetConsoleTitleA("ASCII RPG");
//icon
HWND hwnd = GetConsoleWindow();
HINSTANCE hInstance = GetModuleHandle(NULL);
HICON hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MYICON));
SendMessage(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)hIcon);
SendMessage(hwnd, WM_SETICON, ICON_BIG, (LPARAM)hIcon);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

COORD bufferSize;
bufferSize.X = width;
bufferSize.Y = height;
SetConsoleScreenBufferSize(hConsole, bufferSize);

SMALL_RECT windowSize;
windowSize.Left = 0;
windowSize.Top = 0;
windowSize.Right = width - 1;
windowSize.Bottom = height - 1;
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);

SetConsoleScreenBufferSize(hConsole, bufferSize);

//remove cursor
HANDLE hhConsole = GetStdHandle(STD_OUTPUT_HANDLE);

CONSOLE_CURSOR_INFO cursorInfo;
GetConsoleCursorInfo(hhConsole, &cursorInfo);

cursorInfo.bVisible = false;
SetConsoleCursorInfo(hhConsole, &cursorInfo);
}

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

const bool Menu::getInvalidChoice(){
        return invalidChoice;
};

void Menu::setInvalidChoice(bool _invalidChoice){
        invalidChoice = _invalidChoice;
}

Menu::Menu() : invalidChoice(false), selectedOption(0){
        options = {"1.New Game", "2. Load Game", "3.Author", "4. Exit Game"};
};

void Menu::Display() {

clearscreen();
setColor(BLUE);        
std::cout << "     _     ____   ____ ___ ___   ____  ____   ____ \n";
std::cout << "    / \\   / ___| / ___|_ _|_ _| |  _ \\|  _ \\ / ___|\n";
std::cout << "   / _ \\  \\___ \\| |    | | | |  | |_) | |_) | |  _ \n";
std::cout << "  / ___ \\  ___) | |___ | | | |  |  _ <|  __/| |_| |\n";
std::cout << " /_/   \\_\\|____/\\_____|___|___| |_| \\_\\_|    \\____|\n";
std::cout << "                                                   \n";
        std::cout << "\n\n";

setColor(LIGHT_RED);
std::cout << '+' << std::string(50, '-') << '+' << std::endl;
for(int i=0; i<options.size(); i++){
        std::cout << '|';
        if(i == selectedOption){
                setColor(BLUE);
        }
        else{
                setDefaultColor();
        }
        std::cout << std::format("{:^50}", options[i]);
        setColor(LIGHT_RED);
        std::cout << '|' << std::endl;
}
std::cout << '+' << std::string(50, '-') << '+' << std::endl;
setDefaultColor();

if (getInvalidChoice() == true){
        setColor(RED);
        std::clog << std::format("{:^52}", "Invalid option. Please choose again.") << std::endl;
        setDefaultColor();
        setInvalidChoice(false);
}
};

void Menu::Run(){
        while (true){
                Display();

                int ch = _getch();
                if (ch == 224) { //special keys
                        ch = _getch();
                        if ( ch == 72) { //up
                                selectedOption = (selectedOption == 0) ? options.size() - 1 : selectedOption - 1;
                        }
                        else if (ch == 80) { //down
                                selectedOption = (selectedOption == options.size() - 1) ? 0 : selectedOption + 1;
                        }} 
                else if (ch == 13) { // enter
                        switch (selectedOption) {
                        case 0:
                                clearscreen();
                                std::cout << "Started a new game.\n";
                                system("timeout 3");
                                return;
                        case 1:
                                clearscreen();
                                std::cout << "Loaded the game.\n";
                                system("timeout 3");
                                return;
                        case 2:
                                clearscreen();
                                for (int i = 0; i < 10; i++){
                                        if(i == 0 or i == 9){
                                                setColor(YELLOW);
                                                std::cout << '+' << std::string(50, '-') << '+' << std::endl;
                                                continue;
                                        }
                                        else if(i == 4){
                                                setColor(YELLOW);
                                                std::cout << '|';
                                                setDefaultColor();
                                                std::cout << std::format("{:^50}", "Created by");
                                                setColor(YELLOW);
                                                std::cout << '|' << std::endl;
                                                continue;
                                        }
                                        else if(i == 5){
                                                setColor(YELLOW);
                                                std::cout << '|';
                                                setDefaultColor();
                                                std::cout << std::format("{:^50}", "Jakub Tomaszewski");
                                                setColor(YELLOW);
                                                std::cout << '|' << std::endl;
                                                continue;
                                        }
                                        setColor(YELLOW);
                                        std::cout << std::format("|{:<50}|", ' ') << std::endl;
                                }
                                setDefaultColor();
                                std::cout << R"(               Returning to menu)";
                                for (int i=0; i<3; i++){
                                        std::cout << '.';
                                        Sleep(1500);
                                }
                                break;
                        case 3:
                                clearscreen();
                                std::cout << "Exiting the game...\n";
                                system("timeout 5");
                                return;
                        }
                }
        }
};
