#include <stdio.h>
int main(){
	int n, i, j;
	printf("���ڸ� �Է��Ͻÿ�. : ");
	scanf_s("%d", &n);
	if (n < 1) n = 1;

	if (n % 2 == 0){
		for (i = 0; i <= n / 2 - 1; i++){
			for (j = i; j < n / 2; j++){
				printf(" ");
			}
			for (j = n - 1 - i * 2; j < n; j++){
				printf("*");
			}
			printf("\n");
		}
	}

	else{
		for (i = 0; i <= n / 2; i++){
			for (j = i; j < n / 2; j++){
				printf(" ");
			}
			for (j = n - 1 - i * 2; j < n; j++){
				printf("*");
			}
			printf("\n");
		}
	}
	
	for (i = n / 2 - 1; i >= 0; i--){
		for (j = i; j < n / 2; j++){
			printf(" ");
		}
		for (j = n - 1 - i * 2; j < n; j++){
			printf("*");
		}
		printf("\n");
	}
}
