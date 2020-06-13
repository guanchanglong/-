
#ifndef PLAYPERSIST_H_
#define PLAYPERSIST_H_

#include "Play.h"
//标识符：TTMS_SCU_Play_Perst_SelAll
//功能：载入全部剧目
int Play_Perst_SelectAll(play_list_t list);

//标识符：TTMS_SCU_Play_Perst_Insert
//功能:存储新剧目
int Play_Perst_Insert(play_t *data);

//标识符：TTMS_SCU_Play_Perst_Update
//功能：更新剧目 
int Play_Perst_Update(const play_t *data);

//标识符：TTMS_SCU_Play_Perst_RemByID
//功能：根据ID去除剧目
int Play_Perst_RemByID(int id);

//标识符：TTMS_SCU_Play_Perst_SelByID
//功能：根据ID载入剧目
int Play_Perst_SelectByID(int id, play_t *buf);

int Play_Perst_SelectByName(play_list_t list, char condt[]);


#endif /* PLAYPERSIST_H_ */