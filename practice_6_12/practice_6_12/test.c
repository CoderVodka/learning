#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//дһ������ReverseString(char* string)���ݹ�ʵ�������ַ������ݣ�����ʹ��C���Ժ������е��ַ�����������
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

//����˼·Ϊÿ�εݹ����Ԫ���±�+1���Ҳ�Ԫ���±�-1��
//��Ϊ���鴫�δ��ݵ�����Ԫ�صĵ�ַ����ˣ�����ʹ��*(string + x)�ҵ���x��Ԫ��
//��Ϊ�����˲�������ˣ���Ҫͨ���ݹ�ʵ�֣���ת��Ϊÿ�εݹ�ȥ���ַ�������βԪ��
void ReverseString(char* string)
{
	int lenth = GetLenth(string);
	char tmp = *string;               //����Ԫ�ظ�ֵ��tmp
	*string = *(string + lenth - 1);  //��βԪ�ظ�ֵ����Ԫ��
	*(string + lenth - 1) = '\0';     //��βԪ�ظ�ֵΪ'\0'

	if (GetLenth((string + 1)) >= 2)    //��Ԫ�ص�ַ+1�����ҽ�βԪ�ظ�Ϊ'\0'֮�󼴿�ʵ��ȥ���ַ�����βԪ�ص�Ŀ��
	{                                 
		ReverseString(string + 1);    //�˴���һ�εݹ���Ԫ��ָ�����b���ַ���Ϊ"bcde"
	}

	*(string + lenth - 1) = tmp;      //��tmp��ֵ�����һ��Ԫ��
}

int main()
{
	char ch[] = "abcdef";
	ReverseString(ch);
	printf("%s\n", ch);

	return 0;
}