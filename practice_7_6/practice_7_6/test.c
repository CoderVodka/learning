#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//дһ�����������ز�����������1�ĸ���
//����һ
//int Count_1(int number)
//{
//	int count = 0;
//	int i = 0;
//
//	for (i = 0; i < 8 * sizeof(int); i++)
//	{
//		if ((number & 1) == 1)
//			count++;
//		number >>= 1;
//	}
//
//	return count;
//}

//����2
//int Count_1(int number)
//�������д�����numberΪ����ʱ���ܷ�����ȷ��ֵ����Ϊ�������ڴ����Բ�����ʽ�洢��Ӧ���������͸�Ϊ�޷�������
//int Count_1(unsigned int number)
//{
//	int sum = 0;
//	int i = 0;
//	
//	while (number)
//	{
//		//˼·�����ڷֱ�ȡ��ʮ�������ֵ�ÿһλ
//		//number / 2��Ϊ�����������һλ����
//		//��numberΪ����ʱ�������������һλΪ1��number % 2 = 1����ȡ����һλ1��
//		sum += number % 2;
//		number /= 2;
//	}
//
//	return sum;
//}

//����3
int Count_1(int number)
{
	int count = 0;

	while (number)
	{
		//��һ�����㽫number���ұߵ�1��Ϊ0
		//e.g. number = 1110
		// number - 1 = 1101
		// 1110 & 1101 = 1100
		// ���ַ������Դ���ȼ���ѭ������
		number = number & (number - 1);
		count++;
	}
	
	return count;
}

int main()
{
	int num = 0;
	scanf("%d", &num);
	printf("%d\n", Count_1(num));

	return 0;
}