#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include "Ticket_UI.h"
#include "List.h"
#include "Ticket.h"
#include "Schedule.h"
#include "Play.h"
#include "Studio.h"
#include <stdio.h>
#include <stdlib.h>

int Ticket_UI_MgtEntry(int schedule_id) {
	int i, id;
	int studio_id;
	char choice;
	schedule_t buf;
	play_t data;
	Schedule_Srv_FetchByID(schedule_id, &buf);
	Play_Srv_FetchByID(buf.play_id, &data);
	printf("===============================================================\n");
	printf("%10s     %5s%10s%10s    \n", "剧目名字", "演出厅ID", "日期", "时间");
	printf("%10s     %5d     %5d-%02d-%02d  %02d:%02d:%02d\n", data.name, buf.studio_id,
		buf.date.year, buf.date.month,
		buf.date.day, buf.time.hour, buf.time.minute, buf.time.second);
	printf("  [G]生成演出票      [C]重新生成票\n");
	setbuf(stdin, NULL);
	scanf("%c", &choice);
	getchar();
	switch (choice)
	{
	case'G':
	case'g':
		Ticket_Srv_GenBatch(schedule_id);
		//printf("successful !");
		break;
	case'c':
	case'C':
		Ticket_Srv_DeleteBatch(schedule_id);
		Ticket_Srv_GenBatch(schedule_id);
		//printf("successful !");
		break;
	}
	return 0;
}

void Ticket_UI_Query(void) {
	printf("==================================================\n");
	printf("******************查询门票*********************\n");
	printf("请输入门票的ID:");

	int id;
	scanf("%d", &id);
	getchar();

	Ticket_UI_ShowTicket(id);
}

int Ticket_UI_ShowTicket(int ticket_id) {
	ticket_t buf;
	int temp = Ticket_Srv_FetchByID(ticket_id, &buf);
	if (temp == 0)
	{
		printf("该门票不存在!\n");
	}
	else
	{
		printf("门票ID      演出计划ID      座位ID      门票价格      门票状态    \n");
		printf("%6d  %6d     %6d    %6d   %6d    \n", buf.id, buf.schedule_id, buf.seat_id, buf.price, buf.status);
	}
	return 0;
}