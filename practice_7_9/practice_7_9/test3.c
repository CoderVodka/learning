#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ��һƿ��ˮ��20Ԫ���Ժȶ�����ˮ
int main()
{
	float money = 0;
	float price = 0;
	scanf("%f %f", &money, &price);
	int	firstCola = money / price;
	int empty = firstCola;
	//int changeCola = 0;
	int totalCola = firstCola;

	while (empty >= 2)
	{
		//changeCola = empty / 2;
		//totalCola += changeCola;
		totalCola += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d\n", totalCola);

	return 0;
}