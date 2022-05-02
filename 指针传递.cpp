#include <stdio.h>
void swap(int * x,int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
	
} 
int main(){
	int a, b;
	int temp;
	a = 1;
	b = 2;
	printf("a=%d b=%d\n",a,b);
	swap(&a , &b);
	printf("a=%d b=%d\n",a,b);
	return 0;
}
