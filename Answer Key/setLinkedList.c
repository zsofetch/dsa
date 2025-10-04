#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node {
	int data;
	struct node* next;
} *SET;

void initialize(SET *S);
void insertUniqueSorted(SET *S, int elem);
int find(SET S, int elem);
void deletion(SET *S, int elem);
SET setUnion(SET A, SET B);
SET setIntersection(SET A, SET B);
SET setDifference(SET A, SET B);
void display(SET S);
void pause();

int main(){
	SET A, B, U, I, D;
	int i;
	
	initialize(&A);
	initialize(&B);
	
	printf("Initializing SET A:\n");
	for(i = 0; i < 10; i++){
		insertUniqueSorted(&A, i + 1); // Set A contains 1 to 10
	}
	
	insertUniqueSorted(&A, 5); // Check if can insert a duplicate element
	
	printf("\nInitializing SET B:\n");
	for(i = 0; i < 10; i++){
		insertUniqueSorted(&B, i + 5); // Set B contains 5 to 14
	}
	
	printf("\nSET A:\n");
	display(A);
	
	printf("\nSET B:\n");
	display(B);
	
	pause();
	
	// Check if find works (both cases)
	printf("The element 8 %s in the set.\n", find(A, 8) ? "exists" : "does not exist");
	printf("The element 15 %s in the set.\n", find(A, 15) ? "exists" : "does not exist");
	
	// Check if deletion works (both cases)
	deletion(&A, 8);
	deletion(&A, 15);
	
	printf("\nSET A:\n");
	display(A);
	
	pause();
	
	U = setUnion(A, B); // U should have 1 to 14
	printf("\nSet Union (A and B):\n");
	display(U);
	
	pause();
	
	I = setIntersection(A, B); // I should have 5 to 10 (except 8 since we deleted 8 from set A)
	printf("\nSet Intersection (A and B):\n");
	display(I);
	
	pause();
	
	D = setDifference(A, B); // D should have 1 to 4
	printf("\nSet Difference (A - B):\n");
	display(D);
	
	return 0;
}

void initialize(SET *S){
	*S = NULL;
}

void insertUniqueSorted(SET *S, int elem){
	SET temp, *trav;
	
	for(trav = S; *trav != NULL && (*trav)->data < elem; trav = &(*trav)->next){}
	
	if(*trav == NULL || (*trav)->data > elem){
		temp = (SET)malloc(sizeof(struct node));
		
		if(temp != NULL){
			temp->data = elem;
			temp->next = *trav;
			*trav = temp;
			
			printf("Inserted %d into the set.\n", elem);
		} else {
			printf("Memory allocation failed.\n");
		}
	}
}

int find(SET S, int elem){	
	for(; S != NULL && S->data != elem; S = S->next){}
	
	return (S != NULL) ? 1 : 0;
}

void deletion(SET *S, int elem){
	SET temp, *trav;
	
	for(trav = S; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
	
	if(*trav != NULL){
		temp = *trav;
		*trav = temp->next;
		
		free(temp);
		
		printf("Successfully deleted %d from the set.\n", elem);
	} else {
		printf("The element %d does not exist.\n", elem);
	}
}

SET setUnion(SET A, SET B){
	SET S, *trav;
	
	initialize(&S);
	
	for(trav = &A; *trav != NULL; trav = &(*trav)->next){
		insertUniqueSorted(&S, (*trav)->data);
	}
	
	for(trav = &B; *trav != NULL; trav = &(*trav)->next){
		insertUniqueSorted(&S, (*trav)->data);
	}
	
	return S;
}

SET setIntersection(SET A, SET B){
	SET S, *trav_A, *trav_B;
	
	initialize(&S);
	
	for(trav_A = &A; *trav_A != NULL; trav_A = &(*trav_A)->next){
		for(trav_B = &B; *trav_B != NULL && (*trav_B)->data != (*trav_A)->data; trav_B = &(*trav_B)->next){}
		
		if(*trav_B != NULL){
			insertUniqueSorted(&S, (*trav_A)->data);
		}
	}
	
	return S;
}

SET setDifference(SET A, SET B){
	SET S, *trav_A, *trav_B;
	
	initialize(&S);
	
	for(trav_A = &A; *trav_A != NULL; trav_A = &(*trav_A)->next){
		for(trav_B = &B; *trav_B != NULL && (*trav_B)->data != (*trav_A)->data; trav_B = &(*trav_B)->next){}
		
		if(*trav_B == NULL){
			insertUniqueSorted(&S, (*trav_A)->data);
		}
	}
	
	return S;
}

void display(SET S){
	for(; S != NULL; S = S->next){
		printf("%d -> ", S->data);
	}
	
	printf("NULL\n\n");
}

void pause(){
	printf("\n\nPress any key to continue...");
	getch();
	system("CLS");
}