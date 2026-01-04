// A library stores books using a BST based on book ID.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char String[32];

typedef struct {
    int book_id;
    String book_name;
} Book;

typedef struct node {
    Book book;
    struct node *left;
    struct node *right;
} *BST;

void insertNode(BST *root, Book newBook) {
    if (*root == NULL) {
        *root = (BST)malloc(sizeof(struct node)); //allocate memory for a new node 
        (*root)->book = newBook;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } 
    else if (newBook.book_id < (*root)->book.book_id) {
        insertNode(&((*root)->left), newBook);
    } 
    else if (newBook.book_id > (*root)->book.book_id) {
        insertNode(&((*root)->right), newBook);
    }
}

void displayBook(BST root, int book_id) {
    //Base case: If the tree is emoty or we hit a NULL path (Book not found)
    if (root == NULL) {
        printf("Book with ID %d not found.\n", book_id);
        return;
    }

    //Case 1: Found the book
    if (book_id == root->book.book_id) { //so book_id is equal sa root's book_id (kay root is a BST struct)
        printf("Book Found: %s\n", root->book.book_name);
        return;
    }
    
    //Case 2: The ID we want is smaller than the current node -> Search Left
    if (book_id < root->book.book_id) {
        displayBook(root->left, book_id);
    } 
    //Case 3: The ID we want is larger than the current node -> Search Right
    else {
        displayBook(root->right, book_id); //recursion
    }
}

// --- MAIN FOR TESTING ---

int main() {
    BST root = NULL; // Start with an empty tree

    // 1. Create Data
    Book b1 = {100, "Intro to C"};
    Book b2 = {50,  "Data Structures"};
    Book b3 = {150, "Algorithms"};
    Book b4 = {25,  "Discrete Math"};
    Book b5 = {75,  "Database Systems"};

    // 2. Insert into Tree
    // Note: We pass &root because insertNode expects (BST *)
    insertNode(&root, b1);
    insertNode(&root, b2);
    insertNode(&root, b3);
    insertNode(&root, b4);
    insertNode(&root, b5);

    // 3. Test Display Function
    printf("--- Testing Search ---\n");
    
    // Should find "Database Systems"
    printf("Searching for ID 75: ");
    displayBook(root, 75);

    // Should find "Algorithms"
    printf("Searching for ID 150: ");
    displayBook(root, 150);

    // Should say not found
    printf("Searching for ID 999: ");
    displayBook(root, 999);

    return 0;
}