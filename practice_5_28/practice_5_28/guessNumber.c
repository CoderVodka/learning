#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//���Բ���һ���������1-100��
// �����֣������´���/��С��,���3��
// �¶�ʱ����

void menu()
{
	printf("**************************\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
	printf("��ѡ��");
}

void game()
{
	//1.���������
	int ret = rand() % 100 + 1;   //�������������1-100��x%100=[0,99]��+1�õ�1-100.  rand()��srand()������Ҫͷ�ļ�<stdlib.h>

	//2.������
	printf("������֣�\n");	
	int guess = 0;
	int i = 1;
	while(i <= 3)
	{
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("�´���\n");
			i++;
		}
		else if (guess < ret)
		{
			printf("��С��\n");
			i++;
		}
		else
		{
			printf("�¶���\n");
			printf("�ܹ�����%d��\n", i);
			break;
		}
	}
	if (i > 3)
		printf("��Ϸʧ��\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //�������������������
	                                 //time����Ϊָ�룬����Ҫʹ��ʱ���Դ�NULL���ú�����Ҫͷ�ļ�time.h
	                                 //time����ֵΪlong/long long��srand����Ϊint���˴�����ǿ��ת��
	do
	{
		//��ӡ�˵�
		menu();               
		scanf("%d", &input);

		//�ж�play/exit/����
		switch (input)        
		{
			case 1:
				game();
				break;
			case 0:
				printf("�˳���Ϸ\n");
				break;
			default:
				printf("ѡ�����������ѡ��");
				break;
		}
	} while (input);          //input = 0ʱ�˳�ѭ��
}