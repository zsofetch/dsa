//Queue implementation using linked list (Variation 1)
//Queue has both front and rear pointers

#include <stdio.h>   // Include standard input/output library for printf
#include <stdlib.h>  // Include standard library for malloc and free
#include <stdbool.h> // Include boolean library for true/false values

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
bool isFull(Queue* q);
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

// Check if the queue is full (linked list implementation can never be full)
bool isFull(Queue* q) {
    // Return false because linked list can grow dynamically
    // (limited only by available system memory)
    return false;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    // Check if queue pointer is valid
    if (q == NULL) {
        return true; // Consider NULL queue as empty
    }
    
    // Queue is empty if the front pointer is NULL
    return (q->front == NULL);
}

// Enqueue (add) a new value to the rear of the queue
bool enqueue(Queue* q, int value) {
    // Check if the queue pointer is valid
    if (q == NULL) {
        printf("Invalid queue!\n");
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
    // Check if the queue is empty
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
        return; // Nothing to display
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
    if (q == NULL) return;
    
    // Free all nodes in the queue
    while (!isEmpty(q)) {
        dequeue(q); // This will free each node
    }
    
    // Free the queue structure itself
    free(q);
}

// Main function to demonstrate the queue operations
int main() {
    // Initialize an empty queue
    Queue* myQueue = initialize();
    
    // Check if initialization was successful
    if (myQueue == NULL) {
        return 1; // Exit with error code
    }
    
    // Test queue operations
    printf("=== Queue Operations Demo ===\n");
    
    // Test isEmpty on empty queue
    printf("Is queue empty? %s\n", isEmpty(myQueue) ? "Yes" : "No");
    
    // Test enqueue operations
    printf("\nEnqueuing elements: 10, 20, 30, 40\n");
    enqueue(myQueue, 10);  // Add 10 to rear
    enqueue(myQueue, 20);  // Add 20 to rear
    enqueue(myQueue, 30);  // Add 30 to rear
    enqueue(myQueue, 40);  // Add 40 to rear
    
    // Display current queue
    display(myQueue);
    
    // Test front operation
    printf("Front element: %d\n", front(myQueue));
    
    // Test isEmpty on non-empty queue
    printf("Is queue empty? %s\n", isEmpty(myQueue) ? "Yes" : "No");
    
    // Test isFull operation
    printf("Is queue full? %s\n", isFull(myQueue) ? "Yes" : "No");
    
    // Test dequeue operations
    printf("\nDequeuing elements:\n");
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 10
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 20
    
    // Display queue after dequeuing
    display(myQueue);
    
    // Test front after dequeuing
    printf("Front element after dequeuing: %d\n", front(myQueue));
    
    // Enqueue more elements to test mixed operations
    printf("\nEnqueuing element: 50\n");
    enqueue(myQueue, 50);
    display(myQueue);
    
    // Dequeue remaining elements
    printf("\nDequeuing all remaining elements:\n");
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 30
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 40
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 50
    
    // Test operations on empty queue
    printf("\nTesting operations on empty queue:\n");
    display(myQueue);                    // Should show empty
    dequeue(myQueue);                    // Should show error
    printf("Front result: %d\n", front(myQueue)); // Should show error
    
    // Test enqueuing after emptying
    printf("\nEnqueuing after emptying: 100\n");
    enqueue(myQueue, 100);
    display(myQueue);
    
    // Clean up memory
    destroyQueue(myQueue);
    
    return 0; // Successful program termination
}