/*���������� ����
10.30��*/
//����������
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
//�����͹迭
/*
int main(void) {
	char* f[4] = {"apple","grape","watermelon","tangerine"};
	int size = sizeof(f) / sizeof(f[0]);//��� ����=sizeof(��ü)/sizeof(�����͹迭��[0])
	for (int i = 0; i < size; i++) {
		printf("%s\n", f[i]);//[i]
	}
	return 0;
}*/
//4Ģ�����ϴµ� ��ȯ�� ����, ���ø޴��� 1���� ����.
//��������1.36���� �Լ������͹迭�ʱ�ȭ�� ù �࿡,
// ={}���� �ٷ� �ʱ�ȭ���ֱ� else int (*pf[4])(int, int);�ϰ� pf[0]=add;�ϳ���
//2.while�� ����,if�� �� break;�߰�
//3.��ȯ�� �ľ�
//4.�Լ� ȣ�� �� [�ε���!!!] ex)pf[choice](a,b);
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
		printf("1.����\n2.����\n3.����\n4.������\n5.����\n");
		printf("=========================\n");

		printf("�޴��� �����Ͻÿ�: ");
		scanf("%d", &menu);
		if (menu < 1 || menu >= 5) {
			break;
		}
		printf("�� ���� ���� �Է�: ");
		scanf("%d %d", &a, &b);
		pf[menu-1](a, b);//!!�迭�� ȣ���� ���� �־���Ѵ�!!!
	}
}
void add(int a, int b) {printf("����� %d�Դϴ�.", a + b);}
void sub(int a, int b){ printf("����� %d�Դϴ�.", a - b); }
void mul(int a, int b){ printf("����� %d�Դϴ�.", a * b); }
void div(int a, int b){ printf("����� %d�Դϴ�.", a / b); }
*/
//626p 8��
//i�� j�� ���� 
/*
#include<string.h>
void sort(char* s[], int size);
int main(void) {
	char* s[3] = { "mycopy","src","dst" };
	
	sort(s, 3);
	printf("������: \n");
	for (int k = 0; k < 3; k++) {
		printf("%s\n", s[k]);
	}
	return 0;
}
void sort(char* s[], int size){
	char* temp;
	int least, i, j;
	for (i = 0; i < size - 1; i++) {  //i�� ó������ ������-1  �ٵ� 3�� ���⺸�� size�� ����!
		least = i;
		for (j = i + 1; j < size; j++) { //j�� ó��(i)+1����, <�迭ũ��
			if (strcmp(s[j], s[least]) < 0) {
				least = j;
			}
		}
		temp = s[i];
		s[i] = s[least];
		s[least] = temp;
	}
}*/
//sum�� ������
/*
int main(void) {
	int m[3][3] = { {10, 20, 30}, {40, 50, 60}, {70, 80, 90} };

	for (int i = 0; i < 3; i++) {
		int sum = 0;//sum�� ������ �����Ѵٸ� i�ݺ�����
		for (int j = 0; j < 3; j++) {
			printf("%d ", m[i][j]);  
			sum += m[i][j]; 
		}
		printf("%d\n", sum);  //\n�� ��� ������ ������ ���
	}
	return 0;
}
*/
//���� �� ���
/*
int f(int list[], int n);
int main(void) {
	int a[3][3] = { {10,20,30},{40,50,60},{70,80,90} };
	
	for (int i = 0; i < 3; i++) {
		f(a[i], 3);
		printf("%d���� ����:  %d\n", i, f(a[i], 3));
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
//4��->�� ��ü �� ���
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
	printf("������ �� = %d", allsum);
	return 0;
}
int get(int array[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++) {
		sum += array[i];
	}
	return sum;
}*/
//7�� �����ϱ�
/*
void f(int m[], int size, int** max);
int main(void) {
	int m[6] = { 5,6,1,3,7,9 };
	int* p;
	f(m, 6, &p); //������p�� �����߱⶧���� &p
	//���⼭ �ִ� ����ҰŸ� *p�� �ؾ� ��.
	return 0;
}
void f(int m[], int size, int** max) {
	*max = &m[0];// &m[0]-> **max�� ����Ű�� ������(*max)**�� m[0]�� �ּҸ� ����
	//**max=m[0];�� ����ġ.
	for (int i = 1; i < size; i++) {
		if (m[i] > m[0]) {
			*max = &m[i];// &m[i]
		}
	}
	printf("���� ū ���� %d�Դϴ�", **max);//**�� ����->���� �� �������
}*/
//9��
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

	image(m);  // �Լ� ȣ��

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

	image(m);  // �Լ� ȣ��

	return 0;
}
void image(int a[][5]) {
	int* p = &a[0][0];
	int* endp = &a[4][4];

	while (p <= endp) {// ������ p�� �迭�� ������ ��ȸ�ϱ� ���� ����
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
//10��
/*
void copy(int ori[][3], int cop[][3]);
int main(void) {
	int a[3][3] = { {100,30,67},{89,50,12},{19,60,90} };
	int b[3][3] = { 0 };
	copy(a,b);//�Լ� ȣ��� �迭�� �̸��� ���
	//=copy(&a[0][0], &b[0][0]);
	printf("����\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("���纻\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}	
	return 0;
}
void copy(int ori[][3], int cop[][3]) {
		int* p_ori = (int*)ori;  //1���� �迭 �����ͷ� ��ȯ�ϴ� ����
		int* p_cop = (int*)cop;  

		for (int i = 0; i < 9; i++) {  // 3x3 �迭�̹Ƿ� �� 9���� ���Ұ� ����
			*(p_cop + i) = *(p_ori + i);  // ������ ����� ����Ͽ� �� ����
		}
	}*/