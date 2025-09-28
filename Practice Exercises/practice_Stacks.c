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
    pushSorted(stack, 25);

    display(stack);

    printf("top element is: %d\n", peek(stack));
    
    pop(stack);
    pop(stack);  
    display(stack);
    free(stack); 
    return 0;
}

//=========fill the code -- linked list stack=========

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// struct for a single node in the stack
typedef struct Node {
    int data; 
    struct Node* next;
} Node;

//struct for the stack itself
typedef struct Stack {
    Node* top; //pointer to the top node of the stack
} Stack;

Stack* initialize();
bool isFull(Stack* s);
bool isEmpty(Stack* s);
bool push(Stack* s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);
void freeStack(Stack* s);

Stack* initialize() {
    //allocate memory for Stack *s

    //if s is NULL print memory allocation failed and return NULL

    //if not, initialize top to NULL indicating that the stack is empty

    //return s (pointer to stack)
}

bool isFull(Stack* s) {
    // return false because linked list can grow dynamically
}

bool isEmpty(Stack* s) {
    //check if s is NULL and return true (NULL stack is considered empty)

    //else return top == NULL; (indicates stack is empty because top pointer is NULL)
}

bool push(Stack* s, int value) {
    //check if s is NULL and print invalid stack then return false

    //allocate memory for a new node

    //if newNode is NULL print memory allocation failed and return false

    //set the data of the new node to the provided value

    //Link the pointer next of new node to the current top of the stack

    //Update the stack's top pointer to point to the new node

    //return true

}

int pop(Stack* s) {
    //check if stack is empty with an if statement and print a statement then return -1

    //else initialize a temporary pointer to the top node indicating the node to be removed

    //before removing the top node, store its data in a temporary variable named data to return later
    
    //then we update the top pointer to point to the next node in the stack (hint: this is a linked list so you need to access the next pointer of the top node)

    //we throw away or free the memory of the old top node using the temporary pointer

    //return the data of that temp pointer
}

int peek(Stack* s) {
    //check if stack is empty with an if statement and print a statement then return -1

    //else return the data at the current top node (hint: this is a linked list so you need to access the data of the top node)
}

// Display from top to bottom
void display(Stack* s) {

    //check if stack is empty with an if statement and print a statement then return

    //else initialize a temporary pointer to the top node indicating the current node to print

    //while the temp pointer is not NULL

        //print the data of the current node

        //initialize temp as the next node (temp->next) - this means move to the next node in the stack

    //print a newline at the end

}

void freeStack(Stack* s) {

    //while the stack is not empty

        //pop elements in stack s to free nodes

    //free the stack structure itself

}

int main() {
    // Initialize an empty stack
    Stack* myStack = initialize();
    
    // Check if initialization was successful
    if (myStack == NULL) {
        return 1; // Exit with error code
    }
    
    printf("=== Stack Operations Demo ===\n");
    
    printf("Is stack empty? %s\n", isEmpty(myStack) ? "Yes" : "No");
    
    printf("\nPushing elements: 10, 20, 30\n");
    push(myStack, 10);  // Push 10 onto stack
    push(myStack, 20);  // Push 20 onto stack  
    push(myStack, 30);  // Push 30 onto stack
    
    display(myStack);
    
    printf("Top element (peek): %d\n", peek(myStack));
    
    printf("Is stack empty? %s\n", isEmpty(myStack) ? "Yes" : "No");
    
    printf("Is stack full? %s\n", isFull(myStack) ? "Yes" : "No");
    
    printf("\nPopping elements:\n");
    printf("Popped: %d\n", pop(myStack));  
    printf("Popped: %d\n", pop(myStack));  
    
    display(myStack);
    
    printf("Popped: %d\n", pop(myStack));  
    
    printf("\nTesting operations on empty stack:\n");
    display(myStack);           // show empty
    pop(myStack);               // show error
    printf("Peek result: %d\n", peek(myStack)); // show error
    
    freeStack(myStack);
    
    return 0; 
}