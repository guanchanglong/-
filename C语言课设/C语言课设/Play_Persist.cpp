#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Play_Persist.h"
#include "Play.h"
#include "List.h"
#include "EntityKey_Persist.h"
#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"
#include <assert.h>
#include <string.h>
#include <io.h>

static const char PLAY_DATA_FILE[] = "Play.dat";
static const char PLAY_DATA_TEMP_FILE[] = "PlayTmp.dat";
static const char PLAY_KEY_NAME[] = "Play";

//标识符：TTMS_SCU_Play_Perst_Insert
//功能:存储新剧目
int Play_Perst_Insert(play_t *data){
	//	data->id=EntKey_Perst_GetNewKeys(data->name,1);
	FILE *fp;
	int rtn = 0;
	fp = fopen(PLAY_DATA_FILE, "ab+");
	if (fp == NULL){
		printf("Open file  Play.dat failed!");
		return 0;
	}
	rtn = fwrite(data, sizeof(play_t), 1, fp);
	//	if(rtn==1) printf("存入文件成功!\n");
	//	else printf("存入文件失败!\n");
	fclose(fp);
	return rtn;
}

int Play_Perst_Update(const play_t *data) {
	FILE *fp;
	play_t tmp;

	int count = 0;
	fp = fopen(PLAY_DATA_FILE, "rb+");
	if (fp == NULL)
	{
		printf("\n");
		return 0;
	}
	while (1)
	{
		if (fread(&tmp, sizeof(play_t), 1, fp)<1)
			break;
		if (data->id == tmp.id)                  //找到修改的ID
		{
			count = 1;
			fpos_t pos;
			fgetpos(fp, &pos);
			fseek(fp, -(int)sizeof(play_t), SEEK_CUR);
			fwrite(data, sizeof(play_t), 1, fp);
			fsetpos(fp, &pos);
			break;
		}
	}
	if (!count) printf("\n");
	fclose(fp);
	printf("\n");
	return count;
}

int Play_Perst_RemByID(int ID) {
	//将原始文件重命名，然后读取数据重新写入到数据文件中，并将要删除的实体过滤掉。
	//借助辅助文件，实现记录删除
	FILE *fp_read = fopen(PLAY_DATA_FILE, "rb");
	FILE *fp_write = fopen(PLAY_DATA_TEMP_FILE, "wb");
	if (!fp_read || !fp_write)
	{
		printf("open file for Delete is failed!\n");
		return 0;
	}
	play_t tmp;
	static int count = 0;
	while (1)
	{
		if (fread(&tmp, sizeof(play_t), 1, fp_read)<1)
			break;
		if (ID != tmp.id)
		{
			fwrite(&tmp, sizeof(play_t), 1, fp_write);
		}
		else
		{
			count++;
		}
	}
	fclose(fp_read);
	fclose(fp_write);
	remove(PLAY_DATA_FILE);
	rename(PLAY_DATA_TEMP_FILE, PLAY_DATA_FILE);
	if (count) return 1;
	return 0;
}


int Play_Perst_SelectByID(int ID, play_t *buf) {
	FILE *fp;
	int found = 0;
	play_t data;
	if ((fp = fopen(PLAY_DATA_FILE, "rb")) == NULL){
		printf("%s打开失败!\n", PLAY_DATA_FILE);
		return found;
	}
	while (!feof(fp)) {
		if (fread(&data, sizeof(play_t), 1, fp)) {
			if (data.id == ID) {
				*buf = data;
				found = 1;
				break;
			}
		}
	}
	fclose(fp);
	return found;
}


//标识符：TTMS_SCU_Play_Perst_SelAll
//功能：载入全部剧目
//返回值：整型，表示载入的剧目数量 
int Play_Perst_SelectAll(play_list_t list){
	FILE *fp;
	play_t tmp;
	int recCount = 0;
	play_node_t *newNode;
	fp = fopen(PLAY_DATA_FILE, "rb");
	//List_Init(list,play_node_t);
	if (!fp){
		printf("打开文件失败\n");
		return 0;
	}
	else{
		while (1){
			if (fread(&tmp, sizeof(play_t), 1, fp)<1)
				break;
			newNode = (play_node_t *)malloc(sizeof(play_node_t));
			newNode->data = tmp;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}


int Play_Perst_SelectByName(play_list_t list, char condt[]) {
	assert(NULL != list);
	List_Free(list, play_node_t);

	int recCount = 0;
	FILE *fp;
	play_t buf;
	play_list_t newNode;
	if ((fp = fopen(PLAY_DATA_FILE, "rb")) == NULL){
		printf("%s打开失败!", PLAY_DATA_FILE);
		return 0;
	}
	while (!feof(fp)){
		fread(&buf, sizeof(buf), 1, fp);
		if (strstr(buf.name, condt)){
			if ((newNode = (play_list_t)malloc(sizeof(play_node_t)))){
				printf("内存申请失败!\n");
				break;
			}
			newNode->data = buf;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}

