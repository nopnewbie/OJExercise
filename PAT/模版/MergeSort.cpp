/*
	Merge Sort
	Date: 2016年2月27日 10:10:51
	迭代版
*/
#include<iostream>
#include<cassert>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;

void Merge(int *A, int *tmp, int L, int R, int Rend)
{
	int Lend = R;
	while(L < Lend && R < Rend)
	{
		if(A[L] < A[R]) *tmp++ = A[L++];
		else *tmp++ = A[R++];
	}
	while(L < Lend) *tmp++ = A[L++];
	while(R < Rend) *tmp++ = A[R++];
}

void Merge_pass(int *A, int *tmp, int n, int len)
{
	int i = 0;
	for(; i + 2 * len <= n; i += len<<1) Merge(A, tmp, i, i + len, i + (len << 1));
	if(i + len < n) Merge(A, tmp, i, i + len, n);	//剩最后两个归并段,且最后一个归并段长度小于len
	else while(i < n) { tmp[i] = A[i]; ++i;}
}

void MergeSort(int *A, int n)
{
	int *tmp = new int[n];
	assert(tmp != NULL);
	int len = 2;
	while(len < n)
	{
		Merge_pass(A, tmp, n, len);
		len <<= 1;
		Merge_pass(tmp, A, n, len);
		len <<= 1;
	}
}

int main()
{
	srand(time(NULL));
	unsigned size  = rand() % 1000;
	int *a = new int[size], *b = new int[size];
	for(unsigned i = 0; i < size; ++i) a[i] = b[i] = rand() % 1000;
	MergeSort(a, size);
	sort(b, b + size);
	for(unsigned i = 0; i < size; ++i) if(a[i] != b[i]) printf("differnt at %d\n", i);
	return 0;
}