#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "../include/characters.h"
#include <math.h>
#include <assert.h>

void initStats(tStats *stats){
    stats->hp = 0;
    stats->def = 0;
    stats->atk = 0;
    stats->spd = 0;
    stats->critRate = 0;
    stats->critDmg = 0;
    
}

void initCharacter(tCharacter *character){

    strcpy(character->name, "");
    character->role = 0;
    character->level = 0;
    character->exp = 0;
    initStats(&character->stats);
}

void calculateLvl(tCharacter *character){
    

    
    //int expToLvlUp = (int)pow(2, character->level) + 250;
    int expToLvlUp = 1000;
    
    while(character->exp >= expToLvlUp){
        character->level++;
        character->exp -= expToLvlUp;
    }

}

//////
//
// Base stats are temporal until sub-roles are implemented
//
//////

void calculateBaseStats(tCharacter *character, int setRole){ 

    character->role = setRole;
    character->stats.critRate = BASE_CRIT;
    character->stats.critDmg = BASE_CRIT_DMG;
    character->level = 1;

    switch(character->role){
        case PROTECTOR:
            character->stats.hp = 850;
            character->stats.def = 300;
            character->stats.atk = 200;
            character->stats.spd = 1.0;
            break;
        case DAMAGE_DEALER:
            character->stats.hp = 500;
            character->stats.def = 100;
            character->stats.atk = 350;
            character->stats.spd = 1.2;
            break;
        case DEBUFFER:
            character->stats.hp = 750;
            character->stats.def = 125;
            character->stats.atk = 225;
            character->stats.spd = 1.25;
            break;
        case BUFFER:
            character->stats.hp = 750;
            character->stats.def = 100;
            character->stats.atk = 225;
            character->stats.spd = 1.1;
            break;
    }
    
    
}

void readCharacterFile(tCharacter *character){

    
    FILE *file;
    file = fopen("character.txt", "r");
    if(file == NULL){
        printf("Error opening file\n");
        exit(1);
    }
    
    char line[MAX_LINE];

    //Store the information in the character struct
    fgets(line, sizeof(line), file);    //Name
    sscanf(line, "%s", character->name);

    fgets(line, sizeof(line), file);    //Role
    character->role = atoi(line);

    fgets(line, sizeof(line), file);    //HP
    character->stats.hp = atoi(line);
    
    fgets(line, sizeof(line), file);    //DEF
    character->stats.def = atoi(line);
    
    fgets(line, sizeof(line), file);    //ATK
    character->stats.atk = atoi(line);
    
    fgets(line, sizeof(line), file);    //SPD
    character->stats.spd = atof(line);
    
    fgets(line, sizeof(line), file);    //Crit Rate
    character->stats.critRate = (float)atof(line);
    
    fgets(line, sizeof(line), file);    //Crit Dmg
    character->stats.critDmg = (float)atof(line);
    
    fgets(line, sizeof(line), file);    //Level
    character->level = atoi(line);

    
     fclose(file);
}

void storeFile(tCharacter *character, char *route){

    FILE *file = NULL;
    
    char *firStr = NULL;

    if(route != NULL){
        
        firStr = malloc(strlen(character->name) + strlen(route) + strlen(".txt") + 1);
        sprintf(firStr, "%s%s%s", route, character->name, ".txt");

    }else{

        firStr = malloc(strlen(character->name) + strlen(".txt") + 1);
        sprintf(firStr, "%s%s", character->name, ".txt");
    }

    

    if(firStr == NULL){
        printf("Error allocating memory\n");
        
        exit(1);
    }
    

    file = fopen(firStr, "w");
    if(file == NULL){
        printf("Error opening file\n");
        free(firStr);
        exit(1);
    }

    
    free(firStr);

    //Store the information in the file
    fprintf(file, "%s\n", character->name);
    fprintf(file, "%d\n", character->role);
    fprintf(file, "%d\n", character->stats.hp);
    fprintf(file, "%d\n", character->stats.def);
    fprintf(file, "%d\n", character->stats.atk);
    fprintf(file, "%.2f\n", character->stats.spd);
    fprintf(file, "%.2f\n", character->stats.critRate);
    fprintf(file, "%.2f\n", character->stats.critDmg);
    fprintf(file, "%d\n", character->level);

    fclose(file);
}

void printCharacter(tCharacter *character){

    printf("Character selected: %s\n", character->name);
    switch (character->role)
    {
    case 1:
        printf("Role: Protector\n");
        break;

    case 2:
        printf("Role: Damage Dealer\n");
        break;

    case 3:
        printf("Role: Debuffer\n");
        break;
    
    case 4:
        printf("Role: Buffer\n");
        break;

    default:
        break;
    }

    printf("HP: %d\n", character->stats.hp);
    printf("DEF: %d\n", character->stats.def);
    printf("ATK: %d\n", character->stats.atk);
    printf("SPD: %.2f\n", character->stats.spd);
    printf("Crit Rate: %.2f\n", character->stats.critRate);
    printf("Crit Dmg: %.2f\n", character->stats.critDmg);
    printf("Level: %d\n", character->level);


}

tCharacter characters[4];

void setCharactersAtBase(tCharacter characterList[]){

    for(int i = 0; i < 4; i++){
        initCharacter(&characterList[i]);
    }

    strcpy(characterList[0].name, "Fu Xuan");
    strcpy(characterList[1].name, "Yang Kai");
    strcpy(characterList[2].name, "Cheon Yeo-Woon");
    strcpy(characterList[3].name, "Jin Mori");

    characterList[0].role = 1;
    characterList[1].role = 2;
    characterList[2].role = 3;
    characterList[3].role = 4;

    for(int i = 0; i < 4; i++){
        calculateBaseStats(&characterList[i], characterList[i].role);
    }

    
    
    
}