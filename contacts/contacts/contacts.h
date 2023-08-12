#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DATA 100
#define NAME 20
#define SEX 7
#define TELE 12

typedef struct PeoInfo
{
	char name[NAME];
	int age;
	char sex[SEX];
	char tele[TELE];
}PeoInfo;

//����ͨѶ¼��Ҫ��¼��Ա��������˽�ͨѶ¼�����������װ��һ���ṹ�壬������ʹ��
typedef struct Contacts
{
	PeoInfo data[DATA];
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