#define _CRT_SECURE_NO_DEPRECATE 0
#define LEN sizeof(struct student)
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int year;
	char name[10];
	char sex[5];
	struct student *next;
};
struct student *input(void)
{
	struct student *head, *p, *q;
	head = (struct student*)malloc(LEN);
	printf("���������ѧ������Ϣ:(������Ϊ0����)���䣺		������		�Ա�\n");
	scanf("%d%s%s", &head->year, &head->name, &head->sex);
	p = q = head;
	while (p->year != 0)
	{
		p = (struct student*)malloc(LEN);
		scanf("%d%s%s", &p->year, &p->name, &p->sex);
		q->next = p;
		q = p;
	}
	q->next = NULL;
	return head;
}
void output(struct student *p)
{
	while (p->next!=NULL)
	{
		printf("%d	%s	%s\n", p->year, p->name, p->sex);
		p = p->next;
	}
}
int main()
{
	struct student *p;
	p = input();
	output(p);
	system("pause");
	return 0;
}
//65.��Ŀ����дinput()��output()�������룬���5��ѧ�������ݼ�¼��
//66.��Ŀ������һ������