#include <stdio.h>

int main(){
	int distance, speed, hour, min; //시간, 속도, 시간, 분 변수설정
	double sec, getTime; //초, getTime 변수 설정
    
	printf("거리와 속력을 입력하시오 : \n");
	scanf("%d %d", &distance, &speed);
	
	getTime = (double)distance / (double)speed; //거리와 속력을 시간에 대한 식으로 변환

	hour = (int)getTime;  //정수형으로 변환해 시간만 계산
	getTime = getTime - hour;
	getTime = getTime * 60.0;
	min = (int)getTime; //정수형으로 변환해 분만 환산
	getTime = getTime - min;
	getTime = getTime * 60.0;
	sec = (double)getTime; //실수형으로 변환해 초 환산

	printf("소요시간은 %d시간 %d분 %.3lf초입니다. \n", hour, min, sec);
	
}