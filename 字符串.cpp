#include <stdio.h>
int main(){
	char str[20];
	int i = 0;
	while(i < 20 - 1){
		char c;
		c = getchar();
		str[i++] = c;
		if (c == '\n'){
			break;
		}
	}
	str[i] = '\0';
	printf(str);
	return 0;
} 
