#include "String.h"

#define  _CRT_SECURE_NO_WARNINGS

char* StringNumCopy(char* destination, const char* source, int count)
{
	assert(destination && source);
	char* start = destination;

	while (count-- && (*destination++ = *source++))
		;

	//if (*(destination - 1) != '\0')
	//	*destination = '\0';                                         	                                                      
	if (count)                             
		while (count--)
			*destination++ = '\0';
	
	return start;
}

char* StringNumCat(char* front, const char* back, int count)
{
	assert(front && back);
	char* start = front;
	
	while (*front)
	{
		front++;
	}

	while (count-- && (*front++ = *back++))
		;

	if (*(front - 1) != '\0')
		*front = '\0';

	return start;
}

int StringNumCompare(const char* string1, const char* string2, int count)
{
	assert(string1 && string2);
	
	//if (!count)   //����д�ᱨ���棺�������пؼ�·�����з���ֵ
	//	return 0;   //��while֮��return 0����count == 0ʱ��while��ִ�У�ֱ��return 0��

	while (count--)
	{
		if (*string1++ != *string2++)
			return *string1 - *string2;
		else if (*string1 == '\0')
			return 0;
	}

	return 0;
}

char* StringString(const char* mainString, const char* objString)
{
	assert(mainString && objString);
	const char* start = mainString;           //����ֵ����
	const char* pmain = mainString;
	const char* pdest = objString;

	if ('\0' == *objString)         //���ҪѰ�ҵ��ַ�������Ϊ0�����ر�Ѱ���ַ������׵�ַ
		return start;
	
	while (*pmain)
	{
		while (*pdest)   //Ѱ���ַ���
		{
			if (*pmain++ != *pdest++)
			{
				pdest = objString;
				pmain = ++start;
				break;
			}
		}

		if (*pdest == '\0')
			break;
	}

	if ((*pmain == '\0') && (*pdest != *pmain)) //û�ҵ�������ֵ���
		start = NULL;

	return start;
}





