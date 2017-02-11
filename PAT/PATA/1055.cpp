/*
	PAT(A):1055. The World's Richest (25)
	Date: 2016年2月15日 19:27:46
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

struct Man
{
	string name;
	int age, net_worth;
	Man(){}
	Man(string na, int a, int w): name(na), age(a), net_worth(w){}
	bool operator < (const Man &rhs)const
	{
		if(net_worth  != rhs.net_worth) return net_worth > rhs.net_worth;
		else if(age != rhs.age) return age < rhs.age;
		else return name < rhs.name;
	}
};
vector<Man> record;
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n, k, age, w;
	string name;
	for(cin >> n >> k; n; --n)
	{
		cin >> name >> age >> w;
		record.push_back(Man(name, age, w));
	}
	sort(record.begin(), record.end()/*, [](const Man &a, const Man &b){return a.age < b.age;}*/);
	for(int i = 1; i <= k; ++i)
	{
		printf("Case #%d:\n", i);
		int m, min_age, max_age;
		cin >> m >> min_age >> max_age;
		vector<Man> ans;
		for(int j = 0; j < record.size() && ans.size() < m; ++j)
		{
			if(record[j].age < min_age || record[j].age > max_age) continue;
			ans.push_back(record[j]);
		}
		if(ans.empty()) puts("None");
		else
		{
			sort(ans.begin(), ans.end());
			for(auto j = 0; j < ans.size(); ++j) printf("%s %d %d\n", ans[j].name.c_str(), ans[j].age, ans[j].net_worth);
		}
	}
	return 0;
}