#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����һ���޷�����������˳���ӡÿһλ
//�ݹ�ʵ��
void print(unsigned int num)
{
	if (num > 9)			//��numΪ��λ������ʱ��ִ�и����
	{
		print(num / 10);	//ȥ�����һλ����
	}
	
	printf("%d ", num % 10);
}

int main()
{
	int number = 0;
	scanf("%d", &number);
	print(number);
	return 0;
}