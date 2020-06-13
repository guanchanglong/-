#ifndef TICKET_UI_H_
#define TICKET_UI_H_
#include "List.h"
#include "Ticket.h"
#include "Seat.h"
#include "Schedule.h"

static const int TICKET_PAGE_SIZE = 8;

int Ticket_UI_MgtEntry(int schedule_id);

void Ticket_UI_Query(void);

int Ticket_UI_ShowTicket(int ticket_id);

void Ticket_UI_Print(const ticket_t data);

#endif /* TICKET_UI_H_ */