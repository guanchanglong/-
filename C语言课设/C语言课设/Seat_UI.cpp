#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Copyright(C), 2007-2008, XUPT Univ.
* 用例编号：TTMS_UC_02
* File name: Seat_UI.c
* Description : 设置座位用例界面层
* Author:   XUPT
* Version:  v.1
* Date: 	2015年4月22日
*/
#include "EntityKey_Persist.h"
#include "Seat_UI.h"
#include "Seat.h"
#include "Studio.h"
#include "List.h"
#include <stdio.h>
#include <conio.h>
#pragma warning(disable: 4996)
/*
表识符：TTMS_SCU_Seat_UI_S2C
函数功能：根据座位状态获取界面显示符号。
参数说明：status为seat_status_t类型，表示座位状态。
返 回 值：字符型，表示座位的界面显示符号。
*/
inline char Seat_UI_Status2Char(seat_status_t status) {
	char statusChar;
	switch (status) {
	case SEAT_GOOD:		//有座位
		statusChar = '#';
		break;
	case SEAT_BROKEN:	//损坏的座位 
		statusChar = '~';
		break;
	case SEAT_NONE:
		statusChar = '/';
		break;
	default:
		//statusChar = '/';//没有座位
		break;
	}
	return statusChar;
}

/*
标识符：TTMS_SCU_Seat_UI_C2S
函数功能：根据输入符号获取座位状态。
参数说明：statusChar为字符型，表示设置座位的输入符号。
返 回 值：seat_status_t类型，表示座位的状态。
*/
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	seat_status_t status;
	switch (statusChar) {
	case '#':		//有座位
		status = SEAT_GOOD;
		break;
	case '~':	//损坏的座位
		status = SEAT_BROKEN;
		break;
	default:
		status = SEAT_NONE;
		break;
	}
	return status;
}

/*
标识符：TTMS_SCU_Seat_UI_MgtEnt
函数功能：界面层管理座位的入口函数，显示当前的座位数据，并提供座位数据添加、修改、删除功能操作的入口。
参数说明：roomID为整型，是需要设置座位的演出厅ID。
返 回 值：无。
*/
void Seat_UI_MgtEntry(int roomID) {
	int i, j;
	char choice;
	int seatCount;
	int changedCount = 0;
	studio_t studioRec;

	if (!Studio_Srv_FetchByID(roomID, &studioRec))
	{  //获得对应id放映厅的信息
		printf("\t\t\t演出厅不存在,按任意键返回");
		getch();
		return;
	}
	seat_list_t list;
	seat_node_t *p;

	List_Init(list, seat_node_t);
	//选择放映厅的所有座位
	seatCount = Seat_Srv_FetchByRoomID(list, roomID);

	if (!seatCount) {		//若放映厅还没有设置座位，则自动生成座位
		seatCount = Seat_Srv_RoomInit(list, roomID, studioRec.rowsCount,
			studioRec.colsCount);
		//修改演出厅里的座位数量
		studioRec.seatsCount = seatCount;
		Studio_Srv_Modify(&studioRec);
	}
	do {
		system("cls");
		printf("\n\t\t\t\t%d 号演出厅座位一览图\n", roomID);
		printf("\n\t\t\t\t=========================================================\n\n\n");

		printf("%4c ", ' ');
		printf("\t\t\t\t\t     ");
		for (i = 1; i <= studioRec.colsCount; i++) {
			printf("%3d", i);
		}
		printf("\n\n");
		//显示数据
		for (i = 1; i <= studioRec.rowsCount; i++) {
			j = 1;
			printf("\t\t\t\t\t%2d  %c", i, ' ');
			List_ForEach(list, p)
			{
				if (p->data.row == i) {
					while (p->data.column != j) {
						//						printf("gg");
						printf("%3c", ' ');
						j++;
					}
					printf("%3c", Seat_UI_Status2Char(p->data.status));
					j++;
				}
			}
			printf("\n");
		}
		printf("\n\n\n\t\t\t\t     1.添加  2.删除  3.修改  4.返回   ");
		printf("\n\n\t\t\t\t     Your choice:");
		choice = getche();
		switch (choice) {
		case '1':
			changedCount = Seat_UI_Add(list, roomID, studioRec.rowsCount,
				studioRec.colsCount);
			if (changedCount > 0) {
				seatCount += changedCount;
				//修改演出厅里的座位数量
				studioRec.seatsCount = seatCount;
				Studio_Srv_Modify(&studioRec);
			}
			break;
		case '2':
			changedCount = Seat_UI_Delete(list, studioRec.rowsCount,
				studioRec.colsCount);
			if (changedCount > 0) {
				seatCount -= changedCount;
				//修改演出厅里的座位数量
				studioRec.seatsCount = seatCount;
				Studio_Srv_Modify(&studioRec);
			}
			break;
		case '3':
			Seat_UI_Modify(list, studioRec.rowsCount, studioRec.colsCount);
			break;
		}
	} while (choice != '4');
	//释放链表空间
	List_Destroy(list, seat_node_t);
}

/*
识符：TTMS_SCU_Seat_UI_Add
函数功能：用于添加一个新的座位数据。
参数说明：第一个参数list为seat_list_t类型指针，指向座位链表头指针，
第二个参数rowsCount为整型，表示座位所在行号，第三个参数colsCount为整型，表示座位所在列号。
返 回 值：整型，表示是否成功添加了座位的标志。
*/
int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //输入一个座位
	//输入一个座位
	seat_t rec;
	seat_node_t *p;
	int newRecCount = 0;
	char choice;
	do {
		printf("\n\t\t\t==================================================================\n");
		printf("\t\t\t 						   添加新的座位  							\n");
		printf("\t\t\t------------------------------------------------------------------\n");

		do {
			printf("\t\t\t行数不能超过 %d 列不能超过 %d!\n", row, column);
			printf("\t\t\t座位的行数:");
			scanf("%d", &(rec.row));
			printf("\t\t\t座位的列数:");
			scanf("%d", &(rec.column));
			fflush(stdin);
		} while (rec.row > row || rec.column > column);

		p = Seat_Srv_FindByRowCol(list, rec.row, rec.column);
		if (p != NULL) {						//若输入的行列号所对应的座位已存在，则不能插入
			printf("\t\t\t该作为已存在! \n");
			printf("\t\t\t------------------------------------------------------------------\n");
			printf("\t\t\t[A]继续添加   [R]返回 :  ");
			fflush(stdin);
			choice = getche();
			continue;
		}

		rec.id = EntKey_Perst_GetNewKeys("Seat", 1);		//设置座位id
		rec.roomID = roomID;
		rec.status = SEAT_GOOD;    //插入的新座位的状态默认为好座位
		printf("\t\t\t==================================================================\n");

		if (Seat_Srv_Add(&rec)) {
			newRecCount++;
			printf("\t\t\t座位成功添加!\n");
			p = (seat_node_t*)malloc(sizeof(seat_node_t));
			p->data = rec;
			Seat_Srv_AddToSoftedList(list, p); //若增加了新座位，需更新list
		}
		else
			printf("\t\t\t座位添加失败!\n");
		printf("\t\t\t------------------------------------------------------------------\n");
		printf("\t\t\t[A]继续添加   [R]返回 :  ");
		fflush(stdin);
		choice = getche();
	} while ('a' == choice || 'A' == choice);
	//getchar();
	return newRecCount;
}

/*
标识符：TTMS_SCU_Seat_UI_Mod
函数功能：用于修改一个座位数据。
参数说明：第一个参数list为seat_list_t类型指针，指向座位链表头指针，第二个参数rowsCount为整型，表示座位所在行号，第三个参数colsCount为整型，表示座位所在列号。
返 回 值：整型，表示是否成功修改了座位的标志。
*/
int Seat_UI_Modify(seat_list_t list, int row, int column) {
	int rtn = 0;
	int newrow, newcolumn;
	char choice;
	seat_node_t *p;

	printf("\n\t\t\t==================================================================\n");
	printf("\t\t\t								  修改座位  						\n");
	printf("\t\t\t------------------------------------------------------------------\n");
	do {
		do {				//更新的座位行列信息不能超出放映厅的行列数
			printf("\t\t\t行数不能超过 %d 列不能超过 %d!\n", row, column);
			printf("\t\t\t座位行数 :");
			scanf("%d", &newrow);
			printf("\t\t\t座位列数 :");
			scanf("%d", &newcolumn);
			getchar();
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {
			printf("\t\t\t座位坐标 [%d,%d]: [%c]:", newrow, newcolumn, Seat_UI_Status2Char(p->data.status));
			//fflush(stdin);
			//getchar();
			p->data.status = Seat_UI_Char2Status(getchar());
			printf("\t\t\t-------------------------------------------------------------------\n");
			if (Seat_Srv_Modify(&(p->data))) {
				rtn = 1;
				printf("\t\t\t座位成功修改!\n");
			}
			else
				printf("\t\t\t座位修改失败!\n");
		}
		else
			printf("\t\t\t该座位不存在!\n");
		printf("\t\t\t-------------------------------------------------------------------\n\t\t\t");
		printf("[U]继续修改, [R]返回 :  ");
		choice = getche();
	} while ('u' == choice || 'U' == choice);
	return rtn;


}

/*
标识符：TTMS_SCU_Seat_UI_Del
函数功能：用于删除一个座位的数据。
参数说明：第一个参数list为seat_list_t类型指针，指向座位链表头指针，第二个参数rowsCount为整型，表示座位所在行号，第三个参数colsCount为整型，表示座位所在列号。
返 回 值：整型，表示是否成功删除了座位的标志。
*/
int Seat_UI_Delete(seat_list_t list, int row, int column) {
	int delSeatCount = 0;
	int newrow, newcolumn;
	seat_node_t *p;
	char choice;

	do {
		printf("\n\n\t删除座位\n");
		printf("\t=========================================================\n");

		do {
			fflush(stdin);
			printf("\t行数(小于等于 %d):", row);
			scanf("%d", &(newrow));
			printf("\t列数(小于等于 %d):", column);
			scanf("%d", &(newcolumn));
			fflush(stdin);
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {

			if (Seat_Srv_DeleteByID(p->data.id)) {
				printf("\t删除成功\n");

				delSeatCount++;
				List_FreeNode(p);	//释放结点座位结点p
			}
		}
		else {
			printf("\t座位不存在\n");
		}

		printf("\t------------------------------------------------------------------\n");
		printf("\t[1]继续删除\t[2]返回");
		choice = getche();
	} while ('1' == choice);
	return delSeatCount;

}

