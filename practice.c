#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct { //a list 
    Node *head; //this is a pointer to the next node
    int count;
} List;

List* initialize();
void empty(List *list);
void insertFirst(List *list, int data);
void insertLast(List *list, int data);
void insertPos(List *list, int data, int index);
void deleteStart(List *list);
void deleteLast(List *list);
void deletePos(List *list, int index);
int retrieve(List *list, int index);
int locate(List *list, int data);
void display(List *list);

// Function implementations

List* initialize() {
    List *list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        return NULL;
    }
    list->head = NULL;
    list->count = 0;
    return list;
}

void empty(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    } 
    list->head = NULL;
    list->count = 0;
}

void insertFirst(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    // if (newNode == NULL) return; //need ba ni?
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->count++;
}

void insertLast(List *list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    // if (newNode == NULL) return;
    // newNode->data = data;
    // newNode->next = NULL;

    newNode->data = data;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *current = list->head;
        while(current->next != NULL) {
            current = current->next; //ambot
        }
        current->next = newNode;
    }
    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count)
    return;
    
    if(index == 0) {
        insertFirst(list, data);
        return;
    }
    if (index == list->count) {
        insertLast(list, data);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    
    if (newNode == NULL)
    return;

    newNode->data = data;

    

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    list->count++;
}

void deleteStart(List *list) {
    if (list->head == NULL) return;

    Node *temp = list->head;
    list->head = list->head->next;
    free(temp);
    list->count--;
}

void deleteLast(List *list) {
    if (list->head == NULL) return;

    if (list->head->next == NULL) {
        free(list->head);
        list->head = NULL;
        list->count--;
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < list->count - 2; i++) {
        current = current->next;
    }
    free(current->next);
    current->next = NULL;
    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) return;

    if (index == 0) {
        deleteStart(list);
        return;
    }

    Node *current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    list->count--;
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) return -1;

    Node *current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

int locate(List *list, int data) {
    if (list->head == NULL) return -1;

    Node *current = list->head;
    int index = 0;
    while (current != NULL) {
        if (current->data == data) return index;
        current = current->next;
        index++;
    }
    return -1;
}

void display(List *list) {
    Node *current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Sample usage
int main() {
    List *myList = initialize();

    insertLast(myList, 2);
    insertLast(myList, 6);
    insertLast(myList, 5);
    printf("Initial List:\n");
    display(myList);

    insertFirst(myList, 7);
    printf("After insertFirst 7:\n");
    display(myList);

    insertPos(myList, 10, 2);
    printf("After insertPos 10 at index 2:\n");
    display(myList);

    deleteStart(myList);
    printf("After deleteStart:\n");
    display(myList);

    deleteLast(myList);
    printf("After deleteLast:\n");
    display(myList);

    deletePos(myList, 1);
    printf("After deletePos at index 1:\n");
    display(myList);

    int pos = locate(myList, 6);
    printf("Locate 6: %d\n", pos);

    int val = retrieve(myList, 1);
    printf("Retrieve index 1: %d\n", val);

    empty(myList);
    printf("After emptying the list:\n");
    display(myList);

    free(myList);
    return 0;
}
