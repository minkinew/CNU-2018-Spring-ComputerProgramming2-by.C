#include <stdio.h>
#include <string.h>

void invertedOutput(char str[]);

int main(){
	char c[100] = { 0 }; //���ڿ� �迭 ����(������ ������ 0���� �ʱ�ȭ)
	printf("�� ���� �Է��ϼ���. >>\n");
	gets(c); //��ĭ�� ������ ���ڿ� �Է�
	printf("������ �Է��� ���ڿ��� �Ųٷ� ����մϴ�.\n");
	
	invertedOutput(c); //invertedOutput�Լ� ȣ��
	
	return 0;
}

void invertedOutput(char str[]){
	char reverse[100]= {0}; //���ο� ���ڿ� �迭 ����(������ ������ 0���� �ʱ�ȭ)
	int len = strlen(str); //�迭�� ���̸� len������ �ʱ�ȭ
	
	for (int i = len-1 , j = 0; i >= 0; i--,j++){
		reverse[j] = str[i]; //������ �迭�� ���ڿ��� ���ο� �迭�� �������� ����
	}
	puts(reverse); //���ο� �迭�� ����� ���ڿ� ���
}