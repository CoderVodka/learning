#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��дһ�����������ַ�������
//int getLength(char *str)
//{
//	int count = 0;
//
//	while (*str != '\0')
//	{
//		count++;
//		str++;
//	}
//
//	return count;
//}

//��дһ�����������ַ�������,����ʹ����ʱ����
int getLength(char* str)
{
	if (*str != '\0')
	{
		return 1 + getLength(str + 1);  //���ﲻʹ��++str����֤str��ֵ���ı�
	};

	return 0;
}

int main()
{
	char ch[30];
	scanf("%s", ch);
	int len = getLength(ch);
	printf("%d", len);

	return 0;
}