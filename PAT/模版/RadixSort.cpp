/*
	Radix Sort
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;

void RadixSort(const int radix, vector<int> &A)
{//����Ԫ��ֵ����[0, radix)
	for(int i = 1; i <= radix; i *= 10)
	{//i������ʮ���Ƶĸ���λ����ֵ
		vector<vector<int>> bucket(radix);	//Ͱ
		for(int j = 0; j < A.size(); ++j)
		{//һ��Ͱ����()
			int pos = A[j] / i % 10;
			bucket[pos].push_back(A[j]);
		}
		A.clear();
		for(int j = 0; j < radix; ++j)		//һ��Ԫ���ռ�
			for(int k = 0; k < bucket[j].size(); ++k)	A.push_back(bucket[j][k]);
	}
}

int main()
{
//	freopen("F:\\input.txt", "r", stdin);
	const int RADIX = 1000 + 1;
	srand(time(NULL));
	int n = rand() ;
	vector<int> a1(n), a2(n);
	for(int i = 0; i < n; ++i)	a1[i] = a2[i] = rand() % RADIX;
	RadixSort(RADIX, a1);
	sort(a2.begin(), a2.end());
	if(a1 == a2) puts("YES");
	else puts("NO");
	return 0;
}