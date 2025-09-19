//Queue implementation using linked list (Variation 2)
//FRONT is a pointer to the LAST node, REAR is a pointer to the FIRST node

#include <stdio.h>   
#include <stdlib.h>  
#include <stdbool.h> 

//structure for a single node in the queue
typedef struct Node {
    int data;           // Store the actual data value
    struct Node* next;  // Pointer to the next node in the queue
} Node;

//structure for the queue itself (Variation 2)
typedef struct Queue {
    Node* front;  // Pointer to the LAST node of the list (dequeue from here)
    Node* rear;   // Pointer to the FIRST node of the list (enqueue here)
} Queue;

// Function prototypes 
Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
bool enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front_element(Queue* q);
void display(Queue* q);


Queue* initialize() {
    // Allocate memory for the queue structure
    Queue* q = (Queue*)malloc(sizeof(Queue));
    
    // Check if memory allocation was successful
    if (q == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    
    // Initialize both front and rear pointers to NULL (empty queue)
    // front points to last node, rear points to first node
    q->front = NULL;  // No last node yet
    q->rear = NULL;   // No first node yet
    
    // Return the pointer to the initialized queue
    return q;
}

// Check if the queue is full (linked list implementation can never be full)
bool isFull(Queue* q) {
    // Return false because linked list can grow dynamically
    return false;
}

// Check if the queue is empty
bool isEmpty(Queue* q) {
    // Check if queue pointer is valid
    if (q == NULL) {
        return true; // Consider NULL queue as empty
    }
    
    // Queue is empty if the rear pointer (first node) is NULL
    return (q->rear == NULL);
}

// Enqueue (add) a new value to the front of the queue (becomes new first node)
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
    
    // Check if the queue is currently empty
    if (isEmpty(q)) {
        // If empty, the new node is both the first and last node
        newNode->next = NULL;  // Only one node, so next is NULL
        q->rear = newNode;     // rear points to first node (the new node)
        q->front = newNode;    // front points to last node (also the new node)
    } else {
        // If not empty, new node becomes the new first node
        newNode->next = q->rear;  // New node points to current first node
        q->rear = newNode;        // Update rear to point to new first node
        // front (last node) remains unchanged
    }
    
    return true; // Operation successful
}

// Dequeue (remove and return) the last value from the queue
int dequeue(Queue* q) {
    // Check if the queue is empty before attempting to dequeue
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot dequeue.\n");
        return -1; // Return -1 as error indicator
    }
    
    // Store the data of the front node (last node - to be removed)
    int data = q->front->data;
    
    // Check if there's only one node in the queue
    if (q->rear == q->front) {
        // Only one node - queue will become empty
        free(q->front);        // Free the only node
        q->front = NULL;       // Set front to NULL
        q->rear = NULL;        // Set rear to NULL
    } else {
        // Multiple nodes - find the second-to-last node
        Node* current = q->rear;  // Start from first node (rear)
        
        // Traverse to find the node that points to the last node (front)
        while (current->next != q->front) {
            current = current->next;
        }
        
        // Free the last node (front)
        free(q->front);
        
        // Update front to point to the new last node
        q->front = current;
        
        // Set the new last node's next to NULL
        current->next = NULL;
    }
    
    // Return the stored value from the dequeued node
    return data;
}

// Get the last element (front node) without removing it from the queue
int front_element(Queue* q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty! Cannot get front element.\n");
        return -1; // Return -1 as error indicator
    }
    
    // Return the data of the front node (last node in the list)
    return q->front->data;
}

// Display all elements in the queue from first to last (rear to front)
void display(Queue* q) {
    // Check if the queue is empty
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return; // Nothing to display
    }
    
    // Create a temporary pointer to traverse the queue
    // Start from the rear node (first node in the list)
    Node* temp = q->rear;
    
    printf("Queue elements (first to last): ");
    
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
int main() {
    Queue* myQueue = initialize();
    if (myQueue == NULL) return 1; // Exit if initialization fails
    
    // Initially empty
    printf("Is queue empty? %s\n\n", isEmpty(myQueue) ? "Yes" : "No");
    
    // Enqueue a few elements
    printf("Enqueuing 10, 20, 30:\n");
    enqueue(myQueue, 10);  // Queue: 10
    enqueue(myQueue, 20);  // Queue: 20 -> 10
    enqueue(myQueue, 30);  // Queue: 30 -> 20 -> 10
    display(myQueue);
    printf("Front element (last node): %d\n\n", front_element(myQueue)); // should be 10
    
    // Dequeue some elements
    printf("Dequeuing two elements:\n");
    printf("Dequeued: %d\n", dequeue(myQueue)); // Removes 10
    printf("Dequeued: %d\n", dequeue(myQueue)); // Removes 20
    display(myQueue); // Queue should show only 30
    printf("Front element: %d\n\n", front_element(myQueue));
    
    // Enqueue another element
    printf("Enqueuing 40:\n");
    enqueue(myQueue, 40);  // Queue: 40 -> 30
    display(myQueue);
    
    // Empty the queue
    printf("\nDequeuing all elements:\n");
    while (!isEmpty(myQueue)) {
        printf("Dequeued: %d\n", dequeue(myQueue));
    }
    display(myQueue);
    
    // Test enqueue after empty
    printf("\nEnqueuing after empty: 50\n");
    enqueue(myQueue, 50); // Queue: 50
    display(myQueue);
    
    // Clean up memory
    destroyQueue(myQueue);
    return 0;
}