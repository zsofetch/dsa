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
    Stack *s = (Stack*)malloc(sizeof(Stack)); //why are we malloc-ing
    s->top = -1; //top is -1 (ure not pointing to any box yet)
    return s; //pointer to stack
}

bool isFull(Stack* s) {
    return s->top == MAX - 1; //s-top == MAX - 1 mean ure at the last box already
}

bool isEmpty(Stack* s) {
    return s->top == -1;  //top is -1 (ure not pointing to any box yet)
}

void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("stack is full silly!\n");
        return;
    }
    s->top++;
    s->items[s->top] = value; 
    /*place the new value at the current top position 
    because this is pushing value to the right*/
}

int pop (Stack *s) {
    if (isEmpty(s)) {
        printf("stack is empty dumdum!\n");
        return -1;
    }
    int value = s->items[s->top]; 
    /*get the value at the current
    top of the stack?!??! HA*/
    s->top--;
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
    for(int i = s->top; i >= 0; i--) {
        /*its like we're saying if i = to the top block keep
        printing until you reach the bottom as long as i = 0 or bigger
        when i become -1, STOP! go down one block at a time therefore decrementing*/
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
