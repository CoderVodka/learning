#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[7];
	char tele[12];
}PeoInfo;

//创建通讯录需要记录成员数量，因此将通讯录数组与计数封装成一个结构体，更方便使用
typedef struct Contacts
{
	PeoInfo data[100];
	int count;
}Contacts;

//展示通讯录
void ShowAllData(const Contacts* list);

//添加联系人
int AddPeo(Contacts* list);

//搜索联系人
PeoInfo* SearchPeo(const Contacts* list);

//删除联系人
int DelPeo(Contacts* list);

//修改联系人的信息
PeoInfo* MotifyInfo(Contacts* list);

//按姓名顺序排序
void SortPeoName(Contacts* list);