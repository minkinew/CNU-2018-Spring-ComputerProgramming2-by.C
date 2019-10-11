#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student Student; //Student ������ ������

struct student{ //����ü ����
	int hakbun; //�й�
	char name[20]; //�̸�
	int ko, en, ma; //����, ����, ����
	int sum; //����
	double avg; //���
	char score; //����
};

void input_data(Student *pary, int inputSize); //input_data �Լ� 
void print_data(Student *pary, int inputSize); //print_data �Լ� ����
void calc_data(Student *pary, int inputSize); //calc_data �Լ� ����
void sort_data(Student *pary, int inputSize); //sort_data �Լ� ����

int main(){
	Student hakseng[100]; //Student���� �迭 ����
	int num; //�л� ��

	printf("�л� �� �Է� : ");
	scanf("%d", &num); //�л� �� �Է�

	input_data(hakseng, num); //input_data �Լ� ȣ��
	calc_data(hakseng, num); //calc_data �Լ� ȣ��
	
	printf("> ���� �� ������ \n");
	print_data(hakseng, num); //print_data �Լ� ȣ��
	
	printf("\n");

	printf("> ���� �� ������ \n"); 
	sort_data(hakseng, num); //sort_data �Լ� ȣ��
	print_data(hakseng, num); //print_data �Լ� ȣ��

	return 0;
}


void input_data(Student *pary, int inputSize){ //input_data �Լ� ����
	int i; //�ݺ��� ����

	for (i = 0; i < inputSize; i++){
		printf("�й� : ");
		scanf("%d", &(pary + i) -> hakbun); // �й� �Է�

		printf("�̸� : ");
		scanf("%s", &(pary + i) -> name); // �̸� �Է�
		
		printf("����, ����, ���� ���� : ");
		scanf("%d %d %d", &(pary + i) -> ko, &(pary + i) -> en, &(pary + i) -> ma); // ��, ��, �� ���� �Է�
	}

} //�л� ������ �Է�

void print_data(Student *pary, int inputSize){ //print_data �Լ� ����
	int i; // �ݺ��� ����
	
	for (i = 0; i < inputSize; i++){
		printf("%d ", (pary + i ) -> hakbun); // �й� ���
		printf("%s ", (pary + i) -> name); // �̸� ���
		printf("%d  %d  %d  ", (pary + i) -> ko, (pary + i) -> en, (pary + i) -> ma); // ��, ��, �� ���� ���
		printf("%d  %.1lf  %c \n", (pary + i) -> sum, (pary + i) -> avg, (pary + i) -> score); //����, ���, ���� ���
	}
} //�л� ������ ���

void calc_data(Student *pary, int inputSize){ //calc_data �Լ� ����
	int i; // �ݺ��� ����
	
	for (i = 0; i < inputSize; i++){
		(pary + i) -> sum = (pary + i) -> ko + (pary + i) -> en + (pary + i) -> ma; // ���� ���� (���� = �� + ��+ �� ����)
		(pary + i) -> avg = (double)(pary + i) -> sum / 3; // ��� ���� (���� / 3)
		
		if ((pary + i) -> avg >= 90) // 90�� �̻� A����
			(pary + i) -> score = 'A';
		else if ((pary + i) -> avg >= 80) // 80�� �̻� 90�̸� B����
			(pary + i) -> score = 'B';
		else if ((pary + i) -> avg >= 70) // 70�� �̻� 80�� �̸� C����
			(pary + i) -> score = 'C';
		else  // 0���̻� 70�� �̸� F����
			(pary + i) -> score = 'F';
	}
} // �л��� ����, ���, ������ ���

void sort_data(Student *pary, int inputSize){ //sort_data �Լ� ����
	int i, j; // �ݺ��� ����

	Student temp; // Student���� ���� ����
	for (i = 0; i < inputSize; i++){ // ���� ������ �������� ���� �ݺ���
		for (j = i; j < inputSize; j++){
			if ((pary + i) -> sum < (pary + j) -> sum){
				temp = pary[i];
				pary[i]= pary[j];
				pary[j] = temp;
			}
		}
	}
} //�л��� ������ ����