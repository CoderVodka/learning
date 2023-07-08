#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

//输入一个字母，如果是大写则转换成小写，反之转换成大写
int main()
{
	char ch = 0;
	
	while (scanf("%c", &ch) == 1)
	{
		if (islower(ch))
			printf("%c\n", toupper(ch));
		else
			printf("%c\n", tolower(ch));
		getchar();
	}

	return 0;
}

