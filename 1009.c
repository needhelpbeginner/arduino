/*�̸�:20240411 �����
* �ۼ���:2024 10 09
���α׷���: */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//�⺻ ����ü ����ϱ�
/*
struct student {
	int number;
	char name[10];
	double grade;
};
int main(void) {
	struct student s;

	printf("�й��� �Է��Ͻÿ�: ");
	scanf("%d", &s.number);
	printf("�̸��� �Է��Ͻÿ�: ");
	scanf("%s", s.name);
	printf("������ �Է��Ͻÿ�: ");
	scanf("%lf", &s.grade);

	printf("�й�:% d\n", s.number);
	printf("�̸�:%s\n", s.name);
	printf("����:%.2lf", s.grade);
	return 0;
}
*/

//�迭�� �Է¹ް� ����ϱ�
/*
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
struct student {
	int number;
	char name[10];
	double grade;
};
int main(void) {
	struct student s[5];

	for (int i = 0; i < 5; i++) {
		printf("�й��� �Է����ּ���:");
		scanf("%d", &s[i].number);
		printf("�̸��� �Է����ּ���:");
		scanf("%s", s[i].name);
		printf("������ �Է����ּ���:");
		scanf("%lf", &s[i].grade);
		printf("\n");
	}


	for (int i = 0; i < 5; i++) {
		printf("�й�:%d\n", s[i].number);
		printf("�̸�:%s\n", s[i].name);
		printf("����:%.2lf\n", s[i].grade);
		printf("\n");
	}

	return 0;
}
*/

//�� �� ������ �Ÿ�
/*
#include<stdio.h>
#include <math.h>
struct point {
	int x1, y1, x2, y2;
};
int main(void) {
	struct point p;
	printf("���� ��ǥ�� �Է��Ͻÿ�(x1,y1):");
	scanf("%d %d", &p.x1, &p.y1);
	printf("���� ��ǥ�� �Է��Ͻÿ�(x2,y2):");
	scanf("%d %d", &p.x2, &p.y2);

	double dis = sqrt((double)(p.x2 - p.x1) * (p.x2 - p.x1) + (p.y2 - p.y1) * (p.y2 - p.y1));
	printf("�� �� ������ �Ÿ��� %.2lf�Դϴ�.",dis);

	return 0;

}
*/

//2���� �Է¹޾Ƽ� �簢�� ���� ���ϱ�
/*
struct point {
	int x1, y1, x2, y2;
};
int main(void) {
	struct point p;

	printf("���� ��ǥ�� �Է��Ͻÿ�(x1,y1):");
	scanf("%d %d", &p.x1, &p.y1);
	printf("���� ��ǥ�� �Է��Ͻÿ�(x2,y2):");
	scanf("%d %d", &p.x2, &p.y2);

	int mit_x = (p.x2 - p.x1);
	int mit_y = (p.y2 - p.y1);

	double s = mit_x * mit_y;
	printf("�簢���� ���̴� %.2lf�Դϴ�.", s);

	return 0;
}
*/

//4���� �Է¹޾Ƽ� �簢�� �ѷ� ���ϱ�
/*
#include <math.h>
struct point {
	int x1, y1, x2, y2, x3, y3, x4, y4;
};
double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main(void) {
	struct point p;

	printf("ex) x1 <= x2 ������ ���� ���� �ͺ��� �Է����ּ���.\n");

	printf("���� ��ǥ�� �Է��Ͻÿ� (x1,y1): ");
	scanf("%d %d", &p.x1, &p.y1);
	printf("���� ��ǥ�� �Է��Ͻÿ� (x2,y2): ");
	scanf("%d %d", &p.x2, &p.y2);
	printf("���� ��ǥ�� �Է��Ͻÿ� (x3,y3): ");
	scanf("%d %d", &p.x3, &p.y3);
	printf("���� ��ǥ�� �Է��Ͻÿ� (x4,y4): ");
	scanf("%d %d", &p.x4, &p.y4);

	double dule = distance(p.x1, p.y1, p.x2, p.y2) + //dule�� �ѷ�
		distance(p.x2, p.y2, p.x3, p.y3) +
		distance(p.x3, p.y3, p.x4, p.y4) +
		distance(p.x4, p.y4, p.x1, p.y1);

	printf("�簢���� �ѷ��� %.2lf�Դϴ�.\n", dule);

	return 0;
}
*/

//587p 8��

#define PI 3.141592
struct point {
	int x, y;
};
struct circle {
	struct point center;
	double radius;
};
double area(struct circle c);
double dul(struct circle c); // dul�� �ѷ�

int main(void) {
	struct circle c;

	printf("���� �߽� ��ǥ (x, y)�� �Է��ϼ���: ");
	scanf("%d %d", &c.center.x, &c.center.y);
	printf("���� �������� �Է��ϼ���: ");
	scanf("%lf", &c.radius);

	
	printf("���� ����: %.2lf\n", area(c));  //(c)�� c.center.x�� c.center.y�� c.radius��� ����ü�� �����Ѵ�
	printf("���� �ѷ�: %.2lf\n", dul(c));

	return 0;
}

double area(struct circle c) {
	return c.radius * c.radius * PI; 
}

double dul(struct circle c) {
	return c.radius * 2 * PI; 
}


//7��
/*
struct point {
	int x1, y1;
};
int main(void) {
	struct point p;

	printf("(x1, y1)�� �Է����ּ���: ");
	scanf("%d %d", &p.x1, &p.y1);

	if (p.x1 > 0 && p.y1 > 0) { printf("(%d,%d)�� ��и� = 1\n", p.x1, p.y1); }
	else if (p.x1 < 0 && p.y1 > 0) { printf("(%d,%d)�� ��и� = 2\n", p.x1, p.y1); }
	else if (p.x1 < 0 && p.y1 < 0) { printf("(%d,%d)�� ��и� = 3\n", p.x1, p.y1); }
	else { printf("(%d,%d)�� ��и� = 4", p.x1, p.y1); }
}
*/
printf("hello world");