/*
	PAT(A):1062. Talent and Virtue (25)
	Date: 2016年2月15日 09:47:42
	用cin,cout会超时
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

struct Stu
{
	unsigned id;
	unsigned v, t;
	Stu(){}
	Stu(unsigned _id, unsigned _v, unsigned _t):id(_id), v(_v), t(_t){}
	bool operator < (const Stu &rhs) const
	{
		if( (v + t) != (rhs.v + rhs.t)) return (v + t) > (rhs.v + rhs.t);
		else if(v != rhs.v) return v > rhs.v;
		else return id < rhs.id;
	}
};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	unsigned n, L, H, m;
	vector<vector<Stu>> stu(4);
	for(scanf("%u%u%u", &n, &L, &H); n; --n)
	{
		unsigned id, v, t;
		scanf("%u%u%u", &id, &v, &t);
		if(v < L || t < L) continue;	//单科不达线的先刷掉
		else if(v >= H && t >= H) stu[0].push_back(Stu(id, v, t));
		else if(t < H && v >= H)	stu[1].push_back(Stu(id, v, t));
		else if(v < H && v >= t) stu[2].push_back(Stu(id, v, t));
		else if(v < t)	stu[3].push_back(Stu(id, v, t));
	}
	unsigned total = 0;
	for(int i = 0; i < 4; ++i) 
		if(!stu[i].empty()) {total += stu[i].size(); sort(stu[i].begin(), stu[i].end()); }
	printf("%u\n", total);
	for(int i = 0; i < 4; ++i)
	{
		if(stu[i].empty()) continue;
		for(auto j = 0; j < stu[i].size(); ++j)
			printf("%08u %u %u\n", stu[i][j].id, stu[i][j].v, stu[i][j].t);
	}
	return 0;
}