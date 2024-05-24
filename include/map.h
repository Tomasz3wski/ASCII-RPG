#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>

class Map {
public:
    Map(int width, int height);
    void display() const;
    void updatePlayerPosition(int x, int y);

private:
    int width;
    int height;
    std::vector<std::string> mapData;
    int playerX;
    int playerY;
};

#endif
