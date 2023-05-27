#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



int main()
{
	char title1[8] = "Name";   //定义字符串需要用数组的形式定义 char title1 = "Name"; 是不对的
	char title2[8] = "Age";
	char title3[8] = "Gender";
	char name[8] = "Jack";
	int age = 18;
	char gender[8] = "man";

	printf("%-6s %-6s %-6s \n", title1, title2, title3);
	printf("---------------------\n");
	printf("%-6s %-6d %-6s \n",name,age,gender);
	//对齐输出，方法一
	// 每个控制字符可以写成%nC的形式，如%10d, %12f, %5c, %20s等等，
	//其对应的是不足部分左侧补空格，实现右对齐效果；若要不足部分右侧补空格，
	//只需要在宽度字符前加-符号即可，如%-12f，此时实现的是左对齐效果。

	printf("%s\t %s\t %s\t \n", title1, title2, title3);
	printf("---------------------\n");
	printf("%s\t %d\t %s\t \n", name, age, gender);
	//制表符\t输出的时候，会移动输出光标，实现对齐效果。因此可以在输出的对应位置，增加\t来实现对齐。
	//缺点：要求每行相同列输出占用空间差别不可以太大。

	return 0;

}