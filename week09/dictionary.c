#include <stdio.h>
#include <string.h>

int input_intro(char(*intro)[80]); // int input_intro 함수 선언 
void init_intro(char(*intro)[80], char **intp); // void init_intro 함수 선언
void sort_intro(char **intp, int cnt); // void sort_intro 함수 선언
void print_intro(int mode, void *vp, int cnt); // void print_intro 함수 선언
int assign03(void); //int assign03 함수 선언

int main(){
	char intro[10][80];
	char *intp[10];
	int cnt;

	init_intro(intro, intp); //init_intro 함수 호출
	cnt = input_intro(intro); //cnt 변수 정의
	sort_intro(intp, cnt); //sort_intro 함수 호출
	print_intro(1, intp, cnt); //print_intro 함수 호출
	print_intro(0, intro, cnt); //print_intro 함수 호출

	return 0;
}
int input_intro(char(*intro)[80]){ //int input_intro 함수 정의
	int p = 0;

	for (int i = 0;; i++){ // 문장입력 반복문
		printf("> 문장 입력 : ");
		scanf("%s", intro[i]);

		if (strcmp(intro[i], "end") == 0){ // end를 입력하면 종료
			printf("종료\n");
			break;
		}
		p++;
	}
	return p;
} //문장을 입력받음

void init_intro(char(*intro)[80], char **intp){ //void init_intro 함수 정의
	for (int i = 0; i < 10; i++){
		intp[i] = intro[i];
	}
} //전달받은 intro를 intp로 복사

void sort_intro(char **intp, int cnt){ //void sort_intro 함수 정의
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
} //사전순으로 정렬

void print_intro(int mode, void *vp, int cnt){ //void print_intro 함수 정의
	if (mode == 1) { // mode가 1일 떄 사전순으로 출력
		char **p = (char**)vp;
		printf("사전순으로 출력... : \n");

		for (int i = 0; i < cnt; i++) {
			printf("%s\n", p[i]);
		}
	}

	if (mode == 0){ // mode가 0일 때 입력순으로 출력
		char(*q)[80] = (char**)vp;
		printf("입력순으로 출력...\n");

		for (int i = 0; i < cnt; i++){
			printf("%s\n", q[i]);
		}
	}
}