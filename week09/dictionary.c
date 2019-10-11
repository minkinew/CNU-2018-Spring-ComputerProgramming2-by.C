#include <stdio.h>
#include <string.h>

int input_intro(char(*intro)[80]); // int input_intro �Լ� ���� 
void init_intro(char(*intro)[80], char **intp); // void init_intro �Լ� ����
void sort_intro(char **intp, int cnt); // void sort_intro �Լ� ����
void print_intro(int mode, void *vp, int cnt); // void print_intro �Լ� ����
int assign03(void); //int assign03 �Լ� ����

int main(){
	char intro[10][80];
	char *intp[10];
	int cnt;

	init_intro(intro, intp); //init_intro �Լ� ȣ��
	cnt = input_intro(intro); //cnt ���� ����
	sort_intro(intp, cnt); //sort_intro �Լ� ȣ��
	print_intro(1, intp, cnt); //print_intro �Լ� ȣ��
	print_intro(0, intro, cnt); //print_intro �Լ� ȣ��

	return 0;
}
int input_intro(char(*intro)[80]){ //int input_intro �Լ� ����
	int p = 0;

	for (int i = 0;; i++){ // �����Է� �ݺ���
		printf("> ���� �Է� : ");
		scanf("%s", intro[i]);

		if (strcmp(intro[i], "end") == 0){ // end�� �Է��ϸ� ����
			printf("����\n");
			break;
		}
		p++;
	}
	return p;
} //������ �Է¹���

void init_intro(char(*intro)[80], char **intp){ //void init_intro �Լ� ����
	for (int i = 0; i < 10; i++){
		intp[i] = intro[i];
	}
} //���޹��� intro�� intp�� ����

void sort_intro(char **intp, int cnt){ //void sort_intro �Լ� ����
	char *n;

	for (int i = 0; i < cnt; i++){
		for (int j = i; j < cnt; j++){
			if (strcmp(intp[i], intp[j]) > 0){
				n = intp[i];
				intp[i] = intp[j];
				intp[j] = n;
			}
		}
	}
} //���������� ����

void print_intro(int mode, void *vp, int cnt){ //void print_intro �Լ� ����
	if (mode == 1) { // mode�� 1�� �� ���������� ���
		char **p = (char**)vp;
		printf("���������� ���... : \n");

		for (int i = 0; i < cnt; i++) {
			printf("%s\n", p[i]);
		}
	}

	if (mode == 0){ // mode�� 0�� �� �Է¼����� ���
		char(*q)[80] = (char**)vp;
		printf("�Է¼����� ���...\n");

		for (int i = 0; i < cnt; i++){
			printf("%s\n", q[i]);
		}
	}
}