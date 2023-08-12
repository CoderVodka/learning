#pragma once

#include <stdio.h>
#include <string.h>

typedef struct PeoInfo
{
	char name[20];
	int age;
	char sex[7];
	char tele[12];
}PeoInfo;

void ShowAllList(PeoInfo list[100], int count);

void ShowSmpList(PeoInfo list[100], int count);

int AddPeo(PeoInfo list[100], int* pcount);

int SearchKeyWords(PeoInfo list[100], int* pcount, PeoInfo** searchRes, char* keywords);

int SearchTele(PeoInfo list[100], int* pcount, PeoInfo** searchRes, char* teleNum);

PeoInfo* SearchPeo(PeoInfo list[100], int* pcount);

int DelPeo(PeoInfo list[100], int* pcount);

PeoInfo* MotifyInfo(PeoInfo list[100], int* pcount);

void SortPeoName(PeoInfo list[100], int count);