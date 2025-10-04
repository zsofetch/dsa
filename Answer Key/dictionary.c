#include <stdio.h>

int hash1(int x){
	return x % 100;
}

int hash2(int x){
	int sum = 0;
	
	while(x != 0){
		sum += (x % 10);
		x /= 10;
	}
	
	return sum % 19;
}

int hash3(char name[]){
	int sum = 0, i;
	
	for(i = 0; name[i] != '\0'; i++){
		sum += name[i];
	}
	
	return sum % 49;
}

int main(){
	printf("The hundreds place of 269 is %d\n", hash1(269));
	printf("The hash value of 15 is %d\n", hash2(15));
	printf("The name Cris has a has value of %d\n", hash3("Cris"));
	
	return 0;
}
