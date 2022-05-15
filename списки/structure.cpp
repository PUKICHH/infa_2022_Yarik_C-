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

void insert(List *list, int new_val, int n) {
    Node *node = new Node;
    node->value = new_val;
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        Node *nodebef = list->head;
        Node *nodeaft = list->head;
        for (int i = 0; i < n; i++) {
            nodebef = nodeaft;
            nodeaft = nodeaft->next;
            if (nodebef == list->tail) {
                list->tail->next = node;
                list->tail = node;
            }
        }
        if (n != 0) {
            nodebef->next = node;
            node->next = nodeaft;
        }
        if (n == 0) {
            list->head = node;
            node->next = nodeaft;
        }

    }
    list->size = list->size + 1;
}

int pop_back(List *list) {
    int a = list->tail->value;
    Node *element = list->head;
    if (list->size > 1) {
        for (int i = 0; i < list->size - 2; i++) {
            element = element->next;
        }
        element->next = nullptr;
        list->tail = element;
        list->size = list->size - 1;
    } else {
        list->head = nullptr;
        list->tail = nullptr;
        list->size = list->size - 1;
    }
    return a;
}

int pop_front(List *list) {
    int a = list->head->value;
    Node *element = list->head;
    if (list->size > 1) {
        for (int i = 0; i < list->size - 2; i++) {
            element = element->next;
        }
        list->tail = element;
        list->size = list->size - 1;
    } else {
        list->head = nullptr;
        list->tail = nullptr;
        list->size = list->size - 1;
    }
    return a;

}

void remove(List *list, int i) {
    if ((i != list->size - 1) && (i != 0)) {
        Node *nodebef = list->head;
        for (int j = 0; j < i - 1; j++) {
            nodebef = nodebef->next;
        }
        nodebef->next = nodebef->next->next;
        list->size -= 1;
    } else if (i == 0) {
        list->head = list->head->next;
        list->size -= 1;
    } else if (i = list->size - 1) {
        pop_back(list);
    }
}

int get(List *list, int i) {
    Node *node = list->head;
    for (int k = 0; k < i; k++) {
        node = node->next;
    }
    return node->value;
}

void clear(List *list) {
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
}

void printlist(List *list) {
    int n = list->size;
    for (int i = 0; i < n; i++) {
        std::cout << get(list, i) << ", ";
    }
    std::cout << std::endl;
}

int main() {
    List list;
    list.size = 0;
    push_back(&list, 1);
    insert(&list, 0, 0);
    insert(&list, 21, 2);
    push_back(&list, 11);
    push_back(&list, 113);
    printlist(&list);
    remove(&list, 3);
    printlist(&list);
    remove(&list, 0);
    printlist(&list);
    remove(&list, 2);
    printlist(&list);
}