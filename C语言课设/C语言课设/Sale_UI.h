#ifndef SALE_UI_H_
#define SALE_UI_H_
#include"Play.h"
#include "Schedule.h"
#include "Seat.h"
//#include "Account.h"
#include "Ticket.h"
//���ݾ�ĿID��ʾ�ݳ��ƻ�
void Sale_UI_ShowScheduler(int playID);
//��Ʊ����
inline int Sale_UI_SellTicket(ticket_list_t tickList, seat_list_t seatList);
//������Ʊ��������
void Sale_UI_MgtEntry(void);
//��Ʊ
void Sale_UI_ReturnTicket();

int Sale_UI_ShowTicket(int schedule_id);
#endif
