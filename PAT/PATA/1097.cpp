/*
	PAT(A):1097. Deduplication on a Linked List (25)
	Date: 2016年2月22日 09:29:53
	Finished: 2016年2月22日 10:27:06
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<fstream>
using namespace std;

const int maxn = 100000 + 10;

struct Node
{
	int addr, key, next, no;
}node[maxn];

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int beg, n;
	cin >> beg >> n;
	for(int i = 0, ad, key, nxt; i < n; ++i)
	{
		cin >> ad >> key >> nxt;
		node[ad].addr = ad;
		node[ad].key = key;
		node[ad].next = nxt;
	}
	vector<Node> original_list, lefted_list, rm_list;
	for(int now = beg, no = 0; now > -1; now = node[now].next) 
	{
		node[now].no = ++no;	//给节点编号
		original_list.push_back(node[now]);
	}
	if(original_list.empty()) puts("original list is empty!!");
	else
	{
		sort(original_list.begin(), original_list.end(), [](const Node &a, const Node &b)->bool
		{//按key绝对值排序,处理重复节点(用set来保存key的绝对值, 则不必用这种方法排序)
			if(abs(a.key) != abs(b.key)) return abs(a.key) < abs(b.key);
			else	return a.no < b.no;
		});
		lefted_list.push_back(original_list[0]);
		for(int i = 1, preK = abs(original_list[0].key); i < original_list.size(); ++i)
		{
			if(abs( original_list[i].key) == preK ) rm_list.push_back(original_list[i]);
			else
			{
				lefted_list.push_back(original_list[i]);
				preK = abs(original_list[i].key);
			}
		}
		if(!lefted_list.empty())
		{
			sort(lefted_list.begin(), lefted_list.end(), [](const Node &a, const Node &b)->bool{return a.no < b.no;});
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
			sort(rm_list.begin(), rm_list.end(), [](const Node &a, const Node &b)->bool{return a.no < b.no;});
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
	}
	return 0;
}