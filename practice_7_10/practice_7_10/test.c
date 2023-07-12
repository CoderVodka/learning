#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//倒置一句话的单词，标点不倒置。e.g. I like Beijing. -> Beijing. like I
//方法一：将单词按照从后向前的顺序储存在一个新的数组中
//void InversionWords(char* sentence)
//{
//	char copy[100] = { 0 };
//	int left = strlen(sentence) - 1;  //left指向最后一个单词的尾字母
//	int i = 0;
//	int j = 0;
//	int n = 0;
//
//	for (i = left; i >= 0; i--)
//	{
//		if (sentence[i] == ' ')
//		{
//			for (n = 0; n < left - i; n++) //此时i指向单词左边的空格，left - i为单词的长度
//			{
//				copy[j++] = sentence[i + 1 + n]; //i + 1即指向单词首字母
//			}
//
//			copy[j++] = ' ';
//			left = i - 1;             //令left指向下一个单词的尾字母
//		}
//
//		if (i == 0)   //最后将最左边的单词复制到新数组中
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

//方法二：先将整个字符串逆序，再分别逆序每个字母
//这段代码更简洁也更易理解
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

//方法二优化：
//使用指针使得逆序字符串的函数InversionChar复用性更好
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