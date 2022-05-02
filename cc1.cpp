#include <stdio.h>
int main() {
	int password;
	while (1) {
		scanf("%d", &password);
		if (password == 12345) {
			break;
		}
		printf("password error\n");
	}
	printf("welcome back\n");
	return 0;
}
