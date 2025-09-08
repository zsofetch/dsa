#include <stdio.h>
#define LENGTH 10

typedef struct {
    int *elemPtr;
    int count;
    int max;
} List;

List initialize(List L);
List insertPos(List L, int data, int position);
List deletePos(List L, int position);
int locate(List L, int data);
List insertSorted(List L, int data);
void display(List L);
List resize(List L);

Dynamically allocate memory for the array using LENGTH
Set max to defined LENGTH
Set the count to 0
Return List
List initialize(List L) {

}


