#define _CRT_SECURE_NO_DEPRECATE 0
#include "Account.h"
#include "List.h"
#include "Account_Persist.h"
#include "Account_UI.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include"conio.h"
#include<ctype.h>
#include"EntityKey_Persist.h"
#pragma warning(disable: 4996)
extern account_t GL_CurUser;
//密码回显函数 
void secretword(char key[]){
	printf("请输入密码：");
	unsigned char c;
	int i = 0;
	while ((c = getch()) != '\r'){
		if (i<20 && isprint(c)){
			key[i] = c;
			i++;
			putchar('*');
		}
		else if (i>0 && c == '\b'){
			i--;
			putchar('\b');
			putchar(' ');
			putchar('\b');
		}
	}
	printf("\n");
	key[i] = '\0';
}

//创建系统初始化账号admin
void Account_Srv_InitSys(){
	if (Account_Perst_CheckAccFile()){
		return;
	}
	account_t data_admin;
	/*	printf("输入用户名：");
	scanf("%s",data_admin.username);
	printf("输入admin系统用户ID：");
	printf("输入用户类型:\nUSR_ANOMY = 0 匿名用户\nUSR_CLERK = 1 售票员\nUSR_MANG  = 2  经理\nUSR_ADMIN = 9  系统管理员\n");
	getchar();
	char ch;
	scanf("%c",&ch);
	data_admin.type=swap_charto_meiju(ch);*/
	data_admin.id = EntKey_Perst_GetNewKeys("Account", 1);
	data_admin.type = USR_ADMIN;
	strcpy(data_admin.username, "admin");
	strcpy(data_admin.password, "admin");
	//printf("输入密码：");
	/*密码回显
	secretword(data_admin.password);
	scanf("%s",data_admin.password);*/
	Account_Srv_Add(&data_admin);
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

//验证用户名是否存在，遍历list，若存在，返回对应结点指针；否则，返回null
account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	account_node_t *pos;
	List_ForEach(list, pos){
		if (strcmp(pos->data.username, usrName) == 0){
			//printf("该用户存在!\n"); 
			return pos;
		}
	}
	return NULL;
}

//添加一个用户账号，通过调用Account_Perst_Insert(data)函数实现
inline int Account_Srv_Add(const account_t *data){
	if (Account_Perst_Insert(data))
	{
		//  printf("添加成功!\n");
		return 1;
	}
	else
	{
		//   printf("添加失败!\n");
		return 0;
	}
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


//提取usrName对应的用户账号信息，通过调用Account_Perst_SelByName(usrName, buf)函数实现
inline int Account_Srv_FetchByName(char usrName[], account_t *buf){
	return Account_Perst_SelByName(usrName, buf);
}





//提取usrID对应的用户账号信息，通过调用Account_Perst_SelectByID(usrID, buf)函数实现
inline int Account_Srv_FetchByID(int usrID, account_t *buf){
	return Account_Perst_SelectByID(usrID, buf);
}

