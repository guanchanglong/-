#define _CRT_SECURE_NO_DEPRECATE 0
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	for (a = 'x'; a <= 'z'; a++)
	{
		for (b = 'x'; b <= 'z'; b++)
		{
			for (c = 'x'; c <= 'z'; c++)
			{
				if (a != 'x' && c != 'x' && c != 'z' && a!=b && a!=c && b!=c)
				{
					printf("a��%c,b��%c,c��%c\n", a, b, c);
				}
			}
		}
	}
	system("pause");
	return 0;
}
//27.��Ŀ��	����ƹ����ӽ��б������������ˡ��׶�Ϊa,b,c���ˣ��Ҷ�Ϊx,y,z���ˡ��Գ�ǩ��������������
//			�������Ա����������������a˵������x�ȣ�c˵������x,z�ȣ��������ҳ��������ֵ�������