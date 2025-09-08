//to be debugged
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
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->top = -1;
    return s;
}

bool isFull(Stack* s) {
    return s->top == MAX - 1;
}

bool isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("stack is full silly!");
        return;
    }
    s->top++;
    s->items[s->top] = value;
}

int pop (Stack *s) {
    if (isFull(s)) {
        printf("stack is full dumdum!");
        return -1;
    }
    int value = s->items[s->top]; //get the value at the current top of the stack ?!?!??! HA?!??!
    s->top--;
    return value;
}
// i >= 0; i--

int peek (Stack *s) {
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
    for(int i = s->top; i >= 0; i--) { //increment or decrement?!??
        printf("%d\n", s->items[i]);
    }
}
    

int main() {
    Stack* stack = initialize();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    display(stack);

    printf("top element is: %d\n", peek(stack));
    display(stack);
    pop(stack);
    pop(stack);  

    free(stack); 
    return 0;
}
