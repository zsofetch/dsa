//linked list accessed by value 

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next; //pointer to next node in the list
} Node;

//structure for a single node in the linked list
typedef struct {
    Node *head; //pointer to the first node in the list
    int count; //how many nodes are in the list
} List;

//function prototypes

List initialize();
List empty(List list);
List insertFirst(List list, int data);
List insertLast(List list, int data);
List insertPos(List list, int data, int index);
List deleteStart(List list);
List deleteLast(List list);
List deletePos(List list, int index);
int retrieve(List list, int index);
int locate(List list, int data);
void display(List list);

List initialize() {
    List list; //new list
    list.head = NULL; //empty list
    list.count = 0; //count = 0 which means no nodes
    return list; //return the initialized empty list
}

//free all nodes in the list and reset it to empty
List empty(List list) {
    Node *current = list.head; //start from first node
    Node *temp; //temp pointer to hold node before freeing

    //traverse list
    while (current != NULL) {
        temp = current; //save current node in temp
        current = current->next; //move to next node
        free(temp); //free saved node 
    }

    list.head = NULL; //reset head to NULL (empty list)
    list.count = 0; //reset count to 0
    return list; //return ang now-empty list
}


List insertFirst(List list, int data) {
    Node *newNode = (Node*)malloc(sizeof(Node)); //allocate memory
    newNode->data = data; //set the data value
    newNode->next = list.head; //mo point siyas old head
    list.head = newNode; //new node becomes head
    list.count++;
    return list; //ireturn ang updated list
}

List insertLast(List list, int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data; //set the data value
    newNode->next = NULL; //last node should point to null

    if (list.head == NULL) {
        list.head = newNode; //if list is empty new node becomes the head
    } else { //if not empty traverse to find the last node
        Node *current = list.head;
        while (current->next != NULL) { //keep moving until we find the last node
            current = current->next; 
        }
        current->next = newNode; //mo attach ug new node at the end
    }

    list.count++;
    return list;
}

List insertPos(List list, int data, int index) {
    //index myst be between 0 and count
    if (index < 0 || index > list.count) {
        printf("Invalid index!\n");
        return list; //unchanged ghapon ang list
    }

    //if inserting at the beginning, mag insert first
    if (index == 0) {
        return insertFirst(list, data);
    } else if (index == list.count) { //if inserting at the index count use insert last
        return insertLast(list, data);
    } else { //else insert in between
        Node *newNode = (Node*) malloc(sizeof(Node)); //pag allocate ug memory
        newNode->data = data; //set data

        Node *current = list.head; //traverse to the node before inserting
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }


        //insert new node between current and current->next
        newNode->next = current->next; //new node points to the next node
        current->next = newNode; //previous node points to new node
        list.count++;
        return list;
    }
}

List deleteStart(List list) { 
    if (list.head == NULL) //if empty there is nothing to delete
    return list;

    Node *temp = list.head; //save reference to first node
    list.head = list.head->next; //move head to second node
    free(temp); //free the old first node 
    list.count--; //decrement count
    return list;
}

List deleteLast(List list) {
    if (list.head == NULL) 
    return list;

    if (list.head->next == NULL) { //if only one node delete it and set head to NULL
        free(list.head); //free the only node
        list.head = NULL; //set head to null
    } else {
        //find second to the last node
        Node *current = list.head;
        while (current->next->next != NULL) { //stop at the second to the last 
            current = current->next;
        }
        free(current->next); //free the last node
        current->next = NULL; //set the second to last node to point to NULL
    }
    list.count--;
    return list;
}

List deletePos(List list, int index) {
    if (index < 0 || index >= list.count) { //index must be between 0 and count
        printf("Invalid index!\n");
        return list;
    }

    if (index == 0) { //if deleting first node, use delete start
        return deleteStart(list);
    } else {
        Node *current = list.head; //traverse to node just before the one to delete
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }

        Node *temp = current->next; //save node to delete 
        current->next = temp->next; //skip over node to delete
        free(temp); //free deleted node
        list.count--; 
        return list;
    }
}

//get the value at a specific index
int retrieve(List list, int index) {
    if (index < 0 || index >= list.count) {
        printf("Invalid index!\n");
        return -1;
    }

    Node *current = list.head;
    for (int i = 0; i < index; i++) { //traverse to the specified index
        current = current->next;
    }

    return current->data; //return the data at that position
}

int locate(List list, int data) {
    Node *current = list.head; //start at the beginning = head
    int index = 0; //track current position

    while (current != NULL) { //traverse the list looking for the data
        if (current->data == data)
        return index; //nakit an na so return the index
        current = current->next; //move to next node
        index++;
    }

    return -1;
}

void display(List list) {
    Node *current = list.head; //start from beginning
    printf("List elements: ");

    while (current != NULL) { //traverse and print each element
        printf("%d ", current->data); //print current node's data
        current = current->next; //move to next node
    }
    printf("\n");
}

int main() {
    List myList = initialize();  // no malloc needed

    myList = insertFirst(myList, 10);
    myList = insertLast(myList, 20);
    myList = insertLast(myList, 30);
    myList = insertPos(myList, 15, 1);
    display(myList);

    //10, 15, 20, 30

    myList = deleteStart(myList);
    myList = deleteLast(myList);
    myList = deletePos(myList, 1);
    display(myList);

    //15

    printf("Element at index 0: %d\n", retrieve(myList, 0));
    printf("Index of 20: %d\n", locate(myList, 20));

    
    myList = empty(myList); // free all nodes
    return 0;
}

