#ifndef LIST_H
#define LIST_H

#include <stddef.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    size_t length;
} List;

/* Initializes an empty list. */
void list_init(List *list);

/* Frees all nodes in the list and resets it to empty. */
void list_free(List *list);

/* Returns the number of values in the list. */
size_t list_len(const List *list);

/* Adds value to the beginning of the list. */
void list_push_front(List *list, int value);

/* Adds value to the end of the list. */
void list_push_back(List *list, int value);

/* Removes the first value into *out. Returns 1 on success, 0 if empty. */
int list_pop_front(List *list, int *out);

/* Copies up to capacity values into out in order, returning the count copied. */
size_t list_values(const List *list, int *out, size_t capacity);

#endif
