#define _CRT_SECURE_NO_DEPRECATE 0
#include "Sale_Persist.h"

//����¶�����Ϣ
int Sale_Srv_Add(sale_t *data){
	return Sale_Perst_Insert(data);
}

int Sale_Srv_FetchByticket(int ticket_id, sale_t *sale)//+
{
	// return 0;
	return Sale_Perst_SelByTicketID(ticket_id, sale);
}

//����ƱID��ȡ���ۼ�¼
int Sale_Srv_FetchByTicketID(int ticket_id, sale_t *sale){

	return Sale_Perst_SelByTicketID(ticket_id, sale);

}

int Sale_Srv_Modify(const sale_t *data)
{
	return Sale_Perst_Update(data);
}

//
////�޸�Ʊ״̬
//int Ticket_Srv_Modify (const ticket_t *data){
//	return 0;
//}
//
//
////�����ݳ��ƻ�ID��ȡƱ������
//int Ticket_Srv_FetchBySchID(ticket_list_t list, int schedule_id){
//	return 0;
//
//}
//
//
////����ID��ȡƱ
//ticket_node_t * Ticket_Srv_FetchBySeatID (ticket_list_t list, int seat_id){
//	return 0;
//}