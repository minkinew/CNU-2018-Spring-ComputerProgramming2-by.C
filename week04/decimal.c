#include <stdio.h>
int prime_check(int checkNum);

int main(){
	int n; //��������
	int count = 0;

	printf("���ڸ� �Է��Ͻÿ�."); //printf��¹�
	scanf_s("%d", &n); //n�� �Է¹��� scanf����
	
	for (int i = 2; i <= n; i++){ //i�� 2~n���� ����
		if (prime_check(i) == 1) { //prime_check�Լ��� i�� ������ Ȯ��
			printf("%d   ", i); //1�̸� ��� 
			count++;
		}
		if (count == 3 ) { // 1�ٿ� 3���� �����.
			printf("\n");
			count = 0;
		}
	}
	return 0;
}

int prime_check(int checkNum){
	for (int i = 2; i <= checkNum; i++){  // �Ҽ��Ǻ���
		if (checkNum % i == 0){ //checkNum�� i�� ��� ������ �������� 0�̸� ����
			break;
			return 1;
		}
}
