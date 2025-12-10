//PRACTICE - DICTIONARIES

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int data;
	struct node* next;
} *SET;

typedef SET Dictionary[MAX];
typedef enum {FALSE, TRUE} Boolean;

void initDict(Dictionary D);
int hash(Dictionary D, int elem);
void insertUniqueSorted(Dictionary D, int elem);
void deleteElem(Dictionary D, int elem);
Boolean isMember(Dictionary D, int elem);
void display(Dictionary D); // This function is completed for you
void makeNull(Dictionary D);

int main(){
	Dictionary D;
	
	initDict(D);
	
	insertUniqueSorted(D, 10);
	insertUniqueSorted(D, 11);
	insertUniqueSorted(D, 12);
	insertUniqueSorted(D, 13);
	insertUniqueSorted(D, 14);
//	insertUniqueSorted(D, 15); Check if display works as intended
	insertUniqueSorted(D, 16);
	insertUniqueSorted(D, 17);
	insertUniqueSorted(D, 18);
	insertUniqueSorted(D, 19);
	printf("\n");
	
	// Check if insertUniqueSorted works as intended
	insertUniqueSorted(D, 80);
	insertUniqueSorted(D, 30);
	insertUniqueSorted(D, 90);
	insertUniqueSorted(D, 50);
	insertUniqueSorted(D, 60);
	printf("\n");
	
	// Check if duplicate element can be inserted
	insertUniqueSorted(D, 30);
	printf("\n");
	
	// Check if deleteElem works as intended (both cases)
	deleteElem(D, 10);
	deleteElem(D, 10);
	printf("\n");
	
	// Check if isMember works as intended (both cases)
	printf("The member %d %s in the dictionary.\n", 30, (isMember(D, 30) == TRUE) ? "exists" : "does not exist");
	printf("The member %d %s in the dictionary.\n", 69, (isMember(D, 69) == TRUE) ? "exists" : "does not exist");
	printf("\n");
	
	display(D);
	
	// Check if makeNull works as intended
	makeNull(D);
	printf("\n");
	
	display(D);
	
	return 0;
}

// This functions initalizes the dictionary
// Set each indices of the dictionary to be NULL
void initDict(Dictionary D){
//loop through the array
for (int i = 0; i < MAX; i++) {
    //initialize each index of array D to null
    D[i] = NULL;
}
}

// This function will return a key based on the ONES digit of the passed elem 
// For example, the passed elem is 10. This function will return 0 since the ONES digit of elem is 0.
int hash(Dictionary D, int elem){
//to get the ONES element, modulo 10 element
return elem % 10;
}

// This function inserts an element into the dictionary in ascending order
// Ensures no duplicates are inserted
// uses p2p (*trav) for easy insertion
void insertUniqueSorted(Dictionary D, int elem){
//find which bucket to use - initialize key by (getting the bucket index) using the hash function

//initialize SET *trav to the address D[key] or the pointer to the first node in the bucket as well as the new node

//use a while loop to traverse - while the pointer trav is not equal to NULL and data of pointer trav is less than the element

//initialize trav = first dereferences the double pointer trav to get the current node (*trav), 
//then accesses the next member of that node, and finally takes the address of this next pointer, assigning it back to trav

//exit while loop and create an if statement 
//if *trav is not or not equal to NULL and data at *trav is equal to elem

//print that elem already exists in the dictionary and return

//exit if statement and create a new node by mallocing first

//store the elem at newNode's data

//initialize the next of newNode and point to the current node (*trav)

//initialize *trav to newNode (this links the previous node to the new node)

//print a message that element has been inserted in the bucket

}

// This function will delete an element in the dictionary
void deleteElem(Dictionary D, int elem){
//similar to insertUniqueSorted find which bucket to use 

//trav starts at the address of D[key] so we can modify the pointer that points to the node we want to delete
//initialize SET *trav to the address D[key] or the pointer to the first node in the bucket as well as temp

//with a while loop, find node with data == elem -> while *trav is not or not equal to NULL and the data in *trav is not equal to elem 

//initialize trav to address of *trav->next (this traverses through the linked list)

//exit loop and initialize an if statement wherein if *trav is NULL print that the element does not exist in the dictionary

//else, store the node to delete by initializing a temp variable to *trav

//bypass node by traversing through the linked list

//free temp variable

//create a print statement saying that deletion has been successful
}

// This function will check if the passed elem exists in the dictionary
// If the elem exists, return TRUE
// else, return FALSE
Boolean isMember(Dictionary D, int elem){
//similar to insertUniqueSorted find which bucket to use

//initialize trav with datatype SET to D[key] (this is the start of the linked list)

//create a while loop wherein while trav is not equal to NULL

//create a nested if statement wherein if data in trav is equal to elem, return TRUE

//exit if statement and initialize trav to the next of trav

//exit while loop and return FALSE
}



// This function empties the dictionary
// Frees all allocated nodes in every bucket
// After execution, all indices will point to NULL
// Once done, print a message that the dictionary is now empty
void makeNull(Dictionary D){
//create a for loop and traverse 

//initialize trav with datatype SET to the index of array D and temp

//while trav is not equal to NULL 

//initialize temp to trav

//initialize trav to trav->next

//free the temp variable

//exit for loop and initialize the index of D array to NULL (resets bucket just like initialization)

//exit while loop and print dictionary is now empty
}


// This function is completed for you
void display(Dictionary D){
	SET trav;
	int i, temp;
	
	printf("Dictionary:\n");
	
	for(i = 0; i < MAX; i++){
		printf("[%d]: ", i);
		
		if(D[i] == NULL){
			printf("EMPTY");
		} else {
			for(trav = D[i]; trav != NULL; trav = trav->next){
				if(trav->next != NULL){
					printf("%d -> ", trav->data);
				} else {
					printf("%d", trav->data);
				}	
			}
		}
		
		printf("\n");
	}
	
	printf("\n");
}
