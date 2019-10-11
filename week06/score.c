#include <stdio.h>

int main(){
	int inputScore(int *scoreArray, int inputIndex); //������ �Է¹޴� �Լ�

	int printScore(int *scoreArray, int index); //������ ����ϴ� �Լ�

	int scoreArray[20][3]; //2���� �迭 ����
	int inputStudentSize; //�л� ��
	int studentIndex; //�л��迭�� �ε��� ��
	

	printf("�Է� ���� �л����� �Է��ϼ��� : "); 
	scanf_s("%d", &inputStudentSize); 

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		inputScore(&(scoreArray[studentIndex]), inputStudentSize); //��, ��, �� ������ �л��迭�� ���������� �Է�(inputScore �Լ��� �ҷ���)

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printScore(&(scoreArray[studentIndex]), studentIndex, inputStudentSize); //��, ��, �� ������ �л��迭�� ���������� ���(printScore �Լ��� �ҷ���)

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printSum(&(scoreArray[studentIndex]), studentIndex, inputStudentSize); //��, ��, �� ������ �� �л��麰�� ������ ���(printSum�Լ��� �ҷ���)

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printAvg(&(scoreArray[studentIndex]), studentIndex, inputStudentSize); //��, ��, �� ������ �� �л��麰�� ����� ���(printAvg�Լ��� �ҷ���)



	return 0;
}

int inputScore(int *scoreArray){  //��, ��, �� ������ �Է¹���
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[0]);
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[1]);
	printf("���� ���� �Է� : ");
	scanf_s("%d", &scoreArray[2]);
	
}
int printScore(int *scoreArray, int index){ //��, ��, �� �Լ��� ���
	printf("[%d] %d, %d, %d\n",index, scoreArray[0], scoreArray[1], scoreArray[2]);

}

int printSum(int *scoreArray, int index){ //�л����� ������ �����ϴ� �Լ�
	int sum = 0;
	for (int i = 0; i < 3; i++){
		sum = sum + scoreArray[i];
	}

	printf("�л�%d�� ���� : %d\n", index + 1 ,sum ); //�л��� ���� ���
	return sum;
}

int printAvg(int *scoreArray, int index){ //�л����� ������ ��ճ��� �Լ�
	int Avg;
	int sum = 0;
	for (int i = 0; i < 3; i++){
		sum = sum + scoreArray[i];
	}
	Avg = sum / 3;

	printf("�л�%d�� ��� : %d\n",index + 1, Avg); //�л��� ������� ���
	return Avg;
}