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
//������Ժ��� 
void secretword(char key[]){
	printf("���������룺");
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

//����ϵͳ��ʼ���˺�admin
void Account_Srv_InitSys(){
	if (Account_Perst_CheckAccFile()){
		return;
	}
	account_t data_admin;
	/*	printf("�����û�����");
	scanf("%s",data_admin.username);
	printf("����adminϵͳ�û�ID��");
	printf("�����û�����:\nUSR_ANOMY = 0 �����û�\nUSR_CLERK = 1 ��ƱԱ\nUSR_MANG  = 2  ����\nUSR_ADMIN = 9  ϵͳ����Ա\n");
	getchar();
	char ch;
	scanf("%c",&ch);
	data_admin.type=swap_charto_meiju(ch);*/
	data_admin.id = EntKey_Perst_GetNewKeys("Account", 1);
	data_admin.type = USR_ADMIN;
	strcpy(data_admin.username, "admin");
	strcpy(data_admin.password, "admin");
	//printf("�������룺");
	/*�������
	secretword(data_admin.password);
	scanf("%s",data_admin.password);*/
	Account_Srv_Add(&data_admin);
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

//��֤�û����Ƿ���ڣ�����list�������ڣ����ض�Ӧ���ָ�룻���򣬷���null
account_node_t * Account_Srv_FindByUsrName(account_list_t list, char usrName[]) {
	account_node_t *pos;
	List_ForEach(list, pos){
		if (strcmp(pos->data.username, usrName) == 0){
			//printf("���û�����!\n"); 
			return pos;
		}
	}
	return NULL;
}

//���һ���û��˺ţ�ͨ������Account_Perst_Insert(data)����ʵ��
inline int Account_Srv_Add(const account_t *data){
	if (Account_Perst_Insert(data))
	{
		//  printf("��ӳɹ�!\n");
		return 1;
	}
	else
	{
		//   printf("���ʧ��!\n");
		return 0;
	}
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


//��ȡusrName��Ӧ���û��˺���Ϣ��ͨ������Account_Perst_SelByName(usrName, buf)����ʵ��
inline int Account_Srv_FetchByName(char usrName[], account_t *buf){
	return Account_Perst_SelByName(usrName, buf);
}





//��ȡusrID��Ӧ���û��˺���Ϣ��ͨ������Account_Perst_SelectByID(usrID, buf)����ʵ��
inline int Account_Srv_FetchByID(int usrID, account_t *buf){
	return Account_Perst_SelectByID(usrID, buf);
}

