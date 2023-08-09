#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <assert.h>

//��дһ�������������ַ����е�k���ַ�
// e.g. ABCD����1�� -> BCDA
//          ����2�� -> CDAB
// ÿ����תһ���ַ�����k�����ַ�������ʱ���ظ�֮ǰ�Ĳ���
// e.g. ABCD����6�� -> CDAB
//          ����5�� -> BCDA
//����1
//void LeftRevolve(char* string, int num)
//{
//  int length = strlen(string);
//  num %= length;
// 
//	while (num--)
//	{
//		char* pfirst = string;
//		char first = *string;
//
//		while (*string)
//		{
//			*string = *(string + 1);
//			string++;
//		}
//
//		*(string - 1) = first;
//		string = pfirst;
//	}
//}

//����2
//���ַ�����Ϊ���������֣�����ַ�������Ϊk��
//�ֱ������������֣����������򣬼���ʵ�� 
//e.g.ABCD����2���ַ���AB|CD -> �ֱ����� -> BA|DC -> �������� -> CDAB
void Invert(char* start, char* end)
{
	assert(start && end);

	while (start < end)
	{
		char tmp = *start;
		*start = *end;
		*end = tmp;
		end--;
		start++;
	}
}

void LeftRevolve(char* string, int num)
{
	int length = strlen(string);
	num %= length;                           //��ֹԽ��

	Invert(string, string + num - 1);
	Invert(string + num, string + length - 1);
	Invert(string, string + length - 1);
}

int main()
{
	int num = 0;
	char str[10];
	scanf("%d,%s", &num, str);
	LeftRevolve(str, num);
	printf("%s\n", str);

	return 0;
}