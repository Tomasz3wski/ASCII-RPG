#ifndef DISPLAY_H
#define DISPLAY_H
#include <iostream>
#include <string>

void clearscreen();
void setColor(int color);
void setDefaultColor();
void SetConsole(int width, int height);
class Menu{
    bool invalidChoice;

public:
    Menu();
    const bool getInvalidChoice();
    void setInvalidChoice(bool _invalidChoice);
    void Display();
};



#endif