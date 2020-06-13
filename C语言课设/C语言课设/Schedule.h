#ifndef SCHEDULE_H_
#define SCHEDULE_H_

#include "common.h"

typedef struct {
	int id;//演出计划 
	int play_id;
	int studio_id;
	ttms_date_t date;
	ttms_time_t time;
	int seat_count;
}schedule_t;

//双向链表
typedef struct schedule_node {
	schedule_t data;
	struct schedule_node *next, *prev;
} schedule_node_t, *schedule_list_t;

int Schedule_Srv_Add(const schedule_t *data);

int Schedule_Srv_Modify(const schedule_t *data);

int Schedule_Srv_DeleteByID(int ID);

int Schedule_Srv_FetchByID(int ID, schedule_t *buf);

int Schedule_Srv_FetchAll(schedule_list_t list);

int Schedule_Srv_FetchByPlay(schedule_list_t list, int play_id);

//根据剧目ID获取票房
int Schedule_Srv_StatRevByPlay(int play_id, int soldCount);



#endif //SCHEDULE_H_