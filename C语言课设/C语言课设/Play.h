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
	int duration; //以分钟为单位
	ttms_date_t start_date;
	ttms_date_t end_date;
	int price;
} play_t;

//双向链表
typedef struct play_node {
	play_t data;
	struct play_node *next, *prev;
} play_node_t, *play_list_t;

//标识符：TTMS_SCU_Play_Srv_FechALL 
//功能：获取全部剧目
int Play_Srv_FetchAll(play_list_t list);

//标识符：TTMS_SCU_Play_Srv_Add
//功能：添加新剧目 
int Play_Srv_Add(play_t*data);

//标识符：TTMS_SCU_Play_Srv_Mod
//功能：修改剧目
int Play_Srv_Modify(const play_t *data);

//标识符：TTMS_SCU_Play_Srv_DelByID
//功能：根据ID删除剧目 
int Play_Srv_DeleteByID(int id);

//标识符：TTMS_SCU_Play_Srv_FetchByID
//功能：根据ID获取剧目
int Play_Srv_FetchByID(int id, play_t *buf);

//根据剧目名称载入剧目，返回载入的剧目数量
int Play_Srv_FetchByName(play_list_t list, char condt[]);

//根据剧目名称过滤词filter对list进行过滤，返回过滤后剩余的剧目数量
int Play_Srv_FilterByName(play_list_t list, char filter[]);

void Play_Srv_Print(play_list_t list);//打印 
#endif //PLAY_H_

