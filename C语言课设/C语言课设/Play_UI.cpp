#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include <stdlib.h>
#include "Play.h"
#include "Play_UI.h"
//#include "Schedule_UI.h"
#include "List.h"
#include "EntityKey_Persist.h"
#include "Play_Persist.h"

inline  char swap_charto_status_type(play_type_t status)
{
	if (status == PLAY_TYPE_FILE)
		return '1';
	if (status == PLAY_TYPE_OPEAR)
		return '2';
	if (status == PLAY_TYPE_CONCERT)
		return '3'; return '1';
}
inline  char swap_charto_status_rating(play_rating_t status)
{
	if (status == PLAY_RATE_CHILD);
	return '1';
	if (status == PLAY_RATE_TEENAGE)
		return '2';
	if (status == PLAY_RATE_ADULT)
		return '3'; return '1';
}

inline play_type_t swap_statusto_char_type(char status)
{
	if (status == '1')
		return PLAY_TYPE_FILE;
	if (status == '2')
		return PLAY_TYPE_OPEAR;
	if (status == '3')
		return PLAY_TYPE_CONCERT;
	return PLAY_TYPE_FILE;
}
inline play_rating_t swap_statusto_char_rating(char status)
{
	if (status == '1')
		return PLAY_RATE_CHILD;
	if (status == '2')
		return PLAY_RATE_TEENAGE;
	if (status == '3')
		return PLAY_RATE_ADULT;
	return PLAY_RATE_CHILD;
}

//根据ID获取剧目
inline int Play_Srv_FetchByID(int id, play_t *buf) {
	if (Play_Perst_SelectByID(id, buf)){
		return 1;
	}
	else{
		return 0;
	}
}

//根据ID删除剧目
inline int Play_Srv_DeleteByID(int ID) {
	if (Play_Perst_RemByID(ID))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//修改剧目
inline int Play_Srv_Modify(const play_t *data) {
	if (Play_Perst_Update(data))
	{
		printf("修改成功!");
		return 1;
	}
	return 0;
}

/*void Play_UI_ShowList(play_list_t list, Pagination_t paging) {
return 0;
}*/

//管理剧目界面 
void Play_UI_MgtEntry(void)
{
	int i;
	int id;
	char choice;
	play_t buf;
	Pagination_t paging;
	play_list_t head;
	play_list_t pos;
	paging.offset = 0;
	paging.pageSize = PLAY_PAGE_SIZE;
	List_Init(head, play_node_t);
	//载入数据 

	if (paging.totalRecords = Play_Srv_FetchAll(head)){	//若文件打开成功则进入下一级的菜单
		Paging_Locate_FirstPage(head, paging);//第一页	 
		do{
			//遍历 
			printf("=======================================   FILM  List   =====================================\n");
			printf("%5s %15s %5s %10s %10s %6s %10s %10s %10s\n", "剧目ID", "电影名字", "类型", "地区",
				"等级", "时长", "上映时间", "下架时间", "价格");
			printf("--------------------------------------------------------------------------------------------\n");

			//显示数据
			Paging_ViewPage_ForEach(head, paging, play_node_t, pos, i){
				//for(i=0,pos=(play_node_t*)(paging.curPos);pos!=head && i<paging.pageSize;i++){
				printf("%5d %15s %5c %10s %10c %6d %5d-%02d-%02d %5d-%02d-%02d %8d\n",
					pos->data.id, pos->data.name, swap_charto_status_type(pos->data.type), pos->data.area,
					swap_charto_status_rating(pos->data.rating), pos->data.duration,
					pos->data.start_date.year, pos->data.start_date.month,
					pos->data.start_date.day, pos->data.end_date.year, pos->data.end_date.month,
					pos->data.end_date.day, pos->data.price);
			}
			printf("--------------------- 总记录:%2d ------------------------- 页 %2d/%2d ----------------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("--------------------------------------------------------------------------------------------\n");

			printf("[P]上一页     [N]下一页      [A]添加剧目        [D]删除剧目  \n[U]修改剧目   [Q]查询剧目  [S]安排剧目演出计划  [R]eturn\n\n");

			printf("Your Choice:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);

			switch (choice)
			{
			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, play_node_t);
				}
				break;

			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, play_node_t);
				}
				break;

			case 'a':
			case 'A':
				if (Play_UI_Add(head)){
					//	paging.totalRecords=Play_Srv_FetchAll(head);
					paging.totalRecords += 1;
					Paging_Locate_LastPage(head, paging, play_node_t);
				}
				//		    	paging.totalRecords=Play_Srv_FetchAll(head);
				break;

			case 'd':
			case 'D':
				printf("输入ID:");
				scanf("%d", &id);
				if (Play_UI_Delete(id)) {	//重新载入数据
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head, paging, play_node_t);
				}
				break;

			case 'u':
			case 'U':
				printf("输入剧目ID:");
				scanf("%d", &id);
				fflush(stdin);
				if (Play_UI_Modify(id)) {	//重新载入数据
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head, paging, play_node_t);
				}
				break;
			case 'q':
			case 'Q':
				printf("输入剧目ID:");
				scanf("%d", &id);
				if (Play_UI_Query(id)) {
					paging.totalRecords = Play_Srv_FetchAll(head);
					List_Paging(head, paging, play_node_t);
				}
				break;
			case 's':
			case 'S':
				printf("输入剧目ID:");
				scanf("%d", &id);
				if (Play_Srv_FetchByID(id, &buf)) {
					//Schedule_UI_MgtEntry(id);
					break;
				}
				printf("没有此剧目\n输入[Enter]返回:");
				fflush(stdin);
				getchar();
				break;

			}
		} while (choice != 'r' && choice != 'R');
	}
	//释放链表空间
	List_Destroy(head, play_node_t);
}

//标识符：TTMS_SCU_Play_UI_Add
//功能: 添加新剧目界面 ,通过调用业务逻辑层将数据添加到Play.dat
//参数说明：无
//返回值：整型 1：成功   非1：失败 
int Play_UI_Add(play_list_t list)
{
	int newCount = 0;
	play_t data;
	play_list_t rec;
	printf("\n=======================================================\n");
	printf("\t****************  添加新剧目 ***************\n");
	printf("-------------------------------------------------------\n");
	printf("输入要添加的剧目名称:");
	gets(data.name);
	printf("剧目地区Area:");
	scanf("%s", data.area);
	printf("Type:\n");
	//	rec.type=swap_statusto_char_type(ch);
	printf("PLAY_TYPE_FILE=1\nPLAY_TYPE_OPEAR=2\nPLAY_TYPE_CONCERT=3\n剧目类型：");
	char ch;
	scanf("%c", &ch);
	data.type = swap_statusto_char_type(ch);
	getchar();
	printf("Rating:\n");
	printf("PLAY_RATE_CHILD=1\nPLAY_RATE_TEENAGE=2\nPLAY_RATE_ADULT=3\n请输入剧目等级：");
	getchar();
	scanf("%c", &ch);
	data.rating = swap_statusto_char_rating(ch);
	printf("剧目时长(分钟)Durating:");
	scanf("%d", &data.duration);
	printf("Start_date 年-月-日：");
	scanf("%d-%d-%d", &data.start_date.year, &data.start_date.month, &data.start_date.day);
	printf("End_date 年-月-日：");
	scanf("%d-%d-%d", &data.end_date.year, &data.end_date.month, &data.end_date.day);
	printf("价格Price:");
	scanf("%d", &data.price);
	data.id = EntKey_Perst_GetNewKeys("Play", 1);
	printf("=======================================================\n");
	if (Play_Srv_Add(&data)){
		rec = (play_list_t)malloc(sizeof(play_node_t));
		rec->data = data;
		List_AddTail(list, rec);
		newCount++;
		printf("新剧目添加成功！\n");
		return newCount;
	}
	printf("新剧目添加失败！\n");
	return 0;
}


int Play_UI_Modify(int id) {
	play_t temp;
	int i;
	if (Play_Srv_FetchByID(id, &temp))
	{
		printf("%5s %15s %5s %10s %10s %6s %10s %10s %10s\n", "ID", "电影名字", "电影类型", "地区",
			"等级", "时长", "上映时间", "下架时间", "价格");
		printf("%5d %15s %5c %10s %10c %6d %5d-%02d-%02d %5d-%02d-%02d %8d\n",
			temp.id, temp.name, swap_charto_status_type(temp.type), temp.area,
			swap_charto_status_rating(temp.rating), temp.duration,
			temp.start_date.year, temp.start_date.month, temp.start_date.day,
			temp.end_date.year, temp.end_date.month, temp.end_date.day, temp.price);
	}
	else
	{
		printf("在play.dat中没有找到剧目\n按 [enter]返回");
		getchar();
		return 0;
	}
	printf("输入该剧目的新信息\n");
	printf("剧目名称:");
	scanf("%s", temp.name);
	printf("出品地区:");
	scanf("%s", temp.area);
	printf("PLAY_TYPE_FILE=1\nPLAY_TYPE_OPEAR=2\nPLAY_TYPE_CONCERT=3\n剧目类型");
	scanf("%d", &temp.type);
	printf("PLAY_RATE_CHILD=1\nPLAY_RATE_TEENAGE=2\nPLAY_RATE_ADULT=3\n剧目等级");
	scanf("%d", &temp.rating);
	printf("剧目时长:");
	scanf("%d", &temp.duration);
	printf("上映时间:");
	scanf("%d-%d-%d", &temp.start_date.year, &temp.start_date.month, &temp.start_date.day);
	printf("下架时间:");
	scanf("%d-%d-%d", &temp.end_date.year, &temp.end_date.month, &temp.end_date.day);
	printf("输入票价:");
	scanf("%d", &temp.price);
	getchar();
	int rec = Play_Srv_Modify(&temp);
	if (!rec)
	{
		printf("修改内容失败");
		printf("按任意键退出\n");
		getchar();
		return 0;
	}
	return 1;
}
int Play_UI_Delete(int id) {
	char ch;
	play_t temp;
	if (Play_Srv_FetchByID(id, &temp))
	{
		Play_Srv_DeleteByID(id);
	}
	else
	{
		printf("未找到ID %d的剧目信息\n", id);
	}
	printf("按任意键退出\n");
	getchar();
	return 0;
}

int Play_UI_Query(int id) {
	int tmp;
	int i;
	play_t temp;
	tmp = Play_Srv_FetchByID(id, &temp);
	if (!tmp)
	{
		printf("没有这个ID\n");
		getchar();
		return 0;
	}
	else
	{
		for (i = 0; i<109; i++)putchar('-');
		putchar('\n');
		printf("%5s %15s %5s %10s %10s %6s %10s %10s %10s\n", "ID", "电影名字", "电影类型", "地区",
			"等级", "时长", "上映时间", "下架时间", "价格");
		printf("%5d %15s %5c %10s %10c %6d %5d-%02d-%02d %5d-%02d-%02d %8d\n",
			temp.id, temp.name, swap_charto_status_type(temp.type), temp.area,
			swap_charto_status_rating(temp.rating), temp.duration,
			temp.start_date.year, temp.start_date.month, temp.start_date.day,
			temp.end_date.year, temp.end_date.month, temp.end_date.day, temp.price);
		for (i = 0; i<109; i++)putchar('-');
		putchar('\n');
		fflush(stdin);
		printf("按回车退出");
		getchar();
		return 1;
		//        printf("\n[C]演出计划管理|[R]返回\n");
		//		printf("功能选择:");
		//		char choice;
		//		fflush(stdin);
		//		scanf("%c",&choice);
		//		if(choice=='C' || choice == 'c'){
		//		Schedule_UI_Query(id);
		//		}
		//        return 1;
	}
}