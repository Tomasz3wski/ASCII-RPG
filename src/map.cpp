#include "../include/map.h"
#include <iostream>

Map::Map(int width, int height) : width(width), height(height), playerX(1), playerY(height / 2) {
    mapData.resize(height, std::string(width, '.'));
    mapData[playerY][playerX] = 'P';
}

void Map::display() const {
    for (const auto& row : mapData) {
        std::cout << row << std::endl;
    }
}

void Map::updatePlayerPosition(int x, int y) {
    mapData[playerY][playerX] = '.';
    playerX = x;
    playerY = y;
    mapData[playerY][playerX] = 'P';
}
