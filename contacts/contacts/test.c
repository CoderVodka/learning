#define  _CRT_SECURE_NO_WARNINGS

//通讯录，实现增删改查、排序、显示功能

#include "contacts.h"

void Menu()
{
	printf("***************************************\n");
	printf("****** 0.exit           1.menu   ******\n");
	printf("****** 2.add            3.del    ******\n");
	printf("****** 4.modify         5.search ******\n");
	printf("****** 6.sort           7.show   ******\n");
	printf("***************************************\n");
	printf("请选择操作:\n");
}

int main()
{
	PeoInfo peoList[100] = { 
		{ "zhangsan", 18, "male", "18012345657" }, 
		{ "lisi", 20, "male", "18600930202" },
		{ "zhangli", 18, "female", "13895950429" }, 
		{ "zhenlong", 23, "male", "12422549458" } };
	int count = 4;
	int input = 1;
	Menu();
	
	do
	{
		scanf("%d", &input);

		switch (input)
		{
		case 0:
			printf("exit\n");
			break;
		case 1:
			printf("show menu\n");
			Menu();
			break;
		case 2:
			printf("add member\n");
			int ret = AddPeo(peoList, &count);
			if (-1 == ret)
				printf("重复的姓名或电话\n");
			else
				printf("添加成功\n");
			break;
		case 3:
			printf("delete member\n");
			DelPeo(peoList, &count);
			break;
		case 4:
			printf("motify member information\n");
			MotifyInfo(peoList, &count);
			break;
		case 5:
			printf("search members\n");
			SearchPeo(peoList, &count);
			break;
		case 6:
			printf("sort members\n");
			SortPeoName(peoList, count);
			break;
		case 7:
			printf("show members\n");
			ShowSmpList(peoList, count);
			break;
		default:
			printf("error\n");
			break;
		}
	} while (input);

	return 0;
}