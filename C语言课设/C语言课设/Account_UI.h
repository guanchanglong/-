/*
* Account_UI.h
*
*  Created on: 2015��5��8��
*      Author: Administrator
*/
#include "List.h"
#include "Account.h"

#ifndef ACCOUNT_UI_H_
#define ACCOUNT_UI_H_

static const int ACCOUNT_PAGE_SIZE = 3;

//ϵͳ��¼
int SysLogin();

//ϵͳ�û��������
void Account_UI_MgtEntry();

//�����ϵͳ�û�����
int  Account_UI_Add(account_list_t list);

//�޸�ϵͳ�û�����
int Account_UI_Modify(account_list_t list, char usrName[]);

//ɾ��ϵͳ�û�����
int Account_UI_Delete(account_list_t list, char usrName[]);

//��ѯϵͳ�û�����
int Account_UI_Query(account_list_t list, char usrName[]);

inline  char swap_meijuto_char(account_type_t status);

inline account_type_t swap_charto_meiju(char status);


#endif /* ACCOUNT_UI_H_ */