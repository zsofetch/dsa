#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct node {
	int data;
	struct node* next;
} *SET;  // SET is a pointer to a struct node

typedef SET Dictionary[MAX];  // Dictionary = array of 10 SETs (linked list heads)
typedef enum {FALSE, TRUE} Boolean;

void initDict(Dictionary D);
int hash(Dictionary D, int elem);
void insertUniqueSorted(Dictionary D, int elem);
void deleteElem(Dictionary D, int elem);
Boolean isMember(Dictionary D, int elem);
void display(Dictionary D);
void makeNull(Dictionary D);

int main(){
	Dictionary D;
	
	initDict(D);
	
	insertUniqueSorted(D, 10);
	insertUniqueSorted(D, 11);
	insertUniqueSorted(D, 12);
	insertUniqueSorted(D, 13);
	insertUniqueSorted(D, 14);
	insertUniqueSorted(D, 16);
	insertUniqueSorted(D, 17);
	insertUniqueSorted(D, 18);
	insertUniqueSorted(D, 19);
	printf("\n");
	
	insertUniqueSorted(D, 80);
	insertUniqueSorted(D, 30);
	insertUniqueSorted(D, 90);
	insertUniqueSorted(D, 50);
	insertUniqueSorted(D, 60);
	printf("\n");
	
	insertUniqueSorted(D, 30);
	printf("\n");
	
	deleteElem(D, 10);
	deleteElem(D, 10);
	printf("\n");
	
	printf("The member %d %s in the dictionary.\n", 30, (isMember(D, 30) == TRUE) ? "exists" : "does not exist");
	printf("The member %d %s in the dictionary.\n", 69, (isMember(D, 69) == TRUE) ? "exists" : "does not exist");
	printf("\n");
	
	display(D);
	
	makeNull(D);
	printf("\n");
	
	display(D);
	
	return 0;
}

void initDict(Dictionary D) {
    for (int i = 0; i < MAX; i++) { //loops through the dictionary 
         D[i] = NULL; //sets the indices in D to NULL
    }
}

//returns the ones digit (57 -> 7)
int hash(Dictionary D, int elem) {
    return elem % 10;
}

// - Prevents duplicates
// - Uses p2p (*trav) for easy insertion
void insertUniqueSorted(Dictionary D, int elem) {
    int key = hash(D, elem); //find which bucket to use
    SET *trav = &D[key], newNode;
    /*
      - D is an array of pointers to struct node
      - D[i] is a linked list head pointer (can be NULL or point to the first node)
      - D[key] is a pointer to the first node in bucket [key]
        so &D[key] is the address of that pointer
      - In other words, &D[key] is a pointer to the head pointer
      - SET *trav = &D[key] means trav is a pointer to the pointer D[key]
    */

while (*trav != NULL && (*trav)->data < elem) {
    trav = &(*trav)->next //move to the next node (via p2p)
    /*traverse until we find:
      - a node with data >= elem (insert before it)
      - or the end of the list (insert at tail)
    */
}

//if duplicate found, do not insert
if (*trav != NULL && (*trav)->data == elem) {
    printf("%d already exists in the dictionary.\n", elem);
    return;
}

//create new node
newNode = (SET)malloc(sizeof(struct node));
newNode->data = elem;
newNode->next = *trav; //point to the current node (*trav)
*trav = newNode //link previous node (or head) to new node

printf("Inserted %d in bucket [%d].\n", elem, key);

}

//if element is found, delete the element and print a message that it is deleted
//else, print a message that the element does not exist in the dictionary
void deleteElem(Dictionary D, int elem){
	int key = hash(D, elem);
	SET *trav = &D[key], temp;
	
	// Find node with data == elem
	while(*trav != NULL && (*trav)->data != elem){
		trav = &(*trav)->next;  // traverse through linked list
	}
	
	if(*trav == NULL){
		printf("%d does not exist in the dictionary.\n", elem);
	} else {
		// Found node to delete
		temp = *trav;          // store node to free
		*trav = (*trav)->next; // bypass node
		free(temp);            // free memory
		printf("%d deleted from bucket [%d].\n", elem, key);
	}
}

// This function will check if the passed elem exists in the dictionary
// If the elem exists, return TRUE
// else, return FALSE
Boolean isMember(Dictionary D, int elem){
	int key = hash(D, elem);
	SET trav = D[key];  // start of the linked list
	
	while(trav != NULL){
		if(trav->data == elem){
			return TRUE;
		}
		trav = trav->next;
	}
	return FALSE;
}

void makeNull(Dictionary D){
	for(int i = 0; i < MAX; i++){
		SET trav = D[i], temp;
		while(trav != NULL){
			temp = trav;
			trav = trav->next;
			free(temp);
		}
		D[i] = NULL; // reset bucket
	}
	printf("Dictionary is now empty.\n");
}

void display(Dictionary D){
	SET trav;
	int i;
	
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

