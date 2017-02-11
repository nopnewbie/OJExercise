/*
	Shell Sort
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;

inline void ShellSort(vector<int> &A)
{
	vector<int> increment;	//��������
	for(int i = A.size() / 2; i > 1; i >>= 1)	increment.push_back(i - 1);	//����Hibbard��������
	increment.push_back(1);	//���һ���������б�����1
	for(int i  = 0; i < increment.size(); ++i)
	{
		int inc = increment[i];	//ѡȡÿ�ε�����
		for(int j = inc; j < A.size(); ++j)
		{//��incΪ��������һ�ֲ�������
			int k, tmp = A[j];
			for(k = j; k >= inc && tmp < A[k - inc]; k -= inc)		
			{
				A[k] = A[k - inc];
			}
			A[k] = tmp;
		}
	}
}

int main()
{
	srand(time(NULL));
	int n = rand();
	vector<int> a1(n), a2(n);
	printf("%d\n", n);
	for(int i = 0; i < n; ++i) a1[i] = a2[i] = rand();
	sort(a1.begin(), a1.end());
	ShellSort(a2);
	if(a1 == a2) puts("Yes");
	else puts("No");

	return 0;
}