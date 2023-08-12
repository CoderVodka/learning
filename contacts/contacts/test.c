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

enum Operation 
{
	EXIT,
	MENU,
	ADD,
	DEL,
	MODIFY,
	SEARCH,
	SORT,
	SHOW
};

int main()
{
	Contacts member = {
		{{ "zhangsan", 18, "male", "18012345657" },
		 { "lisi", 20, "male", "18600930202" },
		 { "zhangli", 18, "female", "13895950429" },
		 { "zhenlong", 23, "male", "12422549458" }},
		4 };
	int input = 1;
	Menu();
	
	do
	{
		scanf("%d", &input);

		switch (input)
		{
		case EXIT:
			printf("exit\n");
			break;
		case MENU:
			printf("show menu\n");
			Menu();
			break;
		case ADD:
			printf("add member\n");
			AddPeo(&member);
			break;
		case DEL:
			printf("delete member\n");
			DelPeo(&member);
			break;
		case MODIFY:
			printf("modify member information\n");
			MotifyInfo(&member);
			break;
		case SEARCH:
			printf("search members\n");
			SearchPeo(&member);
			break;
		case SORT:
			printf("sort members\n");
			SortPeoName(&member);
			break;
		case SHOW:
			printf("show members\n");
			ShowAllData(&member);
			break;
		default:
			printf("error\n");
			break;
		}
	} while (input);

	return 0;
}