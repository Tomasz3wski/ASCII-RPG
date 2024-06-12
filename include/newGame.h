#ifndef NEWGAME_H
#define NEWGAME_H

#include <iostream>
#include <vector>
#include "utilities/Colors.h"

void startNewGame();
std::vector<std::string> splitText(const std::string& text, int width);
void displayWithBorder(const std::string& content, int width);

#endif // NEWGAME_H
