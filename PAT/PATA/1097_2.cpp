/*
	PAT(A):1097. Deduplication on a Linked List (25)
	Date: 2016年2月22日 10:28:26
	Finished: 2016年2月22日 10:27:06
	改用set来保存key的绝对值,以次删除重复元素
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<fstream>
using namespace std;

const int maxn = 100000 + 10;

struct Node
{
	int addr, key, next;
}node[maxn];

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int beg, n;
	scanf("%d %d", &beg, &n);
	for(int i = 0, ad, key, nxt; i < n; ++i)
	{
		scanf("%d %d %d", &ad, &key, &nxt);
		node[ad].addr = ad;
		node[ad].key = key;
		node[ad].next = nxt;
	}
	vector<Node> lefted_list, rm_list;
	set<int> keyset;
	for(int now = beg, no = 0; now > -1; now = node[now].next)	
	{
		int k = abs(node[now].key);
		if(keyset.find(k) != keyset.end())
		{
			rm_list.push_back(node[now]);
		}
		else
		{
			keyset.insert(k);
			lefted_list.push_back(node[now]);
		}
	}
	if(!lefted_list.empty())
	{
		printf("%05d %d ", lefted_list[0].addr, lefted_list[0].key);
		if(1 == lefted_list.size()) puts("-1");
		else
		{
			printf("%05d\n", lefted_list[1].addr);
			for(auto i = 1; i < lefted_list.size() - 1; ++i) 
				printf("%05d %d %05d\n",lefted_list[i].addr, lefted_list[i].key, lefted_list[i + 1].addr);
			printf("%05d %d -1\n",lefted_list.back().addr, lefted_list.back().key);
		}
	}
	if(!rm_list.empty())
	{
		printf("%05d %d ", rm_list[0].addr, rm_list[0].key);
		if(1 == rm_list.size()) puts("-1");
		else
		{
			printf("%05d\n", rm_list[1].addr);
			for(auto i = 1; i < rm_list.size() - 1; ++i) 
				printf("%05d %d %05d\n",rm_list[i].addr, rm_list[i].key, rm_list[i + 1].addr);
			printf("%05d %d -1\n",rm_list.back().addr, rm_list.back().key);
		}
	}
	return 0;
}