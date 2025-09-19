//Queue implementation using linked list (Variation 1)
//Queue has both front and rear pointers

#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h> 

// Define the structure for a single node in the queue
typedef struct Node {
    int data;           // Store the actual data value
    struct Node* next;  // Pointer to the next node in the queue
} Node;

// Define the structure for the queue itself
typedef struct Queue {
    Node* front;  // Pointer to the first node of the queue (dequeue from here)
    Node* rear;   // Pointer to the last node of the queue (enqueue here)
} Queue;

// Function prototypes - declare all functions before defining them
Queue* initialize();
bool isEmpty(Queue* q);
bool enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front(Queue* q);
void display(Queue* q);

// Initialize an empty queue
Queue* initialize() {
    // Allocate memory for the queue structure
    Queue* q = (Queue*)malloc(sizeof(Queue));
    
    // Check if memory allocation was successful
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Initialize both front and rear pointers to NULL (empty queue)
    q->front = NULL;
    q->rear = NULL;
    
    // Return the pointer to the initialized queue
    return q;
}


// Check if the queue is empty
bool isEmpty(Queue* q) {
    return (q == NULL || q->front == NULL);
    // Consider NULL queue as empty
    // Queue is empty if the front pointer is NULL
}

// Enqueue (add) a new value to the rear of the queue
bool enqueue(Queue* q, int value) {
    // Check if the queue pointer is valid
    if (q == NULL) {
        return false; // Operation failed
    }
    
    // Allocate memory for a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    
    // Check if memory allocation was successful
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        return false; // Operation failed
    }
    
    // Set the data of the new node to the provided value
    newNode->data = value;
    
    // Set the next pointer of new node to NULL (it will be the last node)
    newNode->next = NULL;
    
    // Check if the queue is currently empty
    if (isEmpty(q)) {
        // If empty, the new node is both the front and the rear
        q->front = newNode;
        q->rear = newNode;
    } else {
        // If not empty, link the current rear to the new node
        q->rear->next = newNode;
        
        // Then, update the rear pointer to the new node
        q->rear = newNode;
    }
    
    return true; // Operation successful
}

// Dequeue (remove and return) the front value from the queue
int dequeue(Queue* q) {
    // Check if the queue is empty before attempting to dequeue
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 as error indicator
    }
    
    // Store a temporary pointer to the front node
    Node* temp = q->front;
    
    // Store the data of the front node (value to be returned)
    int data = temp->data;
    
    // Move the front pointer to the next node
    q->front = q->front->next;
    
    // If the queue becomes empty after this operation, update rear pointer to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    // Free the memory of the old front node using the temporary pointer
    free(temp);
    
    // Return the stored value from the dequeued node
    return data;
}

// Get the front value without removing it from the queue
int front(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot get front element.\n");
        return -1; // Return -1 as error indicator
    }
    
    // Otherwise, return the data of the front node
    return q->front->data;
}

// Display all elements in the queue from front to rear
void display(Queue* q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return;
    }
    
    // Create a temporary pointer to traverse the queue
    // Start from the front node
    Node* temp = q->front;
    
    printf("Queue elements (front to rear): ");
    
    // Loop through the list until the end (NULL) is reached
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print current node's data
        temp = temp->next;          // Move to the next node
    }
    
    printf("\n"); // Print newline at the end
}

// Helper function to free all nodes and the queue structure
void destroyQueue(Queue* q) {
    // Free all nodes in the queue
    while (!isEmpty(q)) {
        dequeue(q); // This will free each node
    }
    
    // Free the queue structure itself
    free(q);
}

// Main function to demonstrate the queue operations
int main() {
    Queue* myQueue = initialize();
    if (myQueue == NULL) return 1;

    printf("=== Linked List Queue Demo (Variation 1) ===\n");

    // Enqueue some elements
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    display(myQueue);

    // Show the front element
    printf("Front element: %d\n", front(myQueue));

    // Dequeue one element
    printf("Dequeued: %d\n", dequeue(myQueue));
    display(myQueue);

    // Add another element
    enqueue(myQueue, 40);
    display(myQueue);

    // Dequeue all remaining elements
    printf("Emptying the queue:\n");
    while (!isEmpty(myQueue)) {
        printf("Dequeued: %d\n", dequeue(myQueue));
    }

    display(myQueue);

    destroyQueue(myQueue);
    return 0;
}