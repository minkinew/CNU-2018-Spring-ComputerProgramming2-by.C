#include <stdio.h>

void exchange(double *a, double *b); // void exchange 함수 선언 
void func(void(*p)(double *, double *), double, double); // void func 함수 선언
int assingn02(void); //int assign02 함수 선언

int main(){
	assign02(); //assign02 함수 호출
}

int assign02(){ //assign02 함수 정의
	double a = 10;
	double b = 20;
	func(exchange, a, b); //func 함수 호출(exchange 함수를 쓰되, a와 b변수를 사용)
	return 0;
}
void exchange(double *a, double *b){ // void exchange 함수
	double c = *a;
	*a = *b;
	*b = c;
} // 주소를 인수로 받아서 가리키는 두 값을 바꿈

void func(void(*p)(double *a, double *b), double a, double b){// void func 함수
	printf("a = %.1f, b = %.1f\n", a, b);
	p(&a, &b); // 함수 포인터 p에 의한 호출
	printf("a = %.1f, b = %.1f\n", a, b);
} // 인수로 받은 두 값을 출력 한 후에 exchange 함수를 사용하여 두 값을 바꾸고 다시 출력