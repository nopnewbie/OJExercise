/*
	PAT(B):1004. 成绩排名 (20)
	Date: 2016年1月27日 20:30:54
*/
#define LOCAL
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

struct Student
{
	string name, id;
	int grade;
};

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n;
	cin >> n;
	vector<Student> stu(n);
	for( int i = 0; i < n; ++i )	cin >> stu[i].name >> stu[i].id >> stu[i].grade;
	sort( stu.begin(), stu.end(), []( const Student &a, const Student &b ){ return a.grade > b.grade; } );
	cout << stu[0].name << " " << stu[0].id << endl;
	cout << stu.back().name << " " << stu.back().id << endl;
	return 0;
}