#include <stdio.h>

void exchange(double *a, double *b); // void exchange �Լ� ���� 
void func(void(*p)(double *, double *), double, double); // void func �Լ� ����
int assingn02(void); //int assign02 �Լ� ����

int main(){
	assign02(); //assign02 �Լ� ȣ��
}

int assign02(){ //assign02 �Լ� ����
	double a = 10;
	double b = 20;
	func(exchange, a, b); //func �Լ� ȣ��(exchange �Լ��� ����, a�� b������ ���)
	return 0;
}
void exchange(double *a, double *b){ // void exchange �Լ�
	double c = *a;
	*a = *b;
	*b = c;
} // �ּҸ� �μ��� �޾Ƽ� ����Ű�� �� ���� �ٲ�

void func(void(*p)(double *a, double *b), double a, double b){// void func �Լ�
	printf("a = %.1f, b = %.1f\n", a, b);
	p(&a, &b); // �Լ� ������ p�� ���� ȣ��
	printf("a = %.1f, b = %.1f\n", a, b);
} // �μ��� ���� �� ���� ��� �� �Ŀ� exchange �Լ��� ����Ͽ� �� ���� �ٲٰ� �ٽ� ���