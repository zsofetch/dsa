//=========fill the code -- array list variation 1=========
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int elem[MAX];
    int count;
} List;

List L;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);

List initialize(List L) {
    //set count to 0
    //return L
}

//this is insert first
List insertPos(List L, int data, int position) {
    // make an if statement to validate
    if (if position isn't a negative number && position is within the bounds of count && count doesn't exceed MAX) {
       // make a for loop -- shift elements to the right to make space (start from last element then move backwards)
       for (start at the last valid index; i is at or after the target position; move backwards) {
       //shift elements from one position to the right
        destination/next index position = source;
       }
       //the position is free so place your new data
       access array with position = value to store;

       //increment

    }
    //return the list

}

List deletePos(List L, int position) {
    //make an if statement to validate
  if (position to delete is greater or equal to 0 && position is less than or equal to count) {
    //shift elements to the left; start from the position being deleted 
    for (initialize i as the position to delete; i is less than second to the last position; move forward) {
      //shift element one position to the left
      source = destination/next index position
    }
    //decrement

  }
  //return L

}

int locate(List L, int data) {
    //make a standard for loop for traversing through the array
    for (initialize i to 0; i should be less than count; move forward) {
        //if statement to check if data to locate is equal to the array element
        if (the element in that index == data) {
            //return the index

        }
    }
    //return -1 if not found
}

insertSorted(List L, int data) {
    //make an if statement
    if (count does not exceed MAX) { 
        //initialize the position to 0

        //make a while loop 
        while(position does not exceed count && the element in that position is less than the data to insert) {
            //increment and move to the next position

        }
        //make a for loop
        for (initialize i to the second to the last index; continue while i is at or after the target position; move backwards) {
            //shift elements one position to the right
            destination = source;
        }
        //access the element in that position and store the value

        //increment the count of L

    }
    //return list

}
 
void display (List L) {
    //make a standard for loop for traversing through the array 
    for (initialize i to 0; i should be less than count; move forward) {
        //print the value in every index (L.elem[i])

        //for commas
        //make an if statement and print commas every after the value except the last value
        if (i is less than the count - 1) {
            printf(" ,");
        }
    }
    printf("\n");
}

int main() {
    List myList = initialize(myList);

    myList = insertPos(myList, 1, 1);
    myList = insertPos(myList, 3, 2);
    myList = insertPos(myList, 2, 3);
    myList = insertPos(myList, 5, 4);
    printf("After insertPos:\n");
    display(myList);

    myList = deletePos(myList, 1);
    printf("After deletePos:\n");
    display(myList);

    int pos = locate(myList, 2);
    printf("Locate 2: %d\n", pos);

    myList = insertSorted(myList, 4);
    printf("After insertSorted:\n");
    display(myList);

    return 0;
}

//=========fill the code -- array list variation 2=========
