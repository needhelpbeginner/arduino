/*이름:20240411 김민재
* 작성일:2024 10 09
프로그램명: */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

//기본 구조체 출력하기
/*
struct student {
	int number;
	char name[10];
	double grade;
};
int main(void) {
	struct student s;

	printf("학번을 입력하시오: ");
	scanf("%d", &s.number);
	printf("이름을 입력하시오: ");
	scanf("%s", s.name);
	printf("학점을 입력하시오: ");
	scanf("%lf", &s.grade);

	printf("학번:% d\n", s.number);
	printf("이름:%s\n", s.name);
	printf("학점:%.2lf", s.grade);
	return 0;
}
*/

//배열로 입력받고 출력하기
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
		printf("학번을 입력해주세요:");
		scanf("%d", &s[i].number);
		printf("이름을 입력해주세요:");
		scanf("%s", s[i].name);
		printf("학점을 입력해주세요:");
		scanf("%lf", &s[i].grade);
		printf("\n");
	}


	for (int i = 0; i < 5; i++) {
		printf("학번:%d\n", s[i].number);
		printf("이름:%s\n", s[i].name);
		printf("학점:%.2lf\n", s[i].grade);
		printf("\n");
	}

	return 0;
}
*/

//두 점 사이의 거리
/*
#include<stdio.h>
#include <math.h>
struct point {
	int x1, y1, x2, y2;
};
int main(void) {
	struct point p;
	printf("점의 좌표를 입력하시오(x1,y1):");
	scanf("%d %d", &p.x1, &p.y1);
	printf("점의 좌표를 입력하시오(x2,y2):");
	scanf("%d %d", &p.x2, &p.y2);

	double dis = sqrt((double)(p.x2 - p.x1) * (p.x2 - p.x1) + (p.y2 - p.y1) * (p.y2 - p.y1));
	printf("두 점 사이의 거리는 %.2lf입니다.",dis);

	return 0;

}
*/

//2점을 입력받아서 사각형 넓이 구하기
/*
struct point {
	int x1, y1, x2, y2;
};
int main(void) {
	struct point p;

	printf("점의 좌표를 입력하시오(x1,y1):");
	scanf("%d %d", &p.x1, &p.y1);
	printf("점의 좌표를 입력하시오(x2,y2):");
	scanf("%d %d", &p.x2, &p.y2);

	int mit_x = (p.x2 - p.x1);
	int mit_y = (p.y2 - p.y1);

	double s = mit_x * mit_y;
	printf("사각형의 넓이는 %.2lf입니다.", s);

	return 0;
}
*/

//4점을 입력받아서 사각형 둘레 구하기
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

	printf("ex) x1 <= x2 순서로 값이 작은 것부터 입력해주세요.\n");

	printf("점의 좌표를 입력하시오 (x1,y1): ");
	scanf("%d %d", &p.x1, &p.y1);
	printf("점의 좌표를 입력하시오 (x2,y2): ");
	scanf("%d %d", &p.x2, &p.y2);
	printf("점의 좌표를 입력하시오 (x3,y3): ");
	scanf("%d %d", &p.x3, &p.y3);
	printf("점의 좌표를 입력하시오 (x4,y4): ");
	scanf("%d %d", &p.x4, &p.y4);

	double dule = distance(p.x1, p.y1, p.x2, p.y2) + //dule는 둘레
		distance(p.x2, p.y2, p.x3, p.y3) +
		distance(p.x3, p.y3, p.x4, p.y4) +
		distance(p.x4, p.y4, p.x1, p.y1);

	printf("사각형의 둘레는 %.2lf입니다.\n", dule);

	return 0;
}
*/

//587p 8번

#define PI 3.141592
struct point {
	int x, y;
};
struct circle {
	struct point center;
	double radius;
};
double area(struct circle c);
double dul(struct circle c); // dul은 둘레

int main(void) {
	struct circle c;

	printf("원의 중심 좌표 (x, y)를 입력하세요: ");
	scanf("%d %d", &c.center.x, &c.center.y);
	printf("원의 반지름을 입력하세요: ");
	scanf("%lf", &c.radius);

	
	printf("원의 면적: %.2lf\n", area(c));  //(c)는 c.center.x와 c.center.y와 c.radius라는 구조체를 포함한다
	printf("원의 둘레: %.2lf\n", dul(c));

	return 0;
}

double area(struct circle c) {
	return c.radius * c.radius * PI; 
}

double dul(struct circle c) {
	return c.radius * 2 * PI; 
}


//7번
/*
struct point {
	int x1, y1;
};
int main(void) {
	struct point p;

	printf("(x1, y1)을 입력해주세요: ");
	scanf("%d %d", &p.x1, &p.y1);

	if (p.x1 > 0 && p.y1 > 0) { printf("(%d,%d)의 사분면 = 1\n", p.x1, p.y1); }
	else if (p.x1 < 0 && p.y1 > 0) { printf("(%d,%d)의 사분면 = 2\n", p.x1, p.y1); }
	else if (p.x1 < 0 && p.y1 < 0) { printf("(%d,%d)의 사분면 = 3\n", p.x1, p.y1); }
	else { printf("(%d,%d)의 사분면 = 4", p.x1, p.y1); }
}
*/
printf("hello world");