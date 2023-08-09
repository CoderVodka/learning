#define  _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// ���Ͼ���
// ��һ�����־��󣬾���ÿ�д����ҵ��������ϵ��µ�����
// ���дһ�����򣬲��Ҿ������Ƿ����ĳ������
// Ҫ��ʱ�临�Ӷ�С��O(N)�������ܱ�������
// ���������־�������º����Ͻ�����λ�õ�ֵ��Ϊ���⣬
// ����Ϊ�������ֵ��������Сֵ������Ϊ�������ֵ��������Сֵ
// ͨ����������ֵ�Ƚϣ����Կ����ų�һ��Ԫ��
//int SearchYoungTableau(const void* arr, int row, int col, int num)
//{
//
//	const int* pLL = (int*)arr + (col * (row - 1));
//	const int* pUR = (int*)arr + col - 1;
//	int flag = 0;
//
//	while ((pLL >= (int*)arr) && (pLL <= (int*)arr + col * row - 1)  //��������߽����ѭ��
//		&& (pUR >= (int*)arr) && (pUR <= (int*)arr + col * row - 1)
//		&& ((pLL - (int*)arr) / col >= (pUR - (int*)arr) / col)  //pLL��pUR�Ϸ�����
//		&& ((pUR - (int*)arr) % col >= (pLL - (int*)arr) % col)) //pUR��pLL������
//	{
//		//�ж����½���Ŀ�����ֵĴ�С
//		if (*pLL > num)       //���½����ִ������ƶ�һ��
//			pLL -= col;
//		else if (*pLL < num)  //���½�����С�������ƶ�һ��
//			pLL++;
//		else
//		{
//			flag = 1;
//			break;
//		}
//
//		//�ж����Ͻ���Ŀ�����ִ�С
//		if (*pUR > num)       //���Ͻ����ִ������ƶ�һ��
//			pUR--;
//		else if (*pUR < num)  //���Ͻ�����С�������ƶ�һ��
//			pUR += col;
//		else
//		{
//			flag = 1;
//			break;
//		}
//	}
//
//	return flag;
//}

//��
//ע�⣺�������Һʹ�һ���ҵ��ٶ���һ����
int SearchYoungTableau(const void* arr, int row, int col, int num)
{
	const int* pUR = (int*)arr + col - 1;
	int flag = 0;

	while ((pUR >= (int*)arr) && (pUR <= (int*)arr + col * row - 1)) 
	{
		//�ж����Ͻ���Ŀ�����ִ�С
		if (*pUR > num)       //���Ͻ����ִ������ƶ�һ��
		{
			if ((pUR - arr) % col)
				pUR--;
			else              //�����������һ��ʱ����*pUR > num��˵��û�ҵ�������ѭ��
				break;
		}
		else if (*pUR < num)  //���Ͻ�����С�������ƶ�һ��
			pUR += col;
		else
		{
			flag = 1;
			break;
		}
	}

	return flag;
}

//���ڷ���ֵ�����⣬����뷵���ҵ����ֵ����꣬����ʹ���������ַ�����
// 1.����һ���ṹ�壬���������x��yֵ
// 2.������row��col�ĳ�ָ�룬�����ҵ�Ŀ��ʱ����ĳ�Ŀ��λ��x��yֵ
// 3.����(pUR - arr)��ʾ������ĵڼ�������֮�����ͨ������õ�����ֵ
// 4.����ָ��pUR��֮��Ҳ����ͨ������õ�����

int main()
{
	int arr[4][3] = { 1,3,5,2,4,6,8,10,11,9,13,16 };
	int num = 0;
	scanf("%d", &num);
	int ret = SearchYoungTableau(arr, 4, 3, num);
	if (ret)
		printf("�ҵ���\n");
	else
		printf("û�ҵ�\n");

	return 0;
}