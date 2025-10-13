#include <stdio.h>
#include <string.h>
#define EMPTY "~"
#define DELETED "!"
#define MAX 10

typedef char String[50];

typedef struct {
	String elem;
	int frequency;
} Dictionary[MAX];

typedef enum {FALSE, TRUE} Boolean;

void initDictionary(Dictionary D);
int hashBrown(String fruit);
Boolean isMember(Dictionary D, String fruit);
void insertFruit(Dictionary D, String fruit);
void deleteFruit(Dictionary D, String fruit);
int getSearchLength(Dictionary D, String fruit);
void displaySearchLength(Dictionary D);
void displayDictionary(Dictionary D);

int main(){
	Dictionary D;
	char choice;
	String fruitChoice;
	
	initDictionary(D);
	
	do {
		printf("----- Fruit Frequency Counter -----\n");
		printf("[1] Check Membership\n");
		printf("[2] Insert Fruit\n");
		printf("[3] Delete Fruit\n");
		printf("[4] Display Search Length\n");
		printf("[5] Display Dictionary\n");
		printf("[X] Exit\n");
		printf("Choice: ");
		scanf(" %c", &choice);
		
		switch(choice){
			case '1':{
				printf("Fruit: ");
				scanf("%s", fruitChoice);
				
				printf("\nThe fruit '%s' is %s member in the dictionary.\n", fruitChoice, isMember(D, fruitChoice)  == TRUE ? "A" : "NOT a");
				
				break;
			}
			
			case '2':{
				printf("Fruit: ");
				scanf("%s", fruitChoice);
				
				insertFruit(D, fruitChoice);
				
				break;
			}
			
			case '3':{
				printf("Fruit: ");
				scanf("%s", fruitChoice);
				
				deleteFruit(D, fruitChoice);
				
				break;
			}
			
			case '4':{
				displaySearchLength(D);
				
				break;
			}
			
			case '5':{
				displayDictionary(D);
				
				break;
			}
			
			case 'X':{
				printf("\n\nEND");
				break;
			}
		}
		
		printf("\n");
		
	} while (choice != 'X');
	
	return 0;
}

void initDictionary(Dictionary D){
	int i;
	
	for(i = 0; i < MAX; i++){
		strcpy(D[i].elem, EMPTY);
		D[i].frequency = 0;
	}
}

int hashBrown(String fruit){
	int i, totalValue = 0;
	
	for(i = 0; fruit[i] != '\0'; i++){
		totalValue += fruit[i];
	}
	
	return totalValue % MAX;
}

Boolean isMember(Dictionary D, String fruit){
	int i, sl;
	
	for(i = hashBrown(fruit), sl = 1; sl < MAX && strcmp(D[i].elem, fruit) != 0; i = (i + 1) % MAX, sl++){}
	
	return (sl < MAX) ? TRUE : FALSE;
}

void insertFruit(Dictionary D, String fruit){
	int i, sl;
	
	for(i = hashBrown(fruit), sl = 1; sl < MAX && strcmp(D[i].elem, fruit) != 0 && (strcmp(D[i].elem, EMPTY) != 0 && strcmp(D[i].elem, DELETED) != 0); i = (i + 1) % MAX, sl++){}
	
	if(sl < MAX && strcmp(D[i].elem, fruit) != 0){
		strcpy(D[i].elem, fruit);
		D[i].frequency++;
	} else if (sl < MAX && strcmp(D[i].elem, fruit) == 0) {
		D[i].frequency++;
	} else {
		printf("\nDictionary is full! Fruit '%s' cannot be inserted.\n", fruit);
	}
}

void deleteFruit(Dictionary D, String fruit){
	int i, sl;
	
	for(i = hashBrown(fruit), sl = 1; sl < MAX && strcmp(D[i].elem, fruit) != 0 && (strcmp(D[i].elem, EMPTY) != 0 || strcmp(D[i].elem, DELETED) != 0); i = (i + 1) % MAX, sl++){}

	if(sl < MAX && strcmp(D[i].elem, fruit) == 0){
		if(D[i].frequency > 1){
			D[i].frequency--;
		} else {
			strcpy(D[i].elem, DELETED);
			D[i].frequency = 0;
		}
	} else {
		printf("\nFruit '%s' does not exist in the dictionary.\n", fruit);
	}
}

int getSearchLength(Dictionary D, String fruit){
	int i, sl;
	
	for(i = hashBrown(fruit), sl = 1; sl < MAX && strcmp(D[i].elem, fruit) != 0; i = (i + 1) % MAX, sl++){}
	
	return sl;
}

void displaySearchLength(Dictionary D){
	int i, sl, fruit_count = 0;
	float avg = 0.0;
	
	printf("\n%-15s%-15s\n", "FRUIT", "LENGTH");
	
	for(i = 0; i < MAX; i++){
		if(strcmp(D[i].elem, EMPTY) != 0 && strcmp(D[i].elem, DELETED) != 0){
			sl = getSearchLength(D, D[i].elem);
			printf("%-18s%-15d\n", D[i].elem, sl);
			avg += sl;
			fruit_count++;
		}
	}
	
	if(fruit_count != 0){
		avg /= fruit_count;
	}
	
	printf("\nAverage Search Length: %.2f\n", avg);
}

void displayDictionary(Dictionary D){
	int i;
	
	printf("\n%-15s%-15s%-15s\n", "INDEX", "FRUIT", "FREQUENCY");
	
	for(i = 0; i < MAX; i++){
		printf("  %-13d%-19s%-15d\n", i, D[i].elem, D[i].frequency);
	}
}