//Queue implementation using linked list (Variation 2)
//FRONT is a pointer to the LAST node, REAR is a pointer to the FIRST node

#include <stdio.h>   // Include standard input/output library for printf
#include <stdlib.h>  // Include standard library for malloc and free
#include <stdbool.h> // Include boolean library for true/false values

// Define the structure for a single node in the queue
typedef struct Node {
    int data;           // Store the actual data value
    struct Node* next;  // Pointer to the next node in the queue
} Node;

// Define the structure for the queue itself (Variation 2)
typedef struct Queue {
    Node* front;  // Pointer to the LAST node of the list (dequeue from here)
    Node* rear;   // Pointer to the FIRST node of the list (enqueue here)
} Queue;

// Function prototypes - declare all functions before defining them
Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
bool enqueue(Queue* q, int value);
int dequeue(Queue* q);
int front_element(Queue* q);
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
    // front points to last node, rear points to first node
    q->front = NULL;  // No last node yet
    q->rear = NULL;   // No first node yet
    
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

// Main function to demonstrate the queue operations
int main() {
    // Initialize an empty queue
    Queue* myQueue = initialize();
    
    // Check if initialization was successful
    if (myQueue == NULL) {
        return 1; // Exit with error code
    }
    
    // Test queue operations
    printf("=== Queue Operations Demo (Variation 2) ===\n");
    printf("Note: FRONT points to LAST node, REAR points to FIRST node\n\n");
    
    // Test isEmpty on empty queue
    printf("Is queue empty? %s\n", isEmpty(myQueue) ? "Yes" : "No");
    
    // Test enqueue operations
    printf("\nEnqueuing elements: 10, 20, 30, 40\n");
    printf("(Each new element becomes the new FIRST node)\n");
    enqueue(myQueue, 10);  // 10 becomes first node
    enqueue(myQueue, 20);  // 20 becomes new first node, points to 10
    enqueue(myQueue, 30);  // 30 becomes new first node, points to 20
    enqueue(myQueue, 40);  // 40 becomes new first node, points to 30
    
    // Display current queue (40->30->20->10)
    display(myQueue);
    
    // Test front operation (should return last element: 10)
    printf("Front element (last in list): %d\n", front_element(myQueue));
    
    // Test isEmpty on non-empty queue
    printf("Is queue empty? %s\n", isEmpty(myQueue) ? "Yes" : "No");
    
    // Test isFull operation
    printf("Is queue full? %s\n", isFull(myQueue) ? "Yes" : "No");
    
    // Test dequeue operations (removes from the end/last node)
    printf("\nDequeuing elements (from the LAST node):\n");
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 10 (last node)
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 20 (new last node)
    
    // Display queue after dequeuing
    display(myQueue);
    
    // Test front after dequeuing (should be new last element)
    printf("Front element after dequeuing: %d\n", front_element(myQueue));
    
    // Enqueue more elements to test mixed operations
    printf("\nEnqueuing element: 50\n");
    enqueue(myQueue, 50);  // 50 becomes new first node
    display(myQueue);      // Should show: 50->40->30
    
    // Show the queue structure
    printf("\nQueue structure explanation:\n");
    printf("- REAR (first node): points to node with value 50\n");
    printf("- FRONT (last node): points to node with value 30\n");
    printf("- Queue order: 50->40->30 (first to last)\n");
    printf("- Enqueue adds to beginning, Dequeue removes from end\n");
    
    // Dequeue remaining elements
    printf("\nDequeuing all remaining elements:\n");
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 30 (last)
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 40 (new last)
    printf("Dequeued: %d\n", dequeue(myQueue));  // Should dequeue 50 (only remaining)
    
    // Test operations on empty queue
    printf("\nTesting operations on empty queue:\n");
    display(myQueue);                           // Should show empty
    dequeue(myQueue);                           // Should show error
    printf("Front result: %d\n", front_element(myQueue)); // Should show error
    
    // Test enqueuing after emptying
    printf("\nEnqueuing after emptying: 100\n");
    enqueue(myQueue, 100);
    display(myQueue);
    
    // Clean up memory
    destroyQueue(myQueue);
    
    return 0; // Successful program termination
}