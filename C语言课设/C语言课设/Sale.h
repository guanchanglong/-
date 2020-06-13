#ifndef SALE_H_
#define SALE_H_
#include "common.h"
#include "Account.h"
#include "Ticket.h"

//交易类型，为售票或退票
typedef enum{
	SALE_SELL = 1,	//买票
	SALE_RETURN = -1	//退票
}sale_type_t;


typedef struct {
	int id;      		//销售记录ID
	int user_id;		//售票员ID
	int ticket_id;		//票ID
	ttms_date_t date;	//处理日期
	ttms_time_t time;	//处理时间
	int value;			//票价
	sale_type_t type; //交易类型
}sale_t;

//双向链表
typedef struct sale_node {
	sale_t data;
	struct sale_node *next, *prev;
} sale_node_t, *sale_list_t;

//添加新订单信息
int Sale_Srv_Add(sale_t *data);
//修改票状态
int Ticket_Srv_Modify(const ticket_t *data);

int Sale_Srv_FetchByticket(int schedule_id, sale_t *sale);
//根据演出计划ID获取票的数据
//int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id);

//根据演出计划ID获取票的数据
//int Ticket_Srv_FetchBySchID(int ID, ticket_list_t list);

//根据ID获取票
ticket_node_t * Ticket_Srv_FetchBySeatID(ticket_list_t list, int seat_id);

int Sale_Srv_Modify(const sale_t *data);

int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale);
#endif //SALE_H_
