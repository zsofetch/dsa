//this is a bonus file, not part of the assignment
//this time we have an array stack wherein its dynamic

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 4

typedef struct {
    int *items;     // dynamically allocated array
    int top;        // index of top element
    int capacity;   // current capacity of the array
} Stack;

//function prototypes
Stack* initialize();
bool isFull(Stack *s);
bool isEmpty(Stack *s);
void resize(Stack *s);
void push(Stack *s, int value);
void pushSorted(Stack *s, int value);
int pop(Stack* s);
int peek(Stack* s);
void display(Stack* s);

Stack* initialize() {
    Stack *s = (Stack*)malloc(sizeof(Stack)); 
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->items = (int*)malloc(INITIAL_CAPACITY * sizeof(int));
    if (s->items == NULL) {
        printf("Array allocation failed!\n");
        exit(1);
    }
    s->top = -1; //top is -1 (ure not pointing to any box yet)
    s->capacity = INITIAL_CAPACITY;
    return s; //pointer to stack
}

bool isFull(Stack* s) {
    return s->top == s->capacity - 1; //s-top == last index means you're full
}

bool isEmpty(Stack* s) {
    return s->top == -1;  //top is -1 (ure not pointing to any box yet)
}

void resize(Stack *s) {
    s->capacity *= 2;
    s->items = (int*)realloc(s->items, s->capacity * sizeof(int));
    if (s->items == NULL) {
        printf("Reallocation failed!\n");
        exit(1);
    }
    printf("Stack resized to capacity %d\n", s->capacity);
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        resize(s); // double the size if full
    }
    s->top++;
    s->items[s->top] = value; 
    /*place the new value at the current top position 
    because this is pushing value to the right*/
}

void pushSorted(Stack *s, int value) {
    if (isFull(s)) {
        resize(s); // make room before shifting
    }

    int i = s->top;
    // shift bigger elements to the right to make space for the smaller value
    while (i >= 0 && s->items[i] > value) {
        s->items[i + 1] = s->items[i];
        i--;
    }

    s->items[i + 1] = value; // insert new value
    s->top++;
}

int pop (Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty dumdum!\n");
        return -1;
    }
    int value = s->items[s->top]; 
    s->top--; //move down one block
    return value;
}

int peek (Stack *s) { //returning value on top of the stack
    if (isEmpty(s)) {
        printf("stack is empty! what's there to peek!?!?!?\n");
        return -1;
    }
    return s->items[s->top];
}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty! what's there to display?!?!\n");
        return;
    }
    printf("here are the stack elements! \n");
    for(int i = s->top; i >= 0; i--) {
        printf("%d\n", s->items[i]);
    }
}

int main() {
    Stack* stack = initialize();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50); // triggers resize

    pushSorted(stack, 25); // inserts in sorted position

    display(stack);

    printf("top element is: %d\n", peek(stack));
    
    pop(stack);
    pop(stack);  
    display(stack);

    free(stack->items); 
    free(stack); 
    return 0;
}
