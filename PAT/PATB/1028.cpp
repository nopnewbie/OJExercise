/*
	PAT(B):1028. 人口普查(20)
	Date: 2016年1月30日 15:16:30
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

struct Person
{
	string name;
	int yy, mm, dd;
	Person(){}
	Person(string na, int y, int m, int d):name(na), yy(y), mm(m), dd(d){}
	bool operator < (const Person &a) const
	{
		if( yy != a.yy ) return yy < a.yy;
		else if( mm != a.mm ) return mm < a.mm;
		else return dd < a.dd;
	}
};
const int year = 2014, month = 9, day = 6;
const int old_year = 1814, old_month = 9, old_day = 6;
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	vector<Person> ans;
	int n, yy, mm, dd;
	char na[6] = {0};
	for( scanf("%d", &n); n; --n )
	{
		scanf("%s %d/%d/%d", na, &yy, &mm, &dd);
		if( yy > year ) continue;
		else if( yy == year &&( mm > month || (mm == month && dd > day) ) )continue;
		if( yy < old_year ) continue;
		else if( yy == old_year && ( mm < month || (mm == old_month && dd < old_day) ) ) continue;
		ans.push_back(Person(na, yy, mm, dd));
	}
	if(ans.empty()) printf("0\n");
	else
	{
		sort(ans.begin(), ans.end());
		printf("%d %s %s\n", ans.size(), ans[0].name.c_str(), ans.back().name.c_str());
	}
	return 0;
}