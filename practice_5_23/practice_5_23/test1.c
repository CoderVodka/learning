#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	return 0;
}*/
//��δ�����ʵ��޸�����������������Ƶ����https://www.bilibili.com/video/BV1Vm4y1r7jY/?p=30

/*int main()
{
	char password[20];
	printf("����������\n");
	scanf("%s", &password);
	printf("��ȷ������,����Y OR N\n");
	int check = getchar();
	if (check == 'y')
		printf("yes\n", check);
	else
		printf("no\n", check);

	return 0;
}*/
//��δ����������벢�س�֮���ֱ�����no����Ϊ��������󴢴������뻺�����У�
//getchar()�ӻ�������ȡ�����ݣ���������������ʱ�Իس���\n����β��scanf��ȡ�ַ�����\nֹͣ��
//��ʱ�� \n�������뻺�����У�getchar()�������뻺�����õ�\n������ֵ��check����ʱcheck != 'y'�����no��
//ͨ��ʹ��getchar()�����������Ա�����������ķ�����ʾ�����£�

int main()
{
	char password[20];
	printf("����������\n");
	scanf("%s", &password);
	int ret = 0;
	while (ret = getchar() != '\n')      //��������
	{
		;
	}
	printf("��ȷ������,����Y OR N\n");
	int check = getchar();
	if (check == 'Y')
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
//��δ��������ȷִ��������������ȷ�ϵĹ��ܡ�