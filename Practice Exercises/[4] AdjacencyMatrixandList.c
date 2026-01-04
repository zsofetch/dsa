#include <stdio.h>
#include <stdlib.h>

#define V 8 // Number of vertices (Nodes A-H)

struct Node {
    int dest;
    struct Node* next;
};

// Helper function to create a new list node
struct Node* createNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Helper to add node to the end of the list (preserves order)
void appendToList(struct Node** headRef, int dest) {
    struct Node* newNode = createNode(dest);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print mapping of Index to Character
char getLabel(int index) {
    return 'A' + index;
}

int main() {
    // --- STEP 1: CREATE ADJACENCY MATRIX ---
    // Initialize with 0s
    int adjMatrix[V][V] = {0};

    // Manually input the edges from the image
    // Mapping: A=0, B=1, C=2, D=3, E=4, F=5, G=6, H=7
    
    adjMatrix[0][1] = 1; // A -> B

    adjMatrix[1][4] = 1; // B -> E
    adjMatrix[1][5] = 1; // B -> F

    adjMatrix[2][0] = 1; // C -> A
    adjMatrix[2][6] = 1; // C -> G

    adjMatrix[3][1] = 1; // D -> B
    adjMatrix[3][4] = 1; // D -> E

    adjMatrix[4][7] = 1; // E -> H

    adjMatrix[5][2] = 1; // F -> C

    adjMatrix[6][5] = 1; // G -> F
    adjMatrix[6][7] = 1; // G -> H

    adjMatrix[7][0] = 1; // H -> A


    // --- DISPLAY ADJACENCY MATRIX ---
    printf("\n--- Adjacency Matrix ---\n");
    printf("  ");
    for (int i = 0; i < V; i++) printf("%c ", getLabel(i));
    printf("\n");

    for (int i = 0; i < V; i++) {
        printf("%c ", getLabel(i));
        for (int j = 0; j < V; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }


    // --- STEP 2: CONVERT MATRIX TO ADJACENCY LIST ---
    struct Node* adjList[V] = {NULL}; // Array of pointers

    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            // If there is an edge (1) in the matrix, add to list
            if (adjMatrix[i][j] == 1) {
                appendToList(&adjList[i], j);
            }
        }
    }


    // --- DISPLAY ADJACENCY LIST ---
    printf("\n--- Adjacency List ---\n");
    for (int i = 0; i < V; i++) {
        printf("%c -> ", getLabel(i));
        
        struct Node* temp = adjList[i];
        if (temp == NULL) {
            printf("NULL");
        }
        while (temp != NULL) {
            printf("%c", getLabel(temp->dest));
            if (temp->next != NULL) printf(" -> ");
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}