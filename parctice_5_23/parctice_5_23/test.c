#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//输出1-100之间的奇数
int main()
{

	int i = 1;

	while (i <= 100)
	{
		if (i % 2 == 1)
			printf("%d ", i);
		i++;
	}

	return 0;
}