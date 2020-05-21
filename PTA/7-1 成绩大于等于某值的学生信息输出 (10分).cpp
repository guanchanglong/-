#define _CRT_SECURE_NO_DEPRECATE 0
//#include <stdio.h>
//#include<stdlib.h>
//struct stud_node{
//	int num;
//	char name[20];
//	int score;
//	struct stud_node *next;
//};
//struct stud_node *Creat_Stu_Doc(){
//	struct stud_node *p, *q, *head;
//	p = q = (struct stud_node*)malloc(sizeof(struct stud_node));
//	head = p;
//	scanf("%d", &p->num);
//	if (p->num != 0)
//	{
//		scanf("%s %d", p->name, &p->score);
//	}
//	else{
//		head = NULL;
//	}
//	while (p->num != 0){
//		p = (struct stud_node*)malloc(sizeof(struct stud_node));
//		scanf("%d", &p->num);
//		if (p->num != 0)
//		{
//			scanf("%s %d", p->name, &p->score);
//		}
//		else{
//			break;
//		}
//		q->next = p;
//		q = p;
//	}
//	q->next = NULL;
//	return head;
//}
//struct stud_node *DeleteDoc(struct stud_node *head, int min_score){
//	struct stud_node *p1, *p2;
//	p2 = NULL;
//	if (head != NULL){
//		p1 = head;
//	}
//	else{
//		return NULL;
//	}
//	while (p1->next != NULL){
//		if (p1->score < min_score){
//			if (p1 == head){//目标节点为头节点
//				head = p1->next;
//			}
//			else{
//				p2->next = p1->next;
//			}
//		}
//		p2 = p1;
//		p1 = p2->next;
//	}
//	return head;
//}
//void Ptrint_Stu_Doc(struct stud_node *head){
//	while (head != NULL){
//		printf("%d %s %d\n", head->num, head->name, head->score);
//		head = head->next;
//	}
//}
//int main()
//{
//	struct stud_node *head;
//	int n;
//	head = Creat_Stu_Doc();
//	scanf("%d", &n);
//	head = DeleteDoc(head, n);
//	Ptrint_Stu_Doc(head);
//	system("pause");
//	return 0;
//}


#include<stdio.h>
#include<stdlib.h>
struct stud_node
{
	char name[20];
	int num, score;
	struct stud_node *next;
};
struct stud_node *Creat()
{
	struct stud_node *p, *head = NULL, *tail = NULL;
	int i;
	while (1)
	{
		p = (struct stud_node *)malloc(sizeof(struct stud_node));
		scanf("%d", &p->num);
		if (p->num == 0)
			break;
		scanf("%s", p->name);
		scanf("%d", &p->score);
		p->next = NULL;
		if (head == NULL)
		{
			head = p;
		}
		else
		{
			tail->next = p;
		}
		tail = p;
	}
	return head;
}
int main()
{
	struct stud_node *head = NULL, *p;
	int n;
	head = Creat();
	scanf("%d", &n);
	for (p = head; p != NULL; p = p->next)
	{
		if ((p->score) >= n)
			printf("%d %s %d\n", p->num, p->name, p->score);
	}
	system("pause");
	return 0;
}