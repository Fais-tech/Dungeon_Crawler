# Dungeon Project

A C++ dungeon crawler built as a semester project for CSCI 1300 at CU Boulder.

## Overview

Explore a multi-floor dungeon, fight monsters, and collect loot. This project uses object-oriented design to organize game logic across multiple classes and source files.

## Key Features
- Object-oriented design with classes for Character, Monster, and Loot
- Multi-floor dungeon system with increasing difficulty scaling
- Turn-based combat system with attack and defend mechanics
- Randomized loot generation after encounters
- Persistent run history tracking using file I/O
- Command-line interface for user interaction

## Technical Highlights
- Organized code across multiple source files to improve modularity and maintainability
- Managed game state and interactions between entities using structured class relationships
- Implemented file I/O to log and persist gameplay results
- Designed reusable helper functions to reduce redundancy and improve readability

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
This project demonstrates:
- Object-oriented programming (encapsulation, modularity)
- Game state management
- File I/O for persistent data
- Structured program design in C++

## Files

- `main.cpp` — game entry point and overall flow
- `Character.cpp` / `Character.h` — player character implementation
- `Monster.cpp` / `Monster.h` — monster generation and behavior
- `Loot.cpp` / `Loot.h` — loot creation and item handling
- `helperFunctions.cpp` / `helperFunctions.h` — shared utility functions
- `global.cpp` / `global.h` — global constants and shared data
- `Run_History.txt` — stores a history of final game runs
