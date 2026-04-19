# Dungeon Project

A C++ dungeon crawler built as a semester project for CSCI 1300 at CU Boulder.

## Overview

Explore a multi-floor dungeon, fight monsters, and collect loot. This project uses object-oriented design to organize game logic across multiple classes and source files.

## Features

- Object-oriented design with separate classes for `Character`, `Monster`, and `Loot`
- Dungeon progression with increasing difficulty by floor
- Player choices for attacking or defending during combat
- Randomized loot rewards after each encounter
- Simple command-line gameplay with character selection and floor-based scaling
- Run history logging in `Run_History.txt`

## Build Instructions

Compile with:

```bash
g++ main.cpp Character.cpp Loot.cpp Monster.cpp helperFunctions.cpp global.cpp -o dungeonGame
```

Run the game with:

```bash
./dungeonGame
```

## How to Play

1. Choose the number of dungeon floors to explore.
2. Select a character with unique stats.
3. During combat, choose between:
   - `Attack` — target an enemy and deal damage
   - `Defend` — increase the value of your shield
4. After each battle, pick one of three randomly generated loot items.
5. Progress as far as you can through the dungeon.

## Purpose

This project demonstrates key C++ concepts:

- Classes and encapsulation
- Object relationships and game state management
- Modular code organization across multiple source files
- Basic user interaction through the terminal
- File I/O for run history tracking

## Files

- `main.cpp` — game entry point and overall flow
- `Character.cpp` / `Character.h` — player character implementation
- `Monster.cpp` / `Monster.h` — monster generation and behavior
- `Loot.cpp` / `Loot.h` — loot creation and item handling
- `helperFunctions.cpp` / `helperFunctions.h` — shared utility functions
- `global.cpp` / `global.h` — global constants and shared data
- `Run_History.txt` — stores a history of final game runs