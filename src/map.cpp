#include "../include/map.h"
#include "../include/display.h"
#include "../include/utilities/Colors.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <format>

Map::Map(int width, int height) : width(width), height(height), playerX(1), playerY(height / 2) {
    mapData.resize(height, std::string(width, '.'));

    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            int randElement = std::rand() % 40;
            if (randElement == 0) {
                mapData[i][j] = '#'; // wall
            } else if (randElement == 1) {
                mapData[i][j] = 'T'; // tree
            } else if (randElement == 2) {
                mapData[i][j] = '~'; // water
            }
        }
    }
    mapData[playerY][playerX] = 'P';
    std::srand(std::time(0));
}

void Map::display() const {
    setColor(LIGHT_RED);
    std::cout << '+' << std::string(width, '-') << "+\n";
    for (const auto& row : mapData) {
        std::cout << '|';
        setDefaultColor();
        for (char cell : row) {
            if (cell == 'E') {
                setColor(RED);
                std::cout << cell;
                setDefaultColor();
            }
            else if (cell == 'P') {
                setColor(LIGHT_PURPLE);
                std::cout << cell;
                setDefaultColor(); 
            }
            else if (cell == '~') {
                setColor(LIGHT_AQUA);
                std::cout << cell;
                setDefaultColor(); 
            }
            else if (cell == 'T') {
                setColor(GREEN);
                std::cout << cell;
                setDefaultColor(); 
            }
            else {
                std::cout << cell;
            }
        }
        setColor(LIGHT_RED);
        std::cout << "|\n";
    }
    std::cout << '+' << std::string(width, '-') << "+\n";
    setDefaultColor();
}


void Map::updatePlayerPosition(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height) return;
    if (mapData[y][x] == '#' || mapData[y][x] == 'T' || mapData[y][x] == '~') return;
    mapData[playerY][playerX] = '.';
    playerX = x;
    playerY = y;
    if (mapData[playerY][playerX] == 'E')
        return;
    mapData[playerY][playerX] = 'P';
    
}

void Map::placeEnemies(int numberOfEnemies) {
    for (int i = 0; i < numberOfEnemies; ++i) {
        int ex, ey;
        do {
            ex = std::rand() % width;
            ey = std::rand() % height;
        } while (mapData[ey][ex] != '.');
        mapData[ey][ex] = 'E';
    }
}

bool Map::encounterEnemy() const {
    return mapData[playerY][playerX] == 'E';
}

void Map::removeEnemy(int x, int y) {
    if (mapData[y][x] == 'E') {
        mapData[y][x] = '.';
    }
}

int Map::getPlayerX() const {
    return playerX;
}

int Map::getPlayerY() const {
    return playerY;
}
