//please dont mind the comments sir ty
#include <stdio.h>
#define MAX 10


typedef struct {
    int elem[MAX];
    int count;
} List;


List L;
//this is a slay
List initialize(List L) {
    L.count = 0;
    return L;
}
//something is kuwang sa if statement...
List insertPos(List L, int data, int position) {  
    if (position < 0 || position > L.count) {
        printf("invalid\n");
        return L;
    }


    for (int i = L.count - 1; i >= position; i--) {
        L.elem[i + 1] = L.elem[i];
    }


    L.elem[position] = data;
    L.count++;
    return L;
}


//kuwang ug if statement
List deletePos(List L, int position) {
     if (position < 0 || position >= L.count) {
        printf("invalid\n");
        return L;
    }


    for (int i = position; i < L.count - 1; i++) {
        L.elem[i] = L.elem[i + 1];
    }


    L.count--;
    return L;
}


int locate (List L, int data) {
    //printf("Enter data to find: ");
    //scanf("%d", &data);


    for (int i = 0; i < L.count; i++) {
        if(L.elem[i] == data) {
            return i;
        }
    }
    return -1;
}
//kuwangan ug if statement
List insertSorted (List L, int data) {
    if (L.count >= MAX) {
        printf("list is full silly!");
    }
    int pos = 0;
 while (pos < L.count && L.elem[pos] < data) {
        pos++;
    }
    for (int i = L.count - 1; i >= pos; i--) {
        L.elem[i + 1] = L.elem[i];
    }
    L.elem[pos] = data;
    L.count++;
    return L;
}




void display(List L) {
    for (int i = 0; i < L.count; i++) {
        printf("%d", L.elem[i]);
    }
}


//fix the populated List
int main() {
    L = initialize(L);


    L = insertPos(L, 1, 0);
    L = insertPos(L, 3, 1);
    L = insertPos(L, 2, 1);
    L = insertPos(L, 5, 3);
   
    display(L);


    L = deletePos(L, 1);
    display(L);


    L = insertSorted(L, 4);
    display(L);


}






#include <stdio.h>
#define MAX 10


typedef struct {
    int elem[MAX];
    int count;
} Etype, *EPtr;


EPtr L;


void initialize (EPtr L) {
    L->count = 0;
    return L;
}


void insertPos(EPtr L, int data, int position) {  
    if (position < 0 || position > L->count) {
        printf("invalid\n");
        return L;
    }


    for (int i = L->count - 1; i >= position; i--) {
        L->elem[i + 1] = L->elem[i];
    }


    L->elem[position] = data;
    L->count++;
    return L;
}


void deletePos(EPtr L, int position) {
       if (position < 0 || position >= L->count) {
        printf("invalid\n");
        return L;
    }


    for (int i = position; i < L->count - 1; i++) {
        L->elem[i] = L->elem[i + 1];
    }


    L->count--;
    return L;
}



