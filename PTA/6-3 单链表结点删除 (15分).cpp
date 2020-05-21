#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode *next;
};

struct ListNode *readlist(){
	struct ListNode *head, *p, *q;
	p = q = (struct ListNode*)malloc(sizeof(struct ListNode));
	head = p;
	scanf("%d", &p->data);
	while (p->data != -1){
		p = (struct ListNode*)malloc(sizeof(struct ListNode));
		scanf("%d", &p->data);
		q->next = p;
		q = p;
	}
	q->next = NULL;
	return head;
}
struct ListNode *deletem(struct ListNode *L, int m){
	struct ListNode *head, *p, *q;
	p = q = (struct ListNode*)malloc(sizeof(struct ListNode));
	head = p;
	while (L->next != NULL){
		if (L->data != m){
			p = (struct ListNode*)malloc(sizeof(struct ListNode));
			p->data = L->data;
			q->next = p;
			q = p;
		}
		L = L->next;
	}
	q->next = NULL;
	return head->next;
}
void printlist(struct ListNode *L)
{
	struct ListNode *p = L;
	while (p) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int m;
	struct ListNode *L = readlist();
	scanf("%d", &m);
	L = deletem(L, m);
	printlist(L);
	system("pause");
	return 0;
}