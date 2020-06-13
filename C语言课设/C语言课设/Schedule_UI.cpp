#define _CRT_SECURE_NO_DEPRECATE 0
#include "Schedule_UI.h"
#include "Play_UI.h"
#include "List.h"
#include "Schedule.h"
#include "Play.h"
#include "Studio.h"
#include "EntityKey_Persist.h"
#include "Seat.h"
#include "Ticket.h"
#include "Ticket_UI.h"
#include "conio.h"
#include <stdio.h>
#include <stdlib.h>	 

void Schedule_UI_MgtEntry(int play_id)
{
	int i;
	int id;
	char choice;
	char ch;
	schedule_t buf;
	schedule_list_t list;
	schedule_node_t *pos;
	Pagination_t paging;

	List_Init(list, schedule_node_t);

	paging.offset = 0;
	paging.pageSize = 6;

	if (paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id))    //获取   演出计划链表
	{
		Paging_Locate_FirstPage(list, paging);
		do {
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("    		    演出计划管理    			       			  \n");
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("%6s %6s %6s %10s %10s       %6s\n", "演出计划ID", "剧目ID", "演出厅ID", "放映日期", "放映时间", "座位数");
			Paging_ViewPage_ForEach(list, paging, schedule_node_t, pos, i){
				//	if(pos->data.play_id==play_id){			
				printf("%6d %6d %10d   %04d-%02d-%02d     %02d:%02d:%02d     %6d\n",
					pos->data.id, pos->data.play_id, pos->data.studio_id,
					pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);
				//   }

			}
			printf("--------------------- Total Records:%2d ------------------------- Page %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("[A]添加演出计划\n");
			printf("[U]修改演出计划\n");
			printf("[D]删除演出计划\n");
			printf("[T]生成演出票\n");
			printf("[P]上一页\t[N]下一页\t[R]返回\n");
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("\n请选择:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice)
			{
			case 'a':
			case 'A':
				//添加演出计划
				if (Schedule_UI_Add(play_id))    //新添加成功，跳到最后一页显示
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id);
					Paging_Locate_LastPage(list, paging, schedule_node_t);
				}
				break;
			case 'u':
			case 'U':
				//修改演出计划
				printf("输入演出计划ID:");
				fflush(stdin);
				scanf("%d", &id);
				if (Schedule_UI_Modify(id)) {	//从新载入数据
					paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id);
					List_Paging(list, paging, schedule_node_t);
				}
				break;
			case 'd':
			case 'D':
				//删除演出计划
				printf("输入演出计划ID:");
				fflush(stdin);
				scanf("%d", &id);
				if (Schedule_UI_Delete(id)) //从新载入数据
				{
					paging.totalRecords = Schedule_Srv_FetchByPlay(list, play_id);
					List_Paging(list, paging, schedule_node_t);
				}
				break;
			case 't':
			case 'T':
				printf("输入要生成的演出票的演出计划ID:");
				fflush(stdin);
				scanf("%d", &id);
				//			if(Schedule_Srv_FetchByID(id,&buf)){
				getchar();
				Ticket_UI_MgtEntry(id);
				break;
				//			}
				//			printf("没有查询到演出计划%d 按[Enter]返回",id);
				//			fflush(stdin);
				//			getchar();
				//			break;

			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, -1, schedule_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, 1, schedule_node_t);
				}
				break;
			}
		} while (choice != 'R' && choice != 'r');
	}
	//释放链表
	List_Destroy(list, schedule_node_t);
}

int Schedule_UI_Add(int play_id)
{
	schedule_t rec;
	seat_list_t list;
	List_Init(list, seat_node_t);
	char choice;
	int newRecCount = 0;
	printf("\n===============================================================\n");
	printf("****************  添加演出计划  ****************\n");
	printf("---------------------------------------------------------------\n");
	fflush(stdin);
	rec.play_id = play_id;
	printf("演出厅 ID:");
	scanf("%d", &rec.studio_id);
	printf("演出日期 year-month-day:");
	scanf("%d-%d-%d", &rec.date.year, &rec.date.month, &rec.date.day);
	printf("演出时间 hour:minute:second:");
	scanf("%d:%d:%d", &rec.time.hour, &rec.time.minute, &rec.time.second);
	printf("输入座位数:");
	scanf("%d", &rec.seat_count);
	getchar();
	printf("=======================================================\n");
	//获取主键
	rec.id = EntKey_Perst_GetNewKeys("Schedule", 1);
	//  rec.seat_count =Seat_Srv_FetchValidByRoomID(list, rec.studio_id);
	if (Schedule_Srv_Add(&rec)/*&&Ticket_Srv_AddBatch(rec.id,rec.studio_id)*/) {
		newRecCount++;
		printf("您已成功添加新的演出计划!\n");
	}
	else {
		printf("新的演出计划添加失败!\n");
	}
	printf("-------------------------------------------------------\n");
	return newRecCount;
}

int Schedule_UI_Modify(int id)
{

	schedule_t rec;
	int rtn = 0;
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("该演出计划不存在!\n按 [Enter] 返回!\n");
		getchar();
		return 0;
	}
	//界面	
	printf("输入该演出计划的新信息\n");
	getchar();
	//	printf("剧目 ID:");
	//	scanf("%d",rec.play_id);
	printf("演出厅 ID:");
	scanf("%d", &rec.studio_id);
	getchar();
	printf("演出日期 year-month-day:");
	scanf("%d-%d-%d", &rec.date.year, &rec.date.month, &rec.date.day);
	printf("演出时间 hour:minute:second:");
	scanf("%d:%d:%d", &rec.time.hour, &rec.time.minute, &rec.time.second);
	printf("输入座位数:");
	scanf("%d", &rec.seat_count);
	Ticket_Srv_DeleteBatch(rec.id);
	printf("-------------------------------------------------------\n");
	int temp = Schedule_Srv_Modify(&rec);
	if (!temp)
	{
		printf("修改内容失败");
		printf("按任意键退出\n");
		getchar();
		return 0;
	}
	return 1;
	//	rec.seat_count=Ticket_Srv_AddBatch(rec.id, rec.studio_id);
	//	if (Schedule_Srv_Modify(&rec)) {
	//		rtn = 1;
	//		printf(
	//			"演出计划成功修改!\n按 [Enter] 返回!\n");
	//	}
	//	else
	//		printf("演出计划修改失败！\n按 [Enter] 返回!\n");
	//	getchar();
	//	getchar();
	//	return rtn;
}


int Schedule_UI_Delete(int id)
{
	schedule_t rec;
	if (!Schedule_Srv_FetchByID(id, &rec)) {
		printf("演出计划不存在!\n按 [Enter] 返回!\n");
		fflush(stdin);
		getchar();
		return 0;
	}
	if (Schedule_Srv_DeleteByID(id)/*&& Ticket_Srv_DeleteBatch(rec.studio_id)*/) {
		printf("演出计划成功删除!\n");
		return 1;
	}
	else {
		printf("演出计划不存在！\n按 [Enter] 返回!\n");
		fflush(stdin);
		getchar();
		return 0;
	}
}
/*
int Schedule_UI_Query(int id)
{
int rtn = 1;
schedule_t  buf;
if (Schedule_Srv_FetchByID(id, &buf)) {
printf("\n");
printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
printf("    		    ID为%3d的演出计划  			       			  \n", buf.id);
printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
printf("\n");
rtn = 1;
printf("计划ID: %d\n", buf.id);
printf("剧目ID: %d\n", buf.play_id);
printf("放映厅ID: %d\n", buf.studio_id);
printf("演出日期:%d-%d-%d\n", buf.date.year, buf.date.month, buf.date.day);
printf("演出时间:%d:%d:%d\n", buf.time.hour, buf.time.minute, buf.time.second);
printf("座位数量:%d\n", buf.seat_count);
printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
printf("输入回车键结束");
fflush(stdin);
getchar();
return 1;
}
else
{
printf("查找不到该演出计划！");
return 0;
}
return rtn;
}
*/
int Schedule_UI_Query(int id){
	int i;
	char choice;
	schedule_list_t list;
	schedule_node_t *pos;
	Pagination_t paging;
	List_Init(list, schedule_node_t);
	paging.offset = 0;
	paging.pageSize = 6;
	if (paging.totalRecords = Schedule_Srv_FetchByPlay(list, id))    //获取   演出计划链表
	{
		Paging_Locate_FirstPage(list, paging);
		do {
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("    		    演出计划管理    			       			  \n");
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("%6s %6s %6s %10s %10s       %6s\n", "演出计划ID", "剧目ID", "演出厅ID", "放映日期", "放映时间", "座位数");
			Paging_ViewPage_ForEach(list, paging, schedule_node_t, pos, i){
				printf("%6d %6d %10d   %04d-%02d-%02d     %02d:%02d:%02d     %6d\n",
					pos->data.id, pos->data.play_id, pos->data.studio_id,
					pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);
			}
			printf("--------------------- Total Records:%2d ------------------------- Page %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("[P]上一页\t[N]下一页\t[R]返回\n");
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("\n请选择:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice){
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, -1, schedule_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(list, paging, 1, schedule_node_t);
				}
				break;
			}
		} while (choice != 'R' && choice != 'r');
	}
	//释放链表
	List_Destroy(list, schedule_node_t);
	return 0;
}


void Schedule_UI_ListAll(void) {
	int i;
	int id;
	char choice;
	char ch;
	schedule_list_t head;
	schedule_list_t pos;
	Pagination_t paging;
	List_Init(head, schedule_node_t);
	paging.offset = 0;
	paging.pageSize = SCHEDULE_PAGE_SIZE;
	//载入数据
	if (paging.totalRecords = Schedule_Srv_FetchAll(head)){
		Paging_Locate_FirstPage(head, paging);
		do {
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("    		    演出计划管理    			       			  \n");
			printf(" = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("%6s %6s %6s %10s %10s       %6s\n", "演出计划ID", "剧目ID", "演出厅ID", "放映日期", "放映时间", "座位数");
			Paging_ViewPage_ForEach(head, paging, schedule_node_t, pos, i){
				printf("%6d %6d %10d   %04d-%02d-%02d     %02d:%02d:%02d     %6d\n",
					pos->data.id, pos->data.play_id, pos->data.studio_id,
					pos->data.date.year, pos->data.date.month, pos->data.date.day,
					pos->data.time.hour, pos->data.time.minute, pos->data.time.second, pos->data.seat_count);
			}
			printf("--------------------- Total Records:%2d ------------------------- Page %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("[P]上一页\t[N]下一页\t[S]查询剧目演出计划\t[R]返回\n");
			printf("= = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =\n");
			printf("\n请选择:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice) {
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, schedule_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, schedule_node_t);
				}
				break;
			case 's':
			case 'S':
				printf("输入要查询的剧目ID:");
				scanf("%d", &id);
				if (Schedule_UI_Query(id)){
					break;
				}
				else{
					printf("该剧目不存在！");
					break;
				}
			}
		} while ('r' != choice && 'R' != choice);
	}
	List_Destroy(head, schedule_node_t);
}
void Schedule_UI_ListByPlay(play_t *play, schedule_list_t list, Pagination_t paging){
}