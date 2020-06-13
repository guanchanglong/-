#define _CRT_SECURE_NO_DEPRECATE 0
/*
* salesanalysis.c
*
*  Created on: 2015年6月12日
*      Author: Administrator
*/
#include <string.h>
#include <stdio.h>
#include "SalesAnalysis.h"
#include "Sale.h"
#include "Ticket.h"
#include "Play.h"
#include "Schedule.h"
#include "List.h"

//获取剧目票房
int SalesAnalysis_Srv_StaticSale(salesanalysis_list_t list){
	assert(list != NULL);
	play_list_t playList;
	play_node_t *pos;
	salesanalysis_node_t *newNode;
	int sold = 0;

	List_Free(list, salesanalysis_node_t);
	List_Init(playList, play_node_t);
	Play_Srv_FetchAll(playList);

	List_ForEach(playList, pos){
		sold++;
		newNode = (salesanalysis_node_t *)malloc(sizeof(salesanalysis_node_t));
		newNode->data.end_date = pos->data.end_date;
		newNode->data.start_date = pos->data.start_date;
		strcpy(newNode->data.area, pos->data.area);
		newNode->data.play_id = pos->data.id;
		newNode->data.price = pos->data.price;
		newNode->data.duration = pos->data.duration;
		strcpy(newNode->data.name, pos->data.name);
		//根据剧目ID获取票房
		newNode->data.sales = Schedule_Srv_StatRevByPlay(pos->data.id, (int)newNode->data.totaltickets);
		List_AddTail(list, newNode);
	}
	List_Destroy(playList, play_node_t);
	return sold;
}

//剧目票房排行
void SalesAnalysis_Srv_SortBySale(salesanalysis_list_t list)
{
	assert(list != NULL);
	salesanalysis_list_t listLeft;
	salesanalysis_list_t p;
	if (List_IsEmpty(list)){
		return;
	}
	else{
		list->prev->next = NULL;
		listLeft = list->next;
		list->next = list->prev = list;

		while (listLeft != NULL){
			p = listLeft;
			listLeft = listLeft->next;
			SalesAnalysis_Srv_AddToSoftedList(list, p);
		}
	}
	return;
}
/*salesanalysis_list_t temp=NULL ,buf=list->next,flag;
List_Init(temp,salesanalysis_node_t);
while(buf!=list)
{
if(temp->next == temp)
{
List_AddHead(temp,buf);
flag=temp->next;

}
else
{
while(flag->data.sales > buf->data.sales)
{
flag=flag->next;
}
List_InsertBefore(flag,buf);
}
buf=list->next;
}
list->next = temp->next;
temp->next->prev = list;*/


////根据演出计划ID获取票房
//int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount){
//	return 0;
//}
//根据票ID获取销售记录
//int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){
//	return 0;
//}

void SalesAnalysis_Srv_AddToSoftedList(salesanalysis_list_t list, salesanalysis_list_t node) {

	salesanalysis_list_t p;
	assert(list != NULL && node != NULL);
	if (List_IsEmpty(list)){
		List_AddTail(list, node);
	}
	else{
		p = list->next;
		while (p != list&&p->data.sales < node->data.sales){
			p = p->next;
		}
		List_InsertBefore(p, node);
	}
}
