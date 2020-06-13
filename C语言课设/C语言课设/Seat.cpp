#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_02
* File name: Seat.c
* Description : ������λ����ҵ���߼���
* Author:   XUPT
* Version:  v.1
* Date: 	2015��4��22��
*/

#include <stdlib.h>
#include "List.h"
#include "Seat.h"
#include "EntityKey_Persist.h"
#include "Seat_Persist.h"
#include "Seat_UI.h"

/*
�������ܣ��������һ������λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ��ӵ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��������λ�ı�־��
*/
int Seat_Srv_Add(seat_t *data){
	return Seat_Perst_Insert(data);
	//return 0;
}

/*
�������ܣ����������λ���ݡ�
����˵����listΪseat_list_t����ָ�룬��ʾ��Ҫ��ӵ�������λ�����γɵ�����
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ������������λ�ı�־��
*/
int Seat_Srv_AddBatch(seat_list_t list){
	return Seat_Perst_InsertBatch(list);
	//return 0;
}

/*
�������ܣ������޸�һ����λ���ݡ�
����˵����dataΪseat_t����ָ�룬��ʾ��Ҫ�޸ĵ���λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸�����λ�ı�־��
*/
int Seat_Srv_Modify(const seat_t *data){
	return Seat_Perst_Update(data);
	//return 0;
}

/*
�������ܣ�������λIDɾ��һ����λ��
����˵����IDΪ���ͣ���ʾ��Ҫɾ������λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_Srv_DeleteByID(int ID){
	return Seat_Perst_DeleteByID(ID);
	//return 1;
}

/*
�������ܣ�������λID��ȡ��λ���ݡ�
����˵������һ������IDΪ���ͣ���ʾ��λID���ڶ�������bufΪseat_tָ�룬ָ�����ȡ����λ���ݽ�㡣
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���ȡ����λ�ı�־��
*/
int Seat_Srv_FetchByID(int ID, seat_t *buf){
	return Seat_Perst_SelectByID(ID, buf);
	//return 0;
}

/*
�������ܣ������ݳ���IDɾ��������λ��
����˵����roomIDΪ���ͣ���ʾ��Ҫɾ��������λ���ݳ���ID��
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ�����ݳ���������λ�ı�־��
*/
inline int Seat_Srv_DeleteAllByRoomID(int roomID){
	return Seat_Perst_DeleteAllByRoomID(roomID);
	//return 0;
}

/*
�������ܣ����ݸ����ݳ������С�������ʼ���ݳ�����������λ���ݣ�����ÿ����λ��㰴�в�����λ����
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���ʼ�����ݳ�����������λ��
*/
int Seat_Srv_FetchByRoomID(seat_list_t list, int roomID){
	int SeatCount = Seat_Perst_SelectByRoomID(list, roomID);
	Seat_Srv_SortSeatList(list);
	return SeatCount;
}

/*
�������ܣ������ݳ���ID��ø��ݳ�������Ч��λ��
����˵������һ������listΪseat_list_t���ͣ���ʾ��ȡ������Ч��λ����ͷָ�룬�ڶ�������roomIDΪ���ͣ���ʾ��Ҫ��ȡ��Ч��λ���ݳ���ID��
�� �� ֵ�����ͣ���ʾ�ݳ�������Ч��λ������
*/
int Seat_Srv_FetchValidByRoomID(seat_list_t list, int roomID)
{
	int SeatCount = Seat_Perst_SelectByRoomID(list, roomID);
	seat_node_t *p;
	List_ForEach(list, p){
		if (p->data.status != SEAT_GOOD){
			List_FreeNode(p);
			SeatCount--;
		}
	}
	Seat_Srv_SortSeatList(list);
	return SeatCount;
}

/*
�������ܣ����ݸ����ݳ������С�������ʼ���ݳ�����������λ���ݣ�����ÿ����λ��㰴�в�����λ����
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ���ʼ�����ݳ�����������λ��
*/
int Seat_Srv_RoomInit(seat_list_t list, int roomID, int rowsCount,
	int colsCount) {
	int i, j;

	seat_node_t *p;

	//������ȡ����
	//long seatID=EntKey_Srv_CompNewKeys("Seat", rowsCount*colsCount);
	long seatID = EntKey_Perst_GetNewKeys("Seat", rowsCount*colsCount);
	for (i = 1; i <= rowsCount; i++){
		for (j = 1; j <= colsCount; j++) {
			p = (seat_node_t *)malloc(sizeof(seat_node_t));
			p->data.id = seatID;
			p->data.roomID = roomID;
			p->data.row = i;
			p->data.column = j;
			p->data.status = SEAT_GOOD;
			seatID++;
			List_AddTail(list, p);
		}
	}

	return Seat_Perst_InsertBatch(list);
}

/*
�������ܣ�����λ����list����λ�кš��кŽ�������
����˵����listΪseat_list_t���ͣ���ʾ��������λ����ͷָ�롣
�� �� ֵ���ޡ�
*/
void Seat_Srv_SortSeatList(seat_list_t list) {
	seat_node_t *p, *listLeft;
	assert(list != NULL);

	if (List_IsEmpty(list))
		return;

	list->prev->next = NULL;
	listLeft = list->next;
	list->next = list->prev = list;

	while (listLeft != NULL)
	{
		p = listLeft;
		listLeft = listLeft->next;
		Seat_Srv_AddToSoftedList(list, p);
	}
}

/*
�������ܣ���һ����λ�����뵽���������λ�����С�
����˵������һ������listΪseat_list_t���ͣ���ʾ�����������λ����ͷָ�룬�ڶ�������nodeΪseat_node_tָ�룬��ʾ��Ҫ�������λ���ݽ�㡣
�� �� ֵ���ޡ�
*/
void Seat_Srv_AddToSoftedList(seat_list_t list, seat_node_t *node) {
	seat_node_t *p;
	assert(list != NULL && node != NULL);
	if (List_IsEmpty(list))	{
		List_AddTail(list, node);
	}
	else
	{
		p = list->next;

		while (p != list && (p->data.row<node->data.row ||
			(p->data.row == node->data.row && p->data.column<node->data.column))){
			p = p->next;
		}
		List_InsertBefore(p, node);
	}
}

/*
�������ܣ�������λ���С��кŻ�ȡ��λ���ݡ�
����˵������һ������listΪseat_list_t���ͣ���ʾ��λ����ͷָ�룬
�ڶ�������rowΪ���ͣ���ʾ����ȡ��λ���кţ�����������columnΪ���ͣ���ʾ����ȡ��λ���кš�
�� �� ֵ��Ϊseat_node_tָ�룬��ʾ��ȡ������λ���ݡ�
*/
seat_node_t * Seat_Srv_FindByRowCol(seat_list_t list, int row, int column) {
	assert(NULL != list);
	seat_node_t *p;

	List_ForEach(list, p)
	if (p->data.row == row && p->data.column == column)
		return p;
	
	return NULL;
}

/*
�������ܣ�������λID�������л�ȡ��λ���ݡ�
����˵������һ������listΪseat_list_t���ͣ�ָ����λ���������ڶ�������IDΪ���ͣ���ʾ��λID��
�� �� ֵ��seat_node_t���ͣ���ʾ��ȡ����λ���ݡ�
*/
seat_node_t * Seat_Srv_FindByID(seat_list_t list, int rowID) {
	assert(NULL != list);
	seat_node_t *p;

	List_ForEach(list, p)
	if (p->data.id == rowID)
		return p;

	return NULL;
}