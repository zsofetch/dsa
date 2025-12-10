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

// TODO Functions
void initDictionary(Dictionary D);
int hashBrown(String fruit);
Boolean isMember(Dictionary D, String fruit);
void insertFruit(Dictionary D, String fruit);
void deleteFruit(Dictionary D, String fruit);
int getSearchLength(Dictionary D, String fruit);

// Completed Functions
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

// This function initializes an empty dictionary.
// Each bucket shall have an EMPTY elem and 0 frequency.
// EMPTY is defined as a macro.
void initDictionary(Dictionary D){
	//iterate through each index of the dictionary

	//strcpy the elem of D at index i to EMPTY

	//set the frequency of D at index i to 0
}

// This function returns a hash value based on the remainder of total ASCII value of the fruit divided by MAX.
// E.g. The string "Plum" has 414 total ASCII Value.
int hashBrown(String fruit){

	//initialize totalValue to 0

	//iterate through each index of the fruit string until it is not equal to '\0'

	   //add totalValue for each character in the fruit string

	//return totalValue modulus MAX
}

// This function returns a Boolean value of either TRUE OR FALSE.
// It will check if the passed fruit is a member in the dictionary.
Boolean isMember(Dictionary D, String fruit){
	//declare i and sl variable

	//butterfly loop - initialize i to hashBrown(fruit); sl = 1; sl < MAX and strcmp the element of D at index i and fruit is not equal to 0; i = (i + 1) % MAX, sl++ {}

	//return sl < MAX is it TRUE else FALSE
}

// This function inserts a fruit into the dictionary based on its hash value.
// If the fruit already exists in the dictionary, increase its frequency.
// If the dictionary is full, print a message that it is full and the fruit cannot be inserted.
void insertFruit(Dictionary D, String fruit){
	//declare i and sl variable

	//butterfly loop - initialize i to hashBrown function, sl = 1; sl < MAX and strcmp D at index i and fruit is not equal to 0 and strcmp D at index i and EMPTY is not equal to 0 and strcmp D at index i and DELETED is not equal to 0; i = (i + 1) % MAX, sl++){}

	//if sl < MAX and strcmp D at index i and fruit is not equal to 0

	   //strcpy D at index i elem to fruit

	   //increment frequency of D at index i
	
	//else if sl < MAX and strcmp D at index i and fruit is equal to 0

	    //increment frequency of D at index i
	
	//else print dictionary is full and fruit cannot be inserted

}

// This function deletes a fruit from the dictionary.
// If fruit exists and its frequency is more than 1, decrease its frequency.
// Else, delete the fruit by marking it as DELETED and its frequency to 0.
// DELETED is defined as a macro.
// If fruit does not exist in the dictionary, print a message that the fruit does not exist in the dictionary.
void deleteFruit(Dictionary D, String fruit){

	//declare i and sl variable

	//butterfly loop - initialize i to hashBrown function, sl = 1; sl < MAX and strcmp element of D at index i and fruit is not equal to 0 and strcmp element of D at index i and EMPTY is not equal to 0 or strcmp element of D at index i and DELETED is not equal to 0; i = (i + 1) % MAX, sl++) {}

	//if sl < MAX and strmcp element of D at index i and fruit is equal to 0 

	   //if frequency of D at index i is more than 1

	       //decrement frequency of D at index i

	// else

           //strcpy element of D at index i to DELETED 

		   //set frequency of D at index i to 0
		
    //else print fruit does not exist in the dictionary
}

// This function returns the search length of a fruit.
int getSearchLength(Dictionary D, String fruit){

	//declare i and sl variable

	//butterfly loop - initialize i to hashBrown function, sl = 1; sl < MAX and strcmp element of D at index i and fruit is not equal to 0; i = (i + 1) % MAX, sl++) {}

	//return sl

}

// This function is completed for you.
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

// This function is completed for you.
void displayDictionary(Dictionary D){
	int i;
	
	printf("\n%-15s%-15s%-15s\n", "INDEX", "FRUIT", "FREQUENCY");
	
	for(i = 0; i < MAX; i++){
		printf("  %-13d%-19s%-15d\n", i, D[i].elem, D[i].frequency);
	}
}