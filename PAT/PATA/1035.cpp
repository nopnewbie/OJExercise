/*
	PAT(A):1035. Password (20)
	Date: 2016年1月19日 17:03:41
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<string>
#define LOCAL
using namespace std ;

int main()
{
#ifdef LOCAL
#define cin fin
	//ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	vector<char> t(128) ;
	vector<string> name, psw ;
	for( int i = 0; i < 128; ++i ) t[i] = i ;
	t['1'] = '@'; t['0'] = '%'; t['l'] = 'L'; t['O'] = 'o';
	int n ;
	scanf("%d", &n) ;
	for( int i = 0 ; i < n; ++i )
	{
		string pw ;
		bool flag = false ;
		char c, na[15];	
		scanf( "%s",na );
		getchar();
		for( int j = 0; j < 15 &&  (c = getchar()) != '\n' && c > 0; ++j )
		{
			pw.push_back( t[c] ) ; 
			if( c != pw.back() ) flag = true ;	//进行了修改
		}
		if(flag) { name.push_back(na); psw.push_back(pw); }
	}
	if( name.empty() )	//没有一个被修改 
	{
		cout << "There " << (1==n ?"is ":"are ") << n <<" account"
			<< (1 < n ? "s": "") <<" and no account is modified" << endl;
	}
	else
	{
		cout << name.size() << endl;
		for( int i = 0; i < name.size(); ++i )
		{
			cout << name[i] << " " << psw[i] << endl ;
		}
	}
	return 0 ;
}