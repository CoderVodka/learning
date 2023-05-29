#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//电脑产生一个随机数（1-100）
// 猜数字，反馈猜大了/猜小了,最多3次
// 猜对时结束

void menu()
{
	printf("**************************\n");
	printf("******    1.play    ******\n");
	printf("******    0.exit    ******\n");
	printf("**************************\n");
	printf("请选择：");
}

void game()
{
	//1.生成随机数
	int ret = rand() % 100 + 1;   //将随机数控制在1-100，x%100=[0,99]，+1得到1-100.  rand()和srand()函数需要头文件<stdlib.h>

	//2.猜数字
	printf("请猜数字：\n");	
	int guess = 0;
	int i = 1;
	while(i <= 3)
	{
		scanf("%d", &guess);
		if (guess > ret)
		{
			printf("猜大了\n");
			i++;
		}
		else if (guess < ret)
		{
			printf("猜小了\n");
			i++;
		}
		else
		{
			printf("猜对了\n");
			printf("总共猜了%d次\n", i);
			break;
		}
	}
	if (i > 3)
		printf("游戏失败\n");
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL)); //设置随机数的生成器。
	                                 //time参数为指针，不需要使用时可以传NULL，该函数需要头文件time.h
	                                 //time返回值为long/long long，srand参数为int，此处进行强制转换
	do
	{
		//打印菜单
		menu();               
		scanf("%d", &input);

		//判断play/exit/错误
		switch (input)        
		{
			case 1:
				game();
				break;
			case 0:
				printf("退出游戏\n");
				break;
			default:
				printf("选择错误，请重新选择");
				break;
		}
	} while (input);          //input = 0时退出循环
}