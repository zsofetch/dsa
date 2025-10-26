#include <stdio.h>

typedef unsigned char SET; //SET is a small set of up to 8 elements

void initialize(SET *S);
void displayBits(SET S);
void insertFront(SET *S);
void insertRear(SET *S);
void insertPos(SET *S, int pos);
void deleteFront(SET *S);
void deleteRear(SET *S);
void deletePos(SET *S, int pos);
SET setUnion(SET A, SET B);
SET setIntersection(SET A, SET B);
SET setDifference(SET A, SET B);

void initialize(SET *S){
	*S = 0; 
}

void displayBits(SET S){
	SET mask = 1 << (sizeof(SET) * 8 - 1); //1 << 7 moves the bit 1 seven places to the left so 10000000
	int i;
	
	for(i = 1; mask > 0; mask >>=1, i++){ //mask >>=1 shifts mask right every loop
		printf("%u", (S & mask) != 0 ? 1 : 0); //checks if that bit is 1 or 0
		
		if(i % 8 == 0){
			printf(" ");
		}
	}
	
	printf("\n");
}

void insertFront(SET *S){
	SET mask = 1 << (sizeof(SET) * 8 - 1); 
	*S = *S | mask; 
	//mask = 10000000
	//turns on the leftmost bit / turns on the bit where mask = 1 so it becomes 10000000 meaning it inserts a 1 at the front of the bit
}

void insertRear(SET *S){
	SET mask = 1;
	*S = *S | mask;
	//mask = 00000001
	//turns on the rightmost bit / inserts 1 at the REAR of the bit
}

void insertPos(SET *S, int pos){
	SET mask = 1 << (sizeof(SET) * pos - 1);
	*S = *S | mask;
}

void deleteFront(SET *S){
	SET mask = 1 << (sizeof(SET) * 8 - 1);
	*S = *S & (~mask);
}

void deleteRear(SET *S){
	SET mask = 1;
	*S = *S & (~mask);
}

void deletePos(SET *S, int pos){
	SET mask = 1 << (sizeof(SET) * pos - 1);
	*S = *S & (~mask);
}

SET setUnion(SET A, SET B){
	SET S = A | B;
	
	return S;
}

SET setIntersection(SET A, SET B){
	SET S = A & B;
	
	return S;
}

SET setDifference(SET A, SET B){
	SET S = A & (~B);
	
	return S;
}

int main(){
	SET A = 200; // 11001000 in binary
	SET B = 100; // 01100100 in binary
	SET C, U, I, D;
	int i;
	
	initialize(&C);
	
	printf("SET A and SET B:\n");
	displayBits(A);
	displayBits(B);
	
	printf("\nInsert Front:\n");
	insertFront(&C);
	displayBits(C);
	
	printf("\nInsert Rear:\n");
	insertRear(&C);
	displayBits(C);
	
	printf("\nDelete Front:\n");
	deleteFront(&C);
	displayBits(C);
	
	printf("\nDelete Rear:\n");
	deleteRear(&C);
	displayBits(C);
	
	printf("\nInsert at Pos:\n");
	for(i = 0; i < 8; i++){
		insertPos(&C, i + 1);
		displayBits(C);
	}
	
	printf("\nDelete at Pos:\n");
	for(i = 0; i < 8; i++){
		deletePos(&C, i + 1);
		displayBits(C);
	}
	
	printf("\nSet Union (A and B):\n");
	U = setUnion(A, B);
	displayBits(U);
	
	printf("\nSet Intersection (A and B):\n");
	I = setIntersection(A, B);
	displayBits(I);
	
	printf("\nSet Difference (A - B):\n");
	D = setDifference(A, B);
	displayBits(D);
	
	printf("\nSet Difference (B - A):\n");
	D = setDifference(B, A);
	displayBits(D);
	
	return 0;
}
