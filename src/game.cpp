#include "../include/map.h"
#include "../include/display.h"
#include "../include/menuHandler.h"
#include "../include/game.h"
#include <conio.h>
#include <windows.h>

void runGame() {
    Map gameMap(52, 20);
    int playerX = 1;
    int playerY = 20/2;

    while (true) {
        clearscreen();
        displayLogo();
        gameMap.display();

        int ch = _getch();
        if (ch == 224) { //special keys
            ch = _getch();
            switch (ch) {
                case 72: //up
                    if (playerY > 0) playerY--;
                    break;
                case 80: //down
                    if (playerY < 19) playerY++;
                    break;
                case 75: //left
                    if (playerX > 0) playerX--;
                    break;
                case 77: //right
                    if (playerX < 51) playerX++;
                    break;
            }
            gameMap.updatePlayerPosition(playerX, playerY);
        }
    }
}
