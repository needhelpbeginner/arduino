/*작성자: 20240411 김민재
작성일: 2024.11.27.수요일
프로그램명: 전화번호부*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct NODE {
    char name[50];
    char num[50];
    struct NODE* link;
} NODE;

void reset(NODE** list);
void add(NODE** list);
void search(NODE* list);
int main(void) {
    NODE* list = NULL;//시작하는 포인터
    int choice;

    while (1) {
        printf("메뉴\n");
        printf("-------------------------\n");
        printf("1. 초기화\n2. 전화 번호 추가\n3. 전화 번호 탐색\n4. 종료\n");
        printf("-------------------------\n");
        printf("번호를 입력하시오  : ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            reset(&list);
        }
        else if (choice == 2) {
            add(&list);
        }
        else if (choice == 3) {
            search(list);
        }
        else if (choice == 4) {
            printf("종료\n");
            break;
        }
        else {
            printf("다시 입력해주세요.\n");
        }
    }
    return 0;
}
void reset(NODE** list) {
    NODE* p;
    while (*list) {
        p = *list;
        *list = (*list)->link;
        free(p);
    }
    printf("전화번호부가 초기화 되었습니다\n");
}
void add(NODE** list) {
    NODE* p = (NODE*)malloc(sizeof(NODE));  // p라는 노드를 생성한다
    if (!p) {
        printf("메모리 할당 실패\n");
        return;
    }

    char pname[50], pnum[50];

    printf("이름 : ");
    scanf("%s", pname);
    printf("HP : ");
    scanf("%s", pnum);

    strcpy(p->name, pname); //이름을 저장함
    strcpy(p->num, pnum); //전화번호를 저장함
    p->link = NULL;

    if (*list == NULL) {
        *list = p;//아무것도 없으면 p를 첫번째로 설정해준다.
    }
    else {
        NODE* temp = *list;
        // 리스트의 마지막 노드를 찾고, 새로운 노드를 그 뒤에 추가
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = p;
    }
    printf("추가되었습니다.\n");
}
void search(NODE* list) {
    char findname[50];
    NODE* p = list;  // p로 변경

    printf("탐색 이름 : ");
    scanf("%s", findname);

    while (p != NULL) {
        if (strcmp(p->name, findname) == 0) { // 이름이 같으면 전화번호 출력
            printf("HP : %s\n", p->num);
            return;
        }
        p = p->link;
    }
    printf("전화번호에 없습니다.\n");
}