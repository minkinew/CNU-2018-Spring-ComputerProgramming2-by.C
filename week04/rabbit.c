#include <stdio.h>
int Rabbit(int x);

int main(){
	int n; //���� �����ϴ� ����
	int result; //1�޸��� ��ü�䳢�� �������� �����ϴ� ����

	printf("1���Ŀ� ��ü �䳢�� ������ : \n");
	for (n = 1; n < 13; n++){ // ���� �� ��� 
	result = Rabbit(n); // Rabbit �Լ��� ȣ��
	printf("%d   ", result);
}
	printf("\n");
	return 0;
	
}

int Rabbit(int x) { //�Ѵ޸��� ��ȭ�Ǵ� �䳢�� �������� ����ϴ� �Լ�
	if (x <= 1)
		return x;
	else return Rabbit(x - 1) + Rabbit(x - 2); //����Լ�
}