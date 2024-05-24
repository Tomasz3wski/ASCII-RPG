#include <iostream>
#include <conio.h>
#include <windows.h>
#include <format>
#include "../include/utilities/Colors.h"
#include "../include/menuHandler.h"
#include "../include/display.h"

void clearscreen() {
    system("cls");
};

int displayMenu(const std::vector<std::string>& options) {
    int selectedOption = 0;
    
    while (true) {
        clearscreen();
        displayLogo();
        setColor(LIGHT_RED);
        std::cout << '+' << std::string(50, '-') << '+' << std::endl;
        for (int i = 0; i < options.size(); ++i) {
            std::cout << '|';
            if (i == selectedOption) {
                setColor(RED);
            } else {
                setDefaultColor();
            }
            std::cout << std::format("{:^50}", options[i]);
            setColor(LIGHT_RED);
            std::cout << '|' << std::endl;
        }
        std::cout << '+' << std::string(50, '-') << '+' << std::endl;
        setDefaultColor();

        int ch = _getch();
        if (ch == 224) { //special keys
            ch = _getch();
            if (ch == 72) { //up
                selectedOption = (selectedOption == 0) ? options.size() - 1 : selectedOption - 1;
            } else if (ch == 80) { //down
                selectedOption = (selectedOption == options.size() - 1) ? 0 : selectedOption + 1;
            }
        } else if (ch == 13) { //enter
            return selectedOption;
        }
    }
}
