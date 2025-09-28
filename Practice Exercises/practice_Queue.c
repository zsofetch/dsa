//=========fill the code -- array queue variation 1=========
//need enqueueSorted function

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
} List;

typedef struct {
    List list;
    int front;
    int rear;
} Queue;

//function prototypes 
Queue* initialize();
bool isFull(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peekFront(Queue* q);
void display(Queue* q);

//helper function
void cleanup(Queue* q);

Queue* initialize() {
    //allocate memory for Queue *q

    //if q is not NULL
    
        //initialize list count to 0

        //initialize front and rear to -1 indicating empty queue

    //return q (pointer to queue)
}

bool isFull(Queue* q) {
    //return count == MAX
}
bool isEmpty(Queue* q) {
    //return count == 0
}

void enqueue(Queue* q, int value) {
    //if queue is not full
        
        //if queue is empty

            //set both front and rear to 0 (they both point to the first element cos there is only one element in the queue)
        
        //else (if the queue already has elements) update q->rear pointer circularly ((rear + 1) % MAX)

        //initialize the new value to the list at the rear position by accessing items array at rear position (hint: q->list.items[q->rear])

        //increment the count

        //else print queue is full

}

int dequeue(Queue* q) {
    //initialize the removed value to -1 (default return value for empty queue)

    //if queue is not empty

        //take the removed value at the front of the queue by accessing items array at front position (hint: q->list.items[q->front])

        //if the count of the list is 1 (this is the last element in the queue)

            //reset front and rear to -1 (empty state)

        //else update the front pointer circularly (hint: (q->front + 1) % MAX)

    //decrement the count

//else print queue is empty

//return the removed value
   
}

int peekFront(Queue* q) {
    //if queue is not empty

    //return the value at the front of the queue by accessing items array at front position (hint: q->list.items[q->front])

    //else return -1 (default value if queue is empty)

}

void display(Queue* q) {

    //if queue is empty print queue is empty and return

    //else, initialize i to front (start from front)

    //while count is less than list count (continue while we haven't printed all elements)

        //print the value at items array at index i

        //increment count

        //if count is less than list count (check if not the last element) print comma separator

        //update i to (i + 1) % MAX (move to next position circularly)
    
    //print counting statistics for debugging (count, front, rear)
    
}

void cleanup(Queue* q) {
    //if q != NULL

        //free the memory allocated for the queue structure
}

int main() {
    // Create and initialize queue
    Queue* myQueue = initialize();
    
    printf("=== Queue Demonstration ===\n\n");
    
    // Test enqueue operations
    printf("Enqueuing values: 10, 20, 30, 40, 50\n");
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    enqueue(myQueue, 40);
    enqueue(myQueue, 50);
    display(myQueue);
    
    // Test front function
    printf("\nFront element: %d\n", peekFront(myQueue));
    
    // Test dequeue operations
    printf("\nDequeuing 2 elements:\n");
    printf("Dequeued: %d\n", dequeue(myQueue));
    printf("Dequeued: %d\n", dequeue(myQueue));
    display(myQueue);
    
    // Test circular behavior
    printf("\nEnqueuing more values to test circular behavior: 60, 70\n");
    enqueue(myQueue, 60);
    enqueue(myQueue, 70);
    display(myQueue);
    
    // Clean up
    cleanup(myQueue);
    printf("\nQueue cleaned up successfully.\n");
}

//=========fill the code -- array queue variation 2=========
//need enqueueSorted function
//sacrificial space

#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
#define MAX 10

typedef struct {
    int items[MAX];  // Array to store queue elements
    int front;       // Index of the front and rear elements
    int rear;        
} Queue;

Queue* initialize();
bool isEmpty(Queue* q);
bool isFull(Queue* q);
bool enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peek(Queue* q);
void display(Queue* q);
void displayArray(Queue* q);
void destroyQueue(Queue* q);

Queue* initialize() {
    //allocate memory for Queue* q

    //if q is null print malloc failed and return null

    //initialize front to 1 and rear to 0

        //with a standard for loop, initialize all array elements inside items to 0

    //return q
    
}

bool isEmpty(Queue* q) {
    //if q is NULL return true 

    //else return the indication that the queue is empty (hint: front = rear + 1 % MAX)
}

bool isFull(Queue* q) {
    //if q is NULL return false (bc queue is not full)

    //else return the indication that the queue is full (hint: front == rear + 2 % MAX)
    return (q->front == (q->rear + 2) % MAX);
}

bool enqueue(Queue* q, int value) {
    //if q is NULL print invalid queue and return false

    //else check if q is full

        //print queue is full cant enqueue and return false

    //increment the rear pointer circularly (same as isEmpty) by initializing rear 

    //insert the new value at the rear position inside items array (hint: position = value)
   
    printf("Enqueued %d at position %d\n", value, q->rear);
    //return true 
}

// Dequeue (remove and return) the front value from the queue
int dequeue(Queue* q) {
    //check if q isEmpty then print and return -1

    //get the value at the front position inside items array (hint: value = position)

    // printf("Dequeued %d from position %d\n", data, q->front);

    //optional: clear the dequeued position by initializing front back to 0

    //increment the front pointer circularly (hint: front + 1 % MAX)

    //return the dequeued element
    
}

int peek(Queue* q) {
    //check if q is empty then print and return -1

    //else return the element at the front position inside items array 
}

void display(Queue* q) {
    //check if queue is empty and print and return

    //calculate sacrificial space (hint: q->front - 1 + MAX) % MAX

    //initialize a current variable with front (for looping through the queue circularly until rear)

    //use a while loop to loop through the queue from front to rear
    while(true) {
        //print elements in the current index of items array

        //if current == rear break the loop

        //after the if statement, move the next position circulary (hint: current = (current + 1) % MAX)

    }

    //optional: print a newline

    //display queue status information (front, rear, and sacrificial)
}

// Display the entire array with markers for better understanding
void displayArray(Queue* q) {
    //make a standard for loop

    //print the elements at the current index in items array

    //if index is at the second to the last, print a comma

    //exit if statement (optional: print the index of front and rear)
    
}

// Helper function to free the queue structure
void destroyQueue(Queue* q) {
    //if q is NULL free the queue structure
}

int main() {
    Queue* myQueue = initialize();
    if (myQueue == NULL) return 1;

    printf("=== Simple Queue Demo ===\n");

    // Initial state
    displayArray(myQueue);

    // Enqueue some elements
    printf("\nAdding elements...\n");
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);
    displayArray(myQueue);
    display(myQueue);

    // Show front element
    printf("Front element: %d\n", peek(myQueue));

    // Dequeue two elements
    printf("\nRemoving two elements...\n");
    dequeue(myQueue);
    dequeue(myQueue);
    displayArray(myQueue);
    display(myQueue);

    // Final state
    printf("\nFinal queue state:\n");
    displayArray(myQueue);
    display(myQueue);

    destroyQueue(myQueue);
    return 0;
}



//=========fill the code -- linked list queue =========
//Queue implementation using linked list (Variation 1)
//FRONT is a pointer to the HEAD or FIRST NODE, REAR is a pointer to the LAST NODE

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
    // Allocate memory for the Queue* q structure

    //if q == null print and return null

    //initialize both front and rear pointers of q to NULL (indicating an empty queue)
    
    // Return the pointer to the initialized queue4

}


// Check if the queue is empty
bool isEmpty(Queue* q) {
    //return q is null or front is null
    // Consider NULL queue as empty
    // Queue is empty if the front pointer is NULL
}

bool enqueue(Queue* q, int value) {
    //if q is null return false
    
    //allocate memory for a new node

    //if newnode is null print malloc failed and return false

    //set the new node's data to value

    //set the new node's next to NULL

    //if q isEmpty 
        //initialize the front to newNode

        //initialize rear to newNode

    //else if not empty, link the current rear to the new node

        //initialize rear's next pointer to newNode

        //update the rear pointer by initializing it to the newNode
    
    //return true
}

int dequeue(Queue* q) {
    //if q isEmpty, print and return -1

    //initialize a Node* temp to the front node

    //initialize data to temp's data

    //initialize the front pointer to front->next (this moves the front pointer to the next node)

    //if front is NULL (if the queue becomes empty after dequeueing update rear pointer to NULL)

       //rear is NULL

    //free temp

    //return data

}

// Get the front value without removing it from the queue

int front(Queue* q) {
    //if q isEmpty, print and return -1

    //otherwise return the data of the front node front->data
}

// Display all elements in the queue from front to rear
void display(Queue* q) {
    //if q isEmpty, print and return -1

    //create a temporary Node* temp pointer and initialize it to the front node

    printf("Queue elements (front to rear): ");
    
    //loop through the list while temp is not NULL

        //print the current node's data (temp->data)

        //move to the next node by initializing temp to temp->next

    //print a newline

}

// Helper function to free all nodes and the queue structure
void destroyQueue(Queue* q) {
    //while q is NOT empty

        //dequeue q

    //free the queue struct itself
    
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

//=========fill the code -- linked list queue =========
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
    // Allocate memory for the Queue* q structure
    
    // if q is null print and return NULL

    //initialize both front and rear pointers to NULL (empty queue) - note that front points to last node and rear points to first node
    
    //return q
}


// Check if the queue is empty
bool isEmpty(Queue* q) {
    //if q is NULL return true

    //else return rear initialized as NULL because queue is empty if the rear pointer is null
}

// Enqueue (add) a new value to the front of the queue (becomes new first node)
bool enqueue(Queue* q, int value) {
    //if q is null print and return false

    //else allocate memory for Node* newNode

    //check if malloc was successful; if newnode is null print malloc failed and return false

    //initialize the data of the newNode to the provided value

    //if queue isEmpty 

        //the next of newNode is initialized to NULL

        //the rear and front are also initialized or points to the new node

    // else if not empty 
     
        //new node becomes the new first node by initializing the newNode's next pointer to the rear 

        //the rear is updated and is now new first node

    // return true
}

// Dequeue (remove and return) the last value from the queue
int dequeue(Queue* q) {
    //if q isEmpty print and return -1

    //store the data by initializing it to the front node since this is the last node (q->front->data)

    //if theres only one node in the queue (rear = front) 

        //free the only node in the front

        //set front and rear to null
    
    //else if there are multiple nodes find the one whose next is q->front is the second-to-last node

        //initialize Node* current to the rear (start at first node) 

        //while current's next is not equal to the front (last node)

            //initialize current to current->next
    
        //free the last node(front)

        //update front to point to the new last node (current)

        //set the new last node's next to NULL
    
    //return the stored data from the dequeued node

}

// Get the last element (front node) without removing it from the queue (basically the peek function)
int front_element(Queue* q) {
    //if q isEmpty print and return -1

    //return the data of the front node (or the last node in the list)
}

// Display all elements in the queue from first to last (rear to front)
void display(Queue* q) {
    //if q isEmpty print and return

    //initialize a Node* temp pointer to the queue's rear

    printf("Queue elements (first to last): ");

    //while loop through the list until the end (NULL) is reached (temp != NULL)

    //print the current node's data (temp->data)

    //move to the next node by initializing temp to temp->next

//print a newline at the end

}

// Helper function to free all nodes and the queue structure
void destroyQueue(Queue* q) {
    //if q is NULL return

    //free all nodes in the queue with a while loop - while q is NOT empty

        //call dequeue
    
    //free the queue struct itself

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