#include <stdio.h>
#include <string.h>
#include <stdlib.h> //Rand 함수를 위한 헤더파일
#include <windows.h> //화면 Clear를 위한 헤더파일
#include <time.h> //Srand를 사용하기 위한 헤더파일
#include <conio.h> //getch를 사용하기 위한 헤더파일

//******************************컬러 사용하기 위한 Define 값 ******************************//

#define colorHandle GetStdHandle(STD_OUTPUT_HANDLE) //콘솔창의 핸들정보 받기
#define BLACK SetConsoleTextAttribute(colorHandle,0x0000); //검정색
#define GRAY SetConsoleTextAttribute(colorHandle,0x0007); //밝은 회색
#define RED SetConsoleTextAttribute(colorHandle,0x000c); //빨간색
#define BLUE SetConsoleTextAttribute(colorHandle,0x0001 | 0x0008); //파란색
#define WHITE SetConsoleTextAttribute(colorHandle,0x000f); //흰색
#define YEL SetConsoleTextAttribute(colorHandle,0x000e); //노란색
#define GREEN SetConsoleTextAttribute(colorHandle,0x0002); //녹색
#define VIO SetConsoleTextAttribute(colorHandle,0x0001 | 0x0008 |0x000c); //보라색


//****************************** 커서 숨기기 매크로 ******************************//

enum { HIDDEN, SHOW };


//****************************** 미로함수 방향키 아스키코드 값 ******************************//

#define LEFT 75 //LEFT 아스키코드 값을 75로 설정
#define RIGHT 77 //Right 아스키코드 값을 77로 설정
#define UP 72 //UP 아스키코드 값을 72로 설정 
#define DOWN 80 //DOWN 아스키코드 값을 80으로설정
#define Enter 13 //엔터 값
#define ESC 27 //ESC 값


//****************************** System 함수 ******************************//

void gotoxy(int, int); // x축 y축 이동시켜주는 함수
void delay(clock_t wait); //딜레이 함수 시간 몇초를 대기하여라.
void color(unsigned short color);//랜덤 컬러를 주기 위한 함수
void viewCursor(char show); //커서를 숨기거나 보여준다.


//****************************** 미로탈출게임 함수 ******************************//

void miro();          // 미로게임 메인함수
int miroGame();

int main() {
	miro(); //miro함수 호출
	return 0;
}

void miro() { //miro함수 정의
	int n; //변수설정
	n = miroGame(); //miro게임함수 호출 후 n에 대입
}

void gotoxy(int x, int y) { //gotoxy함수 정의
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
} //x축, y축 이동시켜주는 함수

void color(unsigned short color){ //color함수 정의
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, color);
}//무작위컬러 만들기위한함수

void viewCursor(char show) { //viewCursor함수 정의

	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;

	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
} //커서 숨기기 / 보이기

void delay(clock_t wait) {//delay함수 정의

	clock_t goal;
	goal = wait + clock();
	while (goal > clock());
} //wait ms 만큼 대기. 1000 = 1초

int miroGame() { //miroGame함수 정의
	struct MIRO { // MIRO구조체 선언
		int x, y; // 가로, 세로 좌표 값 멤버 설정
		int PlayN; // 블럭과 블럭을 구별하는 멤버 설정
	};

	struct MIRO Me, Mon[20], Pre[10]; //MIRO 구조체 변수 Me, Mon, Pre 선언
	static int Stage = 1, PreNum; //단계는 1. 하트의 갯수 설정
	static int i, j, k = 0, T = 0, b, c[20][2] = { 0 }, d[30] = { 0 };
	static int Screen[18][28] = { 0 }; //스크린화면
	int randNum[2] = { 0 };
	char ch; //키보드 입력 저장
	int Life = 3, LifeN, GameOver = 0; //목숨을 3개로 설정

	srand((unsigned int)time(NULL)); // * unsigned int (부호없는 정수) 로 캐스팅 해주시는것이 정석입니다. *

	system("mode con lines=20 cols=58"); // 창크기  
	system("cls"); 
	viewCursor(HIDDEN); // 커서 삭제
	system("cls"); 

	while (1) {
		randNum[0] = 0; //Mon이 움직일 수 있게 랜덤한 값을 담는 공간. 초기화
		randNum[1] = 0; //Mon이 움직일 때 방향(상, 하, 좌, 우)을 정하기 위해 랜덤한 값을 담는 공간. 초기화

		gotoxy(22, 9);
		printf("S t a g e %d", Stage);
		Sleep(3000);
		system("cls");

		b = rand() % 14 + 2; // 출구 생성을 위한 랜덤값 설정

		for (i = 0; i < Stage * 2; i++) {
			c[i][0] = rand() % 14 + 2;
			c[i][1] = rand() % 22 + 3;
		} // 맵 사이사이에 나타나는 벽 생성을 랜덤값 설정

		for (i = 0; i < 35; i++) {
			d[i] = rand() % 26 + 1;
		}

		Me.x = 7;
		Me.y = 1;
		Me.PlayN = 1; //Me 초기화


		for (i = 0; i < Stage * 2; i++) {
			Mon[i].x = c[i][0];
			Mon[i].y = c[i][1];
			Mon[i].PlayN = 10;
		} //Mon 초기화 


		for (i = 0; i < Stage; i++) {
			Pre[i].x = c[i][0];
			Pre[i].y = c[i][1] + 1;
			Pre[i].PlayN = 7;
		} //하트 초기화


		for (i = 0; i < 18; i++) {
			for (j = 0; j < 28; j++) {
				Screen[i][j] = 0;
			}
		} //화면 초기화
		k = 0;

		for (i = 0; i < 18; i++) { //게임화면에 벽을 생성하는 반복문
			for (j = 0; j < 28; j++) {
				if (i == 0 || i == 17)
					Screen[i][j] = 9;
				else if (j == 0 || j == 27)
					Screen[i][j] = 9;
			}
		}

		for (i = 1; i < 18; i++) { // 게임화면에 맵 사이사이에 벽을 추가하는 반복문
			for (j = 0; j < 28; j++) {
				if (d[k] == j) {
					Screen[i][j] = 9;
					k++;
				}
			}
		}

		Screen[b][26] = 0;
		Screen[b][27] = 0;
		// 출구 설정

		Screen[7][1] = 1;
		Screen[6][1] = 0;
		//사용자 위치 설정

		for (i = 0; i < Stage * 2; i++) { // 화면상의 장애물 위치 설정
			Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN;
		}

		for (i = 0; i < Stage; i++) { // 화면상의 하트 위치 설정
			Screen[Pre[i].x][Pre[i].y] = Pre[0].PlayN;
		}
	
		while (1) {
			PreNum = 0;

			for (i = 0; i < Stage * 2; i++) {
				randNum[0] = rand() % 15; // 15분의 1의 확률
				if (randNum[0] == 0) { // randNum[0]이 0일 때
					randNum[1] = rand() % 4;
					switch (randNum[1]) {
					case 0: // 왼쪽
						if (Screen[Mon[i].x][Mon[i].y - 1] != 9 && Screen[Mon[i].x][Mon[i].y - 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y - 1] != Pre[0].PlayN) {
							//움직이는 방향이 벽이 아니고, 다른 Mon이 아니고, 하트가 아닐 경우
							Screen[Mon[i].x][Mon[i].y] = 0; //현재 위치 삭제
							Mon[i].y -= 1; //이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //해당위치에 사용자가 있을 때
								Me.PlayN = 99; //사용자 죽음
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; // 게임화면 갱신
						break; //종료
					case 1: // 오른쪽
						if (Screen[Mon[i].x][Mon[i].y + 1] != 9 && Screen[Mon[i].x][Mon[i].y + 1] != Mon[i].PlayN && Screen[Mon[i].x][Mon[i].y + 1] != Pre[0].PlayN) {
							//움직이는 방향이 벽이 아니고, 다른 Mon이 아니고, 하트가 아닐 경우
							Screen[Mon[i].x][Mon[i].y] = 0; //현재 위치 삭제
							Mon[i].y += 1; //이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //해당위치에 사용자가 있을 때
								Me.PlayN = 99; //사용자 죽음
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; //게임화면 갱신
						break; //종료

					case 2: //위쪽
						if (Screen[Mon[i].x - 1][Mon[i].y] != 9 && Screen[Mon[i].x - 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x - 1][Mon[i].y] != Pre[0].PlayN) {
							//움직이는 방향이 벽이 아니고, 다른 Mon이 아니고, 하트가 아닐 경우
							Screen[Mon[i].x][Mon[i].y] = 0; //현재 위치 삭제
							Mon[i].x -= 1; //이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //해당위치에 사용자가 있을 때
								Me.PlayN = 99; //사용자 죽음
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; //게임화면 갱신
						break; //종료
					case 3: //아래쪽
						if (Screen[Mon[i].x + 1][Mon[i].y] != 9 && Screen[Mon[i].x + 1][Mon[i].y] != Mon[i].PlayN && Screen[Mon[i].x + 1][Mon[i].y] != Pre[0].PlayN) {
							//움직이는 방향이 벽이 아니고, 다른 Mon이 아니고, 하트가 아닐 경우
							Screen[Mon[i].x][Mon[i].y] = 0; //현재 위치 삭제
							Mon[i].x += 1; //이동
							if (Screen[Mon[i].x][Mon[i].y] == Me.PlayN) //해당위치에 사용자가 있을 때
								Me.PlayN = 99; //시용자 죽음
						}
						Screen[Mon[i].x][Mon[i].y] = Mon[0].PlayN; //게임화면 갱신
						break; //종료
					}
				}
			}

			for (i = 0; i < 18; i++) { //게임화면 상태에 따라 맞게 출력
				gotoxy(1, i + 1);
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == 0) {
						BLACK;
						printf("★"); //BLACK에 해당하는 모양 출력
					}
					else if (Screen[i][j] == Me.PlayN) {
						RED;
						printf("☆"); //RED에 해당하는 모양 출력
					}
					else if (Screen[i][j] == 9) {
						WHITE;
						printf("■"); //WHITE에 해당하는 모양 출력
					}
					else if (Screen[i][j] == Mon[0].PlayN) {
						VIO;
						printf("◆"); //VIO에 해당하는 모양 출력
					}
					else if (Screen[i][j] == Pre[0].PlayN) {
						YEL;
						printf("♡"); //YEL에 해당하는 모양 출력
					}
				}
				printf("\n"); //줄바꿈
			}


			if (_kbhit()) { //키를 입력 받음
				ch = _getch();
				switch (ch) {
				case 75: // 좌
					if (Screen[Me.x][Me.y - 1] != 9 && Screen[Me.x][Me.y - 1] != Me.PlayN) {
						Screen[Me.x][Me.y] = 0;
						Me.y -= 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) // 장애물에 부딫히면 죽음
							Me.PlayN = 99;
						if (Screen[Me.x][Me.y] == Pre[0].PlayN) // 하트를 먹었을 때
							PreNum--;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break;
				case 77: // 우
					if (Screen[Me.x][Me.y + 1] != 9 && Screen[Me.x][Me.y + 1] != Me.PlayN) {
						Screen[Me.x][Me.y] = 0;
						Me.y += 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) // 장애물에 부딫히면 죽음
							Me.PlayN = 99;
						if (Screen[Me.x][Me.y] == Pre[0].PlayN) // 하트를 먹었을 때
							PreNum--;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break;
				case 72: // 상
					if (Screen[Me.x - 1][Me.y] != 9 && Screen[Me.x - 1][Me.y] != Me.PlayN) {
						Screen[Me.x][Me.y] = 0;
						Me.x -= 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) // 장애물에 부딫히면 죽음
							Me.PlayN = 99;
						if (Screen[Me.x][Me.y] == Pre[0].PlayN) // 하트를 먹었을 때
							PreNum--;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break;
				case 80: // 하
					if (Screen[Me.x + 1][Me.y] != 9 && Screen[Me.x + 1][Me.y] != Me.PlayN) {
						Screen[Me.x][Me.y] = 0;
						Me.x += 1;
						if (Screen[Me.x][Me.y] == Mon[0].PlayN) // 장애물에 부딫히면 죽음
							Me.PlayN = 99;
						if (Screen[Me.x][Me.y] == Pre[0].PlayN) // 하트를 먹었을 때
							PreNum--;
					}
					Screen[Me.x][Me.y] = Me.PlayN;
					break;
				case ESC: break; // ESC 누를 때
				}
			}
			if (ch == ESC) break;

			LifeN = Life;
			if (Me.PlayN == 99) { //현재 스테이지를 다시 시작함
				Life -= 1;
				break;
			}

			for (i = 0; i < 18; i++) { //먹을 하트의 갯수를 세는 반복문
				for (j = 0; j < 28; j++) {
					if (Screen[i][j] == Pre[0].PlayN)
						PreNum++;
				}
			}
		
			if (PreNum == 0) { // 하트를 다먹고 출구에 도착했을 때
				if (Me.y == 27) 
					break;
			}
		}
			if (ch == ESC) break; //ESC눌렀을 때

			if (Life != 0 && Stage != 11){ //생명이 0이 아니거나 11Stage까지 못도달했을 경우 
				if (LifeN == Life) {
					Stage += 1;
					system("cls");
					gotoxy(16, 9);
					printf("S t a g e   C l e a r !!");
					Sleep(3000);
					system("cls");
				} //1Stage를 성공할 때마다 Stage Clear!
				else { //Game Over!
					gotoxy(19, 10);
					printf("G a m e   o v e R ! !");
					Sleep(3000);
					system("cls");
					gotoxy(22, 9);
					RED;
					printf("☆");
					gotoxy(26, 9);
					WHITE;
					printf(" =    %d", Life);
					Sleep(3000);
					system("cls");
					GRAY;
				}
			}
			if (Life == 0){ //생명이 0일 때 GaMeoVeR!
				gotoxy(19, 9);
				printf("G a M e o V e R ! !");
				Sleep(3000);
				system("cls");
				break;
			}
			else if (Stage == 11){ //11Stage까지 모두 클리어했을 때
				system("cls");
				WHITE;
				gotoxy(14, 9);
				printf("C o n g r a t u l a t i o n ");
				Sleep(3000);
				system("cls");
				gotoxy(19, 9);
				printf("T h e E n d ! !");
				Sleep(4000);
				GRAY;
				break;
			} //Congratulation & The End!
		}
		return 0;
	}
