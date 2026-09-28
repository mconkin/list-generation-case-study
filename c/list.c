#include "list.h"

#include <stdlib.h>

void list_init(List *list) {
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;
}

void list_free(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *next = current->next;
        free(current);
        current = next;
    }
    list_init(list);
}

size_t list_len(const List *list) {
    return list->length;
}

void list_push_front(List *list, int value) {
    Node *first = malloc(sizeof(Node));
    first->value = value;
    first->next = list->head;
    list->head = first;
    if (list->tail == NULL) {
        list->tail = first;
    }
    list->length++;
}

void list_push_back(List *list, int value) {
    Node *last = malloc(sizeof(Node));
    last->value = value;
    last->next = NULL;
    if (list->tail == NULL) {
        list->head = last;
    } else {
        list->tail->next = last;
    }
    list->tail = last;
    list->length++;
}

int list_pop_front(List *list, int *out) {
    if (list->head == NULL) {
        return 0;
    }

    Node *first = list->head;
    list->head = first->next;
    list->length--;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    *out = first->value;
    free(first);
    return 1;
}

size_t list_values(const List *list, int *out, size_t capacity) {
    size_t count = 0;
    for (Node *current = list->head; current != NULL && count < capacity; current = current->next) {
        out[count++] = current->value;
    }
    return count;
}
