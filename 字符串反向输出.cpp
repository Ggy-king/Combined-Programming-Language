#include <stdio.h>
#include <string.h>
int main(){
	char a[10];
	int i,j;
	gets(a);
	j = strlen(a);
	if (j > 9){
		return 0;
	}else {
		int q;
		q = j - 1; 
		while(q>=0){
			q--;
			printf("%c",a[q]);
		}
	
	}
	return 0;
}
