#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
	char title1[8] = "Name";   //�����ַ�����Ҫ���������ʽ���� char title1 = "Name"; �ǲ��Ե�
	char title2[8] = "Age";
	char title3[8] = "Gender";
	char name[8] = "Jack";
	int age = 18;
	char gender[8] = "man";

	printf("%-6s %-6s %-6s \n", title1, title2, title3);
	printf("---------------------\n");
	printf("%-6s %-6d %-6s \n",name,age,gender);
	//�������������һ
	// ÿ�������ַ�����д��%nC����ʽ����%10d, %12f, %5c, %20s�ȵȣ�
	//���Ӧ���ǲ��㲿����ಹ�ո�ʵ���Ҷ���Ч������Ҫ���㲿���Ҳಹ�ո�
	//ֻ��Ҫ�ڿ���ַ�ǰ��-���ż��ɣ���%-12f����ʱʵ�ֵ��������Ч����

	printf("%s\t %s\t %s\t \n", title1, title2, title3);
	printf("---------------------\n");
	printf("%s\t %d\t %s\t \n", name, age, gender);
	//�Ʊ��\t�����ʱ�򣬻��ƶ������꣬ʵ�ֶ���Ч������˿���������Ķ�Ӧλ�ã�����\t��ʵ�ֶ��롣
	//ȱ�㣺Ҫ��ÿ����ͬ�����ռ�ÿռ��𲻿���̫��

	return 0;

}