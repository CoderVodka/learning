#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

//����һ����ĸ������Ǵ�д��ת����Сд����֮ת���ɴ�д
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

