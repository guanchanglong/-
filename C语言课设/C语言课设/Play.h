#ifndef PLAY_H_
#define PLAY_H_

#include "common.h"

typedef enum {
	PLAY_TYPE_FILE = 1,
	PLAY_TYPE_OPEAR = 2,
	PLAY_TYPE_CONCERT = 3
} play_type_t;
/*
typedef struct{
int year;
int month;
int day;
}ttms_date_t;*/

typedef enum {
	PLAY_RATE_CHILD = 1,
	PLAY_RATE_TEENAGE = 2,
	PLAY_RATE_ADULT = 3
} play_rating_t;

typedef struct {
	int id;
	char name[31];
	play_type_t type;
	char area[9];
	play_rating_t rating;
	int duration; //�Է���Ϊ��λ
	ttms_date_t start_date;
	ttms_date_t end_date;
	int price;
} play_t;

//˫������
typedef struct play_node {
	play_t data;
	struct play_node *next, *prev;
} play_node_t, *play_list_t;

//��ʶ����TTMS_SCU_Play_Srv_FechALL 
//���ܣ���ȡȫ����Ŀ
int Play_Srv_FetchAll(play_list_t list);

//��ʶ����TTMS_SCU_Play_Srv_Add
//���ܣ�����¾�Ŀ 
int Play_Srv_Add(play_t*data);

//��ʶ����TTMS_SCU_Play_Srv_Mod
//���ܣ��޸ľ�Ŀ
int Play_Srv_Modify(const play_t *data);

//��ʶ����TTMS_SCU_Play_Srv_DelByID
//���ܣ�����IDɾ����Ŀ 
int Play_Srv_DeleteByID(int id);

//��ʶ����TTMS_SCU_Play_Srv_FetchByID
//���ܣ�����ID��ȡ��Ŀ
int Play_Srv_FetchByID(int id, play_t *buf);

//���ݾ�Ŀ���������Ŀ����������ľ�Ŀ����
int Play_Srv_FetchByName(play_list_t list, char condt[]);

//���ݾ�Ŀ���ƹ��˴�filter��list���й��ˣ����ع��˺�ʣ��ľ�Ŀ����
int Play_Srv_FilterByName(play_list_t list, char filter[]);

void Play_Srv_Print(play_list_t list);//��ӡ 
#endif //PLAY_H_

