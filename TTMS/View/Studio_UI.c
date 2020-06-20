#include "Studio_UI.h"

#include "Main_Menu.h"
#include "list.h"
#include "Studio.h"
#include "Seat.h"
#include "EntityKey.h"
#include "Seat_UI.h"
#include "conio.h"


extern account_t gl_CurUser;

static const int STUDIO_PAGE_SIZE = 5;

#include <stdio.h>
#include <Windows.h>

	void Studio_UI_MgtEntry(account_type_t type) {
	int i, id;
	char choice;
	
	studio_list_t head;
	studio_node_t *pos;
	Pagination_t paging;
	List_Init(head, studio_node_t);
	paging.offset = 0;
	paging.pageSize = STUDIO_PAGE_SIZE;
	//��������
	paging.totalRecords = Studio_Srv_FetchAll(head);
	Paging_Locate_FirstPage(head, paging);
	if (type==9) {
		do {
			system("cls");
			printf("\n\n\t\t\t                        �ݳ����嵥\n");
			printf("\t\t\t******************************************************************\n\n");
			printf("\t\t\t%-5s  %-14s  %-12s  %-12s  %-12s\n", "ID", "    ����", "����",
				"����", "��λ��");
			
			//��ʾ����
			for (i = 0, pos = (studio_node_t*)(paging.curPos);
				pos != head && i < paging.pageSize; i++) {
				printf("\t\t\t%-5d  %-14s    %-12d  %-12d  %-12d\n", pos->data.id, pos->data.name, pos->data.rowsCount, pos->data.colsCount, pos->data.seatsCount);
				pos = pos->next;
			}
			printf("\n\t\t\t  ����:%2d \t\t\t\t\t%d/%d \n",
				paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));
			printf("\t\t\t******************************************************************\n\n");
			printf("\t\t\t[P]��һҳ\t\t\t\t[N]��һҳ\n\t\t\t[A]���\t\t\t\t\t[D]ɾ��\n\t\t\t[M]�޸��ݳ�����Ϣ\t\t\t[Z]�����ݳ�����λ\n\t\t\t[R]����");
			
			printf("\n\n\t\t\t:");
			choice = getche();
			switch (choice)
			{ 
			case 'A':
			case 'a':
				if (Studio_UI_Add()) //����ӳɹ����������һҳ��ʾ
				{
					paging.totalRecords = Studio_Srv_FetchAll(head);
					Paging_Locate_LastPage(head, paging, studio_node_t);
				}
				break; 
			case 'D':
			case 'd':
				printf("\n");
				printf("\t\t\tID:");
				scanf("%d", &id);
				getchar();
				if (Studio_UI_Delete(id)) {	//������������
					paging.totalRecords = Studio_Srv_FetchAll(head);
					List_Paging(head, paging, studio_node_t);
				}
				break; 
			case 'M':
			case 'm':
				printf("\n");
				printf("\t\t\tID:");
				scanf("%d", &id);
				if (Studio_UI_Modify(id)) {	//������������
					paging.totalRecords = Studio_Srv_FetchAll(head);
					List_Paging(head, paging, studio_node_t);
				}
				break; 
			case 'Z':
			case 'z':
				printf("\n");
				printf("\t\t\tID:");
				scanf("%d", &id);
				getchar();
				Seat_UI_MgtEntry(id);
				paging.totalRecords = Studio_Srv_FetchAll(head);
				List_Paging(head, paging, studio_node_t);
				break; 
			case 'P':
			case 'p':
				if (1 < Pageing_CurPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, studio_node_t);
				}
				break; 
			case 'N':
			case 'n':
				if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, studio_node_t);
				}
				break;
			}
		} while (choice != 'R'&&choice != 'r');
	}
	else
	{
		do {
			system("cls");
			printf("\n\n\t\t\t                        �ݳ����б�\n");
			printf("\t\t\t******************************************************************\n\n");
			printf("\t\t\t%-5s  %-14s  %-12s  %-12s  %-12s\n\n", "ID", "    ����", "����",
				"����", "��λ��");
			//��ʾ����
			for (i = 0, pos = (studio_node_t *)(paging.curPos);
				pos != head && i < paging.pageSize; i++) {
				printf("\t\t\t%-5d  %-14s    %-12d  %-12d  %-12d\n", pos->data.id,
					pos->data.name, pos->data.rowsCount, pos->data.colsCount,
					pos->data.seatsCount);
				pos = pos->next;
			}
			printf("\n\t\t\t����:%2d\t\t\t\t\t\t    %d/%d \n",
				paging.totalRecords, Pageing_CurPage(paging), Pageing_TotalPages(paging));

			printf("\n\n\t\t\t\t\t  1.��ҳ  2.��ҳ  3.����");

			printf("\n\n\t\t\t:");
			choice = getche();
			switch (choice)
			{
			case '1':

				if (1 < Pageing_CurPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, studio_node_t);
				}
				break;
			case '2':

				if (Pageing_TotalPages(paging) > Pageing_CurPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, studio_node_t);
				}
				break;
			}
		} while (choice != '3');
	}
	//�ͷ�����ռ�
	List_Destroy(head, studio_node_t);
}

int Studio_UI_Add(void) {
	studio_t rec, record;
	int newRecCount = 0;
	char choice;
	do {
		/*system("cls");*/
			printf("\n\n\t\t\t                        �����ݳ���\n");
			printf("\t\t\t******************************************************************\n");

		printf("\t\t\t�ݳ�������:");
		rewind(stdin);
		gets(rec.name);
		printf("\t\t\t����:");
		scanf("\t\t\t%d", &rec.rowsCount);
		printf("\t\t\t����:");
		scanf("%d", &rec.colsCount);
		getchar();
		rec.seatsCount = 0;
		printf("\t\t\t******************************************************************\n");

		//��ȡ����
		FILE* fp = fopen("Studio.dat", "rb");
		int i = 0;
		rewind(fp);
		while (fread(&record, sizeof(studio_t), 1, fp))//�����Ļ�ȡ�����⣬�Ѿ����
		{
			if(record.id>i)
				i = record.id;
		}
		if (i<=0)
		{
			rec.id = i + 1;
		}
		else
		{
			rec.id = i + 1;
		}
		/*rec.id = EntKey_Srv_CompNewKey("Studio"); */ 
		fclose(fp);
		if (Studio_Srv_Add(&rec)) {
			newRecCount += 1;
			printf("\t\t\t��ӳɹ�\n");
		}
		else
			printf("\t\t\t���ʧ��\n");
		printf("\t\t\t-------------------------------------------------------\n");
		printf("\t\t\t1.�������\t2.����");
		choice = getche();
	} while ('1' == choice);
	return newRecCount;
}

int Studio_UI_Modify(int id) {
	studio_t rec;
	int rtn = 0;
	int newrow, newcolumn;
	seat_list_t list;
	int seatcount;

	/*Load record*/
	if (!Studio_Srv_FetchByID(id, &rec)) {
		printf("\t\t\t�ݳ���������,�����������");
		getch();
		return 0;
	}

			printf("\n\n\t\t\t                        �޸��ݳ���\n");
			printf("\t\t\t******************************************************************\n");

	printf("\t\t\t�ݳ���ID:%d\n", rec.id);
	printf("\t\t\t�ݳ�������:", rec.name);
	getchar(); 
	gets(rec.name);

	List_Init(list, seat_node_t);
	seatcount = Seat_Srv_FetchByRoomID(list, rec.id);
	if (seatcount) {
		do {			//�����λ�ļ���������λ��Ϣ������µ����б������ǰ�󣬷����������
			printf("\t\t\t����(����� %d):", rec.rowsCount);
			scanf("\t\t\t%d", &(newrow));
			printf("\t\t\t����(����� %d):", rec.colsCount);
			scanf("%d", &(newcolumn));
		} while (newrow<rec.rowsCount || newcolumn<rec.colsCount);
		getchar();
		rec.rowsCount = newrow;
		rec.colsCount = newcolumn;
		rec.seatsCount = seatcount;
	}
	else {
		printf("\t\t\t����:");
		scanf("%d", &rec.rowsCount);
		printf("\t\t\t����:");
		scanf("%d", &rec.colsCount);
		rec.seatsCount = 0;
	}

	printf("\t\t\t-------------------------------------------------------\n");

	if (Studio_Srv_Modify(&rec)) {
		rtn = 1;
		printf("\t\t\t�޸ĳɹ�,��������˳�");
	}
	else
		printf("\t\t\t�޸�ʧ��,��������˳�");
	getch();
	return rtn;
}

int Studio_UI_Delete(int id) {

	int rtn = 0;

	if (Studio_Srv_DeleteByID(id)) {
		//��ɾ����ӳ��ʱ��ͬʱ���ݷ�ӳ��idɾ����λ�ļ��е���λ
		if (Seat_Srv_DeleteAllByRoomID(id))
		{
			printf("\t\t\tɾ���ɹ�,��������˳�\n");
			Sleep(2000);
		}
		rtn = 1;
	}
	else {
		//printf("\t\t\t�ݳ���������,��������˳�\n");
		Sleep(2000);
	}
	printf("\t\t\t");
	getch();
	return rtn;
}
