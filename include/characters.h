#ifndef CHARACTERS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CHARACTERS_H

#define MAX_NAME 35
#define BASE_CRIT 5
#define BASE_CRIT_DMG 150
#define MAX_LINE 32

typedef enum
{
    PROTECTOR = 1,
    DAMAGE_DEALER,
    DEBUFFER,
    BUFFER
} tRole;

typedef struct
{
    int hp;
    int def;
    int atk;
    double spd;
    float critRate;
    float critDmg;

} tStats;

typedef struct
{
    char name[MAX_NAME];
    tStats stats;
    tRole role;
    int level;
    int exp;

} tCharacter;   

// Function declarations

// Initialize the stats struct to default values
void initStats(tStats *stats);

// Initialize the character struct to default values
void initCharacter(tCharacter *character);

// Calculate the formula to level up the character
void calculateLvl(tCharacter *character);

// Calculate the base stats of the character based on its role
void calculateBaseStats(tCharacter *character, int setRole);

// Read the file and store the information in the character struct
void readCharacterFile(tCharacter *character);

// Print the information of the character
void printCharacter(tCharacter *character);

// Store the information of the character in the file
void storeFile(tCharacter *character, char *route);



extern tCharacter characters[4];



#endif