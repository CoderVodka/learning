#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//����������������������ʱ����
//^����λ����������������λ��ͬΪ0������Ϊ1��
//a ^ a = 0��a ^ 0 = a��������������ʹ�ý�����
int main()
{
	int a = 5;
	int b = 3;
	a = a ^ b;
	b = a ^ b; //��ʱb = a(ԭ����a����5) ^ b ^ b, ��b ^ b = 0��5 ^ 0 = 5����ˣ�b = 5
	a = a ^ b; //��ʱa = a(ԭ����a����5) ^ b ^ a(ԭ����a����5)��ͬ�Ͽɵã�a = 3
	printf("%d %d", a, b);

	return 0;
}