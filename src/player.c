#include <stdio.h>
#include <stdlib.h>
#include "../include/player.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <assert.h>
#include <unistd.h>


#ifdef _WIN32
#include <direct.h>
#define mkdir _mkdir
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif



void storePlayerInfo(char *playerFileName, tPlayer player){

    //char firStr[256];
    //strcpy(firStr, "");


    //////
    //Create the string that will be used to store the player's info. 
    //It will be stored in the directory PlayerCharList with the name: playerFileName.txt
    //////
    char *firStr = malloc(strlen(playerFileName) + strlen("PlayerCharList") + strlen(".txt") + 1);
    sprintf(firStr, "%s%s%s", "PlayerCharList/", playerFileName, ".txt");

    //////
    //In case the directory where player's info gets stored doesn't exist, create it
    //The directory is called PlayerCharList
    //////
    struct stat st = {0};
    if(stat("PlayerCharList", &st) == -1){
        #ifdef _WIN32           //liiipicotres: Bendito sea stackoverflow
        mkdir("PlayerCharList");
        #elif __linux__
        mkdir("PlayerCharList", 0700);   //liiipicotres: Error in linux but still works lol don't touch 
        #endif
    }

    //////
    //Creates the file and checks if it was created successfully
    //////
    FILE *file = fopen(firStr, "w");
    if(file == NULL){
        printf("Fatal error");
        exit(1);
    }


    //////
    //Creates a file for every character in the player's character list.
    //Next update will have to implement a way to store the character's info in the player's file
    //Or maybe store the character's info in a different file
    //Also, will have to implement an id system for the characters
    //////
    for(int i = 0; i < 4; i++){

        storeFile(&player.playerCharacterList[i], "PlayerCharList/");
    }

    fprintf(file, "%s\n", player.name);
    fprintf(file, "%d\n", player.currency);
    
    fclose(file);
    
   
   free(firStr);
   
    
}

void readPlayerInfo(char *fileName){

    FILE *file = fopen(fileName, "r");
    

    fclose(file);
}