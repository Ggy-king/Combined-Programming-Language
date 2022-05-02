#include <stdio.h>
int main(){
	int arr1[10] = {1,2,3,4,5,6,7,8,9,0};
	int arr2[3][4] = {{1,2,3,11},{4,5,6,22},{7,8,9,33}};
	for(int i = 0;i < 3;i++){
		for(int j = 0;j < 4;j++){
			printf("%d",arr2[i][j]);
		}
		printf("\n");
	}
	printf("%d\n",arr2[0][0]);
	printf("%d\n",arr1[3]);
	return 0; 
}
