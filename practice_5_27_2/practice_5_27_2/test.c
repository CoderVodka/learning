#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//��һ�����������в���ĳ������n��������ʹ�ö��ַ�
int main()
{
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 0;
	int size = sizeof(arr) / sizeof(arr[0]);
	int left = 0;     //��߽�
	int right = size - 1; //�ұ߽�
	scanf("%d", &n);

	do
	{
		//int mid = (left + right) / 2; 
		int mid = left + (right - left) / 2;  //�����е㣬���ﲻ��������һ�еĴ��룬Ϊ�˷�ֹleft+right�����ݹ��󳬳����͵����ֵ

		/*if ((arr[mid] != n) && (left == right))    //�˴�����ѭ�����жϿ��ܳ������⣬
		{                                            // ���ƶ��±�ʱ���ܳ���left>right�������
			printf("δ�ҵ�\n");                      //����������޷�����ѭ�����Ӷ�������ѭ�������
			break;
		}
		else*/ 
		if (arr[mid] > n)         //�е�ֵ��������ֵ
		{
			right = mid - 1;      //���ұ߽������е㴦
		}
		else if (arr[mid] < n)
		{
			left = mid + 1;
		}
		else
		{
			printf("�±�Ϊ��%d", mid);
			break;
		}
	} while (left <= right);
	//while (arr[mid] != n);    //��ʹ�����ַ����ж��Ƿ����ѭ��������ͬǰ�� ��ֹ��ѭ��

	if (left > right)
	{
		printf("δ�ҵ�\n");
	}
	return 0;
}