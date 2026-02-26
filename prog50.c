#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int size;
} MyLinkedList;

MyLinkedList* create() {
    MyLinkedList* list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void addAtHead(MyLinkedList* list, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void addAtTail(MyLinkedList* list, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    list->size++;
}

int get(MyLinkedList* list, int index) {
    if (index < 0 || index >= list->size)
        return -1;

    Node* temp = list->head;
    for (int i = 0; i < index; i++)
        temp = temp->next;

    return temp->val;
}

void deleteAtIndex(MyLinkedList* list, int index) {
    if (index < 0 || index >= list->size)
        return;

    Node* temp = list->head;

    if (index == 0) {
        list->head = temp->next;
        free(temp);
    } else {
        for (int i = 0; i < index - 1; i++)
            temp = temp->next;

        Node* del = temp->next;
        temp->next = del->next;
        free(del);
    }

    list->size--;
}

void printList(MyLinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    MyLinkedList* list = create();

    addAtHead(list, 1);
    addAtTail(list, 3);
    addAtHead(list, 0);

    printList(list);

    printf("Value at index 1: %d\n", get(list, 1));

    deleteAtIndex(list, 1);

    printList(list);

    return 0;
}