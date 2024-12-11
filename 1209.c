/*�ۼ���:20240411 �����
�ۼ���: 1209
���α׷���: */
//���Ḯ��Ʈ
#define element int
#include<stdio.h>
#include<stdlib.h>//�����޸�
typedef struct Node {
	element data;
	struct Node* link;
}Node;

void print_list(Node* head);
Node* delete_first(Node* head, Node* prev);
Node* insert_first(Node* head, element value);
Node* insert(Node* head, Node* prev, element value);
int main(void) {
	Node* head = NULL;
	
	head = insert_first(head, 1);
	print_list(head);
	head = insert_first(head, 2);
	print_list(head);

	head = insert_first(head, 3);
	print_list(head);   
    head = insert_first(head, 4);
    print_list(head);
    head = insert_first(head, 5);
    print_list(head);

	head = insert(head, head->link, 4);//�� ��°�� ������ ��,
	print_list(head);

	head = delete_first(head);
	print_list(head);
	
	return 0;
}
void print_list(Node* head) {
    for (Node* p = head; p != NULL; p = p->link) {
        printf("%d->", p->data);
    }
    printf("\n");
}
Node* delete_first(Node* head,Node*prev) {
    Node* removed;
    removed =prev->link;
    prev->link = removed->link;//���� ��������.
    head = removed->link;
    free(removed);
    return head;
}
Node* insert_first(Node* head, element value) {
    Node* p = (Node*)malloc(sizeof(Node)); //��� �ϳ� ����
    p->data = value;
    p->link = head;
    head = p;
    return head;
}
Node* insert(Node* head, Node* prev, element value) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = value;
    p->link = prev->link;//head�� �ȹٲ�� null�� �ٲ�
    prev->link = p;
    return head;
}