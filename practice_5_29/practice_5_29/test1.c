#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//void Swap(int x, int y)   //x,y����ʽ����
//{
//	int z;
//	z = x;
//	x = y;
//	y = z;
//}
//
//int main()
//{
//	int a = 0;              
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("����ǰ��a=%d��b=%d\n", a, b);     //��δ��������a��b������������
//	Swap(a, b);      //a,b��ʵ�ʲ���          //��ʵ�δ��ݸ��β�ʱ���β���ʵ�ε�һ����ʱ������
//	printf("������a=%d��b=%d\n", a, b);     // ���βε��޸Ĳ���Ӱ��ʵ��
//
//	return 0;
//}


//�������Ĳ�����Ϊָ��������Խ����������
void Swap(int *px, int *py)
{
	int z = *px;
	*px = *py;
	*py = z;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("����ǰ��a=%d��b=%d\n", a, b);
	//��a,b�ĵ�ַ���ݸ�����Swap
	Swap(&a, &b);
	printf("������a=%d��b=%d\n", a, b);

	return 0;
}
