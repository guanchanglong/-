#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Copyright(C), 2007-2008, XUPT Univ.
* ������ţ�TTMS_UC_02
* File name: Seat_UI.c
* Description : ������λ���������
* Author:   XUPT
* Version:  v.1
* Date: 	2015��4��22��
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
��ʶ����TTMS_SCU_Seat_UI_S2C
�������ܣ�������λ״̬��ȡ������ʾ���š�
����˵����statusΪseat_status_t���ͣ���ʾ��λ״̬��
�� �� ֵ���ַ��ͣ���ʾ��λ�Ľ�����ʾ���š�
*/
inline char Seat_UI_Status2Char(seat_status_t status) {
	char statusChar;
	switch (status) {
	case SEAT_GOOD:		//����λ
		statusChar = '#';
		break;
	case SEAT_BROKEN:	//�𻵵���λ 
		statusChar = '~';
		break;
	case SEAT_NONE:
		statusChar = '/';
		break;
	default:
		//statusChar = '/';//û����λ
		break;
	}
	return statusChar;
}

/*
��ʶ����TTMS_SCU_Seat_UI_C2S
�������ܣ�����������Ż�ȡ��λ״̬��
����˵����statusCharΪ�ַ��ͣ���ʾ������λ��������š�
�� �� ֵ��seat_status_t���ͣ���ʾ��λ��״̬��
*/
inline seat_status_t Seat_UI_Char2Status(char statusChar) {
	seat_status_t status;
	switch (statusChar) {
	case '#':		//����λ
		status = SEAT_GOOD;
		break;
	case '~':	//�𻵵���λ
		status = SEAT_BROKEN;
		break;
	default:
		status = SEAT_NONE;
		break;
	}
	return status;
}

/*
��ʶ����TTMS_SCU_Seat_UI_MgtEnt
�������ܣ�����������λ����ں�������ʾ��ǰ����λ���ݣ����ṩ��λ������ӡ��޸ġ�ɾ�����ܲ�������ڡ�
����˵����roomIDΪ���ͣ�����Ҫ������λ���ݳ���ID��
�� �� ֵ���ޡ�
*/
void Seat_UI_MgtEntry(int roomID) {
	int i, j;
	char choice;
	int seatCount;
	int changedCount = 0;
	studio_t studioRec;

	if (!Studio_Srv_FetchByID(roomID, &studioRec))
	{  //��ö�Ӧid��ӳ������Ϣ
		printf("\t\t\t�ݳ���������,�����������");
		getch();
		return;
	}
	seat_list_t list;
	seat_node_t *p;

	List_Init(list, seat_node_t);
	//ѡ���ӳ����������λ
	seatCount = Seat_Srv_FetchByRoomID(list, roomID);

	if (!seatCount) {		//����ӳ����û��������λ�����Զ�������λ
		seatCount = Seat_Srv_RoomInit(list, roomID, studioRec.rowsCount,
			studioRec.colsCount);
		//�޸��ݳ��������λ����
		studioRec.seatsCount = seatCount;
		Studio_Srv_Modify(&studioRec);
	}
	do {
		system("cls");
		printf("\n\t\t\t\t%d ���ݳ�����λһ��ͼ\n", roomID);
		printf("\n\t\t\t\t=========================================================\n\n\n");

		printf("%4c ", ' ');
		printf("\t\t\t\t\t     ");
		for (i = 1; i <= studioRec.colsCount; i++) {
			printf("%3d", i);
		}
		printf("\n\n");
		//��ʾ����
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
		printf("\n\n\n\t\t\t\t     1.���  2.ɾ��  3.�޸�  4.����   ");
		printf("\n\n\t\t\t\t     Your choice:");
		choice = getche();
		switch (choice) {
		case '1':
			changedCount = Seat_UI_Add(list, roomID, studioRec.rowsCount,
				studioRec.colsCount);
			if (changedCount > 0) {
				seatCount += changedCount;
				//�޸��ݳ��������λ����
				studioRec.seatsCount = seatCount;
				Studio_Srv_Modify(&studioRec);
			}
			break;
		case '2':
			changedCount = Seat_UI_Delete(list, studioRec.rowsCount,
				studioRec.colsCount);
			if (changedCount > 0) {
				seatCount -= changedCount;
				//�޸��ݳ��������λ����
				studioRec.seatsCount = seatCount;
				Studio_Srv_Modify(&studioRec);
			}
			break;
		case '3':
			Seat_UI_Modify(list, studioRec.rowsCount, studioRec.colsCount);
			break;
		}
	} while (choice != '4');
	//�ͷ�����ռ�
	List_Destroy(list, seat_node_t);
}

/*
ʶ����TTMS_SCU_Seat_UI_Add
�������ܣ��������һ���µ���λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬
�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��������λ�ı�־��
*/
int Seat_UI_Add(seat_list_t list, int roomID, int row, int column) {  //����һ����λ
	//����һ����λ
	seat_t rec;
	seat_node_t *p;
	int newRecCount = 0;
	char choice;
	do {
		printf("\n\t\t\t==================================================================\n");
		printf("\t\t\t 						   ����µ���λ  							\n");
		printf("\t\t\t------------------------------------------------------------------\n");

		do {
			printf("\t\t\t�������ܳ��� %d �в��ܳ��� %d!\n", row, column);
			printf("\t\t\t��λ������:");
			scanf("%d", &(rec.row));
			printf("\t\t\t��λ������:");
			scanf("%d", &(rec.column));
			fflush(stdin);
		} while (rec.row > row || rec.column > column);

		p = Seat_Srv_FindByRowCol(list, rec.row, rec.column);
		if (p != NULL) {						//����������к�����Ӧ����λ�Ѵ��ڣ����ܲ���
			printf("\t\t\t����Ϊ�Ѵ���! \n");
			printf("\t\t\t------------------------------------------------------------------\n");
			printf("\t\t\t[A]�������   [R]���� :  ");
			fflush(stdin);
			choice = getche();
			continue;
		}

		rec.id = EntKey_Perst_GetNewKeys("Seat", 1);		//������λid
		rec.roomID = roomID;
		rec.status = SEAT_GOOD;    //���������λ��״̬Ĭ��Ϊ����λ
		printf("\t\t\t==================================================================\n");

		if (Seat_Srv_Add(&rec)) {
			newRecCount++;
			printf("\t\t\t��λ�ɹ����!\n");
			p = (seat_node_t*)malloc(sizeof(seat_node_t));
			p->data = rec;
			Seat_Srv_AddToSoftedList(list, p); //������������λ�������list
		}
		else
			printf("\t\t\t��λ���ʧ��!\n");
		printf("\t\t\t------------------------------------------------------------------\n");
		printf("\t\t\t[A]�������   [R]���� :  ");
		fflush(stdin);
		choice = getche();
	} while ('a' == choice || 'A' == choice);
	//getchar();
	return newRecCount;
}

/*
��ʶ����TTMS_SCU_Seat_UI_Mod
�������ܣ������޸�һ����λ���ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ��޸�����λ�ı�־��
*/
int Seat_UI_Modify(seat_list_t list, int row, int column) {
	int rtn = 0;
	int newrow, newcolumn;
	char choice;
	seat_node_t *p;

	printf("\n\t\t\t==================================================================\n");
	printf("\t\t\t								  �޸���λ  						\n");
	printf("\t\t\t------------------------------------------------------------------\n");
	do {
		do {				//���µ���λ������Ϣ���ܳ�����ӳ����������
			printf("\t\t\t�������ܳ��� %d �в��ܳ��� %d!\n", row, column);
			printf("\t\t\t��λ���� :");
			scanf("%d", &newrow);
			printf("\t\t\t��λ���� :");
			scanf("%d", &newcolumn);
			getchar();
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {
			printf("\t\t\t��λ���� [%d,%d]: [%c]:", newrow, newcolumn, Seat_UI_Status2Char(p->data.status));
			//fflush(stdin);
			//getchar();
			p->data.status = Seat_UI_Char2Status(getchar());
			printf("\t\t\t-------------------------------------------------------------------\n");
			if (Seat_Srv_Modify(&(p->data))) {
				rtn = 1;
				printf("\t\t\t��λ�ɹ��޸�!\n");
			}
			else
				printf("\t\t\t��λ�޸�ʧ��!\n");
		}
		else
			printf("\t\t\t����λ������!\n");
		printf("\t\t\t-------------------------------------------------------------------\n\t\t\t");
		printf("[U]�����޸�, [R]���� :  ");
		choice = getche();
	} while ('u' == choice || 'U' == choice);
	return rtn;


}

/*
��ʶ����TTMS_SCU_Seat_UI_Del
�������ܣ�����ɾ��һ����λ�����ݡ�
����˵������һ������listΪseat_list_t����ָ�룬ָ����λ����ͷָ�룬�ڶ�������rowsCountΪ���ͣ���ʾ��λ�����кţ�����������colsCountΪ���ͣ���ʾ��λ�����кš�
�� �� ֵ�����ͣ���ʾ�Ƿ�ɹ�ɾ������λ�ı�־��
*/
int Seat_UI_Delete(seat_list_t list, int row, int column) {
	int delSeatCount = 0;
	int newrow, newcolumn;
	seat_node_t *p;
	char choice;

	do {
		printf("\n\n\tɾ����λ\n");
		printf("\t=========================================================\n");

		do {
			fflush(stdin);
			printf("\t����(С�ڵ��� %d):", row);
			scanf("%d", &(newrow));
			printf("\t����(С�ڵ��� %d):", column);
			scanf("%d", &(newcolumn));
			fflush(stdin);
		} while (newrow > row || newcolumn > column);

		p = Seat_Srv_FindByRowCol(list, newrow, newcolumn);
		if (p) {

			if (Seat_Srv_DeleteByID(p->data.id)) {
				printf("\tɾ���ɹ�\n");

				delSeatCount++;
				List_FreeNode(p);	//�ͷŽ����λ���p
			}
		}
		else {
			printf("\t��λ������\n");
		}

		printf("\t------------------------------------------------------------------\n");
		printf("\t[1]����ɾ��\t[2]����");
		choice = getche();
	} while ('1' == choice);
	return delSeatCount;

}

