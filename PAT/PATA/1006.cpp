/*
	PAT(A): 1006.Sign In and Sign Out (25)
*/
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>

using namespace std ;

int m ;
struct Person
{
	string ID ;
	int H1, M1, S1, H2, M2, S2 ;
	Person(string id, int h1, int m1, int s1, int h2, int m2, int s2): 
	ID(id), H1(h1), M1(m1), S1(s1), H2(h2), M2(m2), S2(s2)
	{}
} ;

vector<Person> p ;

int main()
{
	freopen("F:\\input.txt", "r", stdin) ;
	char s[16] ;
	int h1,m1,s1, h2, m2, s2 ;
	scanf("%d", &m) ;
	while(m--)
	{
		scanf("%s %d:%d:%d %d:%d:%d", s, &h1, &m1, &s1, &h2, &m2, &s2 ) ;
		p.push_back(Person(s, h1, m1, s1, h2, m2, s2)) ;
	}
	sort(p.begin(), p.end(), [](const Person& a, const Person& b)->bool
	{
		if(a.H1 == b.H1) 
			if(a.M1 == b.M1) return a.S1  < b.S1 ;
			else return a.M1 < b.M1 ;
		else 
			return a.H1 < b.H1 ;
	} ) ;
	cout << p[0].ID << ' ' ;
		sort(p.begin(), p.end(), [](const Person& a, const Person& b)->bool
	{
		if(a.H2 == b.H2) 
			if(a.M2 == b.M2) return a.S2  > b.S2 ;
			else return a.M2 > b.M2 ;
		else 
			return a.H2 > b.H2 ;
	} ) ;
	cout << p[0].ID << endl ;

	return 0 ;
}