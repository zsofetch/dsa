//=========fill the code -- array stack var 1=========
//pushing elements to the right
//popping elements to the left
//top starts at -1 (empty stack)
//top moves to the right (increments) as elements are pushed
//if top = MAX - 1 then stack is full
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

//function prototypes
Stack* initialize();
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

Stack* initialize() {
    //allocate memory for Stack *s

    //if s is NULL print memory allocation failed and exit

    //if not, initialize top to -1 indicating that the stack is empty

    //return s (pointer to stack)
}

bool isFull(Stack* s) {
    //return top == MAX - 1 (indicates stack is full because top is at the last index)
}

bool isEmpty(Stack* s) {
    //return top == -1;  (indicates stack is empty because top is at -1)
}

void push(Stack *s, int value) {
    //check if stack is full with an if statement and print a statement then return

    //else increment top (since we're moving to the right)

    //at the current top position which is stored in the items array, place the value
    //note: we place the new value at the current top position because this is pushing value to the right
}


void pushSorted(Stack *s, int value) {
    //if stack is full with an if statement and print a statement then return

    //initialize i to the current top position

    //while i is greater than or equal to 0 and the current item at index i is greater than value

        //shift the item at index i to index i + 1 (moving it to the right since it is bigger)

        //decrement i

    //after the while loop, place the new value at index i + 1 (the correct sorted position)

    //increment top
}

int pop (Stack *s) {
    //check if stack is empty with an if statement and print a statement then return -1

    //else get the value and initialize it to the top position of items array

    //decrement top

    //return the value
}

int peek (Stack *s) { //returning value on top of the stack

    //check if stack is empty with an if statement and print a statement then return -1

    //else return the value at the current top position of items array
}

void display(Stack *s) {
    //check if stack is empty with an if statement and print a statement then return

    //else create a for loop starting from the top position; continue while i is greater than or equal to 0; decrement i

    //print the value at the current index of items array

}
    

int main() {
    Stack* stack = initialize();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    display(stack);

    printf("top element is: %d\n", peek(stack));
    
    pop(stack);
    pop(stack);  
    display(stack);
    free(stack); 
    return 0;
}

//=========fill the code -- array stack var 2=========
//top starts at MAX
//top moves to the left (decrements) as elements are pushed
//top moves to the right (increments) as elements are popped
//we are going backwards
//if top = 0 then stack is full

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define MAX 10

typedef struct {
    int items[MAX];
    int top;
} Stack;

//function prototypes
Stack* initialize();
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void push(Stack *s, int value);
void pushSorted(Stack *s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

Stack* initialize() {
    //allocate memory for Stack *s

    //if s is NULL print memory allocation failed and exit

    //if not, initialize top to MAX indicating that the stack is empty

    //return s (pointer to stack)
}

bool isFull(Stack* s) {
    //return top == 0; (indicates stack is full because top is at the first index)
}

bool isEmpty(Stack* s) {
    //return top == MAX;  (indicates stack is empty because top is past the last index)
}

void push(Stack *s, int value) {
    //check if stack is full with an if statement and print a statement then return

    //else decrement top (since we're moving to the left)

    //at the current top position which is stored in the items array, place the value

}

void pushSorted(Stack *s, int value) {
    //check if stack is full with an if statement and print a statement then return

    //initialize i to MAX - 1 (the rightmost used slot)

    //while i is greater than or equal to top and the current item at index i is greater than value

        //shift the item at index i to index i + 1 (moving it to the right since it is bigger)

        //decrement i

    //decrement top (move top left)
    
    //place the new value at index i + 1 (the correct sorted position)

}

int pop (Stack *s) {
    //check if stack is empty with an if statement and print a statement then return -1

    //else get the value and initialize it to the top position of items array

    //increment top

    //return the value

}

int peek (Stack *s) { //returning value on top of the stack
    //check if stack is empty with an if statement and print a statement then return -1

    //else return the value at the current top position of items array

}

void display(Stack *s) {
    //check if stack is empty with an if statement and print a statement then return

    //else create a for loop starting from the top position; continue while i is less than MAX; increment i

    //print the value at the current index of items array
    //note: its like we're saying if i = to the top block keep printing until you reach MAX, go up one block at a time therefore incrementing

}
    

int main() {
    Stack* stack = initialize();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);

    display(stack);

    printf("top element is: %d\n", peek(stack));
    
    pop(stack);
    pop(stack);  
    display(stack);
    free(stack); 
    return 0;
}
