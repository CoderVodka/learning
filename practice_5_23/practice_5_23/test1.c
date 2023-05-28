#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}

	return 0;
}*/
//这段代码可适当修改用来清理缓冲区，视频讲解https://www.bilibili.com/video/BV1Vm4y1r7jY/?p=30

/*int main()
{
	char password[20];
	printf("请输入密码\n");
	scanf("%s", &password);
	printf("请确认密码,输入Y OR N\n");
	int check = getchar();
	if (check == 'y')
		printf("yes\n", check);
	else
		printf("no\n", check);

	return 0;
}*/
//这段代码输入密码并回车之后会直接输出no，因为键盘输入后储存在输入缓冲区中，
//getchar()从缓冲区中取得数据，而键盘输入密码时以回车（\n）结尾，scanf读取字符串到\n停止，
//此时， \n仍在输入缓冲区中，getchar()访问输入缓冲区得到\n，并赋值给check，此时check != 'y'，输出no。
//通过使用getchar()清理缓冲区可以避免这种情况的发生，示例如下：

int main()
{
	char password[20];
	printf("请输入密码\n");
	scanf("%s", &password);
	int ret = 0;
	while (ret = getchar() != '\n')      //清理缓冲区
	{
		;
	}
	printf("请确认密码,输入Y OR N\n");
	int check = getchar();
	if (check == 'Y')
		printf("yes\n");
	else
		printf("no\n");

	return 0;
}
//这段代码可以正确执行输入密码后进行确认的功能。