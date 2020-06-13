#define _CRT_SECURE_NO_DEPRECATE 0
/*
* Account_Persist.c
*
*  Created on: 2015��5��8��
*      Author: Administrator
*/

#include "Account_Persist.h"
#include "Account.h"
#include "List.h"
#include "EntityKey_Persist.h"	
#include "unistd.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#pragma warning(disable: 4996)
static const char ACCOUNT_DATA_FILE[] = "Account.dat";
static const char ACCOUNT_DATA_TEMP_FILE[] = "AccountTmp.dat";

//���˺�д���˺��ļ��У�����ʵ��д������ݿ���Ŀ
int Account_Perst_Insert(const account_t *data) {
	FILE *fp;
	int rtn = 0;
	fp = fopen(ACCOUNT_DATA_FILE, "ab+");
	if (fp == NULL){
		printf("Open file  Account.dat failed!");
		return 0;
	}
	rtn = fwrite(data, sizeof(account_t), 1, fp);
	fclose(fp);
	return rtn;
}

//���˺��ļ��в���������˺�ƥ����˺ţ��ҵ� return 1������ return 0�������и�����д
int Account_Perst_Update(const account_t * data) {
	FILE *fp;
	account_t tmp;

	int count = 0;
	fp = fopen(ACCOUNT_DATA_FILE, "rb+");
	if (fp == NULL)
	{
		printf("\n");
		return 0;
	}
	while (1)
	{
		if (fread(&tmp, sizeof(account_t), 1, fp)<1)
			break;
		if (data->id == tmp.id)                  //�ҵ��޸ĵ�ID
		{
			count = 1;
			fpos_t pos;
			fgetpos(fp, &pos);
			fseek(fp, -(int)sizeof(account_t), SEEK_CUR);
			fwrite(data, sizeof(account_t), 1, fp);
			fsetpos(fp, &pos);
			break;
		}
	}
	if (!count) printf("\n");
	fclose(fp);
	printf("\n");
	return count;
}

//���˺��ļ���ɾ�������idƥ����˺ţ�ɾ���ɹ� return 1������ return 0��
int Account_Perst_DeleteByID(int id) {
	FILE *fp_read = fopen(ACCOUNT_DATA_FILE, "rb");
	FILE *fp_write = fopen(ACCOUNT_DATA_TEMP_FILE, "wb");
	if (!fp_read || !fp_write)
	{
		printf("open file for Delete is failed!\n");
		return 0;
	}
	account_t tmp;
	static int count = 0;
	while (1)
	{
		if (fread(&tmp, sizeof(account_t), 1, fp_read)<1)
			break;
		if (id != tmp.id)
		{
			fwrite(&tmp, sizeof(account_t), 1, fp_write);
		}
		else
		{
			count++;
		}
	}
	fclose(fp_read);
	fclose(fp_write);
	remove(ACCOUNT_DATA_FILE);
	rename(ACCOUNT_DATA_TEMP_FILE, ACCOUNT_DATA_FILE);
	if (count) return 1;
	return 0;

}


//������ACCOUNT_DATA_FILE�ļ�����̬�����û��˺�list����,list Ϊ����ͷָ�룬����list����
int Account_Perst_SelectAll(account_list_t list) {
	FILE *fp;
	account_t tmp;
	int recCount = 0;
	account_node_t *newNode;
	fp = fopen(ACCOUNT_DATA_FILE, "rb");
	//List_Init(list,account_node_t);
	if (!fp){
		printf("���ļ�ʧ��\n");
		return 0;
	}
	else{
		while (1){
			if (fread(&tmp, sizeof(account_t), 1, fp)<1)
				break;
			newNode = (account_node_t *)malloc(sizeof(account_node_t));
			newNode->data = tmp;
			List_AddTail(list, newNode);
			recCount++;
		}
	}
	fclose(fp);
	return recCount;
}

//�ж��˺��ļ��Ƿ���ڣ�����1���ڣ�����0������
int Account_Perst_CheckAccFile() {
	if (access(ACCOUNT_DATA_FILE, 0))
		return 0;
	return 1;
}


//�����û��������˺�,����ɹ� return 1������ return 0
int Account_Perst_SelByName(char usrName[], account_t *buf)
{
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
	account_t data;
	int rtn = 0;
	if (fp == NULL){
		printf("%s��ʧ��!\n", ACCOUNT_DATA_FILE);
		return rtn;
	}
	while (!feof(fp)){
		if (fread(&data, sizeof(data), 1, fp)){
			if (strcmp(data.username, usrName) == 0){
				*buf = data;
				rtn = 1;
				break;
			}
		}
	}
	fclose(fp);
	return rtn;
}


//���˺��ļ��в��������idƥ����˺ţ���ͨ��ָ��buf������ƥ��ɹ� return 1������ return 0��
int Account_Perst_SelectByID(int id, account_t *buf) {
	assert(NULL != buf);
	FILE *fp = fopen(ACCOUNT_DATA_FILE, "rb");
	if (NULL == fp) {
		return 0;
	}
	account_t data;
	int found = 0;
	while (!feof(fp)) {
		if (fread(&data, sizeof(account_t), 1, fp)) {
			if (id == data.id) {
				*buf = data;
				found = 1;
				break;
			};
		}
	}
	fclose(fp);
	return found;
}