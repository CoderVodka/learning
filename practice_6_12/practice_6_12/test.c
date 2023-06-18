#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//写一个函数ReverseString(char* string)，递归实现逆序字符串内容，不得使用C语言函数库中的字符串操作函数
int GetLenth(char* string)
{
	int count = 0;

	while (*string != '\0')
	{
		count++;
		string++;
	}

	return count;
}

//初步思路为每次递归左侧元素下标+1，右侧元素下标-1。
//因为数组传参传递的是首元素的地址，因此，可以使用*(string + x)找到第x个元素
//因为限制了参数，因此，想要通过递归实现，就转变为每次递归去掉字符串的首尾元素
void ReverseString(char* string)
{
	int lenth = GetLenth(string);
	char tmp = *string;               //将首元素赋值给tmp
	*string = *(string + lenth - 1);  //将尾元素赋值给首元素
	*(string + lenth - 1) = '\0';     //将尾元素赋值为'\0'

	if (GetLenth((string + 1)) >= 2)    //首元素地址+1，并且将尾元素改为'\0'之后即可实现去掉字符串首尾元素的目的
	{                                 
		ReverseString(string + 1);    //此处第一次递归首元素指向的是b，字符串为"bcde"
	}

	*(string + lenth - 1) = tmp;      //将tmp赋值给最后一个元素
}

int main()
{
	char ch[] = "abcdef";
	ReverseString(ch);
	printf("%s\n", ch);

	return 0;
}