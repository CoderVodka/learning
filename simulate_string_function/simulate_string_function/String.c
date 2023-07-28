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
	
	if (!count)
		return 0;

	while (count--)
	{
		if (*string1++ != *string2++)
			return *string1 - *string2;
		else if (*string1 == '\0')
			return 0;
	}
}





