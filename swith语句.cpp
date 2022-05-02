#include <stdio.h> 
int main(){
	char letter;
	scanf("%c",&letter);
	switch(letter){
		case 'a':
			printf("A\n");
			break;
		case 'b':
			printf("B\n");
			break;
		case 'c':
			printf("C\n");
			break;
		case 'd':
			printf("D\n");
			break;
		case 'e':
			printf("E\n");
			break;
		default:
			printf("I dont know");
	}
	return 0;
}
