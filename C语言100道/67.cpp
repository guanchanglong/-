#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
struct student
{
	int year;
	char name[10];
	struct student *next;
};
struct student *creat(void)		//头插法
{
	student *head, *p;
	head = NULL;
	printf("请输入数据：(当年龄为0时结束)\n年龄：	姓名：\n");
	p = (student*)malloc(sizeof(student));
	scanf("%d%s", &p->year, &p->name);
	while (p->year != 0)
	{
		p->next = head;
		head = p;
		p = (student*)malloc(sizeof(student));
		scanf("%d%s", &p->year, &p->name);
	}
	return head;
}
int main()
{
	struct student *head;
	head = creat();
	while (head != NULL)
	{
		printf("%d %s\n", head->year, head->name);
		head = head->next;
	}
	system("pause");
	return 0;
}
//67.题目：反向输出一个链表。