#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//�ȴ�С
Max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

//int main() {
//
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	int r = Max(a, b);
//	printf("%d", r);
// 
//  return 0;
//}


//x<0,y=1;x=0,y=0��x>0,y=-1
int main()
{
	//����
	int x = 0;
	int y = 0;
	scanf("%d", &x);

	//����
	if (x > 0)
		y = -1;
	else if (x == 0)
		y = 0;
	else
		y = 1;

	//���
	printf("%d", y);

	return 0;
}