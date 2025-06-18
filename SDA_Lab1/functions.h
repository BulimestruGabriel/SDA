#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

void read_ids(Element *arr, int size);
void read_names(Element *arr, int size);
void print_element(Element e);
void read_elements(Element **arr, int *size);
void print_elements(Element *arr, int size);
int search_by_id(Element *arr, int size, int searchId);
void free_memory(Element **arr);
void swap_elements(Element *a, Element *b);
void sort_elements(Element *arr, int size);
void push_back(Element **arr, int *size, Element newElement);
void push_front(Element **arr, int *size, Element newElement);
int push_at_position(Element **arr, int *size, Element newElement, int position);
int pop_at_position(Element **arr, int *size, int position);
void print_menu();

#endif
