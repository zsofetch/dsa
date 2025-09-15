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

Stack* initialize() {
    // malloc for the stack structure
    Stack* s = (Stack*)malloc(sizeof(Stack));
    
    // check if malloc was successful
    if (s == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // initialize the stack's top pointer to NULL (empty stack)
    s->top = NULL;
    
    // Return the pointer to the initialized stack
    return s;
}

bool isFull(Stack* s) {
    // return false because linked list can grow dynamically
    return false;
}

bool isEmpty(Stack* s) {
    if (s == NULL) {
        return true; //NULL stack as empty
    }
    
    // The stack is empty if its top pointer is NULL
    return (s->top == NULL);
}

bool push(Stack* s, int value) {
    if (s == NULL) {
        printf("Invalid stack!\n");
        return false;
    }
    
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return false;
    }
    
    // Set the data of the new node to the provided value
    newNode->data = value;
    
    // Link the new node to the current top of the stack
    // (new node points to what was previously the top)
    newNode->next = s->top;
    
    // Update the stack's top pointer to point to the new node
    // (making the new node the new top of the stack)
    s->top = newNode;
    
    return true;
}


//popping variation 1
int pop(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot pop.\n");
        return -1;
    }
    
    // Get a temporary pointer to the top node
    Node* temp = s->top;
    
    // Store the data of the top node (value to be returned)
    int data = temp->data;
    
    // Move the top pointer to the next node
    // (effectively removing the current top from the stack)
    s->top = s->top->next;
    
    // Free the memory of the old top node using the temporary pointer
    free(temp);
    
    // Return the stored value from the popped node
    return data;
}

int peek(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty! Cannot peek.\n");
        return -1;
    }
    
    // Return the data of the top node without removing it
    return s->top->data;
}

// Display from top to bottom
void display(Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty!\n");
        return;
    }
    
    // Create a temporary pointer to traverse the stack
    // (start from the top node)
    Node* temp = s->top;
    
    printf("Stack elements (top to bottom): ");
    
    // Traverse the linked list and print each element's data
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    
    printf("\n"); 
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
    
    free(myStack);
    
    return 0; 
}