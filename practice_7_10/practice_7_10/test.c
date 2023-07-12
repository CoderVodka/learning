#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//����һ�仰�ĵ��ʣ���㲻���á�e.g. I like Beijing. -> Beijing. like I
//����һ�������ʰ��մӺ���ǰ��˳�򴢴���һ���µ�������
//void InversionWords(char* sentence)
//{
//	char copy[100] = { 0 };
//	int left = strlen(sentence) - 1;  //leftָ�����һ�����ʵ�β��ĸ
//	int i = 0;
//	int j = 0;
//	int n = 0;
//
//	for (i = left; i >= 0; i--)
//	{
//		if (sentence[i] == ' ')
//		{
//			for (n = 0; n < left - i; n++) //��ʱiָ�򵥴���ߵĿո�left - iΪ���ʵĳ���
//			{
//				copy[j++] = sentence[i + 1 + n]; //i + 1��ָ�򵥴�����ĸ
//			}
//
//			copy[j++] = ' ';
//			left = i - 1;             //��leftָ����һ�����ʵ�β��ĸ
//		}
//
//		if (i == 0)   //�������ߵĵ��ʸ��Ƶ���������
//		{
//			for (n = 0; n <= left; n++)
//			{
//				copy[j++] = sentence[n];
//			}
//
//			copy[j] = '\0';
//		}
//	}
//
//	strcpy(sentence, copy);
//}

//���������Ƚ������ַ��������ٷֱ�����ÿ����ĸ
//��δ�������Ҳ�������
//void InversionChar(char* ch)
//{
//	int left = 0;
//	int right = strlen(ch) - 1;
//
//	while (left < right)
//	{
//		int tmp = ch[left];
//		ch[left] = ch[right];
//		ch[right] = tmp;
//		left++;
//		right--;
//	}
//}
//
//void InversionWords(char* sentence)
//{
//	int i = 0;
//	int firstLetter = 0;
//	InversionChar(sentence);
//
//	for (i = 0; i < strlen(sentence); i++)
//	{
//		if (sentence[i] == ' ')
//		{
//			sentence[i] = '\0';
//			InversionChar(sentence + firstLetter);
//			sentence[i] = ' ';
//			firstLetter = i + 1;
//		}
//	}
//}

//�������Ż���
//ʹ��ָ��ʹ�������ַ����ĺ���InversionChar�����Ը���
void InversionChar(char* left, char* right)
{
	while (left < right)
	{
		char tmp = *left;
		*left = *right;
		*right = tmp;
		left++;
		right--;
	}
}	

void InversionWords(char* sentence)
{
	char* left = sentence;
	char* right = sentence + strlen(sentence) - 1;
	InversionChar(left, right);
	char* start = sentence;
	char* end = start;
	
	while (*start)
	{
		while ((*end != ' ') && (*end != '\0'))
		{
			end++;
		}

		InversionChar(start, end - 1);

		if (*end == ' ')
		{
			end++;
		}

		start = end;
	}
}

int main()
{
	char ch[] = "I like Beijing.";
	InversionWords(ch);
	printf("%s\n", ch);

	return 0;
}