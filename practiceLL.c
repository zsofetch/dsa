#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;


//Why Node** head?
//Because you are modifying the head pointer itself (changing where it points)
//you pass its address - a pointer to a pointer


void insertFirst (Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; //set its data
    newNode->next = *head; //point it to current head
    *head = newNode; //update head to new node
}

//In insertFirst, you link the new node to point to the current head, then move
//the head to this new node. In insertLast, if the list is empty, we just make the
//new node the head. If not, we walk through the list until we find the last node
//whose "next" is NULL, and link it to the new node.
void insertLast (Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value; //set its data
    newNode->next = NULL; //last node points to NULL

    if (*head == NULL) { //if list is empty
        *head = newNode; //new node becomes the head
    } else {
        Node* temp = *head; //start from the head
        while (temp->next != NULL) { //go to the last node
            temp = temp->next;
        }
        temp->next = newNode; //link last node to new node
    }
}

void deleteNode(Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = *head;
    //Case 1: The node to delete is the head

    if (temp->data == value) {
        *head = temp->next; //we update the head pointer and free the old head
        free(temp);
        printf("Node with value %d deleted.\n", value);
        return;
    }

    //Case 2: Search for the node to delete
    Node *prev = NULL;
    while (temp != NULL && temp->data != value) { //walk through the list to find the node with the target value, keeping track of the previous node (prev)
        prev = temp;
        temp = temp->next;
    }

    //Case 3: Node not found
    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    //Unlink node and free memory
    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", value);
}

void printList(Node* head) {
    Node* current = head; //start from head
    printf("Linked List: ");
    while (current != NULL) {  // while not at end of list
        printf("%d -> ", current->data); //print current node's data
        current = current->next; //move to the next node
    }
    printf("NULL\n");
}

void empty(Node *list) {
}

int main () {
    Node* head = NULL;

    insertFirst(&head, 10);
    insertFirst(&head, 20);
    insertLast(&head, 30);
    insertLast(&head, 40);

    printList(head);

    deleteNode(&head, 10);
    printList(head);

    deleteNode(&head, 100); //tries to delete non-existent value 
    return 0;
}