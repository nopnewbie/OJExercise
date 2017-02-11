/*
	PAT(A):1089. Insert or Merge (25)
	Date: 2016年2月25日 15:14:48
	Finished:
	双指针
*/
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int a[2][maxn];

int isInsertion(int n)
{//if yes return the next length, else return -1
	int i = 1;
	while(i < n && a[1][i - 1] <= a[1][i]) ++i;	//题目并未说明元素是不重复的,所以要用<=
	int len = i;
	while(i < n && a[1][i] == a[0][i]) ++i;
	return i == n ? len : -1;
}

inline int findlen(int n)
{
	int i, j;
	
	for(i = 2; i <= n; i <<= 1)
	{
		for(j  = i; j < n; j += i << 1) if(a[1][j - 1] > a[1][j]) return i << 1;
		//bool flag = true;
		//for(j = 0; j + i <= n; j += i) sort(a[0] + j, a[0] + j + i);
		//if(j < n) sort(a[0] + j, a[0] + n);
		//for(j = 0; j < n; ++j)	if(a[0][j] != a[1][j]) 
		//{	flag = false; break; 	}
		//if(flag) return i << 1;
	}
	return -1;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 2; ++i) for(int j = 0; j < n; ++j) scanf("%d", a[i] + j);
	int len = isInsertion(n);
	if(len >= 0)
	{
		puts("Insertion Sort");
		sort(a[1], a[1] + (len + 1 > n ? n : (len + 1) ) );
		printf("%d", a[1][0]);
		for(int i = 1; i < n; ++i) printf(" %d", a[1][i]);
	}
	else 
	{
		puts("Merge Sort");
		len = findlen(n) ;
		len = len > n ? n : len;
		if(len < 0) while(1);
		int i ;
		for(i = 0; i + len <= n; i += len ) sort(a[1] + i, a[1] + i + len );
		if(i < n) sort(a[1] + i, a[1] + n);
		printf("%d", a[1][0]);
		for(int i = 1; i < n; ++i) printf(" %d", a[1][i]);
	}
	return 0;
}