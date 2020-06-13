#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Play.h"
#include "List.h"
//#include "Ticket.h"
#include "Play_Persist.h"
#include <string.h>
#include<stdio.h>


//��ʶ����TTMS_SCU_Play_Srv_Add
//���ܣ�����¾�Ŀ 
//����ֵ������ 1���ɹ� ��1��ʧ�� 
int Play_Srv_Add(play_t *data){
	if (Play_Perst_Insert(data))
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

inline int Play_Srv_FetchByID(int id, play_t *buf) {
	if (Play_Perst_SelectByID(id, buf)){
		return 1;
	}
	else{
		return 0;
	}
}


//��ʶ����TTMS_SCU_Play_Srv_FechALL 
//���ܣ���ȡȫ����Ŀ
//����ֵ�����ͣ���ʾ��ȡ�ľ�Ŀ��Ϣ������ 
int Play_Srv_FetchAll(play_list_t list){
	return Play_Perst_SelectAll(list);
}


//���ݾ�Ŀ���������Ŀ����������ľ�Ŀ����
int Play_Srv_FetchByName(play_list_t list, char condt[]){
	return Play_Perst_SelectByName(list, condt);
}



//���ݾ�Ŀ���ƹ��˴�filter��list���й��ˣ����ع��˺�ʣ��ľ�Ŀ����
int Play_Srv_FilterByName(play_list_t list, char filter[]){
	int rtn = 0;
	if (!List_IsEmpty(list)){
		return rtn;
	}
	play_list_t curPos;
	List_ForEach(list, curPos){
		if (strstr(curPos->data.name, filter)){
			rtn++;
		}
		else{
			List_FreeNode(curPos);
		}
	}
	return rtn;
}