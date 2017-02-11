/*
	PAT(A):1078. Hashing (25)
	Date: 2016年2月28日 11:38:13
	Finished:2016年2月28日 22:12:43
*/
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

const int maxn = 1e5;
bool p[maxn];
bool table[maxn];

inline void init()
{
	p[0] = p[1] = true;
	int x = sqrt((float)maxn) + 1;
	for(int i = 2; i <= x; ++i)
		for(int j = i * i; j < maxn; j += i) p[j] = true;
}

inline int Hash(int key, int size)
{
	vector<bool> flag(size, false);
	int idx = key % size, i = 1;
	int k = idx;
	while(true)
	{
		if(!table[idx]) return idx;
		else if(!flag[idx]) 
		{
			flag[idx] = true;
			idx = (i * i + k) % size; 
			++i;
		}
		else return -1;
	}
}

inline bool isPrime(int x)
{
	if(1 == x || !x) return false;
	if(2 == x) return true;
	int tmp = sqrt((float)x) + 1;
	for(int i = 2; i <= tmp; ++i) if(!(x % i)) return false;
	return true;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
//	init();	//初始化素数表
	int m, n, t;
	scanf("%d%d", &m, &n);
	vector<int> num(m);
	for(int i = 0; i < n; ++i) scanf("%d", &num[i]);
	t = m;
//	while(p[t]) ++t;	//得到比m大的最小素数
	while(!isPrime(t)) ++t;
	for(int i = 0; i < n; ++i)
	{ 
		if(i) putchar(' ');
		int idx = Hash(num[i], t);
		if(idx < 0) putchar('-');
		else
		{
			table[idx] = true;
			printf("%d", idx);
		}
	}
	return 0;
}