#ifndef SLAEINGPERSIST_H
#define SALEINGPERSIST_H

#include "Sale.h"
#include "common.h"

//存储新订单
int Sale_Perst_Insert(sale_t *data);
//更新票状态
int Ticket_Perst_Update(const ticket_t *data);

//根据演出计划ID载入票的数据
int Ticket_Srv_SelBySchID(int id, ticket_list_t list);

//根据票ID载入销售记录
int Sale_Perst_SelByTicketID(int ticket_id, sale_t *sale);

//根据ID载入销售记录
int Sale_Perst_SelByID(sale_list_t list, int usrID);


int Sale_Perst_Update(const sale_t *data);
#endif