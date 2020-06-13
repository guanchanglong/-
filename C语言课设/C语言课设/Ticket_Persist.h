#ifndef TICKETPERSIST_H_
#define TICKETPERSIST_H_

#include "Ticket.h"
#include "Seat.h"
#include "EntityKey_Persist.h"


int  Ticket_Perst_Insert(seat_list_t list, int schedule_id);//生成演出计划时，批量生成票
//int Ticket_Perst_Insert(ticket_list_t list);
int Ticket_Perst_Rem(int schedule_id);

int Ticket_Perst_Update(const ticket_t * data);

int Ticket_Perst_SelectByID(int ID, ticket_t *buf);

int Ticket_Perst_SelectAll(ticket_list_t list);

int Ticket_Perst_SelectBySchID(int schedule_id, ticket_list_t list);

int Ticket_Perst_SelByID(int id, ticket_t *buf);

int Ticket_Perst_SelByseatID(int id, ticket_t *buf, int schedule_id);

int Ticket_Perst_SelBySchID(int id, ticket_list_t list);
#endif /* TICKETPERSIST_H_ */