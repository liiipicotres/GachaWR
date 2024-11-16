#include <stdio.h>

#define CSV_SEPARATOR ;

#define CSV_CHARACTER_FIELDS 8
#define CSV_WEAPON_FIELDS 3
#define CSV_ARTIFACT_FIELDS 6
#define CSV_PLAYER_FIELDS 10

typedef enum {
    CHARACTER = 1,
    WEAPON,
    ARTIFACT,
    PLAYER
} tCSVTypeEntry;

typedef struct {
    
    tCSVTypeEntry type;
    int numFields;
    char **fields;
    


} tCSVEntry;

typedef struct {
    tCSVEntry *entries;
    int numEntries;
} tCSVData;

char *getTypeEntry(tCSVTypeEntry type);

void csv_init(tCSVEntry *entry);

void csvData_init(tCSVData *data);

void csv_free(tCSVEntry *entry);

void csvData_free(tCSVData *data);

void csv_read(const char *filename, tCSVEntry *entry);

void csvData_read(const char *filename, tCSVData *data);

void csv_write(const char *filename, tCSVEntry *data);

void csvData_write(const char *filename, tCSVData *data);

void csv_print(tCSVData *data);

void csv_add_entry(tCSVData *data, const char *name, const char *value);

void csv_remove_entry(tCSVData *data, const char *name);

void csv_remove_all_entries(tCSVData *data);
