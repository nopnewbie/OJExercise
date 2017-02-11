/*
	PAT(A):1075. PAT Judge (25)
	Date: 2016年2月15日 20:05:05
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

const int maxn = 10000 + 10;

struct Record
{
	int id, scores[5], total, pass_no;
	bool isValid;
	Record():isValid(false), total(0), pass_no(0){ scores[0] = scores[1] = scores[2] = scores[3] = scores[4] = -2; }
	bool operator < (const Record &rhs) const
	{
		if(total != rhs.total) return total > rhs.total;
		else if(pass_no != rhs.pass_no) return pass_no > rhs.pass_no;
		else return id < rhs.id;
	}
}Rank[maxn];
int full[5];

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	for(int i = 0; i < k; ++i) scanf("%d", full + i);
	for(int i = 0, uid, pid, psc; i < m; ++i)
	{
		scanf("%d%d%d", &uid, &pid, &psc);
		Rank[uid].id = uid;
		if(psc >= 0) Rank[uid].isValid = true;
		if(psc > Rank[uid].scores[pid - 1]) 
		{
			Rank[uid].scores[pid - 1] = psc < 0 ? 0 : psc;
			if(psc == full[pid - 1]) ++Rank[uid].pass_no;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(Rank[i].isValid)
			for(int j = 0; j < k; ++j)
				Rank[i].total += Rank[i].scores[j] < 0 ? 0 : Rank[i].scores[j];
		else Rank[i].total = -1;
	sort(Rank + 1, Rank + n + 1);
	printf("1 %05d %d", Rank[1].id, Rank[1].total);
	for(int i = 0; i < k; ++i) 
		if(Rank[1].scores[i] < 0) printf(" -");
		else printf(" %d", Rank[1].scores[i]);
	puts("");
	for(int i = 2, pre_rank = 1; i <= n; ++i)
	{
		if(Rank[i].isValid)
		{
			printf("%d %05d %d", pre_rank = Rank[i].total == Rank[i - 1].total ? pre_rank : i ,Rank[i].id, Rank[i].total);
			for(int j = 0; j < k; ++j) 
			if(Rank[i].scores[j] < 0) printf(" -");
			else printf(" %d", Rank[i].scores[j]);
			puts("");
		}
	}
	return 0;
}