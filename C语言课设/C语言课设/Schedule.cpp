#define _CRT_SECURE_NO_DEPRECATE 0
#include "Schedule.h"
#include "List.h"
#include "Schedule_Persist.h"
#include "Ticket.h"
#include <stdio.h>

int Schedule_Srv_FetchByPlay(schedule_list_t list, int play_id) {
	return Schedule_Perst_SelectByPlay(list, play_id);

}

int Schedule_Srv_Add(const schedule_t *data) {
	return Schedule_Perst_Insert(data);
}


int Schedule_Srv_Modify(const schedule_t *data) {
	return Schedule_Perst_Update(data);
}


int Schedule_Srv_DeleteByID(int ID) {
	return Schedule_Perst_DeleteByID(ID);
}

int Schedule_Srv_FetchAll(schedule_list_t list){
	return Schedule_Perst_SelectAll(list);
}

inline int Schedule_Srv_FetchByID(int ID, schedule_t *buf) {
	return Schedule_Perst_SelectByID(ID, buf);

}

//根据剧目ID获取票房
int Schedule_Srv_StatRevByPlay(int play_id, int soldCount){
	int value = 0, sold = 0;
	schedule_list_t list;
	schedule_node_t * p;
	soldCount = 0;
	List_Init(list, schedule_node_t);
	Schedule_Perst_SelectByPlay(list, play_id);
	List_ForEach(list, p){
		soldCount = soldCount + sold;
		value += Ticket_Srv_StatRevBySchID(p->data.id, &sold);
	}
	List_Destroy(list, schedule_node_t);
	return value;

}
