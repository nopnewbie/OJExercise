/*
	PAT(A):1028. List Sorting (25)
	Date: 2016年2月15日 18:52:10
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

struct Stu
{
	int id, grade;
	string name;
	Stu(){}
	Stu(int i, string na, int g):id(i), grade(g), name(na){}
};

bool cmp1(const Stu &a, const Stu &b)
{
	return a.id < b.id;
}

bool cmp2(const Stu &a, const Stu &b)
{
	if(a.name != b.name) return a.name < b.name;
	else return a.id < b.id;
}

bool cmp3(const Stu &a, const Stu &b)
{
	if(a.grade != b.grade) return a.grade < b.grade;
	else return a.id < b.id;
}

bool (*cmp[3])(const Stu &a, const Stu &b) = {cmp1, cmp2, cmp3};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n, c, id, grade;
	string name;
	vector<Stu> stu;
	for(cin >> n >> c; n; --n)
	{
		cin >> id >> name >> grade;
		stu.push_back(Stu(id, name, grade));
	}
	sort(stu.begin(), stu.end(), cmp[c - 1]);
	for(auto i = 0; i < stu.size(); ++i) printf("%06d %s %d\n", stu[i].id, stu[i].name.c_str(), stu[i].grade);
	return 0;
}