/*이중포인터 복습
10.30일*/
//이중포인터
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
/*
int main(void) {
	int i = 100;
	int* p;
	int** q;
	p = &i;
	*p = 200;
	printf("%d\n", *p);
	q = &p;//int**q=&p;
	**q = 300;
	printf("%d\n", **q);
	return 0;
}*/
//포인터배열
/*
int main(void) {
	char* f[4] = {"apple","grape","watermelon","tangerine"};
	int size = sizeof(f) / sizeof(f[0]);//요소 개수=sizeof(전체)/sizeof(포인터배열명[0])
	for (int i = 0; i < size; i++) {
		printf("%s\n", f[i]);//[i]
	}
	return 0;
}*/
//4칙연산하는데 반환값 없고, 선택메뉴는 1부터 시작.
//주의할점1.36번행 함수포인터배열초기화는 첫 행에,
// ={}으로 바로 초기화해주기 else int (*pf[4])(int, int);하고 pf[0]=add;하나씩
//2.while문 쓰기,if문 에 break;추가
//3.반환형 파악
//4.함수 호출 시 [인덱스!!!] ex)pf[choice](a,b);
/*
void add(int a, int b);
void sub(int a, int b);
void mul(int a, int b);
void div(int a, int b);
int main(void) {
	int (*pf[4])(int, int) = { add,sub,mul,div };
	int menu,a,b;
	while (1) {
		printf("=========================\n");
		printf("1.덧셈\n2.뺄셈\n3.곱셈\n4.나눗셈\n5.종료\n");
		printf("=========================\n");

		printf("메뉴를 선택하시오: ");
		scanf("%d", &menu);
		if (menu < 1 || menu >= 5) {
			break;
		}
		printf("두 개의 정수 입력: ");
		scanf("%d %d", &a, &b);
		pf[menu-1](a, b);//!!배열이 호출할 때도 있어야한다!!!
	}
}
void add(int a, int b) {printf("결과는 %d입니다.", a + b);}
void sub(int a, int b){ printf("결과는 %d입니다.", a - b); }
void mul(int a, int b){ printf("결과는 %d입니다.", a * b); }
void div(int a, int b){ printf("결과는 %d입니다.", a / b); }
*/
//626p 8번
//i와 j의 범위 
/*
#include<string.h>
void sort(char* s[], int size);
int main(void) {
	char* s[3] = { "mycopy","src","dst" };
	
	sort(s, 3);
	printf("정렬후: \n");
	for (int k = 0; k < 3; k++) {
		printf("%s\n", s[k]);
	}
	return 0;
}
void sort(char* s[], int size){
	char* temp;
	int least, i, j;
	for (i = 0; i < size - 1; i++) {  //i는 처음부터 마지막-1  근데 3을 쓰기보단 size로 쓰기!
		least = i;
		for (j = i + 1; j < size; j++) { //j는 처음(i)+1부터, <배열크기
			if (strcmp(s[j], s[least]) < 0) {
				least = j;
			}
		}
		temp = s[i];
		s[i] = s[least];
		s[least] = temp;
	}
}*/
//sum을 변수로
/*
int main(void) {
	int m[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };

	for (int i = 0; i < 3; i++) {
		int sum = 0;//sum을 변수로 선언한다면 i반복문에
		for (int j = 0; j < 3; j++) {
			printf("%d ", m[i][j]);  
			sum += m[i][j]; 
		}
		printf("%d\n", sum);  //\n을 썼기 때문에 다음줄 출력
	}
	return 0;
}
*/
//행의 합 출력
/*
int f(int list[], int n);
int main(void) {
	int a[3][3] = { {10,20,30},{40,50,60},{70,80,90} };
	
	for (int i = 0; i < 3; i++) {
		f(a[i], 3);
		printf("%d행의 총합:  %d\n", i, f(a[i], 3));
	}
	return 0;
}
int f(int list[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum +=*( list+i);
	}
	return sum;
}*/
//4번->행 전체 합 출력
/*
int get(int array[], int size);
int main(void) {
	int a[3][6] = {
		{10, 10, 10, 10, 10, 10},
		{10, 10, 10, 10, 10, 10},
		{10, 10, 10, 10, 10, 10}
	};
	int allsum = 0;

	for (int i = 0; i < 3; i++) {
		allsum += get(a[i], 6);
	}
	printf("정수의 합 = %d", allsum);
	return 0;
}
int get(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}*/
//7번 복습하기
/*
void f(int m[], int size, int** max);
int main(void) {
	int m[6] = { 5,6,1,3,7,9 };
	int* p;
	f(m, 6, &p); //포인터p로 선언했기때문에 &p
	//여기서 최댓값 출력할거면 *p로 해야 함.
	return 0;
}
void f(int m[], int size, int** max) {
	*max = &m[0];// &m[0]-> **max가 가리키는 포인터(*max)**에 m[0]의 주소를 저장
	//**max=m[0];뜻 불일치.
	for (int i = 1; i < size; i++) {
		if (m[i] > m[0]) {
			*max = &m[i];// &m[i]
		}
	}
	printf("가장 큰 수는 %d입니다", **max);//**인 이유->실제 값 출력위해
}*/
//9번
/*
void image(int a[][5]);
int main(void)
{
	int m[5][5] = {
		{  130, 0, 0, 0, 0 },
		{ 0, 0, 0, 130, 130 },
		{ 0, 0, 130, 0, 130},
		{ 0, 0, 0, 130, 130 },
		{ 0, 0, 130, 0, 130}
	};

	image(m);  // 함수 호출

	return 0;
}
void image(int a[][5]);
int main(void)
{
	int m[5][5] = {
		{  130, 0, 0, 0, 0 },
		{ 0, 0, 0, 130, 130 },
		{ 0, 0, 130, 0, 130},
		{ 0, 0, 0, 130, 130 },
		{ 0, 0, 130, 0, 130}
	};

	image(m);  // 함수 호출

	return 0;
}
void image(int a[][5]) {
	int* p = &a[0][0];
	int* endp = &a[4][4];

	while (p <= endp) {// 포인터 p가 배열의 끝까지 순회하기 위한 조건
		if (*p < 128) {
			*p = 0;
			p++;
		}
		else if (*p >= 128) {
			*p = 255;
			p++;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}*/
//10번
/*
void copy(int ori[][3], int cop[][3]);
int main(void) {
	int a[3][3] = { {100,30,67},{89,50,12},{19,60,90} };
	int b[3][3] = { 0 };
	copy(a,b);//함수 호출시 배열의 이름을 사용
	//=copy(&a[0][0], &b[0][0]);
	printf("원본\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("복사본\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
void copy(int ori[][3], int cop[][3]) {
		int* p_ori = (int*)ori;  //1차원 배열 포인터로 변환하는 과정
		int* p_cop = (int*)cop;  

		for (int i = 0; i < 9; i++) {  // 3x3 배열이므로 총 9개의 원소가 있음
			*(p_cop + i) = *(p_ori + i);  // 포인터 산술을 사용하여 값 복사
		}
	}*/