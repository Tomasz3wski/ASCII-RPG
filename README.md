# ASCII RPG - Text-Based RPG Game

## Overview

ASCII RPG is a text-based role-playing game where players can explore a map, fight enemies, and gain experience. The game is designed to enhance object-oriented programming skills and provide practical experience in building a larger software project.

## Project Structure
```bash
ASCII_RPG/
├── build/
├── include/
│ ├── character.h
│ ├── display.h
│ ├── enemy.h
│ ├── game.h
│ ├── map.h
│ ├── menuHandler.h
│ ├── newGame.h
│ └── utilities/
│ └── Colors.h
├── res/
│ ├── logo.ico
│ ├── resource.h
│ └── resource.rc
└── src/
├── character.cpp
├── display.cpp
├── enemy.cpp
├── game.cpp
├── main.cpp
├── map.cpp
├── menuHandler.cpp
└── newGame.cpp
```
## Features

- **Game Mechanics**: Explore map, encounter enemies, and level up your character.
- **User Interface**: Simple and clear ASCII graphics interface.
- **Character Management**: Choose between different classes (Mage, Knight, Hunter) with unique abilities.
- **Combat System**: Turn-based combat system with various enemies.

## Requirements

- **Compiler**: g++ (GNU Compiler Collection)
- **Resource Compiler**: windres (part of MinGW for Windows)

## Compilation Instructions

Follow these steps to compile and run the game:

1. **Compile the resource file**:

   ```sh
   windres res/resource.rc -o build/resource.o
   ```

2. **Compile the source files and link them with the resource object file**:

   ```sh
   g++ -std=c++20 .\src\display.cpp .\src\main.cpp .\build\resource.o .\src\newGame.cpp .\src\menuHandler.cpp .\src\character.cpp .\src\game.cpp .\src\map.cpp .\src\enemy.cpp -o asciirpg.exe
   ```

3. **Run the game**:

   ```sh
   .\asciirpg.exe
   ```

## Future Improvements

- Implement a shop where players can purchase items.
- Add more maps and boss fights.
- Increase the variety of enemies.
- Add unique skills for each character class.
- Implement game save functionality.
- Support for multiple platforms (macOS, Linux).
