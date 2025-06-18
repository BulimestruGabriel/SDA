#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

Book *read_book() {
    Book *b = (Book *) malloc(sizeof(Book));
    char buffer[100];

    printf("ID: ");
    scanf("%d", &b->id);

    printf("Title: ");
    scanf(" %[^\n]", buffer);
    b->title = strdup(buffer);

    printf("Author: ");
    scanf(" %[^\n]", buffer);
    b->author = strdup(buffer);

    printf("Year: ");
    scanf("%d", &b->year);
    printf("Price: ");
    scanf("%f", &b->price);

    return b;
}

void read_list(LinkedList *list) {
    int n;
    printf("How many books? ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nBook %d:\n", i + 1);
        Book *b = read_book();
        insert_at_end(list, b);
    }
}

void print_book(Book *b, int position) {
    printf("\nPosition %d:\n", position);
    printf("ID: %d\nTitle: %s\nAuthor: %s\nYear: %d\nPrice: %.2f\n",
           b->id, b->title, b->author, b->year, b->price);
}

void print_list(LinkedList list) {
    Node *current = list.head;
    int i = 0;
    while (current) {
        print_book(current->data, i++);
        current = current->next;
    }
}


int search_by_id(LinkedList list, int id) {
    int pos = 0;
    Node *current = list.head;
    while (current) {
        if (current->data->id == id) return pos;
        current = current->next;
        pos++;
    }
    return -1;
}

void insert_at_end(LinkedList *list, Book *b) {
    Node *nou = (Node *) malloc(sizeof(Node));
    nou->data = b;
    nou->next = NULL;

    if (!list->head) {
        list->head = nou;
    } else {
        Node *temp = list->head;
        while (temp->next) temp = temp->next;
        temp->next = nou;
    }
}

void insert_at_start(LinkedList *list, Book *book) {
    Node *nou = (Node *) malloc(sizeof(Node));
    nou->data = book;
    nou->next = list->head;
    list->head = nou;
}

void insert_at_position(LinkedList *list, Book *b, int poz) {
    if (poz == 0) {
        insert_at_start(list, b);
        return;
    }
    Node *temp = list->head;
    for (int i = 0; temp && i < poz - 1; i++) {
        temp = temp->next;
    }
    if (!temp) {
        printf("Invalid position.\n");
        return;
    }
    Node *nou = (Node *) malloc(sizeof(Node));
    nou->data = b;
    nou->next = temp->next;
    temp->next = nou;
}

void delete_at_position(LinkedList *list, int poz) {
    if (!list->head) return;
    Node *temp = list->head;
    if (poz == 0) {
        list->head = temp->next;
        free(temp->data->title);
        free(temp->data->author);
        free(temp->data);
        free(temp);
        return;
    }
    for (int i = 0; temp && i < poz - 1; i++) {
        temp = temp->next;
    }
    if (!temp || !temp->next) {
        printf("Invalid position.\n");
        return;
    }
    Node *del = temp->next;
    temp->next = del->next;
    free(del->data->title);
    free(del->data->author);
    free(del->data);
    free(del);
}

void invert_list(LinkedList *list) {
    Node *prev = NULL;
    Node *curr = list->head;
    Node *next = NULL;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    list->head = prev;
}

void swap(Node *a, Node *b) {
    Book *temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void sort_after_price(LinkedList *list) {
    if (!list->head) return;
    Node *i, *j;
    for (i = list->head; i && i->next; i = i->next) {
        for (j = i->next; j; j = j->next) {
            if (i->data->price > j->data->price) {
                swap(i, j);
            }
        }
    }
}


void free_list(LinkedList *list) {
    Node *current = list->head;
    while (current) {
        Node *next = current->next;
        free(current->data->title);
        free(current->data->author);
        free(current->data);
        free(current);
        current = next;
    }
    list->head = NULL;
}

void empty_list(LinkedList *list) {
    free_list(list);
}
