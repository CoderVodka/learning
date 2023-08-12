#define  _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//展示通讯录
void ShowAllData(const Contacts* list)
{
	int i = 0;

	printf("---------------------\n");

	for (i = 0; i < list->count; i++)
	{
		printf("姓名：    %s\n", list->data[i].name);
		printf("年龄：    %d\n", list->data[i].age);
		printf("性别：    %s\n", list->data[i].sex);
		printf("电话号码：%s\n", list->data[i].tele);
		printf("---------------------\n");
	}
}

//展示联系人的名称和电话号码
static void ShowSmpList(PeoInfo* members, int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
		printf("%-24s %s\n", members[i].name, members[i].tele);
}

//添加联系人
int AddPeo(Contacts* list)
{
	printf("请输入姓名：");
	scanf("%s", list->data[list->count].name);
	printf("请输入年龄：");
	scanf("%d", &list->data[list->count].age);
	printf("请输入性别：");
	scanf("%s", list->data[list->count].sex);
	printf("请输入电话号码：");
	scanf("%s", list->data[list->count].tele);

	return ++(list->count);
}

//根据名字查找
int SearchName(const Contacts* list, PeoInfo** searchRes, char* keywords)
{
	int len = strlen(keywords);
	int i = 0;
	int searchCount = 0;

	for (i = 0; i < list->count; i++)
	{
		if (strncmp(keywords, list->data[i].name, len) == 0)
			searchRes[searchCount++] = &list->data[i];
	}

	return searchCount;
}

//根据电话查找
int SearchTele(const Contacts* list, PeoInfo** searchRes, char* teleNum)
{
	int len = strlen(teleNum);
	int i = 0;
	int searchCount = 0;

	for (i = 0; i < list->count; i++)
	{
		if (strncmp(teleNum, list->data[i].tele, len) == 0)
			searchRes[searchCount++] = &list->data[i];
	}

	return searchCount;
}

//查找联系人
PeoInfo* SearchPeo(const Contacts* list)
{
	//输入查找关键词
	char searchKeyWords[20] = { 0 };
	printf("请输入要查找的名称或电话：\n");
	scanf("%s", searchKeyWords);
	//创建一个数组储存查找到的联系人的地址
	PeoInfo* resMember[100] = { NULL };
	int resNum = 0;
	int i = 0;

	//判断查找电话或名字
	if (searchKeyWords[0] >= '0' && searchKeyWords[0] <= '9')
		resNum = SearchTele(list, resMember, searchKeyWords);
	else
		resNum = SearchName(list, resMember, searchKeyWords);

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
		printf("请输入目标联系人的编号 / 输入0退出\n");
		scanf("%d", &num);

		//退出返回空指针
		if (0 == num)
			return NULL;

		printf("姓名：    %s\n", resMember[num - 1]->name);
		printf("年龄：    %d\n", resMember[num - 1]->age);
		printf("性别：    %s\n", resMember[num - 1]->sex);
		printf("电话号码：%s\n", resMember[num - 1]->tele);

		//查找完成返回目标地址
		return resMember[num - 1];
	}
}

//删除联系人
int DelPeo(Contacts* list)
{
	//获得搜索到的联系人的地址
	PeoInfo* deleObj = SearchPeo(list);
	int num = 0;
	int i = 0;
	int confirm = 0;

	if (NULL == deleObj)
		return list->count;
	else
	{
		printf("确定删除？1.确定/0.取消\n");
		scanf("%d", &confirm);
		if (confirm)
		{
			num = deleObj - list->data;

			for (i = num; i < list->count - 1; i++)
			{
				list->data[i] = list->data[i + 1];
			}

			return --(list->count);
		}
		else
			return list->count;
	}
}

//修改信息用的菜单
void ModifyMenu()
{
	printf("***************************************\n");
	printf("****** 1.name             2.age  ******\n");
	printf("****** 3.sex              4.tele ******\n");
	printf("****** 0.exit                    ******\n");
	printf("***************************************\n");
}

//修改联系人的信息
PeoInfo* MotifyInfo(Contacts* list)
{
	//获得要修改的联系人地址
	PeoInfo* modifyObj = SearchPeo(list);
	int num = 0;
	int input = 0;
	
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

			//选择修改的内容
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

//根据姓名比较顺序
int CmpByName(const void* elem1, const void* elem2)
{
	return strcmp(((PeoInfo*)elem1)->name, ((PeoInfo*)elem2)->name);
}

//按姓名顺序排序
void SortPeoName(Contacts* list)
{
	qsort(list->data, list->count, sizeof(list->data[0]), CmpByName);
}