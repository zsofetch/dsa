#include <stdio.h>
#define MAX 10
#define EMPTY '~'
#define DELETED '!'

typedef char Dictionary[MAX];
typedef enum {FALSE, TRUE} Boolean;

void initDictionary(Dictionary D);
int hashBrown(char c);
Boolean isMember(Dictionary D, char elem);
void insertUnique(Dictionary D, char elem);
void deleteMember(Dictionary D, char elem);
int getSearchLength(Dictionary D, char elem);
void displayDictionary(Dictionary D);

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

void initDictionary(Dictionary D){
	int i;
	
	for(i = 0; i < MAX; i++){
		D[i] = EMPTY;
	}
}

// hardcoded function from hardcoded input
int hashBrown(char c){
	char elements[MAX] = {"abcdefghij"};
	int hash[MAX] = {3, 9, 4, 3, 9, 0, 1, 3, 0, 3};
	int i;
	
	for(i = 0; i < MAX - 1 && elements[i] != c; i++){}
	
	return hash[i];
}

Boolean isMember(Dictionary D, char elem){
	int idx, sl;
	
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem && D[idx] != EMPTY; idx = (idx + 1) % MAX, sl++){}
	
	printf("\tThe search length is %d\n", sl);
	
	return (sl < MAX) ? TRUE : FALSE;
}

void insertUnique(Dictionary D, char elem){
	int idx, sl;
	
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem && (D[idx] != EMPTY && D[idx] != DELETED); idx = (idx + 1) % MAX, sl++){}
	
	if(sl < MAX && D[idx] != elem){
		D[idx] = elem;
	} else {
		printf("\t%c is already in the dictionary.\n", elem);
	}
}

void deleteMember(Dictionary D, char elem){
	int idx, sl;
	
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem && (D[idx] != EMPTY || D[idx] != DELETED); idx = (idx + 1) % MAX, sl++){}
	
	if(sl < MAX && D[idx] == elem){
		D[idx] = DELETED;
	} else {
		printf("\tThe element [%c] is not found.\n", elem);
	}
}

int getSearchLength(Dictionary D, char elem){
	int idx, sl;
	
	for(idx = hashBrown(elem), sl = 1; sl < MAX && D[idx] != elem; idx = (idx + 1) % MAX, sl++){}
	
	return sl;
}

void displayDictionary(Dictionary D){
	int i;
	
	printf("\tINDEX\tELEMENT\n");
	
	for(i = 0; i < MAX; i++){
		printf("\t [%d]\t   %c\n", i, D[i]);
	}
	
	printf("\n");
}