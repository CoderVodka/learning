#define  _CRT_SECURE_NO_WARNINGS

#include "contacts.h"

//չʾͨѶ¼
void ShowAllData(const Contacts* list)
{
	int i = 0;

	printf("---------------------\n");

	for (i = 0; i < list->count; i++)
	{
		printf("������    %s\n", list->data[i].name);
		printf("���䣺    %d\n", list->data[i].age);
		printf("�Ա�    %s\n", list->data[i].sex);
		printf("�绰���룺%s\n", list->data[i].tele);
		printf("---------------------\n");
	}
}

//չʾ��ϵ�˵����ƺ͵绰����
static void ShowSmpList(PeoInfo* members, int count)
{
	int i = 0;

	for (i = 0; i < count; i++)
		printf("%-24s %s\n", members[i].name, members[i].tele);
}

//�����ϵ��
int AddPeo(Contacts* list)
{
	printf("������������");
	scanf("%s", list->data[list->count].name);
	printf("���������䣺");
	scanf("%d", &list->data[list->count].age);
	printf("�������Ա�");
	scanf("%s", list->data[list->count].sex);
	printf("������绰���룺");
	scanf("%s", list->data[list->count].tele);

	return ++(list->count);
}

//�������ֲ���
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

//���ݵ绰����
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

//������ϵ��
PeoInfo* SearchPeo(const Contacts* list)
{
	//������ҹؼ���
	char searchKeyWords[20] = { 0 };
	printf("������Ҫ���ҵ����ƻ�绰��\n");
	scanf("%s", searchKeyWords);
	//����һ�����鴢����ҵ�����ϵ�˵ĵ�ַ
	PeoInfo* resMember[100] = { NULL };
	int resNum = 0;
	int i = 0;

	//�жϲ��ҵ绰������
	if (searchKeyWords[0] >= '0' && searchKeyWords[0] <= '9')
		resNum = SearchTele(list, resMember, searchKeyWords);
	else
		resNum = SearchName(list, resMember, searchKeyWords);

	if (0 == resNum)
	{
		printf("δ�ҵ�\n");
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
		printf("������Ŀ����ϵ�˵ı�� / ����0�˳�\n");
		scanf("%d", &num);

		//�˳����ؿ�ָ��
		if (0 == num)
			return NULL;

		printf("������    %s\n", resMember[num - 1]->name);
		printf("���䣺    %d\n", resMember[num - 1]->age);
		printf("�Ա�    %s\n", resMember[num - 1]->sex);
		printf("�绰���룺%s\n", resMember[num - 1]->tele);

		//������ɷ���Ŀ���ַ
		return resMember[num - 1];
	}
}

//ɾ����ϵ��
int DelPeo(Contacts* list)
{
	//�������������ϵ�˵ĵ�ַ
	PeoInfo* deleObj = SearchPeo(list);
	int num = 0;
	int i = 0;
	int confirm = 0;

	if (NULL == deleObj)
		return list->count;
	else
	{
		printf("ȷ��ɾ����1.ȷ��/0.ȡ��\n");
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

//�޸���Ϣ�õĲ˵�
void ModifyMenu()
{
	printf("***************************************\n");
	printf("****** 1.name             2.age  ******\n");
	printf("****** 3.sex              4.tele ******\n");
	printf("****** 0.exit                    ******\n");
	printf("***************************************\n");
}

//�޸���ϵ�˵���Ϣ
PeoInfo* MotifyInfo(Contacts* list)
{
	//���Ҫ�޸ĵ���ϵ�˵�ַ
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

			//ѡ���޸ĵ�����
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

//���������Ƚ�˳��
int CmpByName(const void* elem1, const void* elem2)
{
	return strcmp(((PeoInfo*)elem1)->name, ((PeoInfo*)elem2)->name);
}

//������˳������
void SortPeoName(Contacts* list)
{
	qsort(list->data, list->count, sizeof(list->data[0]), CmpByName);
}