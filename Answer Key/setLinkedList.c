#include <stdio.h>
#include <stdlib.h>

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
        insertUniqueSorted(&A, i + 1); // 1–10
    }
    
    insertUniqueSorted(&A, 5); // Duplicate test
    
    printf("\nInitializing SET B:\n");
    for(i = 0; i < 10; i++){
        insertUniqueSorted(&B, i + 5); // 5–14
    }
    
    printf("\nSET A:\n");
    display(A);
    
    printf("\nSET B:\n");
    display(B);
    
    pause();
    
    printf("The element 8 %s in the set.\n", find(A, 8) ? "exists" : "does not exist");
    printf("The element 15 %s in the set.\n", find(A, 15) ? "exists" : "does not exist");
    
    deletion(&A, 8);
    deletion(&A, 15);
    
    printf("\nSET A after deletions:\n");
    display(A);
    
    pause();
    
    U = setUnion(A, B);
    printf("\nSet Union (A and B):\n");
    display(U);
    
    pause();
    
    I = setIntersection(A, B);
    printf("\nSet Intersection (A and B):\n");
    display(I);
    
    pause();
    
    D = setDifference(A, B);
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
        temp = malloc(sizeof(struct node));
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
    return (S != NULL);
}

void deletion(SET *S, int elem){
    SET temp, *trav;
    for(trav = S; *trav != NULL && (*trav)->data != elem; trav = &(*trav)->next){}
    if(*trav != NULL){
        temp = *trav;
        *trav = temp->next;
        free(temp);
        printf("Deleted %d from the set.\n", elem);
    } else {
        printf("Element %d not found.\n", elem);
    }
}

SET setUnion(SET A, SET B){
    SET S;
    initialize(&S);
    for(SET temp = A; temp != NULL; temp = temp->next)
        insertUniqueSorted(&S, temp->data);
    for(SET temp = B; temp != NULL; temp = temp->next)
        insertUniqueSorted(&S, temp->data);
    return S;
}

SET setIntersection(SET A, SET B){
    SET S;
    initialize(&S);
    for(SET tempA = A; tempA != NULL; tempA = tempA->next)
        if(find(B, tempA->data))
            insertUniqueSorted(&S, tempA->data);
    return S;
}

SET setDifference(SET A, SET B){
    SET S;
    initialize(&S);
    for(SET tempA = A; tempA != NULL; tempA = tempA->next)
        if(!find(B, tempA->data))
            insertUniqueSorted(&S, tempA->data);
    return S;
}

void display(SET S){
    for(; S != NULL; S = S->next)
        printf("%d -> ", S->data);
    printf("NULL\n\n");
}

void pause(){
    printf("\n\nPress Enter to continue...");
    getchar();  // waits for user to press Enter
    system("clear"); // works on Linux/Mac (use "cls" on Windows)
}
