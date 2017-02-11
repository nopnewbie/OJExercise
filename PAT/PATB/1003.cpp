/*
	PAT(B):1003. 我要通过！(20)
	Date: 2016年1月27日 14:15:24
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std; 
#define LOCAL

void print(string str)
{
	int pos = str.find("PAT");
	if( string::npos != pos )
	{
		string x1(str.begin(), str.begin() + pos), x2(str.begin() + pos + 3, str.end() );
		if( x1 == x2 && string(x1.size(), 'A') == x1 ) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	else
	{
		int pp = str.find('P');
		int pt = str.find('T');
		if( string::npos == pp || string::npos == pt || pt < pp   ) cout << "NO" << endl;
		else
		{
			string a(str.begin(), str.begin() + pp), b(str.begin() + pp + 1, str.begin() + pt), c(str.begin() + pt + 1, str.end()) ;
			string _b(b.size(), 'A');
			if( b.empty() || b != _b ) { cout << "NO" << endl; return; }
			else
			{
				string s = a + "P" + string( b.begin(), b.begin() + b.size() - 1 ) + "T";
				if( c.size() < a.size() || string( c.begin() + c.size() - a.size(), c.end() ) != a ) { cout << "NO" << endl; return; }
				else print( s + string(c.begin(), c.begin() + c.size() - a.size() ) );
			}
		}
	}
}

int main()
{
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	int n;
	for( cin >> n; n; --n )
	{
		string str;
		cin >> str;
		print(str);
	}
	return 0;
}