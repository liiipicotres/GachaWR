#ifndef PLAYER_H
#define PLAYER_H
#include <stdio.h>
#include <string.h>
#include "game.h"
#include "characters.h"


typedef struct
{
    char name[MAX_NAME];
    tCharacter playerCharacterList[4];
    int currency;

} tPlayer;


void storePlayerInfo(char *fileName, tPlayer player);
void readPlayerInfo(char *fileName);




#endif // PLAYER_H