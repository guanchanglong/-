/*
* Account_UI.h
*
*  Created on: 2015年5月8日
*      Author: Administrator
*/
#include "List.h"
#include "Account.h"

#ifndef ACCOUNT_UI_H_
#define ACCOUNT_UI_H_

static const int ACCOUNT_PAGE_SIZE = 3;

//系统登录
int SysLogin();

//系统用户管理界面
void Account_UI_MgtEntry();

//添加新系统用户界面
int  Account_UI_Add(account_list_t list);

//修改系统用户界面
int Account_UI_Modify(account_list_t list, char usrName[]);

//删除系统用户界面
int Account_UI_Delete(account_list_t list, char usrName[]);

//查询系统用户界面
int Account_UI_Query(account_list_t list, char usrName[]);

inline  char swap_meijuto_char(account_type_t status);

inline account_type_t swap_charto_meiju(char status);


#endif /* ACCOUNT_UI_H_ */