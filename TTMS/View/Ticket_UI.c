#include "Ticket_UI.h"
#include "Sale_UI.h"
#include "Sale.h"
#include "List.h"
#include "Ticket.h"
#include "Schedule.h"
#include "Play.h"
#include "Studio.h"

#include <stdio.h>
#include <stdlib.h>


void Ticket_UI_Query(void) {
	int id;
	printf("\n\t\t\t\t\t票的ID:");
	scanf("%d",&id);
	Ticket_UI_ShowTicket(id);
}

int Ticket_UI_ShowTicket(int ticket_id) {
	ticket_t buf, data;
	sale_t sale;
	system("cls");
	printf("\n\n\n\n\n") ;
	if (Ticket_Srv_FetchByID(ticket_id, &buf))
	{
		if (buf.status == 1)
		{
			data.id = buf.id;
			data.schedule_id = buf.schedule_id;
			data.seat_id = buf.seat_id;
			data.status = 1;

			Ticket_Info(&data);
			printf("\t\t\t\t    状态:已售\n");
			printf("\n\t\t\t\t    任意键返回");
			getch();

		}
		else
		{
			data.id = buf.id;
			data.schedule_id = buf.schedule_id;
			data.seat_id = buf.seat_id;
			data.status = 1;
			
			Ticket_Info(&data);
			printf("\t\t\t\t    状态:未售\n");
			printf("\n\t\t\t\t    任意键返回");
			getch();


		}
	}
	else
	{
		printf("\t\t\t\t        无此票,任意键返回");
		getch();
	}
    return 0;
}
