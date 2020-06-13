#ifndef SALE_UI_H_
#define SALE_UI_H_
#include"Play.h"
#include "Schedule.h"
#include "Seat.h"
//#include "Account.h"
#include "Ticket.h"
//根据剧目ID显示演出计划
void Sale_UI_ShowScheduler(int playID);
//售票界面
inline int Sale_UI_SellTicket(ticket_list_t tickList, seat_list_t seatList);
//管理售票的主界面
void Sale_UI_MgtEntry(void);
//退票
void Sale_UI_ReturnTicket();

int Sale_UI_ShowTicket(int schedule_id);
#endif
