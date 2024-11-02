#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "characters.h"



void startGame();
void printMainMenu(int *retVal);
void setCharactersAtBase(tCharacter characters[]);


#endif // GAME_H