#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include "Sale_Persist.h"
#include "List.h"
#include "Sale.h"
#include "EntityKey_Persist.h"


static const char SALE_DATA_FILE[] = "Sale.dat";
static const char SALE_DATA_TEMP_FILE[] = "SaleTmp.dat";

//存储新订单
int Sale_Perst_Insert(sale_t *data){
	int rtn = 0;
	//	int key = EntKey_Perst_GetNewKeys("Sale",1);
	//	if(key <= 0)     return 0;
	//	data->id = key;
	//	data->id =EntKey_Perst_GetNewKeys("Sale",1);
	FILE *fp = fopen(SALE_DATA_FILE, "ab");

	if (NULL == fp)
	{
		printf("cannot open file %s!!\n", SALE_DATA_FILE);
		return 0;
	}

	rtn = fwrite(data, sizeof(sale_t), 1, fp);

	fclose(fp);

	return rtn;

}
//
////更新票状态
//int Ticket_Perst_Update (const ticket_t *data){
//	return 0;
//}
//
////根据演出计划ID载入票的数据
//int Ticket_Srv_SelBySchID(int id, ticket_list_t list){
//	return 0;
//}
//
//根据票ID载入销售记录
int Sale_Perst_SelByTicketID(int ticket_id, sale_t *sale){
	assert(NULL != sale);

	FILE *fp = fopen(SALE_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}

	sale_t data;
	int found = 0;

	while (!feof(fp)) {
		if (fread(&data, sizeof(sale_t), 1, fp)) {
			if (ticket_id == data.ticket_id) {
				*sale = data;
				found = 1;
				break;
			};

		}
	}
	fclose(fp);

	return found;
}

//根据ID载入销售记录
int Sale_Perst_SelByID(sale_list_t list, int usrID){
	sale_list_t newNode;
	sale_t data;

	int rtn = 0;

	assert(NULL != list);

	List_Free(list, sale_node_t);

	FILE *fp = fopen(SALE_DATA_FILE, "rb");
	if (NULL == fp)   return 0;

	while (!feof(fp))
	{
		if (fread(&data, sizeof(sale_t), 1, fp)<1)
		{
			newNode = (sale_list_t)malloc(sizeof(sale_node_t));
			newNode->data = data;

			if (!newNode)
			{
				printf("Waring,Memory OverFlow!!!\nCannot Load more Data into memory!!!\n");
				break;
			}
			if (usrID == data.id)
			{
				List_AddTail(list, newNode);
				rtn++;
			}
		}
	}

	fclose(fp);

	return rtn;
}

int Sale_Perst_Update(const sale_t *data)
{
	FILE *fp = fopen(SALE_DATA_FILE, "rb+");
	if (NULL == fp)
	{
		printf("%s打开失败！\n", SALE_DATA_FILE);
		return 0;
	}
	sale_t sale_tmp;
	int flag = 0;
	while (1)
	{
		if (fread(&sale_tmp, sizeof(sale_t), 1, fp)<1)
			break;
		if (data->ticket_id == sale_tmp.ticket_id)
		{
			flag = 1;
			fpos_t pos;
			fgetpos(fp, &pos);
			fseek(fp, -(int)sizeof(sale_t), SEEK_CUR);
			fwrite(data, sizeof(sale_t), 1, fp);
			fsetpos(fp, &pos);
			break;
		}
	}
	fclose(fp);
	if (!flag) printf("修改失败!\n");
	return flag;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//int Sale_Perst_SelectByUsrID(sale_list_t list, int usrID, ttms_date_t stDate, ttms_date_t endDate){
//	assert(NULL!=list);
//
//
//	FILE *fp = fopen(SALE_DATA_FILE, "rb");
//	if (NULL == fp)
//	{
//		printf("%s鎵撳紑澶辫触锛乗n",SALE_DATA_FILE);
//		return 0;
//	}
//
//	sale_t saleRec;
//	
//	sale_node_t* newNode;
//	int recCount = 0;
//
//
//	fread(&saleRec, sizeof(sale_t), 1, fp);
//	while (!feof(fp)){
//
//		if ((usrID == saleRec.user_id) /*&& DateCmp(saleRec.date,stDate)<=1 && DateCmp(saleRec.date,endDate)>=-1*/){
//			newNode = (sale_node_t*)malloc(sizeof(sale_node_t));
//			newNode->data = saleRec;
//			List_AddTail(list, newNode);
//			recCount++;
//		}
//			fread(&saleRec, sizeof(sale_t), 1, fp);
//	}
//
//	fclose(fp);
//
//		return recCount;
//	
//}
//
//int Sale_Perst_SelectByUsrID2(sale_list_t list, int usrID){
//	assert(NULL!=list);
//
//
//	FILE *fp = fopen(SALE_DATA_FILE, "rb");
//	if (NULL == fp)
//	{
//		printf("%s鎵撳紑澶辫触锛乗n",SALE_DATA_FILE);
//		return 0;
//	}
//
//	sale_t saleRec;
//	
//	sale_node_t* newNode;
//	int recCount = 0;
//
//
//	fread(&saleRec, sizeof(sale_t), 1, fp);
//	while (!feof(fp)){
//
//		if ((usrID == saleRec.user_id) /*&& DateCmp(saleRec.date,stDate)<=1 && DateCmp(saleRec.date,endDate)>=-1*/){
//			newNode = (sale_node_t*)malloc(sizeof(sale_node_t));
//			newNode->data = saleRec;
//			List_AddTail(list, newNode);
//			recCount++;
//		}
//			fread(&saleRec, sizeof(sale_t), 1, fp);
//	}
//
//	fclose(fp);
//
//		return recCount;
//	
//}
