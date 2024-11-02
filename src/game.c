#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x) * 1000) // liiipicotres: Sleep function for linux
#endif                              // No tengo ni putísima idea de cómo funciona esto
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/characters.h"
#include "../include/game.h"
#include <assert.h>

void printMainMenu(int *retVal)
{

    printf("Welcome to Hunkei Impact\n");

    do
    {
        printf("=========================");
        printf("\nSelect an option:\n");

        printf("1. Start new game\n");
        printf("2. Load game\n");
        printf("3. Credits\n");
        printf("4. Exit\n");
        printf("=========================\n");

        scanf("%d", retVal);
        assert(*retVal > 0 && *retVal < 5);

        switch (*retVal)
        {

        // If the return value is 1 the game will start a new game
        case 1:
            Sleep(300);
            printf("\nStarting new game\n");
            break;

        //////
        // Yet to be implemented
        // Will have to implement a save system
        //////
        case 2:
            Sleep(300);
            printf("\nLoading game\n");
            break;

        //////
        // If the return value is 3 the game will show the credits and ask
        // if the player wants to return to the main menu
        //////
        case 3:
            Sleep(300);
            printf("\nCredits:\n");
            Sleep(700);
            printf("Developed by: Liiipicotres\n");
            Sleep(700);
            printf("Art by: SuperNigger69_\n");
            Sleep(700);
            printf("Music by: NiggaBeats\n");
            Sleep(700);
            printf("Special thanks to: BigNigga\n\n");
            Sleep(700);
            printf("Do you want to return to the main menu? [y/n]\n");
            char option;
            scanf(" %c", &option);
            Sleep(300);

            // Checks if the option is valid
            if (option != 'y' && option != 'n')
            {
                do
                {
                    Sleep(300);
                    printf("Invalid option, please select a valid option\n");
                    scanf(" %c", &option);
                } while (option != 'y' && option != 'n');

                // If the option is 'n' the game will exit
            }
            else if (option == 'n')
            {
                *retVal = 4;
                Sleep(300);
                printf("Exiting game\n");
                Sleep(300);
                printf("See you next time...\n");
                return;

                // If the option is 'y' the game will return to the main menu
            }
            else
            {

                Sleep(300);
                printf("Returning to main menu...\n\n");
                Sleep(600);
            }
            break;
        case 4: // If the return value is 4 the game will exit
            Sleep(300);
            printf("Exiting game\n");
            Sleep(300);
            printf("See you next time...\n");
            return;
        }

    } while (*retVal == 3);
}

void startGame()
{

    int *retVal = (int *)malloc(sizeof(int));

    printMainMenu(retVal);

    switch (*retVal)
    {
    case 1:
        setCharactersAtBase(characters);
        
        break;

    case 2:
        setCharactersAtBase(characters);
        break;
    }

    free(retVal);
}