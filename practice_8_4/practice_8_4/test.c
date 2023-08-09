#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>

//模拟实现memmove
void* MemMove(void* dest, const void* sour, int num)
{
	assert(dest && sour);
	char* pdest = (char*)dest;
	char* psour = (char*)sour;

	if (pdest < psour)
	{
		while (num--)
		{
			*pdest++ = *psour++;
		}
	}
	else if (pdest > psour)
	{
		//pdest += num - 1;
		//psour += num - 1;

		//while (num--)
		//{
		//	*pdest-- = *psour--;
		//}

		//简化
		while (num--)
			*(pdest + num) = *(psour + num);
	}

	return dest;
}

int main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	MemMove(arr + 2, arr, 20);
	int i = 0;

	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}