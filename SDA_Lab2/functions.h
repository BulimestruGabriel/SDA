#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

Book *read_book();

void read_list(LinkedList *list);

void print_list(LinkedList list);

int search_by_id(LinkedList list, int id);

void free_list(LinkedList *list);

void sort_after_price(LinkedList *list);

void insert_at_end(LinkedList *list, Book *b);

void insert_at_start(LinkedList *list, Book *book);

void insert_at_position(LinkedList *list, Book *b, int poz);

void delete_at_position(LinkedList *list, int poz);

void invert_list(LinkedList *list);

void empty_list(LinkedList *list);

void print_book(Book *b, int position);

void swap(Node *a, Node *b);


#endif
