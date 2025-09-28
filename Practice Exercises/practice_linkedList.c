
//=========fill the code -- linked list variation 1=========
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
    //create a new list

    //empty the list by initializing its head to NULL

    //set count of the list to 0

    //return the initialized empty list
}

//free all nodes in the list and reset it to empty
List empty(List list) {

    //initialize a pointer current with data type Node
    //to traverse the list starting from the head

    //initialize a temp pointer to hold node before freeing
    
    //create a while loop to traverse the list (while current is not NULL)

        //inside the loop save current node in temp 

        //move current to the next node by setting current to current->next

        //free the saved node 

    //after the loop reset head to NULL (empty list)

    //reset count to 0

    //return the now-empty list
}

List insertFirst(List list, int data) {
    //allocate memory for a new node 

    //set the data value of the new node to data

    //set the next pointer of the new node to point to the current head of the list

    //update the head of the list to be the new node

    //increment the count of nodes in the list

    //return the updated list
}

List insertLast(List list, int data) {
    //allocate memory for a new node

    //set the data value of the new node to data

    //set the next pointer of the new node to NULL since it will be the last node

    //if the list is empty (head is NULL) set head to the new node

    //else traverse the list to find the last node by:

        //initialize a pointer current to head
    
        //create a while loop to move current->next to the last node (while current->next is not NULL or keep moving forward until we find the last node)
    
            //inside the loop move current to the next node by setting current to current->next
        
        //after the loop, set the next pointer of the last node (current) to the new node to attach it at the end

    //increment the count of nodes in the list

    //return the updated list
}

List insertPos(List list, int data, int index) {
    //make an if statement for when index is less than 0 or greater than count
    //print invalid index and return the unchanged list
    
    //if inserting at the beginning (or index is 0), call insertFirst

    //else if, if inserting at the end (or index is count), call insertLast

    //else if we're inserting in between:

        //allocate memory for a new node

        //set the data value of the new node to data

        //initialize a pointer current to head to traverse to the node before inserting

        //create a for loop to move current to the node just before the target index (for i from 0 to index - 1 keep moving forward)

            //inside the loop move current to the next node by setting current to current->next

        //after the loop, insert the new node between current and current->next by:

            //setting the next pointer of the new node to current->next (new node points to the next node)

            //setting the next pointer of current to the new node (previous node points to new node)

        //increment the count of nodes in the list

        //return the updated list
}

List deleteStart(List list) { 
    //if head is NULL return the unchanged list

    //initialize a temp pointer to hold the first node (list.head)

    //update head to point to the second node by initializing it to head->next

    //free the old first node using the temp

    //decrement count

    //return the updated list
}

List deleteLast(List list) {
    //if head is NULL return the unchanged list

    //if the next node of head is NULL (only one node in the list)
    //free the only node by calling the free function and set head to NULL 

    //else traverse to find the second to the last node by:

        //initialize a pointer current to head meaning we start from the beginning of the list

        //create a while loop; current->next is the next node after current; current->next->next is the node after that
        //we want to stop when current->next->next is NULL meaning current is at the second to the last node
        //so keep moving while current->next->next is not NULL

            //inside the loop move current to the next node by setting current to current->next para ma identify na nato ang last node
        
        //after the loop, free the last node (current->next)
        
        //set current->next to NULL to mark it as the new last node
    
    //decrement count

    //return the updated list
}

List deletePos(List list, int index) {
    //make an if statement to check if index is valid (index is less than 0 or greater than or equal to count)
    //print invalid index
    //return the unchanged list

    //if deleting the first node (index is 0), call deleteStart

    //else, if we're not deleting the first node, we need to find the node right before the one we want to delete:

        //initialize a pointer Mode *current to head to traverse to the node before the one to delete

        //create a for loop to move current to the node just before the target index
        //(for i from 0 to index - 1 keep moving forward)

            //inside the loop initialize current to current->next meaning we have arrived at the node before the one to delete
            //and current will not be equal to the node to delete 
        
        //after the loop, save the node to delete in a temp pointer

        //skip over the node to delete by setting current->next to temp->next meaning the chain now bypasses the node to delete

        //free the deleted node using the temp

        //decrement count

        //return the updated list
}

//get the value at a specific index
int retrieve(List list, int index) {
    //make an if statement to check if index is valid

    //initialize a pointer current to head to traverse the list

    //create a for loop to move current to the target index (for i from 0 to index keep moving forward)

        //inside the loop move current to the next node by setting current to current->next

    //after the loop, return the data at that position by accessing current->data
}

int locate(List list, int data) {
    //initialize a pointer current to head to start at the beginning

    //initialize an index variable to 0 track the current position (head starts at position 0)

    //while current is not NULL (traverse the list looking for the data)

            //if the current data is equal to data we are looking for return the current index (data found so return the index)
        
            //if not found yet, move current to the next node by setting current to current->next

            //increment index to move to the next position

    //return -1 if data is not found
}

void display(List list) {
    //start from the beginning by initializing a pointer current to head

    //while current is not NULL (traverse and print each element)
    
        //print the data of the current node by accessing current->data

        //move current to the next node by setting current to current->next
    
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

//=========fill the code -- linked list variation 2=========
//linked list accessed by reference

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
    //allocate memory for a new List struct

    //if allocation was unsuccessful return NULL (if list == NULL)

    //set head to NULL to start with no nodes

    //set count to 0

    //return the pointer to the initialized list

}
void empty(List *list) {

    //initialize a pointer current with data type Node and set it to head

    //initialize a temp pointer to hold node before freeing

    //create a while loop to traverse the list (while current is not NULL)

        //inside the loop save current node in temp 

        //move current to the next node by setting current to next node

        //free the saved node
    
    //after the loop reset head to NULL (empty list)

    //reset count to 0

    //return nothing since the function is void
}
void insertFirst(List *list, int data) {
    //allocate memory for a new node

    //check if allocation was successful (if newNode == NULL) print memory allocation failed and return

    //set the data of the new node to the value you want to insert

    //set the next pointer of the new node to the current head of the list

    //update the head of the list to point to the new node

    //increment count

}
    
void insertLast(List *list, int data) {
    //allocate memory for a new node

    //check if allocation was successful (if newNode == NULL) print memory allocation failed and return

    //set the data of the new node to the value you want to insert

    //set the next pointer of the new node to NULL since it will be the last node

    //if the list is empty (head is NULL) set head to the new node

    //else traverse the list to find the last node by:

        //initialize a pointer current to head to start at the beginning

        //create a while loop to move current->next to the last node (while current->next is not NULL keep moving forward)

            //inside the loop move current to the next node by setting current to current->next

        //after the loop, set the next pointer of the last node (current) to the new node to attach it at the end

    //increment count
}

void insertPos(List *list, int data, int index) {
    //make an if statement for when index is less than 0 or greater than count
    //print invalid index and return


    //if inserting at the beginning (or index is 0), call insertFirst

    //else if, if inserting at the end (or index is count), call insertLast

    //else if we're inserting in between:

        //allocate memory for a new node

        //check if allocation was successful (if newNode == NULL) print memory allocation failed and return

        //set the data value of the new node to data

        //initialize a pointer current to head to traverse to the node before inserting

        //create a for loop to move current to the node just before the target index (for i from 0 to index - 1 keep moving forward)

            //inside the loop move current to the next node by setting current to current->next
        
        //link the newNode's next to current->next (new node points to the next node)

        //link current next to newNode (previous node points to new node)

        //increment count
}

void deleteStart(List *list) {
    //if statement wherein if head is NULL then return (nothing to delete)

    //initialize a temp pointer to hold the first node (list.head)

    //update head to point to the second node by initializing it to head->next (because we are now deleting the first node so head will now point to the second node as its first node)
 
    //free the old first node using the temp

    //decrement count
}

void deleteLast(List *list) {
    //if head is NULL return (list is empty)

    //if the next node of head is NULL (only one node in the list)

    //free head

    //set head to NULL

    //else traverse to find the second to the last node by:

        //initialize a pointer current to head meaning we start from the beginning of the list

        //create a while loop - we want to stop when current->next->next is NULL meaning current is at the second to the last node
        //so keep moving while current->next->next is not NULL

            //inside the loop move current to the next node by setting current to current->next para ma identify na nato ang last node
        
        //after the loop, free the last node (current->next)
        
        //set current->next to NULL to mark it as the new last node

    //decrement count
}

void deletePos(List *list, int index) {
    //make an if statement to check if index is valid (index is less than 0 or greater than or equal to count)

    //print invalid index

    //return

    //if index is 0 (deleting the first node), call deleteStart

    //else, if we're not deleting the first node, we need to find the node right before the one we want to delete:

        //initialize a pointer Node *current to head to traverse to the node before the one to delete

        //create a for loop to move current to the node just before the target index
        //(for i from 0 to index - 1 keep moving forward)

            //inside the loop initialize current to current->next meaning we have arrived at the node before the one to delete
            //and current->next will now be equal to the node to delete 
        
        //after the loop, store the node to delete in a temp pointer

        //skip over the node to delete by setting current->next to temp->next meaning the chain now bypasses the node to delete

        //free the deleted node using the temp

        //decrement count

}
int retrieve(List *list, int index) {
    //make an if statement to check if index is valid (less than 0 or greater than or equal to count)
    //print invalid index
    //return -1

    //initialize a pointer current to head to traverse the list

    //create a for loop to move current to the target index (for i from 0 to index keep moving forward)

        //inside the loop move current to the next node by setting current to current->next

    //after the loop, return the data at that position by accessing current->data
}

// Find position of a value
int locate(List *list, int data) {

    //initialize a pointer current to head to start at the beginning

    //initialize an index variable to 0 track the current position (head starts at position 0)

    //while current is not NULL (traverse the list looking for the data)

    //if the current data is equal to data we are looking for return the current index (data found so return the index)
        
            //if not found yet, move current to the next node by setting current to current->next

            //increment index to move to the next position

    //return -1 if data is not found
}

void display(List *list) {

    //initialize a pointer current to head to start from the beginning

    //while current is not NULL (traverse and print each element)
    
        //print the data of the current node by accessing current->data

        //move current to the next node by setting current to current->next

    //optional: print a newline at the end for better formatting

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


