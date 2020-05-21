#define _CRT_SECURE_NO_DEPRECATE 0
#include <stdio.h>
#include<stdlib.h>
#define MAXS 10

char *match(char *s, char ch1, char ch2){
	int i = 0, j = 0;
	while (s[i] != '\0'&&s[i] != ch1){
		s[i++];
	}
	char *s2 = &s[i];
	if (s[i] == ch1&&s[i] == ch2){
		printf("%c\n", ch1);
		return &s[i];
	}
	while (s2[j] != '\0'&&s2[j] != ch2){
		printf("%c", s2[j++]);
		if (s2[j] == ch2){
			printf("%c", s2[j]);
		}
	}
	printf("\n");
	return &s[i];
}

int main()
{
	char str[MAXS], ch_start, ch_end, *p;
	scanf("%s\n", str);
	scanf("%c %c", &ch_start, &ch_end);
	p = match(str, ch_start, ch_end);
	printf("%s\n", p);
	system("pause");
	return 0;
}