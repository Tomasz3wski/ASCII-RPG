#include "../include/map.h"
#include "../include/display.h"
#include "../include/menuHandler.h"
#include "../include/game.h"
#include "../include/character.h"
#include "../include/enemy.h"
#include "../include/utilities/Colors.h"
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <memory>
#include <cstdlib>

void displayGameOver() {
    setColor(RED);
    std::cout << "  _____ ____  _      _____   ____  _     _____ ____ \n";
    std::cout << " /  __//  _ \\/ \\__/|/  __/  /  _ \\/ \\ |\\/  __//  __\\\n";
    std::cout << " | |  _| / \\|| |\\/|||  \\    | / \\|| | //|  \\  |  \\/|\n";
    std::cout << " | |_//| |-||| |  |||  /_   | \\_/|| \\// |  /_ |    /\n";
    std::cout << " \\____\\\\_/ \\|\\_/  \\|\\____\\  \\____/\\__/  \\____\\\\_/\\_\\\n";
    std::cout << "                                                   \n";
    setDefaultColor();
}

void runGame(std::unique_ptr<Character> character) {
    Map gameMap(50, 18);
    gameMap.placeEnemies(8);
    gameMap.placePotions(2);
    int playerX = 1;
    int playerY = 18 / 2;

    while (true) {
        clearscreen();
        //displayLogo();
        gameMap.display();
        std::cout << "\narrows - move \n" << std::endl;
        setColor(PURPLE);
        std::cout << "P - player" << std::endl;
        setColor(RED);
        std::cout << "E - enemy" << std::endl;
        setColor(YELLOW);
        std::cout << "H - health potion" << std::endl;
        setColor(GREEN);
        std::cout << "T - tree" << std::endl;
        setColor(AQUA);
        std::cout << "~ - water" << std::endl;
        setDefaultColor();
        std::cout << "# - grass\n" << std::endl;

        character->displayStats();

        int ch = _getch();
        if (ch == 224) { //special keys
            ch = _getch();
            switch (ch) {
                case 72: //up
                    gameMap.updatePlayerPosition(playerX, playerY - 1);
                    break;
                case 80: //down
                    gameMap.updatePlayerPosition(playerX, playerY + 1);
                    break;
                case 75: //left
                    gameMap.updatePlayerPosition(playerX - 1, playerY);
                    break;
                case 77: //right
                    gameMap.updatePlayerPosition(playerX + 1, playerY);
                    break;
            }
            playerX = gameMap.getPlayerX();
            playerY = gameMap.getPlayerY();

            if (gameMap.encounterPotion()) {
            character->addHealth();
            gameMap.removePotion(gameMap.getPlayerX(), gameMap.getPlayerY());
            }

            if (gameMap.encounterEnemy()) {
                clearscreen();
                std::unique_ptr<Enemy> enemy;
                int enemyType = std::rand() % 3;
                if (enemyType == 0) {
                    enemy = std::make_unique<Goblin>(character->getLevel());
                } else if (enemyType == 1) {
                    enemy = std::make_unique<Troll>(character->getLevel());
                } else {
                    enemy = std::make_unique<Dragon>(character->getLevel());
                }
                std::cout << "You encountered a " << enemy->getName() << "!\n";
                std::cout << "Level: " << enemy->getLevel() << "\n";
                std::cout << "Health: " << enemy->getHealth() << "\n";
                std::cout << "Damage: " << enemy->getDamage() << "\n";
                std::cout << std::endl << std::endl;

                //battle loop
                while (character->getHealth() > 0 && enemy->getHealth() > 0) {
                    int characterDamage = character->getDamage() + character->getLevel() * 2;
                    enemy->takeDamage(characterDamage);
                    std::cout << "You dealt " << characterDamage << " damage to the " << enemy->getName() << ".\n";
                    Sleep(1000);

                    if (enemy->getHealth() <= 0) {
                        std::cout << "You defeated the " << enemy->getName() << "!\n";
                        character->gainExp(50);
                        gameMap.removeEnemy(playerX, playerY);
                        break;
                    }

                    int enemyDamage = enemy->getDamage();
                    character->takeDamage(enemyDamage);
                    std::cout << "The " << enemy->getName() << " dealt " << enemyDamage << " damage to you.\n";
                    Sleep(1000);

                    if (character->getHealth() <= 0) {
                        clearscreen();
                        displayGameOver();
                        for (int i = 10; i > 0; --i) {
                            std::cout << "Returning to menu in " << i << " seconds...\r";
                            Sleep(1000);
                        }
                        return;
                    }
                }
                system("pause");
            } 
        }
    }
}
