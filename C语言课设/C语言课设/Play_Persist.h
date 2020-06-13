
#ifndef PLAYPERSIST_H_
#define PLAYPERSIST_H_

#include "Play.h"
//��ʶ����TTMS_SCU_Play_Perst_SelAll
//���ܣ�����ȫ����Ŀ
int Play_Perst_SelectAll(play_list_t list);

//��ʶ����TTMS_SCU_Play_Perst_Insert
//����:�洢�¾�Ŀ
int Play_Perst_Insert(play_t *data);

//��ʶ����TTMS_SCU_Play_Perst_Update
//���ܣ����¾�Ŀ 
int Play_Perst_Update(const play_t *data);

//��ʶ����TTMS_SCU_Play_Perst_RemByID
//���ܣ�����IDȥ����Ŀ
int Play_Perst_RemByID(int id);

//��ʶ����TTMS_SCU_Play_Perst_SelByID
//���ܣ�����ID�����Ŀ
int Play_Perst_SelectByID(int id, play_t *buf);

int Play_Perst_SelectByName(play_list_t list, char condt[]);


#endif /* PLAYPERSIST_H_ */