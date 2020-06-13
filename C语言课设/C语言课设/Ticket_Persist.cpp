#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Ticket_Persist.h"
#include "Schedule_Persist.h"
#include "EntityKey_Persist.h"	
#include "Play_Persist.h"
#include "Ticket.h"
#include "Seat.h"
#include "Play.h"
#include "List.h"
#include <stdlib.h>
#include <stdio.h>
#include "unistd.h"
#include <assert.h>

static const char TICKET_DATA_FILE[] = "Ticket.dat";
static const char TICKET_DATA_TEMP_FILE[] = "TicketTemp.dat";
static const char TICKET_KEY_NAME[] = "Ticket";

int Ticket_Perst_Insert(seat_list_t  list, int schedule_id)
{
	FILE *fp = fopen(TICKET_DATA_FILE, "ab+");
	int rtn = 0;
	seat_list_t temp;
	seat_list_t pos;
	schedule_t sch;
	ticket_t data;
	if (NULL == fp)
	{
		printf("the file not exist!\n");
		return 0;
	}
	play_t buf;
	Schedule_Perst_SelectByID(schedule_id, &sch);
	Play_Perst_SelectByID(sch.play_id, &buf);
	int key = EntKey_Perst_GetNewKeys("Ticket", 1);
	temp = list;
	pos = list->next;
	while (pos != temp)
	{
		data.id = EntKey_Perst_GetNewKeys("Ticket", 1);
		data.schedule_id = schedule_id;
		data.seat_id = pos->data.id;
		data.price = buf.price;
		data.status = TICKET_AVL;
		pos = pos->next;
		rtn = fwrite(&data, sizeof(ticket_t), 1, fp);
	}
	fclose(fp);
	return rtn;
}


int Ticket_Perst_Rem(int schedule_id){
	if (rename(TICKET_DATA_FILE, TICKET_DATA_TEMP_FILE) < 0)
	{
		printf("删除票失败 \n");
		return 0;
	}
	FILE *fpsour, *fpTarg;
	fpsour = fopen(TICKET_DATA_TEMP_FILE, "rb");
	if (NULL == fpsour)
	{
		printf("不能打开文件%s\n", TICKET_DATA_FILE);
		return 0;
	}
	fpTarg = fopen(TICKET_DATA_FILE, "wb");
	if (NULL == fpTarg)
	{
		printf("不能打开文件 %s!\n", TICKET_DATA_TEMP_FILE);
		return 0;
	}
	int found = 0;
	ticket_t buf;
	while (!feof(fpsour))
	{
		if (fread(&buf, sizeof(ticket_t), 1, fpsour))
		{
			if (buf.schedule_id == schedule_id)
			{
				found += 1;
				continue;
			}
			fwrite(&buf, sizeof(ticket_t), 1, fpTarg);

		}
	}
	fclose(fpsour);
	fclose(fpTarg);
	remove(TICKET_DATA_TEMP_FILE);
	return found;
}

//根据ID载入演出票
int Ticket_Perst_SelByID(int id, ticket_t *buf){
	int found = 0;
	ticket_t data;
	FILE *fp = fopen(TICKET_DATA_FILE, "rb");
	if (fp == NULL)
	{
		return 0;
	}

	while (!feof(fp))
	{
		if (fread(&data, sizeof(ticket_t), 1, fp))
		{
			if (id == data.id)
			{
				*buf = data;
				found = 1;
				break;
			}
		}
	}
}


int Ticket_Perst_Update(const ticket_t * data)
{
	assert(NULL != data);
	int found = -1;
	FILE *fp = fopen(TICKET_DATA_FILE, "rb+");

	if (NULL == fp)
	{
		printf("the file is not exit\n!");
		return -1;
	}
	ticket_t temp;
	while (!feof(fp))
	{
		if (fread(&temp, sizeof(ticket_t), 1, fp))
		{
			if (temp.id == data->id)
			{
				fseek(fp, -((int)sizeof(ticket_t)), SEEK_CUR);
				found = 1;
				fwrite(data, sizeof(ticket_t), 1, fp);
				break;
			}
		}
	}
	fclose(fp);
	return found;
}


int Ticket_Perst_SelBySchID(int id, ticket_list_t list)
{
	int count = 0;

	FILE *fp = fopen(TICKET_DATA_FILE, "rb");

	if (NULL == fp)
	{
		printf("the file is not exit");
		return 0;
	}

	ticket_t data;
	ticket_list_t  newNode;

	while (!feof(fp))
	{
		if (fread(&data, sizeof(ticket_t), 1, fp))
		{
			if (data.schedule_id == id)
			{
				count++;
				newNode = (ticket_node_t *)malloc(sizeof(ticket_node_t));
				newNode->data = data;
				List_AddTail(list, newNode);
			}
		}
	}

	fclose(fp);
	return count;
}

//
int Ticket_Perst_SelByseatID(int id, ticket_t *buf, int schedule_id)
{
	int found = 0;
	ticket_t data;
	FILE *fp = fopen(TICKET_DATA_FILE, "rb");
	if (fp == NULL)
	{
		return 0;
	}
	while (!feof(fp))
	{
		if (fread(&data, sizeof(ticket_t), 1, fp))
		{
			if (id == data.seat_id  && schedule_id == data.schedule_id)
			{
				*buf = data;
				found = 1;
				break;
			}
		}
	}
}