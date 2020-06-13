
#ifndef PLAY_UI_H_
#define PLAY_UI_H_
#include "List.h"
#include "Play.h"

static const int PLAY_PAGE_SIZE = 6;

//标识符：TTMS_SCU_Play_UI_Add
//功能: 添加新剧目界面 
int Play_UI_Add(play_list_t list);

//标识符：TTMS_SCU_Play_UI_Mod 
//功能：修改剧目界面 
int Play_UI_Modify(int id);

//标识符：TTMS_SCU_Play_UI_Del 
//功能：删除剧目界面 
int Play_UI_Delete(int id);

//标识符：TTMS_SCU_Play_UI_Qry 
//功能：查询剧目界面 
int Play_UI_Query(int id);

/*以列表模式显示剧目信息*/
void Play_UI_ShowList(play_list_t list, Pagination_t paging);

//标识符：TTMS_SCU_Play_UI_MgtEnt
//功能：管理剧目界面
void Play_UI_MgtEntry(void);

#endif /* PLAY_UI_H_ */
