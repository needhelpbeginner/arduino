/*�ۼ���: 20240411 �����
�ۼ���: 2024.11.27.������
���α׷���: ��ȭ��ȣ��*/
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
    NODE* list = NULL;//�����ϴ� ������
    int choice;

    while (1) {
        printf("�޴�\n");
        printf("-------------------------\n");
        printf("1. �ʱ�ȭ\n2. ��ȭ ��ȣ �߰�\n3. ��ȭ ��ȣ Ž��\n4. ����\n");
        printf("-------------------------\n");
        printf("��ȣ�� �Է��Ͻÿ�  : ");
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
            printf("����\n");
            break;
        }
        else {
            printf("�ٽ� �Է����ּ���.\n");
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
    printf("��ȭ��ȣ�ΰ� �ʱ�ȭ �Ǿ����ϴ�\n");
}
void add(NODE** list) {
    NODE* p = (NODE*)malloc(sizeof(NODE));  // p��� ��带 �����Ѵ�
    if (!p) {
        printf("�޸� �Ҵ� ����\n");
        return;
    }

    char pname[50], pnum[50];

    printf("�̸� : ");
    scanf("%s", pname);
    printf("HP : ");
    scanf("%s", pnum);

    strcpy(p->name, pname); //�̸��� ������
    strcpy(p->num, pnum); //��ȭ��ȣ�� ������
    p->link = NULL;

    if (*list == NULL) {
        *list = p;//�ƹ��͵� ������ p�� ù��°�� �������ش�.
    }
    else {
        NODE* temp = *list;
        // ����Ʈ�� ������ ��带 ã��, ���ο� ��带 �� �ڿ� �߰�
        while (temp->link != NULL) {
            temp = temp->link;
        }
        temp->link = p;
    }
    printf("�߰��Ǿ����ϴ�.\n");
}
void search(NODE* list) {
    char findname[50];
    NODE* p = list;  // p�� ����

    printf("Ž�� �̸� : ");
    scanf("%s", findname);

    while (p != NULL) {
        if (strcmp(p->name, findname) == 0) { // �̸��� ������ ��ȭ��ȣ ���
            printf("HP : %s\n", p->num);
            return;
        }
        p = p->link;
    }
    printf("��ȭ��ȣ�� �����ϴ�.\n");
}