#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_01
* File name: Studio_UI.c
* Description : �ݳ������������
* Author:   XUPT
* Version:  v.1
* Date: 	2015��4��22��
*/

#include "Studio_UI.h"
#include "List.h"
#include "Studio.h"
#include "Seat.h"
#include "Seat_Persist.h"

static const int STUDIO_PAGE_SIZE = 5;

#include <stdio.h>


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
��ʶ����TTMS_SCU_Studio_UI_MgtEnt
�������ܣ����������ݳ�������ں�������ʾ��ǰ���ݳ������ݣ����ṩ�ݳ���������ӡ��޸ļ�ɾ�����ܲ�������ڡ�
����˵�����ޡ�
�� �� ֵ���ޡ�
*/
void Studio_UI_MgtEntry(void) {				//�ݳ�������
	int i, id;
	char choice;							//ѡ�� 

	studio_list_t head;
	studio_node_t *pos;
	Pagination_t paging;					//��ʼ����ҳ���� 

	List_Init(head, studio_node_t);			//��ʼ����Ŀ��Ϣ���� 
	paging.offset = 0;
	paging.pageSize = STUDIO_PAGE_SIZE;

	//��������
	if (paging.totalRecords = Studio_Srv_FetchAll(head))
	{
		Paging_Locate_FirstPage(head, paging);

		do {
			printf(
				"\n==================================================================\n");
			printf(
				"********************** ��ӳ���б� **********************\n");
			printf("%5s  %18s  %10s  %10s  %10s\n", "ID", "Name", "Rows Count",
				"Columns Count", "Seats Count");
			printf(
				"------------------------------------------------------------------\n");
			//��ʾ����
			Paging_ViewPage_ForEach(head, paging, studio_node_t, pos, i){
				printf("%5d  %18s  %10d  %10d  %10d\n", pos->data.id,
					pos->data.name, pos->data.rowsCount, pos->data.colsCount,
					pos->data.seatsCount);
			}

			printf(
				"------- �ܼ�¼:%2d ----------------------- ҳ %2d/%2d ----\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf(
				"******************************************************************\n");
			printf(
				"[P]��һҳ|[N]��һҳ | [A]���|[D]ɾ��|[U]���� | [S]��λ | [R]����");
			printf(
				"\n==================================================================\n");
			printf("���ѡ��:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);

			switch (choice) {
			case 'a':
			case 'A':
				if (Studio_UI_Add()) //����ӳɹ����������һҳ��ʾ
				{
					paging.totalRecords = Studio_Srv_FetchAll(head);
					Paging_Locate_LastPage(head, paging, studio_node_t);
				}
				break;
			case 'd':
			case 'D':
				printf("�����ӳ��ID:");
				scanf("%d", &id);
				if (Studio_UI_Delete(id)) {	//������������
					paging.totalRecords = Studio_Srv_FetchAll(head);
					List_Paging(head, paging, studio_node_t);
				}
				break;
			case 'u':
			case 'U':
				printf("�����ӳ��ID:");
				scanf("%d", &id);
				if (Studio_UI_Modify(id)) {	//������������
					paging.totalRecords = Studio_Srv_FetchAll(head);
					List_Paging(head, paging, studio_node_t);
				}
				break;
			case 's':
			case 'S':
				printf("�����ӳ��ID:");
				scanf("%d", &id);
				//Seat_UI_MgtEntry(id);
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t)
					;
				break;
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, studio_node_t);
				}
				break;
			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, studio_node_t);
				}
				break;
			}
		} while (choice != 'r' && choice != 'R');
	}
	//�ͷ�����ռ�
	List_Destroy(head, studio_node_t);
}

/*
��ʶ����TTMS_SCU_Studio_UI_Add
�������ܣ�������ϵͳ�����һ�����ݳ������ݡ�
����˵�����ޡ�
�� �� ֵ�����ͣ��ɹ�������ݳ����ĸ���������ֵΪ1��0
*/
int Studio_UI_Add(void) {
	studio_t rec;			//��ӳ���Ľṹ����� 
	int newRecCount = 0;
	char choice;
	do {
		printf("\n=======================================================\n");
		printf("****************  �����µķ�ӳ��  ****************\n");
		printf("-------------------------------------------------------\n");
		printf("Room Name:");
		fflush(stdin);
		gets(rec.name);
		printf("��λ����:");
		scanf("%d", &(rec.rowsCount));
		printf("��λ����:");
		scanf("%d", &(rec.colsCount));
		rec.seatsCount = 0;
		printf("=======================================================\n");

		if (Studio_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("����ɹ�!\n");//����ɹ� 
		}
		else
			printf("����ʧ��!\n");//����ʧ�� 
		printf("-------------------------------------------------------\n");
		printf("[A]��������, [R]����:");
		fflush(stdin);
		scanf("%c", &choice);
	} while ('a' == choice || 'A' == choice);
	return newRecCount;
}

/*
��ʶ����TTMS_SCU_Studio_UI_Mod
�������ܣ������޸�ϵͳ���ִ��һ���ݳ������ݡ�
����˵����idΪ���ͣ�����Ҫ�޸ĵ��ݳ���ID��
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸����ݳ����ı�־��
*/
int Studio_UI_Modify(int id) {
	studio_t rec;
	int rtn = 0;
	int newrow, newcolumn;
	seat_list_t list;
	int seatcount;

	/*Load record*/
	if (!Studio_Srv_FetchByID(id, &rec)) {
		printf("����������������!\nPress [Enter] key to return!\n");
		getchar();
		return 0;
	}

	printf("\n=======================================================\n");
	printf("****************  ���·�ӳ��  ****************\n");
	printf("-------------------------------------------------------\n");
	printf("��ӳ��ID:%d\n", rec.id);
	printf("��ӳ������[%s]:", rec.name);
	fflush(stdin);
	gets(rec.name);

	List_Init(list, seat_node_t);
	seatcount = Seat_Srv_FetchByRoomID(list, rec.id);
	if (seatcount) {
		do {			//�����λ�ļ���������λ��Ϣ������µ����б������ǰ�󣬷����������
			printf("��λ����Ӧ�� >= [%d]:", rec.rowsCount);//�������λ������ 
			scanf("%d", &(newrow));
			printf("��λ����Ӧ�� >= [%d]:", rec.colsCount);
			scanf("%d", &(newcolumn));
		} while (newrow < rec.rowsCount || newcolumn < rec.colsCount);
		rec.rowsCount = newrow;
		rec.colsCount = newcolumn;
		rec.seatsCount = seatcount;
	}
	else {
		printf("��λ����:");//��Ϊ 
		scanf("%d", &rec.rowsCount);
		printf("��λ����:");//��Ϊ 
		scanf("%d", &rec.colsCount);
		rec.seatsCount = 0;
	}

	printf("-------------------------------------------------------\n");

	if (Studio_Srv_Modify(&rec)) {
		rtn = 1;
		printf(
			"�������ݸ��³ɹ�!\nPress [Enter] key to return!\n");// �������ݸ��³ɹ�!\��[Enter]������!
	}
	else
		printf("�������ݸ���ʧ��!\nPress [Enter] key to return!\n");	//�������ݸ���ʧ��!\��[Enter]������! 

	getchar();		//������˳� 
	return rtn;
}

/*
��ʶ����TTMS_SCU_Studio_UI_Del
�������ܣ�����ɾ��ϵͳ���ִ��һ���ݳ������ݡ�
����˵����idΪ���ͣ�����Ҫɾ�����ݳ���ID��
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ�����ݳ����ı�־��
*/
int Studio_UI_Delete(int id) {

	int rtn = 0;

	if (Studio_Srv_DeleteByID(id)) {
		//��ɾ����ӳ��ʱ��ͬʱ���ݷ�ӳ��idɾ����λ�ļ��е���λ
		if (Seat_Srv_DeleteAllByRoomID(id))
		{
			printf("The seats of the room deleted successfully!\n");			//�������λɾ���ɹ� 
		}
		printf("����ɾ���ɹ�!\nPress [Enter] key to return!\n");// ����ɾ���ɹ�!\��[Enter]������!
		rtn = 1;
	}
	else {
		printf("����������������!\nPress [Enter] key to return!\n");//����������������!\��[Enter]������! 
	}

	getchar();	//������˳� 
	return rtn;
}
