#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Account_UI.c
*
*  Created on: 2015��4��24��
*      Author: Administrator
*/
#include "Account_UI.h"
#include "Account_Persist.h"
#include "List.h"
#include "Account.h"
#include "EntityKey_Persist.h"
#include<stdio.h>
#include<string.h>
account_t GL_CurUser;
inline  char swap_meijuto_char(account_type_t status)
{
	if (status == USR_ANOMY)
		return '0';
	if (status == USR_CLERK)
		return '1';
	if (status == USR_MANG)
		return '2';
	if (status == USR_ADMIN)
		return '3';
}

inline account_type_t swap_charto_meiju(char status)
{
	if (status == '0')
		return USR_ANOMY;
	if (status == '1')
		return USR_CLERK;
	if (status == '2')
		return USR_MANG;
	if (status == '3')
		return USR_ADMIN;
}

//ɾ��һ���û��˺ţ�ͨ������Account_Perst_DeleteByID(usrID)����ʵ��
inline int Account_Srv_DeleteByID(int usrID){
	if (Account_Perst_DeleteByID(usrID)){
		return 1;
	}
	else{
		return 0;
	}
}

//��ȡ�����û��˺���Ϣ�����浽list�����У�ͨ������Account_Perst_SelectAll(list)����ʵ��
inline int Account_Srv_FetchAll(account_list_t list){
	return Account_Perst_SelectAll(list);
}

//�޸�һ���û��˺ţ�ͨ������Account_Perst_Update(data)����ʵ��
inline int Account_Srv_Modify(const account_t *data){
	if (Account_Perst_Update(data)){
		return 1;
	}
	else{
		return 0;
	}
}

//��֤��¼�˺��Ƿ��Ѵ��ڣ����ڣ������¼�û���Ϣ��ȫ�ֱ���gl_CurUser��return 1������return 0
inline int Account_Srv_Verify(char usrName[], char pwd[]){
	account_t usr;
	if (!Account_Perst_SelByName(usrName, &usr))
	{
		return 0;
	}
	if (strcmp(usr.password, pwd) != 0){
		return 0;
	}
	GL_CurUser = usr;
	return 1;
}

//ϵͳ��¼
int SysLogin(){
	Account_Srv_InitSys();//������ʼ���˺� 
	printf("===============================================\n");
	printf("***********��ӭʹ�ð�˹����ԺƱ�����ϵͳ!*************\n");
	printf("------------------------------------------------\n");
	printf("�����ȵ�¼!\n");
	int i = 0;
	char usrName[20];
	char pwd[20];
	while (i<3){
		printf("�����û���:");
		scanf("%s", usrName);
		printf("��������:");
		scanf("%s", pwd);
		if (Account_Srv_Verify(usrName, pwd)){
			printf("�û����ڣ���½�ɹ�!\n");
			return 1;
		}
		//������         
		printf("�û����������������������\n");
		i++;
	}
	printf("������󳬹�����!\n");
	getchar();
	return 0;
}

//ϵͳ�û��������
void Account_UI_MgtEntry(){
	char usrName[30];
	int i;
	char choice;
	Pagination_t paging;//��ҳ
	if (!SysLogin()){
		return;
	}
	account_list_t head;
	account_node_t *pos;
	paging.offset = 0;
	paging.pageSize = ACCOUNT_PAGE_SIZE;
	List_Init(head, account_node_t);
	if (paging.totalRecords = Account_Srv_FetchAll(head)){
		Paging_Locate_FirstPage(head, paging);
		do{
			//���� 
			printf("=======================================================================\n");
			printf("********************** Account  List **********************************\n");
			printf("%5s %30s %15s %15s", "ID", "username", "account_type", "mima\n");
			Paging_ViewPage_ForEach(head, paging, account_node_t, pos, i){
				printf("%5d  %30s  %15c %15s\n", pos->data.id, pos->data.username, swap_meijuto_char(pos->data.type), pos->data.password);
			}
			printf(
				"\n------- Total Records:%2d ----------------------- Page %2d/%2d -----------\n",
				paging.totalRecords, Pageing_CurPage(paging),
				Pageing_TotalPages(paging));
			printf("[P]��һҳ    [N]��һҳ  \n[A]����û�  [D]ɾ���û�\n[M]�޸�����  [Q]��ѯ�û�  \n[R]����\n");
			printf("Your Choice:");
			fflush(stdin);
			scanf("%c", &choice);
			fflush(stdin);
			switch (choice){
			case 'p':
			case 'P':
				if (!Pageing_IsFirstPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, -1, account_node_t);
				}
				break;

			case 'n':
			case 'N':
				if (!Pageing_IsLastPage(paging)) {
					Paging_Locate_OffsetPage(head, paging, 1, account_node_t);
				}
				break;

			case 'a':
			case 'A':
				if (Account_UI_Add(head)){
					//	printf("��ӳɹ�!");
					//paging.totalRecords =Account_Srv_FetchAll(head);
					paging.totalRecords += 1;
					Paging_Locate_LastPage(head, paging, account_node_t);
				}
				break;
			case 'm':
			case 'M':
				printf("�����û���:");
				scanf("%s", usrName);
				if (Account_UI_Modify(head, usrName)){
					//	printf("�޸ĳɹ���");
					//	paging.totalRecords = Account_Srv_FetchAll(head);
					List_Paging(head, paging, account_node_t);
				}
				break;

			case 'd':
			case 'D':
				printf("����Ҫɾ�����û���:");
				scanf("%s", usrName);
				if (Account_UI_Delete(head, usrName)){
					//	printf("ɾ���ɹ���");
					paging.totalRecords = Account_Srv_FetchAll(head);
					List_Paging(head, paging, account_node_t);
				}	break;

			case 'q':
			case 'Q':
				printf("�����û���:");
				scanf("%s", usrName);
				if (Account_UI_Query(head, usrName)){
					//printf("��ѯ�ɹ���");
					//paging.totalRecords = Account_Srv_FetchAll(head);
					List_Paging(head, paging, account_node_t);
				}
				break;
			}
		} while (choice != 'r' && choice != 'R');
	}
	//�ͷ�����
	List_Destroy(head, account_node_t);
}
//�����ϵͳ�û�����
int  Account_UI_Add(account_list_t list){
	account_t data;
	account_list_t rec;
	int newcount = 0;
	printf("Add New Project Name");
	printf("�����û���:");
	scanf("%s", data.username);
	rec = Account_Srv_FindByUsrName(list, data.username);
	if (rec){
		printf("���û��Ѵ��ڣ������ϵͳ�û�ʧ��\n");
		return 0;
	}
	data.id = EntKey_Perst_GetNewKeys("account", 1);
	printf("\nUSR_ANOMY = 0 �����û�\nUSR_CLERK = 1 ��ƱԱ\nUSR_MANG  = 2  ����\nUSR_ADMIN = 9  ϵͳ����Ա\n�����û�����:");
	getchar();
	char ch;
	scanf("%c", &ch);
	data.type = swap_charto_meiju(ch);
	printf("�������룺");
	scanf("%s", data.password);
	while (strlen(data.password)<6){
		printf("���벻������6λ!\n");
		printf("�������룺");
		scanf("%s", data.password);
	}
	if (Account_Srv_Add(&data)){
		printf("��ӳɹ�!\n");
		rec = (account_list_t)malloc(sizeof(account_node_t));
		rec->data = data;
		List_AddTail(list, rec);
		newcount++;
		return newcount;
	}
	else {
		printf("���ʧ�ܣ�\n");
		return 0;
	}
}

//�޸�ϵͳ�û�����
int Account_UI_Modify(account_list_t list, char usrName[]){
	if (!Account_Srv_FindByUsrName(list, usrName)){
		printf("�û�%s�����ڣ��޸�ʧ��\n", usrName);
		return 0;
	}
	account_list_t rec;
	rec = Account_Srv_FindByUsrName(list, usrName);/*��ȡ���˺ŵĽ��*/
	char password[20];
	char mima[20];
	printf("���������:");
	scanf("%s", mima);
	while (strcmp(mima, rec->data.password) != 0){
		printf("�������\n");
		printf("���ٴ����������:");
		scanf("%s", mima);
	};
	printf("��������ȷ!\n");
	printf("�����µ����룺");
	scanf("%s", password);
	strcpy(rec->data.password, password);
	if (Account_Srv_Modify(&(rec->data))){
		printf("�޸ĳɹ���\n");
		return 1;
	}
	else{
		printf("�޸�ʧ��!\n");
		return 0;
	}
}
//ɾ��ϵͳ�û�����
int Account_UI_Delete(account_list_t list, char usrName[]){
	if (!Account_Srv_FindByUsrName(list, usrName)){
		printf("�û��������ڣ�ɾ��ʧ�ܣ�\n");
		return 0;
	}
	account_node_t *rec;
	rec = Account_Srv_FindByUsrName(list, usrName);
	if (Account_Srv_DeleteByID(rec->data.id)){
		printf("ɾ���ɹ�\n");
		List_DelNode(rec);
		return 1;
	}
	else{
		printf("ɾ��ʧ��\n");
		return 0;
	}
}


//��ѯϵͳ�û�����
int Account_UI_Query(account_list_t list, char usrName[])
{
	account_node_t *rec;
	rec = Account_Srv_FindByUsrName(list, usrName);
	if (!Account_Srv_FindByUsrName(list, usrName)){
		printf("���û������ڣ�\n");
		return 0;
	}
	printf("%5s %30s %15s %15s\n", "ID", "username", "account_type", "mima");
	printf("%5d %30s %15c\n", rec->data.id, rec->data.username, swap_meijuto_char(rec->data.type));
	fflush(stdin);
	printf("��[Enter]����");
	getchar();
	return 1;
}
