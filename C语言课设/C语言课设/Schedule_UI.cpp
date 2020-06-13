#define _CRT_SECURE_NO_DEPRECATE 0
#include "Schedule_UI.h"
#include "Play_UI.h"
#include "List.h"
#include "Schedule.h"
#include "Play.h"
#include "Studio.h"
#include "EntityKey_Persist.h"
#include "Seat.h"
#include "Ticket.h"
#include "Ticket_UI.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>	 

void Schedule_UI_MgtEntry(int play_id)
{
	int i;
	int id;
	char choice;
	char ch;
	schedule_t buf;
	schedule_list_t list;
	schedule_node_t *pos;
	Pagination_t paging;

	List_Init(list, schedule_node_t);

	paging.offset = 0;
	paging.pageSize = 6;

	if (paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id))    //��ȡ   �ݳ��ƻ�����
	{
		Paging_Locate_FirstPage(list, paging);
		do {
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("    		    �ݳ��ƻ�����    			       			  \n");
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("%6s %6s %6s %10s %10s       %6s\n", "�ݳ��ƻ�ID", "��ĿID", "�ݳ���ID", "��ӳ����", "��ӳʱ��", "��λ��");
			Paging_ViewPage_ForEach(list, paging, schedule_node_t, pos, i){
				//	if(pos->data.play_id==play_id){			
				printf("%6d %6d %10d   %04d-%02d-%02d     %02d:%02d:%02d     %6d\n",
					pos->data.id, pos->data.play_id, pos->data.studio_id,
					pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);
				//   }

			}
			printf("--------------------- Total Records:%2d ------------------------- Page %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("[A]����ݳ��ƻ�\n");
			printf("[U]�޸��ݳ��ƻ�\n");
			printf("[D]ɾ���ݳ��ƻ�\n");
			printf("[T]�����ݳ�Ʊ\n");
			printf("[P]��һҳ\t[N]��һҳ\t[R]����\n");
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("\n��ѡ��:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice)
			{
			case 'a':
			case 'A':
				//����ݳ��ƻ�
				if (Schedule_UI_Add(play_id))    //����ӳɹ����������һҳ��ʾ
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id);
					Paging_Locate_LastPage(list, paging, schedule_node_t);
				}
				break;
			case 'u':
			case 'U':
				//�޸��ݳ��ƻ�
				printf("�����ݳ��ƻ�ID:");
				fflush(stdin);
				scanf("%d", &id);
				if (Schedule_UI_Modify(id)) {	//������������
					paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id);
					List_Paging(list, paging, schedule_node_t);
				}
				break;
			case 'd':
			case 'D':
				//ɾ���ݳ��ƻ�
				printf("�����ݳ��ƻ�ID:");
				fflush(stdin);
				scanf("%d", &id);
				if (Schedule_UI_Delete(id)) //������������
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id);
					List_Paging(list, paging, schedule_node_t);
				}
				break;
			case 't':
			case 'T':
				printf("����Ҫ���ɵ��ݳ�Ʊ���ݳ��ƻ�ID:");
				fflush(stdin);
				scanf("%d", &id);
				//			if(Schedule_Srv_FetchByID(id,&buf)){
				getchar();
				Ticket_UI_MgtEntry(id);
				break;
				//			}
				//			printf("û�в�ѯ���ݳ��ƻ�%d ��[Enter]����",id);
				//			fflush(stdin);
				//			getchar();
				//			break;

			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, -1, schedule_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, 1, schedule_node_t);
				}
				break;
			}
		} while (choice != 'R' && choice != 'r');
	}
	//�ͷ�����
	List_Destroy(list, schedule_node_t);
}

int Schedule_UI_Add(int play_id)
{
	schedule_t rec;
	seat_list_t list;
	List_Init(list, seat_node_t);
	char choice;
	int newRecCount = 0;
	printf("\n===============================================================\n");
	printf("****************  ����ݳ��ƻ�  ****************\n");
	printf("---------------------------------------------------------------\n");
	fflush(stdin);
	rec.play_id = play_id;
	printf("�ݳ��� ID:");
	scanf("%d", &rec.studio_id);
	printf("�ݳ����� year-month-day:");
	scanf("%d-%d-%d", &rec.date.year, &rec.date.month, &rec.date.day);
	printf("�ݳ�ʱ�� hour:minute:second:");
	scanf("%d:%d:%d", &rec.time.hour, &rec.time.minute, &rec.time.second);
	printf("������λ��:");
	scanf("%d", &rec.seat_count);
	getchar();
	printf("=======================================================\n");
	//��ȡ����
	rec.id = EntKey_Perst_GetNewKeys("Schedule", 1);
	//  rec.seat_count =Seat_Srv_FetchValidByRoomID(list, rec.studio_id);
	if (Schedule_Srv_Add(&rec)/*&&Ticket_Srv_AddBatch(rec.id,rec.studio_id)*/) {
		newRecCount++;
		printf("���ѳɹ�����µ��ݳ��ƻ�!\n");
	}
	else {
		printf("�µ��ݳ��ƻ����ʧ��!\n");
	}
	printf("-------------------------------------------------------\n");
	return newRecCount;
}

int Schedule_UI_Modify(int id)
{

	schedule_t rec;
	int rtn = 0;
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("���ݳ��ƻ�������!\n�� [Enter] ����!\n");
		getchar();
		return 0;
	}
	//����	
	printf("������ݳ��ƻ�������Ϣ\n");
	getchar();
	//	printf("��Ŀ ID:");
	//	scanf("%d",rec.play_id);
	printf("�ݳ��� ID:");
	scanf("%d", &rec.studio_id);
	getchar();
	printf("�ݳ����� year-month-day:");
	scanf("%d-%d-%d", &rec.date.year, &rec.date.month, &rec.date.day);
	printf("�ݳ�ʱ�� hour:minute:second:");
	scanf("%d:%d:%d", &rec.time.hour, &rec.time.minute, &rec.time.second);
	printf("������λ��:");
	scanf("%d", &rec.seat_count);
	Ticket_Srv_DeleteBatch(rec.id);
	printf("-------------------------------------------------------\n");
	int temp = Schedule_Srv_Modify(&rec);
	if (!temp)
	{
		printf("�޸�����ʧ��");
		printf("��������˳�\n");
		getchar();
		return 0;
	}
	return 1;
	//	rec.seat_count=Ticket_Srv_AddBatch(rec.id, rec.studio_id);
	//	if (Schedule_Srv_Modify(&rec)) {
	//		rtn = 1;
	//		printf(
	//			"�ݳ��ƻ��ɹ��޸�!\n�� [Enter] ����!\n");
	//	}
	//	else
	//		printf("�ݳ��ƻ��޸�ʧ�ܣ�\n�� [Enter] ����!\n");
	//	getchar();
	//	getchar();
	//	return rtn;
}


int Schedule_UI_Delete(int id)
{
	schedule_t rec;
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("�ݳ��ƻ�������!\n�� [Enter] ����!\n");
		fflush(stdin);
		getchar();
		return 0;
	}
	if (Schedule_Srv_DeleteByID(id)/*&& Ticket_Srv_DeleteBatch(rec.studio_id)*/) {
		printf("�ݳ��ƻ��ɹ�ɾ��!\n");
		return 1;
	}
	else {
		printf("�ݳ��ƻ������ڣ�\n�� [Enter] ����!\n");
		fflush(stdin);
		getchar();
		return 0;
	}
}
/*
int Schedule_UI_Query(int id)
{
int rtn = 1;
schedule_t  buf;
if (Schedule_Srv_FetchByID(id, &buf)) {
printf("\n");
printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
printf("    		    IDΪ%3d���ݳ��ƻ�  			       			  \n", buf.id);
printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
printf("\n");
rtn = 1;
printf("�ƻ�ID: %d\n", buf.id);
printf("��ĿID: %d\n", buf.play_id);
printf("��ӳ��ID: %d\n", buf.studio_id);
printf("�ݳ�����:%d-%d-%d\n", buf.date.year, buf.date.month, buf.date.day);
printf("�ݳ�ʱ��:%d:%d:%d\n", buf.time.hour, buf.time.minute, buf.time.second);
printf("��λ����:%d\n", buf.seat_count);
printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
printf("����س�������");
fflush(stdin);
getchar();
return 1;
}
else
{
printf("���Ҳ������ݳ��ƻ���");
return 0;
}
return rtn;
}
*/
int Schedule_UI_Query(int id){
	int i;
	char choice;
	schedule_list_t list;
	schedule_node_t *pos;
	Pagination_t paging;
	List_Init(list, schedule_node_t);
	paging.offset = 0;
	paging.pageSize = 6;
	if (paging.totalRecords = Schedule_Srv_FetchByPlay(list, id))    //��ȡ   �ݳ��ƻ�����
	{
		Paging_Locate_FirstPage(list, paging);
		do {
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("    		    �ݳ��ƻ�����    			       			  \n");
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("%6s %6s %6s %10s %10s       %6s\n", "�ݳ��ƻ�ID", "��ĿID", "�ݳ���ID", "��ӳ����", "��ӳʱ��", "��λ��");
			Paging_ViewPage_ForEach(list, paging, schedule_node_t, pos, i){
				printf("%6d %6d %10d   %04d-%02d-%02d     %02d:%02d:%02d     %6d\n",
					pos->data.id, pos->data.play_id, pos->data.studio_id,
					pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);
			}
			printf("--------------------- Total Records:%2d ------------------------- Page %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("[P]��һҳ\t[N]��һҳ\t[R]����\n");
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("\n��ѡ��:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice){
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, -1, schedule_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, 1, schedule_node_t);
				}
				break;
			}
		} while (choice != 'R' && choice != 'r');
	}
	//�ͷ�����
	List_Destroy(list, schedule_node_t);
	return 0;
}


void Schedule_UI_ListAll(void) {
	int i;
	int id;
	char choice;
	char ch;
	schedule_list_t head;
	schedule_list_t pos;
	Pagination_t paging;
	List_Init(head, schedule_node_t);
	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;
	//��������
	if (paging.totalRecords = Schedule_Srv_FetchAll(head)){
		Paging_Locate_FirstPage(head, paging);
		do {
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("    		    �ݳ��ƻ�����    			       			  \n");
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("%6s %6s %6s %10s %10s       %6s\n", "�ݳ��ƻ�ID", "��ĿID", "�ݳ���ID", "��ӳ����", "��ӳʱ��", "��λ��");
			Paging_ViewPage_ForEach(head, paging, schedule_node_t, pos, i){
				printf("%6d %6d %10d   %04d-%02d-%02d     %02d:%02d:%02d     %6d\n",
					pos->data.id, pos->data.play_id, pos->data.studio_id,
					pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);
			}
			printf("--------------------- Total Records:%2d ------------------------- Page %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("[P]��һҳ\t[N]��һҳ\t[S]��ѯ��Ŀ�ݳ��ƻ�\t[R]����\n");
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("\n��ѡ��:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice) {
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, schedule_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, schedule_node_t);
				}
				break;
			case 's':
			case 'S':
				printf("����Ҫ��ѯ�ľ�ĿID:");
				scanf("%d", &id);
				if (Schedule_UI_Query(id)){
					break;
				}
				else{
					printf("�þ�Ŀ�����ڣ�");
					break;
				}
			}
		} while ('r' != choice && 'R' != choice);
	}
	List_Destroy(head, schedule_node_t);
}
void Schedule_UI_ListByPlay(play_t *play, schedule_list_t list, Pagination_t paging){
}