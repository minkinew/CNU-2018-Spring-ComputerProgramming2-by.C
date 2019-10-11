#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void makeBingo(int * bingoArray, int inputSize); // void makeBingo 함수 선언 
void printBingo(int * bingoArray, int inputSize); // void printBingo 함수 선언 빙고판을 출력 함수
int checkBingo(int * bingoArray, int inputSize); // int checkBingo함수 선언 
int getRandomNumber(int * prevNumberList); // int getRandomNumber 
int getUserSelectNumber(int * prevNumberList); // int getUserSelectNumber

int main() {

	srand((unsigned int)time((time_t*)NULL)); //프로그램 실행 시마다 랜덤한 난수 발생

	int Bingo[400] = { 0 };
	int bingosize;
	//배열 및 변수 설정

	printf("빙고판 사이즈를 입력하세요 : "); 
	scanf("%d", &bingosize); 

	makeBingo(Bingo, bingosize); // makeBingo() 함수 호출
	checkBingo(Bingo, bingosize); // checkBingo() 함수 호출

	return 0;
}


void makeBingo(int * bingoArray, int inputSize) { //void makeBingo 함수 정의
	int Bingo2[400] = { 0 };
	int count = 0;
	int p = 0;
	//변수 설정

	while (count < (inputSize * inputSize)) {
		p = rand() % (inputSize * inputSize) + 1; // 랜덤값을 p에 저장

		if (Bingo2[p - 1] == 0) { // 중복 숫자 예외처리
			++Bingo2[p - 1];
			bingoArray[count++] = p;
		}
	}
	printBingo(bingoArray, inputSize); //printBingo() 호출
} // 빙고판을 생성

void printBingo(int * bingoArray, int inputSize) { // void printBingo 함수 선언 
	for (int i = 0; i < inputSize * inputSize; i++) {
		if (bingoArray[i] == -5) // bingoArray[i]가 -5일 때 '*' 출력
			printf("%4c", '*'); 
		else
			printf("%4d", bingoArray[i]); // 그렇지 않으면 bingoArray[i] 출력

		if (i % inputSize == inputSize - 1)
			printf("\n");  // 줄바꿈
	}
} // 빙고판을 출력

int checkBingo(int * bingoArray, int inputSize) { // int checkBingo 함수 정의
	int Bingocheck[400] = { 0 };
	int checkNum = 0;
	int bingo = 0;
	int Number;
	int bingoNum;
	//변수 설정

	Bingocheck[inputSize * inputSize] = -1;

	while (1) {
		bingoNum = 0;

		printf("숫자 추출 방법을 선택[1:랜덤][2:사용자입력] : ");
		scanf("%d", &Number);

		if (Number == 1)
			bingoNum = getRandomNumber(Bingocheck); // 1번 입력했을 때
		else if (Number == 2)
			bingoNum = getUserSelectNumber(Bingocheck); // 2번 입력했을 때
	

		if (bingoNum == 0) // 1, 2번을 제외한 번호을 입력했을 때
			printf("다시 입력 하세요\n");

		else if (bingoNum == -1) // 중복 숫자를 입력했을 때
			printf("이미 입력된 숫자입니다\n");

		else { // 정상적으로 입력했을 때
			for (int i = 0; i < (inputSize * inputSize); i++) {
				if (bingoArray[i] == bingoNum)
					bingoArray[i] = -5;
			}

			switch (1) { // 빙고 조건 확인
			case 1: // 세로 빙고 확인
				for (int i = 0; i < inputSize; i++) {
					for (int j = 0; j < (inputSize * inputSize); j = j + inputSize) {
						if (bingoArray[i + j] == -5)
							++checkNum;
					}
					if (checkNum == inputSize) { // 세로 빙고가 되었을 때
						++bingo; 
						break;
					}
					checkNum = 0; // 0으로 초기화
				}

				if (checkNum == inputSize) // 종료
					break;

			case 2: // 가로 빙고 확인
				for (int i = 0; i < (inputSize * inputSize); i = i + inputSize) {
					for (int j = 0; j < inputSize; j++) {
						if (bingoArray[i + j] == -5)
							++checkNum;
					}
					if (checkNum == inputSize) { // 가로 빙고가 되었을 때
						++bingo; 
						break;
					}
					checkNum = 0; // 0으로 초기화
				}

				if (checkNum == inputSize) // 탐색 종료,
					break;

			case 3: // 대각선 1번 유형 빙고 확인
				for (int i = inputSize - 1; i < (inputSize * inputSize); i = i + inputSize - 1) {
					if (bingoArray[i] == -5)
						++checkNum;
				}

				if (checkNum == inputSize) { // 대각선 1번 유형이 빙고가 되었을 때
					++bingo; 
					break;
				}
				checkNum = 0; // 0으로 초기화

			case 4: // 대각선 2번 유형 빙고 확인 
				for (int i = 0; i < (inputSize * inputSize); i = i + inputSize + 1) {
					if (bingoArray[i] == -5)
						++checkNum;
				}

				if (checkNum == inputSize) { // 대각선 2번 유형이 빙고가 되었을 때
					++bingo; 
					break;
				}
				checkNum = 0; //0으로 초기화
			}

			if (bingo != 0) {
				printf("빙고!\n"); //"빙고" 출력
				printBingo(bingoArray, inputSize); // printBingo 함수 호출
				break;
			}
		}
	}
	return 0;
} // 빙고를 확인

int getRandomNumber(int * prevNumberList) { // int getUserSelectNumber 함수 정의 
	int m = 0;
	int size = 0;
	int j = 1;

	for (size = 0; prevNumberList[size] != -1; size++);

	while (1) {
		int check = 0;
		m = rand() % size + 1; 

		for (int i = 1; i < size-1; i++)
		if (prevNumberList[i-1] == m) {
			++check;
			break;
		}

		if (check == 0)
			break;
	}

	printf("랜덤 숫자를 추출 : %d\n", m);

	while (1){
		if (prevNumberList[j - 1] == 0) {
			prevNumberList[j - 1] = m;
			break;
		}
		j++;
	}

	return m;
} // 현재까지 나온적이 없는 숫자들중, 하나를 랜덤하게 추출해서 반환

int getUserSelectNumber(int * prevNumberList) { // int getUserSelectNumber 함수 정의 
	int m;
	int size = 0; 
	int check = 0;
	int j = 1;

	for (size = 0; prevNumberList[size] != -1; size++);

	printf("사용자 선택 숫자 입력 : ");
	scanf("%d", &m);

	for (int i = 1; i < size-1; i++)
	if (m == prevNumberList[i-1]) {
		++check;
		break;
	}

	if (check != 0)
		m = -1;
	else {
		while (1){
			if (prevNumberList[j - 1] == 0) {
				prevNumberList[j - 1] = m;
				break;
			}
			j++;
		}
	}
	return m;
} //빙고 번호를 입력받아 반환