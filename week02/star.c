
#include<stdio.h>

int main(void){
	
	
	int i, j, k; // 변수설정
	while (1){ //조건을 만족할 때 까지 계속 반복
	printf("개수를 입력해 주세요 : [종료 : 0]\n"); 
	scanf_s("%d", &k); //숫자를 입력받음

		if (k == 0) return 0; //입력받는 숫자가 0이면 종료
		else if (k <= 10) {
			for (i = 1; i <= k; i++){
				for (j = 1; j <= k - i; j++)
					printf(" ");
				for (j = 1; j <= (i * 2) - 1; j++){
					printf("*");
				} //입력받는 숫자가 10이하의 정수면 *을 출력
				printf("\n");
			}
		}
		else  printf("다시 입력해주세요!\n"); //10초과인 정수를 입력하면 "다시 입력해주세요" 를 출력.
		}
	return 0;
	}

