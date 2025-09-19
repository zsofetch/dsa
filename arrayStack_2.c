//top starts at MAX
//top moves to the left (decrements) as elements are pushed

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
    Stack *s = (Stack*)malloc(sizeof(Stack)); 
     if (s == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    s->top = MAX; //empty stack starts at MAX
    return s; //pointer to stack
}

bool isFull(Stack* s) {
    return s->top == 0; //full when top reaches index 0 means youre at the first box now
}

bool isEmpty(Stack* s) {
    return s->top == MAX; //top == MAX when youre past all the boxes
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("stack is full silly!\n");
        return;
    }
    s->top--; //move to the left 
    s->items[s->top] = value; //store value
}

void pushSorted(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack is full, cannot push %d\n", value);
        return;
    }

    int i = MAX - 1; // start from the rightmost used slot
    // shift smaller elements to the right
    while (i >= s->top && s->items[i] > value) {
        s->items[i + 1] = s->items[i];
        i--;
    }

    s->top--; // move top left
    s->items[i + 1] = value; // place new element
}

int pop (Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty dumdum!\n");
        return -1;
    }
    int value = s->items[s->top]; 
    s->top++; //increment cos we're moving to the right after popping
    return value;
}

int peek (Stack *s) { //returning value on top of the stack
    if (isEmpty(s)) {
        printf("stack is empty! what's there to peek!?!?!?");
        return -1;
    }
    return s->items[s->top];

}

void display(Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty! what's there to display?!?!");
        return;
    }
    printf("here are the stack elements! \n");
    for(int i = s->top; i < MAX; i++) {
        /*its like we're saying if i = to the top block keep
        printing until you reach MAX, go up one block at a time therefore incrementing*/
        printf("%d\n", s->items[i]);
    }
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
