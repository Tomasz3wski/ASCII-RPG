#ifndef GAME_H
#define GAME_H

#include <memory>
#include "character.h"

void runGame(std::unique_ptr<Character> character);

#endif //GAME_H