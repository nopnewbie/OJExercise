/*
	PAT(B):1025. 反转链表 (25)
	Date: 2016年1月29日 18:28:16
*/
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
#include<stack>
#include<utility>
using namespace std;
const int maxn = 10e5 + 10;
//struct node
//{
//int data, next;
//node():data(0), next(-1){}
//}link[maxn];
int s_addr, n, k;
int addr[maxn], node[maxn][2];
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
//	vector<node> link(maxn);
//	vector<int> addr;
	cin >> s_addr >> n >> k;
	for(; n; --n)
	{
		int p;
		cin >> p;
//		cin >> link[p].data >> link[p].next;	//data is Data, next is pNext
		cin >> node[p][0] >> node[p][1];
	}
	int size_addr = 0;
	for(int i = s_addr; -1 != i; i = node[i][1]  )	addr[size_addr++] = i;
	for(int i = 0; i + k <= size_addr; i += k ) reverse(addr + i, addr + i + k);
	for(int i = 0; i < size_addr - 1; ++i ) printf("%05d %d %05d\n", addr[i], node[addr[i]][0], addr[i+1]);
	printf("%05d %d -1\n", addr[size_addr - 1], node[addr[size_addr - 1]][0]);
	return 0;
}