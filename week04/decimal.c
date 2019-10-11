#include <stdio.h>
int prime_check(int checkNum);

int main(){
	int n; //변수설정
	int count = 0;

	printf("숫자를 입력하시오."); //printf출력문
	scanf_s("%d", &n); //n을 입력받을 scanf구문
	
	for (int i = 2; i <= n; i++){ //i는 2~n까지 대입
		if (prime_check(i) == 1) { //prime_check함수에 i를 전달해 확인
			printf("%d   ", i); //1이면 출력 
			count++;
		}
		if (count == 3 ) { // 1줄에 3개씩 출력함.
			printf("\n");
			count = 0;
		}
	}
	return 0;
}

int prime_check(int checkNum){
	for (int i = 2; i <= checkNum; i++){  // 소수판별식
		if (checkNum % i == 0){ //checkNum를 i로 모두 나누어 나머지가 0이면 멈춤
			break;
			return 1;
		}
}
