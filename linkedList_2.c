//linked list accessed by pointer
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;              // stores the integer value
    struct node *next;     // pointer to the next node
} Node;

typedef struct {
    Node *head;   // pointer to the first node in the list
    int count;    // keeps track of how many nodes are in the list
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

List* initialize() {
    List *list = (List*) malloc(sizeof(List)); 
    if (list == NULL) //if the allocation was unsuccessful, return NULL
    return NULL;       

    list->head = NULL; // start with no nodes
    list->count = 0; 
    return list;       
}

void empty(List *list) {
    Node *current = list->head;  // start at the head
    Node *temp; 

    while (current != NULL) {    // loop until all nodes are freed
        temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL; // list is now empty & set head to null
    list->count = 0; // set count to 0
}

void insertFirst(List *list, int data) {
    
    Node *newNode = (Node*) malloc(sizeof(Node)); // allocate memory for a new node
     if (newNode == NULL) {                       // check if allocation was successful
            printf("Memory allocation failed!\n");
            return;
        }
    newNode->data = data;                         // set the data of the new node to the provided data
    newNode->next = list->head;                   // Set the next pointer of the new node to the current head of the list
    list->head = newNode;                         // Update the list's head pointer to point to the new node
    list->count++;                                // increment count
}

void insertLast(List *list, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));

    if (newNode == NULL) {                       
            printf("Memory allocation failed!\n");
            return;
        }

    newNode->data = data;
    newNode->next = NULL;                         // last node points to NULL

    if (list->head == NULL) {                     // if the list is empty
        list->head = newNode;                     // new node becomes head
    } else {
        Node *current = list->head;               // start at the head
        while (current->next != NULL) {           // traverse until the last node
            current = current->next;
        }
        current->next = newNode;                  // link last node to new node
    }

    list->count++;
}

void insertPos(List *list, int data, int index) {
    if (index < 0 || index > list->count) {
        printf("Invalid index!\n");
        return;
    }

    if (index == 0) {
        insertFirst(list, data); // insert at the start
    } else if (index == list->count) {
        insertLast(list, data);  // insert at the end
    } else {
        Node *newNode = (Node*) malloc(sizeof(Node));
        if (newNode == NULL) {                       
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = data;

        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {     // move to node before insertion point
            current = current->next;
        }

        newNode->next = current->next;            // link new node to the next node
        current->next = newNode;                  // link previous node to new node
        list->count++;
    }
}

void deleteStart(List *list) {
    if (list->head == NULL) return;              // nothing to delete

    Node *temp = list->head;                     // store current head
    list->head = list->head->next;               // move head to next node
    free(temp);                                  // free old head
    list->count--;
}

void deleteLast(List *list) {
    if (list->head == NULL) return;              // list is empty

    if (list->head->next == NULL) {              // only one node
        free(list->head);
        list->head = NULL;
    } else {
        Node *current = list->head;
        while (current->next->next != NULL) {    // stop at 2nd last node
            current = current->next;
        }
        free(current->next);                     // free last node
        current->next = NULL;                    // set new end
    }
    list->count--;
}

void deletePos(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index!\n");
        return;
    }

    if (index == 0) {
        deleteStart(list);                       // delete first
    } else {
        Node *current = list->head;
        for (int i = 0; i < index - 1; i++) {    // find node before the one to delete
            current = current->next;
        }

        Node *temp = current->next;              // node to be deleted
        current->next = temp->next;              // bypass temp
        free(temp);                              // free memory
        list->count--;
    }
}

int retrieve(List *list, int index) {
    if (index < 0 || index >= list->count) {
        printf("Invalid index!\n");
        return -1;
    }

    Node *current = list->head;
    for (int i = 0; i < index; i++) {            // move forward index times
        current = current->next;
    }

    return current->data;                        // return value at that node
}

// Find position of a value
int locate(List *list, int data) {
    Node *current = list->head;
    int index = 0;

    while (current != NULL) {
        if (current->data == data) return index; // match found
        current = current->next;                 // move forward
        index++;
    }

    return -1;                                   // not found
}

void display(List *list) {
    Node *current = list->head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    List *myList = initialize();

    insertFirst(myList, 10);
    insertLast(myList, 20);
    insertLast(myList, 30);
    insertPos(myList, 15, 1);   
    display(myList);

    deleteStart(myList);
    deleteLast(myList);
    deletePos(myList, 1);
    display(myList);

    printf("Element at index 0: %d\n", retrieve(myList, 0));
    printf("Index of 20: %d\n", locate(myList, 20));

    empty(myList);
    free(myList);  // free the list struct itself
    return 0;
}


