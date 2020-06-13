#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <stdlib.h>
#include "Play.h"
#include "Play_UI.h"
//#include "Schedule_UI.h"
#include "List.h"
#include "EntityKey_Persist.h"
#include "Play_Persist.h"

inline  char swap_charto_status_type(play_type_t status)
{
	if (status == PLAY_TYPE_FILE)
		return '1';
	if (status == PLAY_TYPE_OPEAR)
		return '2';
	if (status == PLAY_TYPE_CONCERT)
		return '3'; return '1';
}
inline  char swap_charto_status_rating(play_rating_t status)
{
	if (status == PLAY_RATE_CHILD);
	return '1';
	if (status == PLAY_RATE_TEENAGE)
		return '2';
	if (status == PLAY_RATE_ADULT)
		return '3'; return '1';
}

inline play_type_t swap_statusto_char_type(char status)
{
	if (status == '1')
		return PLAY_TYPE_FILE;
	if (status == '2')
		return PLAY_TYPE_OPEAR;
	if (status == '3')
		return PLAY_TYPE_CONCERT;
	return PLAY_TYPE_FILE;
}
inline play_rating_t swap_statusto_char_rating(char status)
{
	if (status == '1')
		return PLAY_RATE_CHILD;
	if (status == '2')
		return PLAY_RATE_TEENAGE;
	if (status == '3')
		return PLAY_RATE_ADULT;
	return PLAY_RATE_CHILD;
}

//����ID��ȡ��Ŀ
inline int Play_Srv_FetchByID(int id, play_t *buf) {
	if (Play_Perst_SelectByID(id, buf)){
		return 1;
	}
	else{
		return 0;
	}
}

//����IDɾ����Ŀ
inline int Play_Srv_DeleteByID(int ID) {
	if (Play_Perst_RemByID(ID))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//�޸ľ�Ŀ
inline int Play_Srv_Modify(const play_t *data) {
	if (Play_Perst_Update(data))
	{
		printf("�޸ĳɹ�!");
		return 1;
	}
	return 0;
}

/*void Play_UI_ShowList(play_list_t list, Pagination_t paging) {
return 0;
}*/

//�����Ŀ���� 
void Play_UI_MgtEntry(void)
{
	int i;
	int id;
	char choice;
	play_t buf;
	Pagination_t paging;
	play_list_t head;
	play_list_t pos;
	paging.offset = 0;
	paging.pageSize = PLAY_PAGE_SIZE;
	List_Init(head, play_node_t);
	//�������� 

	if (paging.totalRecords = Play_Srv_FetchAll(head)){	//���ļ��򿪳ɹ��������һ���Ĳ˵�
		Paging_Locate_FirstPage(head, paging);//��һҳ	 
		do{
			//���� 
			printf("=======================================   FILM  List   =====================================\n");
			printf("%5s %15s %5s %10s %10s %6s %10s %10s %10s\n", "��ĿID", "��Ӱ����", "����", "����",
				"�ȼ�", "ʱ��", "��ӳʱ��", "�¼�ʱ��", "�۸�");
			printf("--------------------------------------------------------------------------------------------\n");

			//��ʾ����
			Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i){
				//for(i=0,pos=(play_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
				printf("%5d %15s %5c %10s %10c %6d %5d-%02d-%02d %5d-%02d-%02d %8d\n",
					pos->data.id, pos->data.name, swap_charto_status_type(pos->data.type), pos->data.area,
					swap_charto_status_rating(pos->data.rating), pos->data.duration,
					pos->data.start_date.year, pos->data.start_date.month,
					pos->data.start_date.day, pos->data.end_date.year, pos->data.end_date.month,
					pos->data.end_date.day, pos->data.price);
			}
			printf("--------------------- �ܼ�¼:%2d ------------------------- ҳ %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("--------------------------------------------------------------------------------------------\n");

			printf("[P]��һҳ     [N]��һҳ      [A]��Ӿ�Ŀ        [D]ɾ����Ŀ  \n[U]�޸ľ�Ŀ   [Q]��ѯ��Ŀ  [S]���ž�Ŀ�ݳ��ƻ�  [R]eturn\n\n");

			printf("Your Choice:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);

			switch (choice)
			{
			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
				}
				break;

			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
				}
				break;

			case 'a':
			case 'A':
				if (Play_UI_Add(head)){
					//	paging.totalRecords=Play_Srv_FetchAll(head);
					paging.totalRecords += 1;
					Paging_Locate_LastPage(head, paging, play_node_t);
				}
				//		    	paging.totalRecords=Play_Srv_FetchAll(head);
				break;

			case 'd':
			case 'D':
				printf("����ID:");
				scanf("%d", &id);
				if (Play_UI_Delete(id)) {	//������������
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head, paging, play_node_t);
				}
				break;

			case 'u':
			case 'U':
				printf("�����ĿID:");
				scanf("%d", &id);
				fflush(stdin);
				if (Play_UI_Modify(id)) {	//������������
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head, paging, play_node_t);
				}
				break;
			case 'q':
			case 'Q':
				printf("�����ĿID:");
				scanf("%d", &id);
				if (Play_UI_Query(id)) {
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head, paging, play_node_t);
				}
				break;
			case 's':
			case 'S':
				printf("�����ĿID:");
				scanf("%d", &id);
				if (Play_Srv_FetchByID(id, &buf)) {
					//Schedule_UI_MgtEntry(id);
					break;
				}
				printf("û�д˾�Ŀ\n����[Enter]����:");
				fflush(stdin);
				getchar();
				break;

			}
		} while (choice != 'r' && choice != 'R');
	}
	//�ͷ�����ռ�
	List_Destroy(head, play_node_t);
}

//��ʶ����TTMS_SCU_Play_UI_Add
//����: ����¾�Ŀ���� ,ͨ������ҵ���߼��㽫������ӵ�Play.dat
//����˵������
//����ֵ������ 1���ɹ�   ��1��ʧ�� 
int Play_UI_Add(play_list_t list)
{
	int newCount = 0;
	play_t data;
	play_list_t rec;
	printf("\n=======================================================\n");
	printf("\t****************  ����¾�Ŀ ***************\n");
	printf("-------------------------------------------------------\n");
	printf("����Ҫ��ӵľ�Ŀ����:");
	gets(data.name);
	printf("��Ŀ����Area:");
	scanf("%s", data.area);
	printf("Type:\n");
	//	rec.type=swap_statusto_char_type(ch);
	printf("PLAY_TYPE_FILE=1\nPLAY_TYPE_OPEAR=2\nPLAY_TYPE_CONCERT=3\n��Ŀ���ͣ�");
	char ch;
	scanf("%c", &ch);
	data.type = swap_statusto_char_type(ch);
	getchar();
	printf("Rating:\n");
	printf("PLAY_RATE_CHILD=1\nPLAY_RATE_TEENAGE=2\nPLAY_RATE_ADULT=3\n�������Ŀ�ȼ���");
	getchar();
	scanf("%c", &ch);
	data.rating = swap_statusto_char_rating(ch);
	printf("��Ŀʱ��(����)Durating:");
	scanf("%d", &data.duration);
	printf("Start_date ��-��-�գ�");
	scanf("%d-%d-%d", &data.start_date.year, &data.start_date.month, &data.start_date.day);
	printf("End_date ��-��-�գ�");
	scanf("%d-%d-%d", &data.end_date.year, &data.end_date.month, &data.end_date.day);
	printf("�۸�Price:");
	scanf("%d", &data.price);
	data.id = EntKey_Perst_GetNewKeys("Play", 1);
	printf("=======================================================\n");
	if (Play_Srv_Add(&data)){
		rec = (play_list_t)malloc(sizeof(play_node_t));
		rec->data = data;
		List_AddTail(list, rec);
		newCount++;
		printf("�¾�Ŀ��ӳɹ���\n");
		return newCount;
	}
	printf("�¾�Ŀ���ʧ�ܣ�\n");
	return 0;
}


int Play_UI_Modify(int id) {
	play_t temp;
	int i;
	if (Play_Srv_FetchByID(id, &temp))
	{
		printf("%5s %15s %5s %10s %10s %6s %10s %10s %10s\n", "ID", "��Ӱ����", "��Ӱ����", "����",
			"�ȼ�", "ʱ��", "��ӳʱ��", "�¼�ʱ��", "�۸�");
		printf("%5d %15s %5c %10s %10c %6d %5d-%02d-%02d %5d-%02d-%02d %8d\n",
			temp.id, temp.name, swap_charto_status_type(temp.type), temp.area,
			swap_charto_status_rating(temp.rating), temp.duration,
			temp.start_date.year, temp.start_date.month, temp.start_date.day,
			temp.end_date.year, temp.end_date.month, temp.end_date.day, temp.price);
	}
	else
	{
		printf("��play.dat��û���ҵ���Ŀ\n�� [enter]����");
		getchar();
		return 0;
	}
	printf("����þ�Ŀ������Ϣ\n");
	printf("��Ŀ����:");
	scanf("%s", temp.name);
	printf("��Ʒ����:");
	scanf("%s", temp.area);
	printf("PLAY_TYPE_FILE=1\nPLAY_TYPE_OPEAR=2\nPLAY_TYPE_CONCERT=3\n��Ŀ����");
	scanf("%d", &temp.type);
	printf("PLAY_RATE_CHILD=1\nPLAY_RATE_TEENAGE=2\nPLAY_RATE_ADULT=3\n��Ŀ�ȼ�");
	scanf("%d", &temp.rating);
	printf("��Ŀʱ��:");
	scanf("%d", &temp.duration);
	printf("��ӳʱ��:");
	scanf("%d-%d-%d", &temp.start_date.year, &temp.start_date.month, &temp.start_date.day);
	printf("�¼�ʱ��:");
	scanf("%d-%d-%d", &temp.end_date.year, &temp.end_date.month, &temp.end_date.day);
	printf("����Ʊ��:");
	scanf("%d", &temp.price);
	getchar();
	int rec = Play_Srv_Modify(&temp);
	if (!rec)
	{
		printf("�޸�����ʧ��");
		printf("��������˳�\n");
		getchar();
		return 0;
	}
	return 1;
}
int Play_UI_Delete(int id) {
	char ch;
	play_t temp;
	if (Play_Srv_FetchByID(id, &temp))
	{
		Play_Srv_DeleteByID(id);
	}
	else
	{
		printf("δ�ҵ�ID %d�ľ�Ŀ��Ϣ\n", id);
	}
	printf("��������˳�\n");
	getchar();
	return 0;
}

int Play_UI_Query(int id) {
	int tmp;
	int i;
	play_t temp;
	tmp = Play_Srv_FetchByID(id, &temp);
	if (!tmp)
	{
		printf("û�����ID\n");
		getchar();
		return 0;
	}
	else
	{
		for (i = 0; i<109; i++)putchar('-');
		putchar('\n');
		printf("%5s %15s %5s %10s %10s %6s %10s %10s %10s\n", "ID", "��Ӱ����", "��Ӱ����", "����",
			"�ȼ�", "ʱ��", "��ӳʱ��", "�¼�ʱ��", "�۸�");
		printf("%5d %15s %5c %10s %10c %6d %5d-%02d-%02d %5d-%02d-%02d %8d\n",
			temp.id, temp.name, swap_charto_status_type(temp.type), temp.area,
			swap_charto_status_rating(temp.rating), temp.duration,
			temp.start_date.year, temp.start_date.month, temp.start_date.day,
			temp.end_date.year, temp.end_date.month, temp.end_date.day, temp.price);
		for (i = 0; i<109; i++)putchar('-');
		putchar('\n');
		fflush(stdin);
		printf("���س��˳�");
		getchar();
		return 1;
		//        printf("\n[C]�ݳ��ƻ�����|[R]����\n");
		//		printf("����ѡ��:");
		//		char choice;
		//		fflush(stdin);
		//		scanf("%c",&choice);
		//		if(choice=='C' || choice == 'c'){
		//		Schedule_UI_Query(id);
		//		}
		//        return 1;
	}
}