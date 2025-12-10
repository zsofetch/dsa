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
    //iterate through the dictionary
	   //set each indices in D to NULL
}

// This function will return a key based on the ONES digit of the passed elem
// For example, the passed elem is 10. This function will return 0 since the ONES digit of elem is 0.
int hash(Dictionary D, int elem){
    //return elem modulus MAX
}

// This function inserts an element into the dictionary in ascending order
// Ensures no duplicates are inserted
void insertUniqueSorted(Dictionary D, int elem){

	//declare *trav and temp variable with datatype SET

	//initialize key variable to hash function

	//allocate memory for newNode with datatype SET

	//initialize trav to address of D at index key

	//set newNode's date to elem

	//if newNode is not NULL
	   
	   //if *trav is NULL

	        //initialize newNode's next to *trav

		    //initialize *trav to newNode

		    //print that elem is inserted in the dictionary

		//else 

		    //butterfly loop - ; while *trav is not NULL and *trav's data is less than elem; initialize trav to address of *trav's next {}

			//if *trav is NULL or *trav's data is greater than elem
			 
			    //initialize temp to *trav

				//initialize newNode's next to temp

				//initialize *trav to newNode

				//print that elem is inserted in the dictionary

		    //else
			    
			    //print that elem already exists in the dictionary

		//else
		    //print malloc failed
}

// This function will delete an element in the dictionary
// If element is found, delete the element and print a message that it is deleted
// Else, print a message that the element does not exist in the dictionary
void deleteElem(Dictionary D, int elem){

	//declare temp and *trav variable with datatype SET

	//initialize key variable to hash function

	//butterfly loop - initialize trav to address of D at index key; while *trav is not NULL and *trav's data is not equal to elem; initialize trav to address of *trav's next {}

	//if *trav is not NULL

	   //initialize temp to *trav

	   //initialize *trav to temp's next

	   //free temp

	   //print that elem is deleted from the dictionary

	//else print that element does not exist in the dictionary

}

// This function will check if the passed elem exists in the dictionary
// If the elem exists, return TRUE
// else, return FALSE
Boolean isMember(Dictionary D, int elem){

	//declare trav variable with datatype SET

	//initialize idx variable to hash function

	//butterfly loop - initialize trav to D at index idx; trav is not NULL and trav's data is not equal to elem; initialize trav to trav's next {}

	//return trav is not NULL ? TRUE OR FALSE

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

// This function empties the dictionary
// Frees all allocated nodes in every bucket
// After execution, all indices will point to NULL
// Once done, print a message that the dictionary is now empty
void makeNull(Dictionary D){

	//declare temp and *trav variable with datatype SET

	//create a for loop and traverse through the dictionary

	   //in the nested loop - while trav = address of D at index i; *trav is not NULL;

	       //initialize temp to *trav

		   //initialize *trav to temp's next

		   //free temp

	//exit for loops and print dictionary is now empty
}

