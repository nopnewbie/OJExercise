/*
	PAT(A):1043. Is It a Binary Search Tree (25)
	Date: 2016年3月2日 10:07:13
	Finished: 2016年3月2日 10:58:50
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Node
{
	int data, lc, rc;
	Node(int d = 0, int l = -1, int r = -1):data(d), lc(l), rc(r){}
};
vector<Node> bst;
int n;
vector<int> preSeq, preMirSeq, pstSeq, pstMirSeq;

void insert(int Root, int key)
{
	if(bst.empty() )	bst.push_back(Node(key));
	else if(key < bst[Root].data) 
	{
		if(bst[Root].lc > -1)	insert(bst[Root].lc, key);
		else 
		{
			bst.push_back(Node(key));
			bst[Root].lc = bst.size() - 1;
		}
	}
	else
	{
		if(bst[Root].rc > -1)	insert(bst[Root].rc, key);
		else 
		{
			bst.push_back(Node(key));
			bst[Root].rc = bst.size() - 1;
		}
	}
}

void preOrd(int s)
{
	if(-1 == s) return;
	preSeq.push_back(bst[s].data);
	if(bst[s].lc > -1)	preOrd(bst[s].lc);
	if(bst[s].rc > -1)	preOrd(bst[s].rc);
}

void preMir(int s)
{
	if(-1 == s) return;
	preMirSeq.push_back(bst[s].data);
	if(bst[s].rc > -1)	preMir(bst[s].rc);
	if(bst[s].lc > -1)	preMir(bst[s].lc);
}

void postOrd(int s)
{
	if(-1 == s) return;
	if(bst[s].lc > -1)	postOrd(bst[s].lc);
	if(bst[s].rc > -1)	postOrd(bst[s].rc);
	pstSeq.push_back(bst[s].data);
}

void postMir(int s)
{
	if(-1 == s) return;
	if(bst[s].rc > -1)	postMir(bst[s].rc);
	if(bst[s].lc > -1)	postMir(bst[s].lc);
	pstMirSeq.push_back(bst[s].data);
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	while(~scanf("%d", &n))
	{
		preSeq.clear();
		preMirSeq.clear();
		pstSeq.clear();
		pstMirSeq.clear();
		bst.clear();
		vector<int> num(n);
		for(int i = 0; i < n; ++i)
		{
			scanf("%d", &num[i]);
			insert(0, num[i]);
		}
		preOrd(0);
		preMir(0);
		postOrd(0);
		postMir(0);
		if(preSeq != num && preMirSeq != num) puts("NO");
		else 
		{
			puts("YES");
			if(preSeq == num)
			{
				printf("%d", pstSeq[0]);
				for(unsigned i = 1; i < pstSeq.size(); ++i) printf(" %d", pstSeq[i]);
				puts("");
			}
			else
			{
				printf("%d", pstMirSeq[0]);
				for(unsigned i = 1; i < pstSeq.size(); ++i) printf(" %d", pstMirSeq[i]);
				puts("");
			}
		}
	}
	return 0;
}