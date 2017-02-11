/*
	PAT(A):1064. Complete Binary Search Tree (30)
	Date: 2016年3月2日 11:11:45
	Finished: 2016年3月2日 11:47:36
	Note: 存储CBT的数组就是层序
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 1000 + 10;
int node[maxn], num[maxn];
int n;

void myFill( int s, int &pos )
{
	if(s >= n) return;
	else if(s < n && 2 * s + 1 >= n) node[s] = num[pos++];
	else 
	{
		int lc = (s << 1) + 1, rc = (s << 1) + 2;
		if(lc < n) myFill(lc, pos);
		node[s] = num[pos++];
		if(rc < n) myFill(rc, pos);
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
	sort(num, num + n);
	int pos = 0;
	myFill(0, pos);
	printf("%d", node[0]);
	for(int i = 1; i < n; ++i) printf(" %d", node[i]);
	return 0;
}