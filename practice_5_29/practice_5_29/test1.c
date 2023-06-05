#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


//void Swap(int x, int y)   //x,y是形式参数
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
//	printf("交换前：a=%d，b=%d\n", a, b);     //这段代码输出的a和b不发生交换，
//	Swap(a, b);      //a,b是实际参数          //当实参传递给形参时，形参是实参的一份临时拷贝，
//	printf("交换后：a=%d，b=%d\n", a, b);     // 对形参的修改不会影响实参
//
//	return 0;
//}


//将函数的参数改为指针变量可以解决上述问题
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
	printf("交换前：a=%d，b=%d\n", a, b);
	//将a,b的地址传递给函数Swap
	Swap(&a, &b);
	printf("交换后：a=%d，b=%d\n", a, b);

	return 0;
}
