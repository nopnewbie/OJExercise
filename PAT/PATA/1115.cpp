/*
	PAT(A):1115. Counting Nodes in a BST (30)
	Date:2016年3月15日 09:57:27
	Finished: 2016年3月15日 10:22:14
*/
#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

struct Node
{
	int data, lch, rch;
	Node(int d, int l = -1, int r = -1):data(d), lch(l), rch(r){}
};
vector<Node> tree;
int n;

void insert(int rt, int key)
{
	if(tree.empty())tree.push_back(Node(key));
	else if(key <= tree[rt].data)
	{
		if(tree[rt].lch < 0) 
		{
			tree.push_back(Node(key));
			tree[rt].lch = tree.size() - 1;
		}
		else insert(tree[rt].lch, key);
	}
	else 
	{
		if(tree[rt].rch < 0)
		{
			tree.push_back(Node(key));
			tree[rt].rch = tree.size() - 1;
		}
		else insert(tree[rt].rch, key);
	}
}

vector<int> layer;
void bfs(int beg)
{
	typedef pair<int, int> pii;
	queue<pii> q;
	q.push(make_pair(beg, 0));
	while(!q.empty())
	{
		int u = q.front().first;
		int lv = q.front().second;
		layer.push_back(lv);
		q.pop();
		if(tree[u].lch >= 0) q.push(make_pair(tree[u].lch, lv + 1));
		if(tree[u].rch >= 0) q.push(make_pair(tree[u].rch, lv + 1));
	}
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	scanf("%d", &n);
	for(int i = 0, k; i < n; ++i)
	{
		scanf("%d", &k);
		insert(0, k);
	}
	bfs(0);
	int n1 = count(layer.begin(), layer.end(), layer.back());
	int n2 = count(layer.begin(), layer.end(), layer.back() - 1);
	printf("%d + %d = %d\n", n1, n2, n1 + n2);
	return 0;
}