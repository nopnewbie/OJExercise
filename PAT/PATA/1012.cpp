/*
	1012. The Best Rank (25)
	ps: vs2013 support only!
	注意深坑: 排序请务必考虑并列的处理
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<map>
#include<vector>
#include<fstream>

#define cin fin

using namespace std;

int N, M;
const int maxn = 2000 + 5;
struct student
{
	string ID;
	int C, M, E, A;
	int ra, rc, rm, re;
	student()
	{
		C = M = E = A = -1;
	}
	student(string id, int c, int m, int e) : ID(id), C(c), M(m), E(e), A((c+m+e)/3)
	{}
};
vector<student> vStu;
map<string, pair<int, char> > stuRank;
int cp[maxn], ma[maxn], en[maxn], an[maxn];

bool cmp1(const int &i, const int &j){ return vStu[i].C > vStu[j].C; }
bool cmp2(const int &i, const int &j){ return vStu[i].M > vStu[j].M; }
bool cmp3(const int &i, const int &j){ return vStu[i].E > vStu[j].E; }
bool cmp4(const int &i, const int &j){ return vStu[i].A > vStu[j].A; }

int main()
{
	ifstream fin("F:\\input.txt");
	string id;
	int c, m, e;
	for (int i = 0; i < maxn; ++i) an[i] = cp[i] = ma[i] = en[i] = i ;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> id >> c >> m >> e;
		vStu.push_back(student(id, c, m, e));
	}
	sort(cp, cp + vStu.size(), cmp1);
	sort(ma, ma + vStu.size(), cmp2);
	sort(en, en + vStu.size(), cmp3);
	sort(an, an + vStu.size(), cmp4);
	
	vStu[cp[0]].rc = vStu[ma[0]].rm = vStu[en[0]].re = vStu[an[0]].ra = 1 ;	//处理第一组情况
	for (int i = 1; i < vStu.size(); ++i)
	{//注意并列的处理,如1 2 2 4 第四个人不是第三名
		if( vStu[cp[i-1]].C == vStu[cp[i]].C ) 	vStu[cp[i]].rc = vStu[cp[i-1]].rc ;
		else	vStu[cp[i]].rc = i + 1;
		
		if( vStu[ma[i-1]].M == vStu[ma[i]].M )	vStu[ma[i]].rm = vStu[ma[i-1]].rm ;
		else	vStu[ma[i]].rm = i + 1 ;
		
		if( vStu[en[i-1]].E == vStu[en[i]].E )	vStu[en[i]].re = vStu[en[i-1]].re ;
		else	vStu[en[i]].re = i + 1 ;
		
		if( vStu[an[i-1]].A == vStu[an[i]].A )	vStu[an[i]].ra = vStu[an[i-1]].ra ;
		else	vStu[an[i]].ra = i + 1 ;
	}
	for (auto &x : vStu)
	{
		string s;
		if (x.ra <= x.rc && x.ra <= x.rm && x.ra <= x.re) stuRank[x.ID] = { x.ra, 'A' };
		else if (x.rc <= x.ra && x.rc <= x.rm && x.rc <= x.re) stuRank[x.ID] = { x.rc, 'C' };
		else if (x.rm <= x.ra && x.rm <= x.rc && x.rm <= x.re) stuRank[x.ID] = { x.rm, 'M' };
		else stuRank[x.ID] = { x.re, 'E' };
	}
	for (int i = 0; i < M; ++i)
	{
		cin >> id;
		auto x = stuRank.find(id);
		if (x != stuRank.end()) 
			cout << stuRank[id].first  << ' ' << stuRank[id].second << endl;
		else cout << "N/A\n";
	}
	return 0;
}