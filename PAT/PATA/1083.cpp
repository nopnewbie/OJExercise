/*
	PAT(A):1083. List Grades (25)
	Date: 2016年2月16日 08:45:26
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

struct Stu
{
	string name, id;
	int grade;
	Stu(){}
	Stu(string n, string i, int g):name(n), id(i), grade(g){}
	bool operator < (const Stu &rhs)const 
	{
		return grade > rhs.grade;
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
	vector<Stu> stu, ans;
	int n, g1, g2, grade;
	string name, id;
	for(cin >> n; n; --n)
	{
		cin >> name >> id >> grade;
		stu.push_back(Stu(name, id, grade));
	}
	cin >> g1 >> g2;
	for(auto i = 0; i < stu.size(); ++i)
		if(stu[i].grade >= g1 && stu[i].grade <= g2) ans.push_back(stu[i]);
	if(ans.empty()) cout << "NONE" << endl;
	else
	{
		sort(ans.begin(), ans.end());
		for(auto i = 0; i < ans.size(); ++i) cout << ans[i].name << " " << ans[i].id << endl;
	}
	return 0;
}