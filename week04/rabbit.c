#include <stdio.h>
int Rabbit(int x);

int main(){
	int n; //달을 지정하는 변수
	int result; //1달마다 전체토끼의 마리수를 지정하는 변수

	printf("1년후에 전체 토끼의 마리수 : \n");
	for (n = 1; n < 13; n++){ // 개월 수 계산 
	result = Rabbit(n); // Rabbit 함수를 호출
	printf("%d   ", result);
}
	printf("\n");
	return 0;
	
}

int Rabbit(int x) { //한달마다 변화되는 토끼의 마리수를 계산하는 함수
	if (x <= 1)
		return x;
	else return Rabbit(x - 1) + Rabbit(x - 2); //재귀함수
}