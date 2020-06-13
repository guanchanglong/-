#define _CRT_SECURE_NO_DEPRECATE 0
#include "Sale_Persist.h"

//添加新订单信息
int Sale_Srv_Add(sale_t *data){
	return Sale_Perst_Insert(data);
}

int Sale_Srv_FetchByticket(int ticket_id, sale_t *sale)//+
{
	// return 0;
	return Sale_Perst_SelByTicketID(ticket_id, sale);
}

//根据票ID获取销售记录
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){

	return Sale_Perst_SelByTicketID(ticket_id, sale);

}

int Sale_Srv_Modify(const sale_t *data)
{
	return Sale_Perst_Update(data);
}

//
////修改票状态
//int Ticket_Srv_Modify (const ticket_t *data){
//	return 0;
//}
//
//
////根据演出计划ID获取票的数据
//int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id){
//	return 0;
//
//}
//
//
////根据ID获取票
//ticket_node_t * Ticket_Srv_FetchBySeatID (ticket_list_t list, int seat_id){
//	return 0;
//}