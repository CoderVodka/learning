#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//喝汽水，1瓶汽水1元，2个空瓶换一瓶汽水，20元可以喝多少汽水
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