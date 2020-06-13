#define _CRT_SECURE_NO_DEPRECATE 0
#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Account_UI.c
*
*  Created on: 2015年4月24日
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

//删除一个用户账号，通过调用Account_Perst_DeleteByID(usrID)函数实现
inline int Account_Srv_DeleteByID(int usrID){
	if (Account_Perst_DeleteByID(usrID)){
		return 1;
	}
	else{
		return 0;
	}
}

//提取所有用户账号信息，保存到list链表中，通过调用Account_Perst_SelectAll(list)函数实现
inline int Account_Srv_FetchAll(account_list_t list){
	return Account_Perst_SelectAll(list);
}

//修改一个用户账号，通过调用Account_Perst_Update(data)函数实现
inline int Account_Srv_Modify(const account_t *data){
	if (Account_Perst_Update(data)){
		return 1;
	}
	else{
		return 0;
	}
}

//验证登录账号是否已存在，存在，保存登录用户信息到全局变量gl_CurUser，return 1；否则return 0
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

//系统登录
int SysLogin(){
	Account_Srv_InitSys();//创建初始化账号 
	printf("===============================================\n");
	printf("***********欢迎使用奥斯卡剧院票务管理系统!*************\n");
	printf("------------------------------------------------\n");
	printf("请您先登录!\n");
	int i = 0;
	char usrName[20];
	char pwd[20];
	while (i<3){
		printf("输入用户名:");
		scanf("%s", usrName);
		printf("输入密码:");
		scanf("%s", pwd);
		if (Account_Srv_Verify(usrName, pwd)){
			printf("用户存在，登陆成功!\n");
			return 1;
		}
		//不存在         
		printf("用户名或密码错误！请重新输入\n");
		i++;
	}
	printf("密码错误超过三次!\n");
	getchar();
	return 0;
}

//系统用户管理界面
void Account_UI_MgtEntry(){
	char usrName[30];
	int i;
	char choice;
	Pagination_t paging;//分页
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
			//遍历 
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
			printf("[P]上一页    [N]下一页  \n[A]添加用户  [D]删除用户\n[M]修改密码  [Q]查询用户  \n[R]结束\n");
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
					//	printf("添加成功!");
					//paging.totalRecords =Account_Srv_FetchAll(head);
					paging.totalRecords += 1;
					Paging_Locate_LastPage(head, paging, account_node_t);
				}
				break;
			case 'm':
			case 'M':
				printf("输入用户名:");
				scanf("%s", usrName);
				if (Account_UI_Modify(head, usrName)){
					//	printf("修改成功！");
					//	paging.totalRecords = Account_Srv_FetchAll(head);
					List_Paging(head, paging, account_node_t);
				}
				break;

			case 'd':
			case 'D':
				printf("输入要删除的用户名:");
				scanf("%s", usrName);
				if (Account_UI_Delete(head, usrName)){
					//	printf("删除成功！");
					paging.totalRecords = Account_Srv_FetchAll(head);
					List_Paging(head, paging, account_node_t);
				}	break;

			case 'q':
			case 'Q':
				printf("输入用户名:");
				scanf("%s", usrName);
				if (Account_UI_Query(head, usrName)){
					//printf("查询成功！");
					//paging.totalRecords = Account_Srv_FetchAll(head);
					List_Paging(head, paging, account_node_t);
				}
				break;
			}
		} while (choice != 'r' && choice != 'R');
	}
	//释放链表
	List_Destroy(head, account_node_t);
}
//添加新系统用户界面
int  Account_UI_Add(account_list_t list){
	account_t data;
	account_list_t rec;
	int newcount = 0;
	printf("Add New Project Name");
	printf("输入用户名:");
	scanf("%s", data.username);
	rec = Account_Srv_FindByUsrName(list, data.username);
	if (rec){
		printf("该用户已存在，添加新系统用户失败\n");
		return 0;
	}
	data.id = EntKey_Perst_GetNewKeys("account", 1);
	printf("\nUSR_ANOMY = 0 匿名用户\nUSR_CLERK = 1 售票员\nUSR_MANG  = 2  经理\nUSR_ADMIN = 9  系统管理员\n输入用户类型:");
	getchar();
	char ch;
	scanf("%c", &ch);
	data.type = swap_charto_meiju(ch);
	printf("输入密码：");
	scanf("%s", data.password);
	while (strlen(data.password)<6){
		printf("密码不得少于6位!\n");
		printf("输入密码：");
		scanf("%s", data.password);
	}
	if (Account_Srv_Add(&data)){
		printf("添加成功!\n");
		rec = (account_list_t)malloc(sizeof(account_node_t));
		rec->data = data;
		List_AddTail(list, rec);
		newcount++;
		return newcount;
	}
	else {
		printf("添加失败！\n");
		return 0;
	}
}

//修改系统用户界面
int Account_UI_Modify(account_list_t list, char usrName[]){
	if (!Account_Srv_FindByUsrName(list, usrName)){
		printf("用户%s不存在，修改失败\n", usrName);
		return 0;
	}
	account_list_t rec;
	rec = Account_Srv_FindByUsrName(list, usrName);/*获取该账号的结点*/
	char password[20];
	char mima[20];
	printf("输入旧密码:");
	scanf("%s", mima);
	while (strcmp(mima, rec->data.password) != 0){
		printf("密码错误\n");
		printf("请再次输入旧密码:");
		scanf("%s", mima);
	};
	printf("旧密码正确!\n");
	printf("输入新的密码：");
	scanf("%s", password);
	strcpy(rec->data.password, password);
	if (Account_Srv_Modify(&(rec->data))){
		printf("修改成功！\n");
		return 1;
	}
	else{
		printf("修改失败!\n");
		return 0;
	}
}
//删除系统用户界面
int Account_UI_Delete(account_list_t list, char usrName[]){
	if (!Account_Srv_FindByUsrName(list, usrName)){
		printf("用户名不存在，删除失败！\n");
		return 0;
	}
	account_node_t *rec;
	rec = Account_Srv_FindByUsrName(list, usrName);
	if (Account_Srv_DeleteByID(rec->data.id)){
		printf("删除成功\n");
		List_DelNode(rec);
		return 1;
	}
	else{
		printf("删除失败\n");
		return 0;
	}
}


//查询系统用户界面
int Account_UI_Query(account_list_t list, char usrName[])
{
	account_node_t *rec;
	rec = Account_Srv_FindByUsrName(list, usrName);
	if (!Account_Srv_FindByUsrName(list, usrName)){
		printf("该用户不存在！\n");
		return 0;
	}
	printf("%5s %30s %15s %15s\n", "ID", "username", "account_type", "mima");
	printf("%5d %30s %15c\n", rec->data.id, rec->data.username, swap_meijuto_char(rec->data.type));
	fflush(stdin);
	printf("按[Enter]返回");
	getchar();
	return 1;
}
