#define  _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

void ShowAllList(PeoInfo list[100], int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
	{
		printf("%s\n%d\n%s\n%s\n\n",
			list[i].name,
			list[i].age,
			list[i].sex,
			list[i].tele);
	}
}

void ShowSmpList(PeoInfo list[100], int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
		printf("%-24s %s\n", list[i].name, list[i].tele);
}

int AddPeo(PeoInfo list[100], int* pcount)
{
	PeoInfo tmp = { 0 };
	scanf("%s %d %s %s", tmp.name, &tmp.age, tmp.sex, tmp.tele);
	int flag = 0;
	int i = 0;
	
	for (i = 0; i < *pcount; i++)
	{
		if (strcmp(list[i].name, tmp.name) == 0 ||
			strcmp(list[i].tele, tmp.tele) == 0)
			flag = 1;
	}

	if (flag)
		return -1;
	else
	{
		list[*pcount] = tmp;
		return ++(*pcount);
	}
}

int SearchKeyWords(PeoInfo list[100], int* pcount, PeoInfo** searchRes, char* keywords)
{
	int len = strlen(keywords);
	int i = 0;
	int searchCount = 0;

	for (i = 0; i < *pcount; i++)
	{
		if (strncmp(keywords, list[i].name, len) == 0)
			searchRes[searchCount++] = &list[i];
	}

	return searchCount;
}

int SearchTele(PeoInfo list[100], int* pcount, PeoInfo** searchRes, char* teleNum)
{
	int len = strlen(teleNum);
	int i = 0;
	int searchCount = 0;

	for (i = 0; i < *pcount; i++)
	{
		if (strncmp(teleNum, list[i].tele, len) == 0)
			searchRes[searchCount++] = &list[i];
	}

	return searchCount;
}




PeoInfo* SearchPeo(PeoInfo list[100], int* pcount)
{
	char searchMsg[20] = { 0 };
	scanf("%s", searchMsg);
	int resNum = 0;
	PeoInfo* resMember[100] = { NULL };
	int i = 0;

	if (searchMsg[0] >= '0' && searchMsg[0] <= '9')
		resNum = SearchTele(list, pcount, resMember, searchMsg);
	else
		resNum = SearchKeyWords(list, pcount, resMember, searchMsg);

	if (0 == resNum)
	{
		printf("未找到\n");
		return NULL;
	}
	else
	{
		for (i = 0; i < resNum; i++)
		{
			printf("%d. ", i + 1);
			ShowSmpList(resMember[i], 1);
		}
		int num = 0;
		printf("请输入目标编号/输入0退出\n");
		scanf("%d", &num);

		if (0 == num)
			return NULL;

		ShowAllList(resMember[num - 1], 1);

		return resMember[num - 1];
	}
}

int DelPeo(PeoInfo list[100], int* pcount)
{
	PeoInfo* deleObj = SearchPeo(list, pcount);
	int num = 0;
	int i = 0;
	int confirm = 0;
	PeoInfo empty = { 0 };

	if (NULL == deleObj)
		return *pcount;
	else
	{
		printf("确定删除？1.确定/0.取消\n");
		scanf("%d", &confirm);
		if (confirm)
		{
			num = deleObj - list;

			for (i = num; i < *pcount - 1; i++)
			{
				list[i] = list[i + 1];
			}

			list[++i] = empty;

			return --(*pcount);
		}
		else
			return *pcount;
	}
}

void ModifyMenu()
{
	printf("***************************************\n");
	printf("****** 1.name             2.age  ******\n");
	printf("****** 3.sex              4.tele ******\n");
	printf("****** 0.exit                    ******\n");
	printf("***************************************\n");
}

PeoInfo* MotifyInfo(PeoInfo list[100], int* pcount)
{
	PeoInfo* modifyObj = SearchPeo(list, pcount);
	int num = 0;
	int input = 0;
	PeoInfo empty = { 0 };

	if (NULL == modifyObj)
	{
		return NULL;
	}
	else
	{
		do
		{
			ModifyMenu();
			scanf("%d", &input);

			switch (input)
			{
			case 0:
				break;
			case 1:
				scanf("%s", modifyObj->name);
				break;
			case 2:
				scanf("%d", &modifyObj->age);
				break;
			case 3:
				scanf("%s", modifyObj->sex);
				break;
			case 4:
				scanf("%s", modifyObj->tele);
				break;
			default:
				break;
			}
		} while (input);

		return modifyObj;
	}
}

void SortPeoName(PeoInfo list[100], int count)
{
	PeoInfo tmp = { 0 };
	int i = 0;
	int j = 0;

	for (i = 0; i < count; i++)
	{
		for (j = 0; j < count; j++)
		{
			if (strcmp(list[i].name, list[i + 1].name) > 0)
			{
				tmp = list[i];
				list[i] = list[i + 1];
				list[i + 1] = tmp;
			}
		}
	}
}