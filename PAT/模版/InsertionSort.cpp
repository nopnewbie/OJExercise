/*
	Insertion Sort
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<ctime>
using namespace std;

void InsertionSort(vector<int> &A)
{
	for(int i = 1; i < A.size(); ++i)
	{
		int j, tmp = A[i];
		for(j = i; j > 0 && tmp < A[j - 1]; --j) A[j] = A[j - 1];
		A[j] = tmp;
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	srand(time(NULL));
	int n = rand();
	vector<int> a1(n), a2(n);
	for(int i = 0; i < n; ++i) a1[i] = a2[i] = rand();
	sort(a1.begin(), a1.end());
	InsertionSort(a2);
	if(a1 == a2) puts("Yes");
	else puts("No");
	return 0;
}