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

//����ͨѶ¼��Ҫ��¼��Ա��������˽�ͨѶ¼�����������װ��һ���ṹ�壬������ʹ��
typedef struct Contacts
{
	PeoInfo data[100];
	int count;
}Contacts;

//չʾͨѶ¼
void ShowAllData(const Contacts* list);

//�����ϵ��
int AddPeo(Contacts* list);

//������ϵ��
PeoInfo* SearchPeo(const Contacts* list);

//ɾ����ϵ��
int DelPeo(Contacts* list);

//�޸���ϵ�˵���Ϣ
PeoInfo* MotifyInfo(Contacts* list);

//������˳������
void SortPeoName(Contacts* list);