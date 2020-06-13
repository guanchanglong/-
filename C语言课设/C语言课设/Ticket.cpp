#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Ticket.h"
#include "List.h"
#include "Schedule.h"
#include "Play.h"
#include "Ticket_Persist.h"
#include "Play_Persist.h"
#include "Schedule_Persist.h"
#include "Seat.h"
#include "Sale.h"
//#include "SalesAnalysis.h"
#include <stdio.h>
#include <stdlib.h>

inline int Schedule_Srv_FetchByID(int ID, schedule_t *buf) {
	return Schedule_Perst_SelectByID(ID, buf);

}

int Ticket_Srv_GenBatch(int schedule_id){
	int count = 0;
	seat_list_t seat_head;
	List_Init(seat_head, seat_node_t);
	schedule_t buf;
	Schedule_Srv_FetchByID(schedule_id, &buf);
	count = Seat_Srv_FetchValidByRoomID(seat_head, buf.studio_id);
	printf("һ������%d����λ\n", count);
	Ticket_Perst_Insert(seat_head, schedule_id);//��Ʊ����Ϣ������ticket.dat�ļ��� 
	//	printf("������Ʊ������Ϊ��%d\n",s);
	return count;
}

int Ticket_Srv_DeleteBatch(int schedule_id) {
	return Ticket_Perst_Rem(schedule_id);

}
//
//
int Ticket_Srv_FetchByID(int id, ticket_t *buf){
	return Ticket_Perst_SelByID(id, buf);

}

int Ticket_Srv_AddBatch(int schedule_id, int studio_id){
	return 0;
}
//�����ݳ��ƻ�ID��ȡƱ��
int Ticket_Srv_StatRevBySchID(int schedule_id, int *soldCount){
	int value = 0;
	ticket_list_t list;
	ticket_node_t *p;
	sale_t sale;
	*soldCount = 0;
	List_Init(list, ticket_node_t);
	*soldCount = Ticket_Srv_FetchBySchID(schedule_id, list);
	List_ForEach(list, p){
		//Sale_Srv_FetchByTicketID(p->data.id, &(sale)); //////////////////////////////////////////////20:29
		//if (p->data.status == 1 && sale->data.type == 1){
		//	(*soldCount)++;
		//	value += p->data.price;
		//}
		Sale_Srv_FetchByticket(p->data.id, &sale);//+
		//sale.type = 1;
		if (sale.type == 1 && p->data.status == 1)//ȷ��Ϊ��Ʊ״̬����ȷ��Ϊ����
		{
			*soldCount++;
			value += p->data.price;
		}
	}
	List_Destroy(list, ticket_node_t);

	return value;

}
//�����ݳ��ƻ�ID��ȡƱ������
int Ticket_Srv_FetchBySchID(int id, ticket_list_t list){
	return Ticket_Perst_SelBySchID(id, list);
}

//�޸� 
int Ticket_Srv_Modify(const ticket_t *data)
{
	return Ticket_Perst_Update(data);
}
