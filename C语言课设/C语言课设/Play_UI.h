
#ifndef PLAY_UI_H_
#define PLAY_UI_H_
#include "List.h"
#include "Play.h"

static const int PLAY_PAGE_SIZE = 6;

//��ʶ����TTMS_SCU_Play_UI_Add
//����: ����¾�Ŀ���� 
int Play_UI_Add(play_list_t list);

//��ʶ����TTMS_SCU_Play_UI_Mod 
//���ܣ��޸ľ�Ŀ���� 
int Play_UI_Modify(int id);

//��ʶ����TTMS_SCU_Play_UI_Del 
//���ܣ�ɾ����Ŀ���� 
int Play_UI_Delete(int id);

//��ʶ����TTMS_SCU_Play_UI_Qry 
//���ܣ���ѯ��Ŀ���� 
int Play_UI_Query(int id);

/*���б�ģʽ��ʾ��Ŀ��Ϣ*/
void Play_UI_ShowList(play_list_t list, Pagination_t paging);

//��ʶ����TTMS_SCU_Play_UI_MgtEnt
//���ܣ������Ŀ����
void Play_UI_MgtEntry(void);

#endif /* PLAY_UI_H_ */
