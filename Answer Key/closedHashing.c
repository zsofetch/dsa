//CLOSED HASHING==================
//OPEN ADDRESSING
#include <stdio.h>
#define MAX 10
#define EMPTY '~' //represents an empty slot
#define DELETED '!' //represents a deleted slot (placeholder)

typedef char Dictionary[MAX]; //dictionary is an array of 10 characters
typedef enum {FALSE, TRUE} Boolean; // 1 or 0

void initDictionary(Dictionary D);
int hashBrown(char c);
Boolean isMember(Dictionary D, char elem);
void insertUnique(Dictionary D, char elem);
void deleteMember(Dictionary D, char elem);
int getSearchLength(Dictionary D, char elem);
void displayDictionary(Dictionary D);

void initDictionary(Dictionary D){
	for(int i = 0; i < MAX; i++){
		D[i] = EMPTY; //fill all slots with ~ 
	}
}
// hardcoded function from hardcoded input
int hashBrown(char c){
	char elements[MAX] = {"abcdefghij"};
	int hash[MAX] = {3, 9, 4, 3, 9, 0, 1, 3, 0, 3}; //maps each letter to an index
	/*if two letters hash to the same index (collision), closed hashing means we probe
	  (check next slots) until we find an empty one.*/
	for(int i = 0; i < MAX - 1 && elements[i] != c; i++){}
	return hash[i];
}

Boolean isMember(Dictionary D, char elem){
	int idx, sl;
	
	/* start at the has index of elem
	   if not found, move forward (idx + 1) % MAX - this is linear probing
	   stop if you find the element or an empty slode (~ means empty)
	   returns TRUE if found, FALSE if not
	*/
	
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem && D[idx] != EMPTY; idx = (idx + 1) % MAX, sl++){}
	/* idx = hashBrown(elem) - the function gives us the hash index - the "home address" for that element 
	   sl = search length - sl = 1 is how many steps we've taken so far in the search
	   while we haven't checked all slots (s1 < MAX)
	   and we haven't found the element (D[idx] != elem)
	   and we haven't hit an empty slot (D[idx] != EMPTY)
	   
	   idx = (idx + 1) % MAX ensures it wraps around to index 0 when you reach the end (circular array)
	   sl++ increases the number of steps you've taken
	*/
	printf("\tThe search length is %d\n", sl);
	
	return (sl < MAX) ? TRUE : FALSE;
}

void insertUnique(Dictionary D, char elem){
	int idx, sl;
	
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem && (D[idx] != EMPTY && D[idx] != DELETED); idx = (idx + 1) % MAX, sl++){}
	/*
	   for this function - if it's already taken by something else, keep moving forward until you find an empty or deleted slot
	   
	   for loop has same logic as the isMember function with additional condition that:
	      -if the current slot has a valid element (something in use), → skip it.
	      -if the current slot is EMPTY or DELETED, → stop here (it’s free for insertion!).
	*/
	
	if(sl < MAX && D[idx] != elem){ //if the element wasnt found and the slot is free, its inserted
		D[idx] = elem;
	} else {
		printf("\t%c is already in the dictionary.\n", elem);
	}
}

void deleteMember(Dictionary D, char elem){
	int idx, sl;
	
	//similar sa deleteMember but instead of && mag ||
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem && (D[idx] != EMPTY || D[idx] != DELETED); idx = (idx + 1) % MAX, sl++){}
	
	if(sl < MAX && D[idx] == elem){
		D[idx] = DELETED;
	} else {
		printf("\tThe element [%c] is not found.\n", elem);
	}
}

int getSearchLength(Dictionary D, char elem){
	int idx, sl;
	
	//calculate how many steps it takes to find an element in the dictionary
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem; idx = (idx + 1) % MAX, sl++){}
	
	return sl;
}

void displayDictionary(Dictionary D){
	printf("\tINDEX\tELEMENT\n");
	
	for(int i = 0; i < MAX; i++){
		printf("\t [%d]\t   %c\n", i, D[i]);
	}
	
	printf("\n");
}

int main(){
	Dictionary D;
	int i, sl;
	float totalAvgSL = 0.0;
	
	printf("START\n\n");
	
	printf("01. INITIALIZE DICTIONARY\n");
	initDictionary(D);
	displayDictionary(D);
	
	printf("02. IS MEMBER\n");
	printf("\tSearch for '%c' in dictionary.\n", 'g');
	printf("\t'%c' is %s member.\n\n", 'g', isMember(D, 'g') == TRUE ? "A" : "NOT a");
	
	printf("03. IS UNIQUE\n");
	for(i = 0; i < MAX; i++){
		insertUnique(D, i + 97);
	}
	displayDictionary(D);
	printf("\tSearch for '%c' in dictionary.\n", 'f');
	printf("\t'%c' is %s member.\n\n", 'f', isMember(D, 'f') == TRUE ? "A" : "NOT a");
	printf("\tSearch for '%c' in dictionary.\n", 'z');
	printf("\t'%c' is %s member.\n\n", 'z', isMember(D, 'z') == TRUE ? "A" : "NOT a");
	
	printf("04. DELETE MEMBER\n");
	deleteMember(D, 'Y');
	deleteMember(D, 'f');
	deleteMember(D, 'a');
	deleteMember(D, 'd');
	deleteMember(D, 'j');
	displayDictionary(D);
	
	printf("05. AVERAGE SELECT LENGTH\n");
	printf("\tELEMENT\tSL\n");
	for(i = 0; i < MAX; i++){
		sl = getSearchLength(D, i + 97);
		printf("\t  [%c] =\t%d\n", i + 97, sl);
		totalAvgSL += sl;
	}
	totalAvgSL /= MAX;
	printf("\tAverage SL for 10 elements are = %.2f", totalAvgSL);
	
	printf("\n\nEND");
	
	return 0;
}
