#include <stdio.h>
#include "../include/csv.h"

void csv_init(tCSVEntry *entry) {
    entry->type = 0;
    entry->numFields = 0;
    entry->fields = NULL;
}

void csvData_init(tCSVData *data) {
    data->entries = NULL;
    data->numEntries = 0;
}

void csv_free(tCSVEntry *entry) {
    if (entry->fields != NULL) {
        for (int i = 0; i < entry->numFields; i++) {
            free(entry->fields[i]);
        }
        free(entry->fields);
    }
}

void csvData_free(tCSVData *data) {
    if (data->entries != NULL) {
        for (int i = 0; i < data->numEntries; i++) {
            csv_free(&data->entries[i]);
        }
        free(data->entries);
    }
}

void add_entry(tCSVData *data, tCSVEntry entry) {

    if(data->entries == NULL || data->numEntries == 0) {
        data->entries = (tCSVEntry *)malloc(sizeof(tCSVEntry));
    } else {

    data->entries = (tCSVEntry *)realloc(data->entries, (data->numEntries+1) * sizeof(tCSVEntry));
    //data->entries[data->numEntries] = entry;
    
    }
    csv_init(&data->entries[data->numEntries]);
    data->entries[data->numEntries].type = entry.type; 
    data->entries[data->numEntries].numFields = entry.numFields;
    data->entries[data->numEntries].fields = (char **)malloc(entry.numFields * sizeof(char *));
    for (int i = 0; i < entry.numFields; i++) {
        data->entries[data->numEntries].fields[i] = (char *)malloc(strlen(entry.fields[i]) + 1);
        strcpy(data->entries[data->numEntries].fields[i], entry.fields[i]);
    }

    data->numEntries++;

}
