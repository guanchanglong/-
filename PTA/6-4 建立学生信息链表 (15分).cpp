#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node {
	int    num;
	char   name[20];
	int    score;
	struct stud_node *next;
};
struct stud_node *head, *tail;

void input(){
	struct stud_node *p, *q;
	p =q= (struct stud_node*)malloc(sizeof(struct stud_node));
	head = p;
	scanf("%d", &p->num);
	if (p->num != 0)
	{
		scanf("%s %d", p->name, &p->score);
	}
	else{
		head = NULL;
	}
	while (p->num!=0){
		p = (struct stud_node*)malloc(sizeof(struct stud_node));
		scanf("%d", &p->num);
		if (p->num!=0)
		{
			scanf("%s %d", p->name, &p->score);
		}
		else{
			break;
		}
		q->next = p;
		q = p;
	}
	q->next = tail;
}
int main()
{
	struct stud_node *p;
	head = tail = NULL;
	input();
	for (p = head; p != NULL; p = p->next)
		printf("%d %s %d\n", p->num, p->name, p->score);
	system("pause");
	return 0;
}