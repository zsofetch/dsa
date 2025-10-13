#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 26

typedef char String[100];

typedef struct node {
	String name;
	struct node *next;
} *SET;

typedef SET Dictionary[MAX];
typedef enum {FALSE, TRUE} Boolean;

void initializeDict(Dictionary D);
int hashBrown(char name[]);
Boolean isMember(Dictionary D, char name[]);
void insertUniqueSorted(Dictionary D, char name[]);
void deleteName(Dictionary D, char name[]);
void displayDict(Dictionary D);

void populateDict(Dictionary D);

int main(){
	Dictionary D;
	
	printf("START\n\n");
	
	printf("01. INITIALIZE DICTIONARY\n");
	initializeDict(D);
	displayDict(D);
	
	printf("02. INSERT UNIQUE SORTED\n");
	populateDict(D);
	insertUniqueSorted(D, "Justine Carl Lequigan");
	insertUniqueSorted(D, "Zach Michael Bacolod");
	displayDict(D);
	
	printf("03. IS MEMBER\n");
	printf("\t[%s] is %s member in the dictionary.\n", "Fern Andrei Rosello", isMember(D, "Fern Andrei Rosello") == TRUE ? "A" : "NOT a");
	printf("\t[%s] is %s member in the dictionary.\n", "Althea Mariel Cinco", isMember(D, "Althea Mariel Cinco") == TRUE ? "A" : "NOT a");
	printf("\t[%s] is %s member in the dictionary.\n\n", "Mauris Matthew Samson", isMember(D, "Mauris Matthew Samson") == TRUE ? "A" : "NOT a");
	
	printf("04. DELETE NAME\n");
	deleteName(D, "Cris Joseph Arquiza");
	deleteName(D, "Justine Carl Lequigan");
	displayDict(D);
	
	return 0;
}

// This funcition initializes an empty dictionary.
// Set each bucket to NULL.
void initializeDict(Dictionary D){

}

// This function returns a hash value based on the remainder of the ASCII value of the first letter (capitalized) of the name divided by 65.
int hashBrown(String name){

}

// This function returns a Boolean value of either TRUE or FALSE.
// It checks if the name is a member in the dictionary.
Boolean isMember(Dictionary D, String name){

}

// This function inserts the name into the dictionary in ascending order, with no duplicates of the name.
// If the name already exists, print a message that the name already exists in the dictionary.
void insertUniqueSorted(Dictionary D, String name){

}

// This function deletes a name from the dictionary.
// If name does not exist, print a message that the name does not exist in the dictionary.
void deleteName(Dictionary D, String name){

}

// This function is completed for you.
void displayDict(Dictionary D){
	SET trav;	
	int i;
	
	printf("\tINDEX\tNAME\n");
	
	for(i = 0; i < MAX; i++){
		printf("\t [%c]:\t", i + 65);
		
		if(D[i] != NULL){
			for(trav = D[i]; trav != NULL; trav = trav->next){
				if(trav->next != NULL){
					printf("%s, ", trav->name);
				} else{
					printf("%s\n", trav->name);
				}
			}
		} else {
			printf("\n");
		}
	}
	
	printf("\n");
}

// This function is completed for you.
void populateDict(Dictionary D){
	int i;
	
	String blockD[18] = {
		"Justine Carl Lequigan", "Akeah Jailyn Diez", "Zach Michael Bacolod",
		"Hansen Tiodianco", "Zyann Bugtong", "Khen Andrei Lim",
		"Lorenze Antoinette Cabahug", "Denise Bocado", "Kate Irah Marie Abendan",
		"Fern Andrei Rosello", "Mauris Matthew Samson", "David Anthony Yap",
		"Althea Mariel Cinco", "Razel Kaye Arenas", "Dinnesh Nicole Manondo",
		"Torcy Klyne Suganob", "Johnfranz Impas", "Hannah Marie Martinez" 
	};
	
	for(i = 0; i < 18; i++){
		insertUniqueSorted(D, blockD[i]);
	}
}