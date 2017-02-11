/*
	1089. Insert or Merge (25)
	temporal practice
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline int isInsert(vector<int> a,  const vector<int> &b)
{
	for(int i = 1; i <= a.size(); ++i)
	{
		sort(a.begin(), a.begin() + i);
		if(a == b) return i + 1;
	}
	return -1;
}
int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	vector<int> a(n), b(n), tmp;
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
	for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
	int len = isInsert(a, b);
	if(len > -1 && len < n)
	{
		puts("Insertion Sort");
		sort(b.begin(), b.begin() + len);
		printf("%d", b[0]);
		for(int i = 1; i < n; ++i) printf(" %d", b[i]);
		puts("");
	}
	else
	{
		puts("Merge Sort");
		bool flag = false;
		for(int i = 2, j; i <= n; i <<= 1)
		{
			tmp = a;
			for(j = 0; j + i <= n ; j += i )	sort(tmp.begin() + j, tmp.begin() + j + i);
			if(j < n) sort(tmp.begin() + j, tmp.end());
			if(flag) break;
			if(tmp == b) flag = true;
		}
		printf("%d", tmp[0]);
		for(int i = 1; i < n; ++i) printf(" %d", tmp[i]);
		puts("");
	}
	return 0;
}