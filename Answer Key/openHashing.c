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

void initDict(Dictionary D){
	int i;
	
	for(i = 0; i < MAX; i++){
		D[i] = NULL;
	}
}

int hash(Dictionary D, int elem){
	return elem % MAX;
}

void insertUniqueSorted(Dictionary D, int elem){
	SET temp, *trav;
	SET newNode = (SET)malloc(sizeof(struct node));
	int key = hash(D, elem);
	
	trav = &D[key];
	newNode->data = elem;
	
	if(newNode != NULL){
		// Check for empty case
		if(*trav == NULL){
			newNode->next = *trav;
			*trav = newNode;
			printf("Inserted %d in the dictionary.\n", elem);
		} else {
			for(; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->next){}
			
			// If *trav == NULL, the eleme is not yet inserted and therefore is unique
			// If (*trav)->data > elem, the elem will be inserted before the node that *trav is pointing to
			if(*trav == NULL || (*trav)->data > elem){
				temp = *trav;
				newNode->next = temp;
				*trav = newNode;
				
				printf("Inserted %d in the dictionary.\n", elem);
			} else {
				printf("Element %d is already in the dictionary.\n", elem);
			}
		}
	} else {
		printf("Memory allocation failed.\n");
	}
}

void deleteElem(Dictionary D, int elem){
	SET temp, *trav;
	int key = hash(D, elem);
	
	for(trav = &D[key]; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
	
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->next;
		
		free(temp);
		
		printf("Deleted %d in the dictionary.\n", elem);
	} else {
		printf("The element %d does not exist in the dictionary.\n", elem);
	}
}

Boolean isMember(Dictionary D, int elem){
	SET trav;
	int idx = hash(D, elem);
	
	for(trav = D[idx]; trav != NULL && trav->data != elem; trav = trav->next){}
	
	return (trav != NULL) ? TRUE : FALSE;
}

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

void makeNull(Dictionary D){
	SET temp, *trav;
	int i;
	
	for(i = 0; i < MAX; i++){
		for(trav = &D[i]; *trav != NULL;){
			temp = *trav;
			*trav = temp->next;
			
			free(temp);
		}
	}
	
	printf("Dictionary is now empty.\n");
}
