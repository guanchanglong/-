#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Schedule_Persist.h"
#include "Schedule.h"
#include "List.h"
#include "Ticket.h"
#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"

static const char SCHEDULE_DATA_FILE[] = "Schedule.dat";//保存演出计划信息
static const char SCHEDULE_DATA_TEMP_FILE[] = "ScheduleTmp.dat";////删除或更新时，暂时保存演出计划信息

int Schedule_Perst_SelectByPlay(schedule_list_t list, int play_id){
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}

	List_Free(list, schedule_node_t);
	schedule_t data;
	int recCount = 0;
	schedule_node_t *newNode;

	while (!feof(fp)) {
		if (fread(&data, sizeof(schedule_t), 1, fp)) {
			newNode = (schedule_node_t*)malloc(sizeof(schedule_node_t));
			if (!newNode) {
				printf("Warning, Memory OverFlow!!!\n Cannot Load more Data into memory!!!\n");
				break;
			}
			if (data.play_id == play_id)
			{
				newNode->data = data;
				List_AddTail(list, newNode);
				recCount++;
			}
		}
	}
	fclose(fp);
	return recCount;
}


int Schedule_Perst_Insert(const schedule_t *data){
	FILE *fp;
	int rtn = 0;
	fp = fopen(SCHEDULE_DATA_FILE, "ab+");
	if (fp == NULL){
		printf("Open file  Schedule.dat failed!");
		return 0;
	}
	rtn = fwrite(data, sizeof(schedule_t), 1, fp);
	fclose(fp);
	return rtn;
}



int Schedule_Perst_Update(const schedule_t *data){
	FILE *fp;
	schedule_t tmp;
	int count = 0;
	fp = fopen(SCHEDULE_DATA_FILE, "rb+");
	if (fp == NULL)
	{
		printf("\n");
		return 0;
	}
	while (1)
	{
		if (fread(&tmp, sizeof(schedule_t), 1, fp)<1)
			break;
		if (data->id == tmp.id)                  //找到修改的ID
		{
			count = 1;
			fpos_t pos;
			fgetpos(fp, &pos);
			fseek(fp, -(int)sizeof(schedule_t), SEEK_CUR);
			fwrite(data, sizeof(schedule_t), 1, fp);
			fsetpos(fp, &pos);
			break;
		}
	}
	if (!count) printf("\n");
	fclose(fp);
	printf("\n");
	return count;
}


int Schedule_Perst_RemByID(int ID)
{
	if (rename(SCHEDULE_DATA_FILE, SCHEDULE_DATA_TEMP_FILE)<0) {
		printf("打开文件失败!\n");
		return 0;
	}

	FILE *fpSour, *fpTarg;
	fpSour = fopen(SCHEDULE_DATA_TEMP_FILE, "rb");
	if (NULL == fpSour) {
		printf("打开文件失败!\n");
		return 0;
	}

	fpTarg = fopen(SCHEDULE_DATA_FILE, "wb");
	if (NULL == fpTarg) {
		printf("打开文件失败!\n");
		return 0;
	}
	schedule_t buf;

	int found = 0;
	while (!feof(fpSour))
	{
		if (fread(&buf, sizeof(schedule_t), 1, fpSour))
		{
			if (ID == buf.id)
			{
				found = 1;
				continue;
			}
			fwrite(&buf, sizeof(schedule_t), 1, fpTarg);//一个数据一个数据写入，当遇到要删除的数据就跳过
		}
	}
	fclose(fpTarg);
	fclose(fpSour);

	remove(SCHEDULE_DATA_FILE);//删除临时文件 
	rename(SCHEDULE_DATA_TEMP_FILE, SCHEDULE_DATA_FILE);
	return found;
}
//
int Schedule_Perst_SelectAll(schedule_list_t list) {
	FILE *fp;
	schedule_t tmp;
	int recCount = 0;
	schedule_node_t *newNode;
	fp = fopen(SCHEDULE_DATA_FILE, "rb");
	//List_Init(list,account_node_t);
	if (!fp){
		printf("打开文件失败\n");
		return 0;
	}
	else{
		while (1){
			if (fread(&tmp, sizeof(schedule_t), 1, fp)<1)
				break;
			newNode = (schedule_node_t *)malloc(sizeof(schedule_node_t));
			newNode->data = tmp;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}

int Schedule_Perst_SelectByID(int ID, schedule_t *buf){
	int rtn = 0;
	FILE *fp = fopen(SCHEDULE_DATA_FILE, "rb");
	if (fp == NULL){
		printf("%s打开失败!\n", SCHEDULE_DATA_FILE);
		return rtn;
	}
	schedule_t data;
	while (!feof(fp)) {
		if (fread(&data, sizeof(data), 1, fp)) {
			if (data.id == ID) {
				*buf = data;
				rtn = 1;
				break;
			}
		}
	}
	fclose(fp);
	return rtn;
}
int Schedule_Perst_DeleteByID(int ID){
	FILE *fp_read = fopen(SCHEDULE_DATA_FILE, "rb");
	FILE *fp_write = fopen(SCHEDULE_DATA_TEMP_FILE, "wb");
	if (!fp_read || !fp_write)
	{
		printf("open file for Delete is failed!\n");
		return 0;
	}
	schedule_t tmp;
	static int count = 0;
	while (1)
	{
		if (fread(&tmp, sizeof(schedule_t), 1, fp_read)<1)
			break;
		if (ID != tmp.id)
		{
			fwrite(&tmp, sizeof(schedule_t), 1, fp_write);
		}
		else
		{
			count++;
		}
	}
	fclose(fp_read);
	fclose(fp_write);
	remove(SCHEDULE_DATA_FILE);
	rename(SCHEDULE_DATA_TEMP_FILE, SCHEDULE_DATA_FILE);
	if (count) return 1;
	return 0;

}