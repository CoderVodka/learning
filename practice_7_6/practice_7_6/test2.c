#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//�ж�һ�����ǲ���2��n�η�
int main()
{
	int num = 0;
	scanf("%d", &num);

	if (num & (num - 1) == 0)
		printf("��������2��n�η�");
	else
		printf("�����ֲ���2��n�η�");

	return 0;
}