#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//这部分练习主要提供一种思路，并不是最好的办法

//5名运动员参加跳水比赛，有人让他们预测结果
// A：B第二，我第三
// B：我第二，E第四
// C：我第一，D第二
// D：C最后，我第三
// E：我第四，A第一
//每个选手都说对了一半，请确定比赛名次
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int d = 0;
//	int e = 0;
//
//	for (a = 1; a <= 5; a++)
//	{
//		for (b = 1; b <= 5; b++)
//		{
//			for (c = 1; c <= 5; c++)
//			{
//				for (d = 1; d <= 5; d++)
//				{
//					for (e = 1; e <= 5; e++)
//					{
//						if (((b == 2) + (a == 3) == 1) &&
//							((b == 2) + (e == 4) == 1) &&
//							((c == 1) + (d == 2) == 1) &&
//							((c == 5) + (d == 3) == 1) &&
//							((e == 4) + (a == 1) == 1))
//						{
//							if (a * b * c * d * e == 120)
//								printf("a = %d, b = %d, c = %d, d = %d, e = %d\n", a, b, c, d, e);
//						}
//					}
//				}
//			}
//		}
//	}
// 
// return 0;
//}

//已知杀人凶手是四个嫌疑犯中的其中一个
//以下为嫌疑犯的供词：
// A：不是我
// B：是C
// C：是D
// D：C在胡说
// 以上仅有一人说了假话，请确定凶手
int main()
{
	char killer;

	for (killer = 'a'; killer <= 'd'; killer++)
	{
		if ((killer != 'a') +
			(killer == 'c') +
			(killer == 'd') +
			(killer != 'd') == 3)
			printf("%c\n", killer);
	}

	return 0;
}