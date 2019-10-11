#include <stdio.h>

int disp_menu(void); //int disp_menu 함수
void enter_park(int(*park_space)[2][5], int(*reserved)[3]); //void enter_park 함수
void exit_park(int(*park_space)[2][5]); //void exit_park 함수
void reserve_park(int(*reserved)[3]); //void reserve_park 함수
void print_park(int(*park_space)[2][5], int(*reserved)[3]); //void print_park 함수
void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]); //void print_basement 함수
int check_reservation(int(*reserved)[3], int basement, int num); //int check_reservation 함수
int check_reserved_num(int(*reserved)[3], int car_num, int*floor, int *resv_num); //int check_reserved_num 함수
int find_space(int(*park_space)[5], int floor, int(*reserved)[3]); //int find_space 함수


int disp_menu(void) { // int disp_menu 함수 정의 (메뉴를 출력하고 선택된 메뉴 반환)
	int input;
	puts("1. 주차");
	puts("2. 출차");
	puts("3. 지정차량 등록");
	puts("4. 주차현황 출력");
	puts("0. 종료");
	printf("> 번호선택 : ");
	scanf("%d", &input);
	return input;
}

void enter_park(int(*park_space)[2][5], int(*reserved)[3]) { // void enter_park 함수 정의 (주차 기능 수행)
	int carNumber = 0;
	int carParking = 0;
	int floor = 1;
	printf("> 차번 입력(숫자 4자리) :");
	scanf("%d", &carNumber);

	if (check_reserved_num(reserved, carNumber, &floor, &carParking) == 1) { 
		park_space[floor][carParking / 5][carParking % 5] = carNumber; 
		printf("\n@ 지정차량 : %d층 %d번 주차했습니다.\n", floor + 1, carParking + 1);
	}
	else {
		printf("@ 주차 가능 공간 : 1층[%d]대  2층[%d]대  3층[%d]대\n",
			find_space(park_space, 1, reserved), find_space(park_space, 2, reserved), find_space(park_space, 3, reserved));

		int PlusMinus;
		print_basement(park_space, floor, reserved);
		while (1) {
			printf("\n\n> 주차 번호 입력(다른층 0, 취소 -1) : ");
			scanf("%d", &carParking);

			if (carParking == -1) 
				break;
			else if (carParking == 0) {
				if (floor == 1) 
					PlusMinus = +1;
				else if (floor == 3) 
					PlusMinus = -1;
				floor =  floor + PlusMinus;
				print_basement(park_space, floor, reserved);
			}
			else {
				if (check_reservation(reserved, floor, carParking - 1) == 1) { 
					printf("\n@ 이미 예약된 자리입니다!\n");
				}
				else {
					park_space[floor - 1][(carParking - 1) / 5][(carParking - 1) % 5] = carNumber;
					printf("\n@ 주차 되었습니다!\n");
					break;
				}
			}
		}
	}
}

void exit_park(int(*park_space)[2][5]) { // void exit_park 함수 정의 (출차 기능 수행)
	int carNumber = 0; 
	printf("> 차번 입력(숫자 4자리) : ");
	scanf("%d", &carNumber);

	for (int i = 1; i < 31; i++) {
		if (*(**park_space + i) == carNumber) {
			*(**park_space + i) = 0;
			puts("\n@ 출차되었습니다.");
			break;
		}
		if (i == 30) puts("\n@ 해당 차량이 없습니다.");
	}
}

void reserved_park(int(*reserved)[3]) { // void reserved_park 함수 정의 (지정차량 등록 수행) 
	int carNumber = 0;
	int carParking = 0;
	int floor = -1;

	for (; floor != 0;) {
		printf("\n> 층과 번호 입력(종료 0) : ");
		scanf("%d", &floor);
		if (floor == 0) break;

		scanf("%d", &carParking);
		printf("> 등록차량 번호 입력 : ");
		scanf("%d", &carNumber);
		reserved[10 * (floor - 1) + (carParking - 1)][2] = carNumber;
		reserved[10 * (floor - 1) + (carParking - 1)][1] = carParking;
		reserved[10 * (floor - 1) + (carParking - 1)][0] = floor;
		printf("@ 등록되었습니다.\n");
	}
}

void print_park(int(*park_space)[2][5], int(*reserved)[3]) { // void print_park 함수 정의 (4번. 주차 현황 출력)
	printf("\n");

	for (int floor = 1; floor <= 3; floor++) {
		printf("[ %d층]========================\n", floor);
		for (int i = 0; i < 5; i++) {
			if (park_space[floor - 1][0][i] >= 1000)
				printf("[%d] ", park_space[floor - 1][0][i]);
			else if (check_reservation(reserved, floor, i) == 1)
				printf("[resv] ");
			else
				printf("[ %d ] ", i + 1);
		}
		printf("\n");

		for (int j = 0; j < 5; j++) {
			if (park_space[floor - 1][1][j] >= 1000)
				printf("[%d] ", park_space[floor - 1][1][j]);
			else if (check_reservation(reserved, floor, j + 5) == 1)
				printf("[resv] ");
			else
				printf("[ %d ] ", 6 + j);
		}
		printf("\n\n");
	}
	printf("[%d]\n ", park_space[0][0][1]);
}

void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) { // void print_basement 함수 정의 (주차 현황 출력)
	printf("\n");
	printf("[ %d층]======================\n", floor);
	for (int i = 0; i < 5; i++) {
		if (park_space[2 * (floor - 1)][i] >= 1000)
			printf("[%2d ] ", park_space[2 * (floor - 1)][i]);
		else if (check_reservation(reserved, floor, i) == 1)
			printf("[resv] ");
		else
			printf("[%2d ] ", i + 1);
	}
	printf("\n");

	for (int j = 0; j < 5; j++) {
		if (park_space[2 * (floor - 1) + 1][j] >= 1000)
			printf("[%2d ] ", park_space[2 * (floor - 1) + 1][j]);
		else if (check_reservation(reserved, floor, j + 5) == 1)
			printf("[resv] ");
		else
			printf("[%2d ] ", 6 + j);
	}
}

int check_reservation(int(*reserved)[3], int basement, int num) { // int check_reservation 함수 정의(지정차량 있는 경우 1, 아니면 0), num = 0~9, 
	if (reserved[10 * (basement - 1) + num][0] == 0)
		return 0;
	else 
		return 1;
} 

int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num) { // int check_reserved_num 함수 정의
	for (int i = 0; i < 30; i++) {
		if (reserved[i][2] == car_num) {
			*floor = i / 10;
			*resv_num = i % 10;
			return 1;
		}
	}
	return 0;
} // 차량이 지정 차량인지 확인, 지정차량이면 1 반환. floor, resv_num에 지정차량 위치 저장
 

int find_space(int(*park_space)[5], int floor, int(*reserved)[3]) { // int find_space 함수 정의 (빈 공간이 얼마나 있는지 확인)
	int size = 0;

	for (int i = 0; i < 5; i++) {
		if (park_space[2 * (floor - 1)][i] < 1000 && reserved[10 * (floor - 1) + i][0] == 0)
			size++;
		if (park_space[2 * (floor - 1) + 1][i] < 1000 && reserved[10 * (floor - 1) + i + 5][0] == 0)
			size++;
	}
	return size;
} 

int main() {
	int park_space[3][2][5] = { 0 }; // 주차장 배열
	int reserved[30][3] = { 0 }; // 30개 예약가능

	for (int input;;) {
		int input = disp_menu();
		if (input == 1) // 주차
			enter_park(park_space, reserved);
		else if (input == 2)  // 출차
			exit_park(park_space);	
		else if (input == 3)  // 지정차량
			reserved_park(reserved);
		else if (input == 4) 
			print_park(park_space, reserved);
		else if (input == 0) 
			break;	
	}

}