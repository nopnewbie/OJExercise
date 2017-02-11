/*
	PAT(A):1056. Mice and Rice (25)
	Date: 2016年2月21日 14:46:15
	Finished: 2016年2月21日 19:43:37
*/
#include<iostream>
#include<fstream>
#include<queue>
#include<algorithm>
using namespace std;

const int maxn = 1000 + 10;

struct Mice
{
	int weight, level, no;
	Mice(int w = 0, int l = 0):weight(w), level(0){}
}mice[maxn];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	queue<int> mice_no;	//编号
	int np, ng;
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; ++i) scanf("%d", &mice[i].weight);
	for(int i = 0, no; i < np; ++i)
	{
		scanf("%d", &no);
		mice_no.push(no);
		mice[i].no = i;
	}
	int now = 0;
	while( mice_no.size() > 1 )
	{
		now = mice[mice_no.front()].level;	//对本层排序
		vector<int> group;
		for(int i = 0; i < ng && !mice_no.empty() && now == mice[mice_no.front()].level; ++i)
		{
			group.push_back( mice_no.front() );
			mice_no.pop();
		}
		sort(group.begin(), group.end(), [](int a, int b)->bool
		{
			return mice[a].weight > mice[b].weight;
		});
		++mice[group[0]].level;
		mice_no.push(group[0]);
	}
	sort(mice, mice + np, [](const Mice &a, const Mice &b){ return a.level > b.level; } );
	for(int i = 0, preLv = mice[0].level , rk = 1; i < np; ++i )
	{
		if(mice[i].level == preLv) mice[i].level = rk;
		else
		{
			preLv = mice[i].level;
			rk = i + 1;
			mice[i].level = rk;
		}
	}
	sort(mice, mice + np, [](const Mice &a, const Mice &b){return a.no < b.no;});
	printf("%d", mice[0].level);
	for(int i = 1; i < np; ++i) printf(" %d", mice[i].level);
	puts("");
	return 0;
}