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
	
	//if (!count)   //这样写会报警告：不是所有控件路径都有返回值
	//	return 0;   //在while之后return 0，当count == 0时，while不执行，直接return 0。

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
	const char* start = mainString;           //返回值参数
	const char* pmain = mainString;
	const char* pdest = objString;

	if ('\0' == *objString)         //如果要寻找的字符串长度为0，返回被寻找字符串的首地址
		return start;
	
	while (*pmain)
	{
		while (*pdest)   //寻找字符串
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

	if ((*pmain == '\0') && (*pdest != *pmain)) //没找到，返回值设空
		start = NULL;

	return start;
}





