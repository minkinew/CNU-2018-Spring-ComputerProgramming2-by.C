#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student Student; //Student 형으로 재정의

struct student{ //구조체 선언
	int hakbun; //학번
	char name[20]; //이름
	int ko, en, ma; //국어, 영어, 수학
	int sum; //총점
	double avg; //평균
	char score; //학점
};

void input_data(Student *pary, int inputSize); //input_data 함수 
void print_data(Student *pary, int inputSize); //print_data 함수 선언
void calc_data(Student *pary, int inputSize); //calc_data 함수 선언
void sort_data(Student *pary, int inputSize); //sort_data 함수 선언

int main(){
	Student hakseng[100]; //Student형의 배열 선언
	int num; //학생 수

	printf("학생 수 입력 : ");
	scanf("%d", &num); //학생 수 입력

	input_data(hakseng, num); //input_data 함수 호출
	calc_data(hakseng, num); //calc_data 함수 호출
	
	printf("> 정렬 전 데이터 \n");
	print_data(hakseng, num); //print_data 함수 호출
	
	printf("\n");

	printf("> 정렬 후 데이터 \n"); 
	sort_data(hakseng, num); //sort_data 함수 호출
	print_data(hakseng, num); //print_data 함수 호출

	return 0;
}


void input_data(Student *pary, int inputSize){ //input_data 함수 정의
	int i; //반복문 변수

	for (i = 0; i < inputSize; i++){
		printf("학번 : ");
		scanf("%d", &(pary + i) -> hakbun); // 학번 입력

		printf("이름 : ");
		scanf("%s", &(pary + i) -> name); // 이름 입력
		
		printf("국어, 영어, 수학 점수 : ");
		scanf("%d %d %d", &(pary + i) -> ko, &(pary + i) -> en, &(pary + i) -> ma); // 국, 영, 수 점수 입력
	}

} //학생 정보를 입력

void print_data(Student *pary, int inputSize){ //print_data 함수 선언
	int i; // 반복문 변수
	
	for (i = 0; i < inputSize; i++){
		printf("%d ", (pary + i ) -> hakbun); // 학번 출력
		printf("%s ", (pary + i) -> name); // 이름 출력
		printf("%d  %d  %d  ", (pary + i) -> ko, (pary + i) -> en, (pary + i) -> ma); // 국, 영, 수 점수 출력
		printf("%d  %.1lf  %c \n", (pary + i) -> sum, (pary + i) -> avg, (pary + i) -> score); //총점, 평균, 학점 출력
	}
} //학생 데이터 출력

void calc_data(Student *pary, int inputSize){ //calc_data 함수 정의
	int i; // 반복문 변수
	
	for (i = 0; i < inputSize; i++){
		(pary + i) -> sum = (pary + i) -> ko + (pary + i) -> en + (pary + i) -> ma; // 총점 정의 (총점 = 국 + 영+ 수 점수)
		(pary + i) -> avg = (double)(pary + i) -> sum / 3; // 평균 정의 (총점 / 3)
		
		if ((pary + i) -> avg >= 90) // 90점 이상 A학점
			(pary + i) -> score = 'A';
		else if ((pary + i) -> avg >= 80) // 80점 이상 90미만 B학점
			(pary + i) -> score = 'B';
		else if ((pary + i) -> avg >= 70) // 70점 이상 80점 미만 C학점
			(pary + i) -> score = 'C';
		else  // 0점이상 70점 미만 F학점
			(pary + i) -> score = 'F';
	}
} // 학생의 총점, 평균, 학점을 계산

void sort_data(Student *pary, int inputSize){ //sort_data 함수 정의
	int i, j; // 반복문 변수

	Student temp; // Student형의 변수 선언
	for (i = 0; i < inputSize; i++){ // 총점 순으로 오름차순 정렬 반복문
		for (j = i; j < inputSize; j++){
			if ((pary + i) -> sum < (pary + j) -> sum){
				temp = pary[i];
				pary[i]= pary[j];
				pary[j] = temp;
			}
		}
	}
} //학생의 데이터 정렬