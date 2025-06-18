#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Player{
    int id;
    char name[50];
} Element;

enum {
    READ_ELEMENTS = 1,
    PRINT_ELEMENTS = 2,
    SEARCH_BY_ID = 3,
    SORT_ELEMENTS = 4,
    INSERT_AT_END = 5,
    INSERT_AT_BEGINNING = 6,
    INSERT_AT_POSITION = 7,
    DELETE_AT_POSITION = 8,
    FREE_MEMORY = 9,
    EXIT = 0,
};

#endif
