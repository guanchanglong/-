#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Play.h"
#include "List.h"
//#include "Ticket.h"
#include "Play_Persist.h"
#include <string.h>
#include<stdio.h>


//标识符：TTMS_SCU_Play_Srv_Add
//功能：添加新剧目 
//返回值：整型 1：成功 非1：失败 
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

//修改剧目
inline int Play_Srv_Modify(const play_t *data) {
	if (Play_Perst_Update(data))
	{
		printf("修改成功!");
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


//标识符：TTMS_SCU_Play_Srv_FechALL 
//功能：获取全部剧目
//返回值：整型，表示获取的剧目信息的数量 
int Play_Srv_FetchAll(play_list_t list){
	return Play_Perst_SelectAll(list);
}


//根据剧目名称载入剧目，返回载入的剧目数量
int Play_Srv_FetchByName(play_list_t list, char condt[]){
	return Play_Perst_SelectByName(list, condt);
}



//根据剧目名称过滤词filter对list进行过滤，返回过滤后剩余的剧目数量
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