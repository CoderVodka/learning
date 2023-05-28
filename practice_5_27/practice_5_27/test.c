#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//计算1!+2!+3!+...+n!

//int Fac(int n)
//{
//	int j = 0;
//	int nfac = 1;
//	for(j = 1; j <= n; j++)
//	{
//		nfac *= j;
//	}
//	return nfac;
//}
//
//int main()
//{
//	int i = 0;
//	int n = 0;
//	int sum = 0;
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//		/*int num = 1;             //注意：这里如果使用循环嵌套结构的话需要在第一个循环内部定义阶乘num，或为其赋值，
//		for (i = 1; i <= j; i++)   //保证每次循环阶乘num恢复初始值，否则阶乘num会保留上一次循环的计算结果，导致最终结果出错
//		{                          //这里更稳妥的方法是将阶乘单独写成一个函数，这样每次函数调用时会初始化阶乘nfac，从而防止计算出错
//			num *= i;
//		}*/
//		int num = Fac(i);
//		sum += num;
//	}
//	printf("%d", sum);
//
//	return 0;
//}

//代码优化：上述代码使用了两层for循环嵌套，其中每次执行阶乘运算时，都要重复上次已执行过的计算
// 例如：在计算3！时计算了1*2*3，而计算4！时要计算1*2*3*4，重复计算了1*2*3，
// 想办法利用之前的计算结果可以简化代码。

int main()
{
	int i = 0;
	int n = 0;
	int ret = 1;
	int sum = 0;
	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		ret *= i;          //4!=3!*4，以此可以优化代码
		sum += ret;
	}
	printf("%d", sum);

	return 0;
}
