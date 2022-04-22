#include <iostream>

struct Node {
    int value;
    Node *next;
};
struct List {
    int size;
    Node *head;
    Node *tail;

};

void push_back(List *list, int new_val) {
    Node *node = new Node;
    node->value = new_val;
    node->next = nullptr;
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;

    }
    list->size += 1;
}

void push_front(List *list, int new_val) {
    Node *node = new Node;
    node->value = new_val;
    node->next = list->head;
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->head = node;
        list->size += 1;
    }
    list->size += 1;
}

int main() {
    List list;
    list.size = 0;
    push_back(&list, 1);
}