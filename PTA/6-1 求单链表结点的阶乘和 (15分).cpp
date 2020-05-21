#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode;
struct Node {
	int Data; /* 存储结点数据 */
	PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 */

int FactorialSum(List L){
	int sum = 0, num = 1;
	for (List p = L; p != NULL; p=p->Next){
		num = 1;
		for (int i = 1; i <= p->Data; i++){
			num *= i;
		}
		sum += num;
	}
	return sum;
}
int main()
{
	int N, i;
	List L, p;
	scanf("%d", &N);
	L = NULL;
	for (i = 0; i<N; i++) {
		p = (List)malloc(sizeof(struct Node));
		scanf("%d", &p->Data);
		p->Next = L;  L = p;
	}
	printf("%d\n", FactorialSum(L));
	system("pause");
	return 0;
}