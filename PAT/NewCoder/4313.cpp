/*
	牛客网PAT
		List Grades (25)
		Date: 2016年1月7日 15:21:46
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

#define LOCAL

using namespace std ;

typedef struct Student
{
	string name, id ;
	int grade ;
	Student(){}
	Student( string _name, string _id, int _grade ):name(_name), id(_id), grade(_grade) {}
	bool operator < (const Student& a) const
	{
		return grade > a.grade ;
	}
} Stu;

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt") ;
#endif
	int n, g1, g2 ;
	cin >> n ;
	vector<Stu> st(n) ;
	for( int i = 0; i < n; ++i )
	{
		cin >> st[i].name >> st[i].id >> st[i].grade ;
	}
	cin >> g1 >> g2 ;
	sort( st.begin(), st.end() ) ;
	vector<Stu> ans ;
	for( int i = 0; i < n; ++i )
	{
		if( st[i].grade >= g1 && st[i].grade <= g2 ) ans.push_back( st[i] ) ;
	}
	if( ans.empty() ) cout << "NONE" << endl ;
	else
	{
		for( int i = 0; i < ans.size() ; ++i )
		{
			cout << ans[i].name << ' ' << ans[i].id << endl ;
		}
	}
	return 0 ;
}