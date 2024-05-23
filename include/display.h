#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <string>
#include <vector>

void clearscreen();
void setColor(int color);
void setDefaultColor();
void SetConsole(int width, int height);

class Menu{
    bool invalidChoice;
    int selectedOption;
    std::vector<std::string> options;

public:
    Menu();
    const bool getInvalidChoice();
    void setInvalidChoice(bool _invalidChoice);
    void Display();
    void Run();
};



#endif //DISPLAY_H