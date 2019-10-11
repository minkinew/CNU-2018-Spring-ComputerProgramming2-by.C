#include<stdio.h>

int main(void)
{
	printf("나는 컴퓨터공학과 2학년이고 .\n");    //학년을 출력
	printf("학번은 201502023이다. .\n");          //학번을 출력
	//실습1


	int grade = 2;                                //정수형으로 학년을 설정하는 변수
	int Student_Number = 201502023;               //정수형으로 학번을 설정하는 변수

	printf("나는 컴퓨터공학과 %d 학년이고 \n", grade);  //학년을 출력.(%d는 정수를 뜻함.)
	printf("학번은 %d 이다.  \n", Student_Number);      //학번을 출력.(%d는 정수를 뜻함.)
    //실습2



	int front = 10;           //정수형으로 첫번째 변수를 설정
	int rear = 5;             //정수형으로 두번쨰 변수를 설정
	
	printf("a + b = %d \n", front + rear);   //첫번째 변수와 두번째 변수를 더하기하라. (%d는 정수를 뜻함)
	printf("a - b = %d \n", front - rear);   //첫번째 변수와 두번째 변수를 뺄셈하라. (%d는 정수를 뜻함)
	printf("a * b = %d \n", front * rear);   //첫번째 변수와 두번째 변수를 곱셈하라. (%d는 정수를 뜻함)
	printf("a / b = %d \n", front / rear);   //첫번째 변수와 두번째 변수를 나눗셈하라. (%d는 정수를 뜻함)
	//실습3
	
	
	int frontInt = 10;   // 정수형으로 첫번째 변수를 10으로 설정
	int rearInt = 15;    // 정수형으로 두번쨰 변수를 15로 설정
 	float frontFloat = 10.0F;  // 실수형으로 첫번째 변수를 10으로 설정
  	float rearFloat = 15.0F;   // 실수형으로 두번쨰 변수를 15로 설정
	
	printf("a + b = %d \n", frontInt + rearInt);  //첫번째 변수와 두번쨰 변수를 더하기하라 (%d는 정수를 뜻함)
	printf("a - b = %d \n", frontInt - rearInt);  //첫번째 변수와 두번쨰 변수를 뺄셈하라 (%d는 정수를 뜻함)
	printf("a * b = %d \n", frontInt * rearInt);  //첫번째 변수와 두번쨰 변수를 곱셈하라 (%d는 정수를 뜻함)
	printf("a / b = %d \n", frontInt / rearInt);  //첫번째 변수와 두번쨰 변수를 나눗셈하라 (%d는 정수를 뜻함)
	printf("c + d = %f \n", frontFloat + rearFloat);  //첫번째 변수와 두번쨰 변수를 더하기하라 (%f는 실수를 뜻함)
	printf("c - d = %f \n", frontFloat - rearFloat);  //첫번째 변수와 두번쨰 변수를 뺄셈하라 (%f는 실수를 뜻함)
	printf("c * d = %f \n", frontFloat * rearFloat);  //첫번째 변수와 두번쨰 변수를 곱셈하라 (%f는 실수를 뜻함)
	printf("c / d = %f \n", frontFloat / rearFloat);  //첫번째 변수와 두번쨰 변수를 나눗셈하라 (%f는 실수를 뜻함))
	//실습4


	int a = 20;  // 정수형으로 a 변수를 20으로 설정
	int	b = 30;  // 정수형으로 b 변수를 30으로 설정
	float p = 3.14F; //실수형으로 p변수를 3.14로 설정
	float q = 4.2F;  //실수형으로 q변수를 4.2로 설정
	double m = 7.23; //실수형으로 m변수를 7.23으로 설정
	double n = 1.2;  //실수형으로 n변수를 1.2로 설정


	int x = 0; //정수형으로 x변수를 0으로 설정
	x = x + 10;//x에 대한 일차방정식(x값에 10을 더하라)
	printf(" x = %d", x); //x값을 출력(%d는 정수를 뜻함)
	
	printf(" a = %d 이고 b = %d \n", a, b); //a와 b를 나타내는 출력문
	printf(" p = %f 이고 q = %f \n", p, q); //p와 q를 나타내는 출력문
	printf(" m = %1f 이고 n = %lf \n\n", m, n); //m과 n을 나타내는 출력문
	printf("\tb / a -> %d\n", b / a); // b를 a로 나눗셈하라 (%d는 정수를 뜻함)
	printf("\tb / a -> %f\n", b / a); // b를 a로 나눗셈하라 (%f는 실수를 뜻함)
	printf("\tp - q -> %f\n", p - q); // p에서 q를 뺄셈하라 (%f는 실수를 뜻함)
	printf("\tm * n -> %lf\n\n", m * n); //m곱하기 n을 하라 (%f는 실수를 뜻함)
	//실습5,

	return 0;
}
