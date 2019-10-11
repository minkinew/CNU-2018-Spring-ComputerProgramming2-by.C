#include <stdio.h>

int main(){
	int inputScore(int *scoreArray, int inputIndex); //점수를 입력받는 함수

	int printScore(int *scoreArray, int index); //점수를 출력하는 함수

	int scoreArray[20][3]; //2차원 배열 설정
	int inputStudentSize; //학생 수
	int studentIndex; //학생배열의 인덱스 값
	

	printf("입력 받을 학생수를 입력하세요 : "); 
	scanf_s("%d", &inputStudentSize); 

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		inputScore(&(scoreArray[studentIndex]), inputStudentSize); //국, 영, 수 점수를 학생배열의 순차적으로 입력(inputScore 함수를 불러옴)

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printScore(&(scoreArray[studentIndex]), studentIndex, inputStudentSize); //국, 영, 수 점수를 학생배열의 순차적으로 출력(printScore 함수를 불러옴)

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printSum(&(scoreArray[studentIndex]), studentIndex, inputStudentSize); //국, 영, 수 점수를 각 학생들별로 총합을 출력(printSum함수를 불러옴)

	for (studentIndex = 0; studentIndex < inputStudentSize; studentIndex++)
		printAvg(&(scoreArray[studentIndex]), studentIndex, inputStudentSize); //국, 영, 수 점수를 각 학생들별로 평균을 출력(printAvg함수를 불러옴)



	return 0;
}

int inputScore(int *scoreArray){  //국, 영, 수 점수를 입력받음
	printf("국어 성적 입력 : ");
	scanf_s("%d", &scoreArray[0]);
	printf("영어 성적 입력 : ");
	scanf_s("%d", &scoreArray[1]);
	printf("수학 성적 입력 : ");
	scanf_s("%d", &scoreArray[2]);
	
}
int printScore(int *scoreArray, int index){ //국, 영, 수 함수를 출력
	printf("[%d] %d, %d, %d\n",index, scoreArray[0], scoreArray[1], scoreArray[2]);

}

int printSum(int *scoreArray, int index){ //학생들의 점수를 총합하는 함수
	int sum = 0;
	for (int i = 0; i < 3; i++){
		sum = sum + scoreArray[i];
	}

	printf("학생%d의 총점 : %d\n", index + 1 ,sum ); //학생의 총점 출력
	return sum;
}

int printAvg(int *scoreArray, int index){ //학생들의 점수를 평균내는 함수
	int Avg;
	int sum = 0;
	for (int i = 0; i < 3; i++){
		sum = sum + scoreArray[i];
	}
	Avg = sum / 3;

	printf("학생%d의 평균 : %d\n",index + 1, Avg); //학생의 평균점수 출력
	return Avg;
}