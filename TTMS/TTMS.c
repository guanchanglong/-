#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <io.h>
#include <Windows.h>
#include "Main_Menu.h"
#include "Account_UI.h"
//����ȫ�ֱ��������ڴ洢��½�û���Ϣ
account_t gl_CurUser = { 0, USR_ANOMY, "Anonymous","" };
int main(void)
{
	char choice;
	account_t data;
    system("color 0F");
    system("mode con cols=103 lines=35");
	while (1) {
		printf("\n\n\t\t\t\t\t��1.ע�� \n");
		printf("\n\n\t\t\t\t\t��2.��¼ \n");
		printf("\n\n\t\t\t\t\t     ");
		rewind(stdin);
		scanf("%c", &choice);
		getchar();
		switch (choice)
		{
		case'1':
			system("cls");
			printf("\n\t\t\tID:");
			scanf("%d", &data.id);
			printf("\n\t\t\tType:");
			scanf("%d", &data.type);
			printf("\n\t\t\t�˺�:");
			scanf("%s", data.username);
			printf("\n\t\t\t����:");
			scanf("%s", data.password);
			rewind(stdin);
			if (Account_Srv_Add(&data)) {
				system("cls");
				printf("\n\n\t\t\t\t\tע��ɹ������� \n");
				Sleep(2000);
				system("cls");
			}
			else {
				system("cls");
				printf("\n\n\t\t\t\t\tע��ʧ�ܣ����� \n");
				Sleep(2000);
				system("cls");
			}
			break;
		case'2':
			setvbuf(stdout, NULL, _IONBF, 0);
			if (!SysLogin()) {
				printf("\n\t\t\t\t\t�����������,�����˳�ϵͳ\n");
				Sleep(3000);
				return EXIT_SUCCESS;
			}
			else {
				Main_Menu(gl_CurUser);
				system("cls");
			}
			break;
		}
	}
	system("pause"); 
	return EXIT_SUCCESS;
}
	

