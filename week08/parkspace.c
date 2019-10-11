#include <stdio.h>

int disp_menu(void); //int disp_menu �Լ�
void enter_park(int(*park_space)[2][5], int(*reserved)[3]); //void enter_park �Լ�
void exit_park(int(*park_space)[2][5]); //void exit_park �Լ�
void reserve_park(int(*reserved)[3]); //void reserve_park �Լ�
void print_park(int(*park_space)[2][5], int(*reserved)[3]); //void print_park �Լ�
void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]); //void print_basement �Լ�
int check_reservation(int(*reserved)[3], int basement, int num); //int check_reservation �Լ�
int check_reserved_num(int(*reserved)[3], int car_num, int*floor, int *resv_num); //int check_reserved_num �Լ�
int find_space(int(*park_space)[5], int floor, int(*reserved)[3]); //int find_space �Լ�


int disp_menu(void) { // int disp_menu �Լ� ���� (�޴��� ����ϰ� ���õ� �޴� ��ȯ)
	int input;
	puts("1. ����");
	puts("2. ����");
	puts("3. �������� ���");
	puts("4. ������Ȳ ���");
	puts("0. ����");
	printf("> ��ȣ���� : ");
	scanf("%d", &input);
	return input;
}

void enter_park(int(*park_space)[2][5], int(*reserved)[3]) { // void enter_park �Լ� ���� (���� ��� ����)
	int carNumber = 0;
	int carParking = 0;
	int floor = 1;
	printf("> ���� �Է�(���� 4�ڸ�) :");
	scanf("%d", &carNumber);

	if (check_reserved_num(reserved, carNumber, &floor, &carParking) == 1) { 
		park_space[floor][carParking / 5][carParking % 5] = carNumber; 
		printf("\n@ �������� : %d�� %d�� �����߽��ϴ�.\n", floor + 1, carParking + 1);
	}
	else {
		printf("@ ���� ���� ���� : 1��[%d]��  2��[%d]��  3��[%d]��\n",
			find_space(park_space, 1, reserved), find_space(park_space, 2, reserved), find_space(park_space, 3, reserved));

		int PlusMinus;
		print_basement(park_space, floor, reserved);
		while (1) {
			printf("\n\n> ���� ��ȣ �Է�(�ٸ��� 0, ��� -1) : ");
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
					printf("\n@ �̹� ����� �ڸ��Դϴ�!\n");
				}
				else {
					park_space[floor - 1][(carParking - 1) / 5][(carParking - 1) % 5] = carNumber;
					printf("\n@ ���� �Ǿ����ϴ�!\n");
					break;
				}
			}
		}
	}
}

void exit_park(int(*park_space)[2][5]) { // void exit_park �Լ� ���� (���� ��� ����)
	int carNumber = 0; 
	printf("> ���� �Է�(���� 4�ڸ�) : ");
	scanf("%d", &carNumber);

	for (int i = 1; i < 31; i++) {
		if (*(**park_space + i) == carNumber) {
			*(**park_space + i) = 0;
			puts("\n@ �����Ǿ����ϴ�.");
			break;
		}
		if (i == 30) puts("\n@ �ش� ������ �����ϴ�.");
	}
}

void reserved_park(int(*reserved)[3]) { // void reserved_park �Լ� ���� (�������� ��� ����) 
	int carNumber = 0;
	int carParking = 0;
	int floor = -1;

	for (; floor != 0;) {
		printf("\n> ���� ��ȣ �Է�(���� 0) : ");
		scanf("%d", &floor);
		if (floor == 0) break;

		scanf("%d", &carParking);
		printf("> ������� ��ȣ �Է� : ");
		scanf("%d", &carNumber);
		reserved[10 * (floor - 1) + (carParking - 1)][2] = carNumber;
		reserved[10 * (floor - 1) + (carParking - 1)][1] = carParking;
		reserved[10 * (floor - 1) + (carParking - 1)][0] = floor;
		printf("@ ��ϵǾ����ϴ�.\n");
	}
}

void print_park(int(*park_space)[2][5], int(*reserved)[3]) { // void print_park �Լ� ���� (4��. ���� ��Ȳ ���)
	printf("\n");

	for (int floor = 1; floor <= 3; floor++) {
		printf("[ %d��]========================\n", floor);
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

void print_basement(int(*park_space)[5], int floor, int(*reserved)[3]) { // void print_basement �Լ� ���� (���� ��Ȳ ���)
	printf("\n");
	printf("[ %d��]======================\n", floor);
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

int check_reservation(int(*reserved)[3], int basement, int num) { // int check_reservation �Լ� ����(�������� �ִ� ��� 1, �ƴϸ� 0), num = 0~9, 
	if (reserved[10 * (basement - 1) + num][0] == 0)
		return 0;
	else 
		return 1;
} 

int check_reserved_num(int(*reserved)[3], int car_num, int *floor, int *resv_num) { // int check_reserved_num �Լ� ����
	for (int i = 0; i < 30; i++) {
		if (reserved[i][2] == car_num) {
			*floor = i / 10;
			*resv_num = i % 10;
			return 1;
		}
	}
	return 0;
} // ������ ���� �������� Ȯ��, ���������̸� 1 ��ȯ. floor, resv_num�� �������� ��ġ ����
 

int find_space(int(*park_space)[5], int floor, int(*reserved)[3]) { // int find_space �Լ� ���� (�� ������ �󸶳� �ִ��� Ȯ��)
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
	int park_space[3][2][5] = { 0 }; // ������ �迭
	int reserved[30][3] = { 0 }; // 30�� ���డ��

	for (int input;;) {
		int input = disp_menu();
		if (input == 1) // ����
			enter_park(park_space, reserved);
		else if (input == 2)  // ����
			exit_park(park_space);	
		else if (input == 3)  // ��������
			reserved_park(reserved);
		else if (input == 4) 
			print_park(park_space, reserved);
		else if (input == 0) 
			break;	
	}

}