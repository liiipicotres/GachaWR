#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/characters.h"
#include "../include/game.h"
#include "../include/player.h"
#include "../include/gacha.h"
#include <assert.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x) * 1000) // liiipicotres: Sleep function for linux
#endif       

void gachaSystem(){

    //Options:
    //1. Bullshit 
    //2. Jin-Mori //1% chance of getting a 5* character and 50% chance for it to be Jin Mori
    //3. Cheon Yeo-Woon //1.5% chance of getting a 5* character and 50% chance for it to be Cheon Yeo-Woon

    

    //srand(time(NULL)); // Seed the random number generator

     

    

    double roll = rand() % RAND_MAX % 10; // Generate a random number between 0 and 9999

    if (roll <= 0.1) { 
        double characterRoll = rand() % RAND_MAX % 10;
        if (characterRoll <= 0.5) {
            printf("Congratulations! You got Jin-Mori!\n");
            
        } else{
            printf("Congratulations! You got Cheon Yeo-Woon!\n");
            
        }
    } else{

        printf(".");
        //printf("Congratulations! You got Nothing!\n");
        }

    

}

void printGachaMenu(tPlayer *player)
{

    int *option = malloc(sizeof(int));
    bool *retCondition = malloc(sizeof(bool)); // liiipicotres: if false, won't finish the loop

    Sleep(300);
    printf("Gacha system\n");

    do
    {

        printf("1. Single Roll\n");
        printf("2. 10x Roll\n");
        printf("3. Exit\n");
        scanf("%d", option);
        assert(*option > 0 && *option < 4);

        // liiipicotres: Check if the player has enough currency to roll. If not, will not allow the player to roll
        if ((player->currency < 160 && *option == 1) || (player->currency < 1600 && *option == 2))
        {
            Sleep(300);
            printf("F2p, no money?? lmao\n");
        }
        else
        {
            *retCondition = true;
        }

    } while (*retCondition == false);

    Sleep(300);

    switch (*option)
    {
    case 1:

        printf("Single Roll\n");
        gachaSystem(player);
        break;

    case 2:
        printf("10 Roll\n");
        for(int i = 0; i < 100; i++){
            gachaSystem(player);
        }
        break;

    case 3:
        printf("Exit\n");
        break;
    }
}