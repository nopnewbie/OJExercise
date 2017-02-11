/*
	PAT(B):1024. 科学计数法 (20)
	Date: 2016年1月29日 16:29:34
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	char sign, tmp;
	string cof;
	int exp, pointPos ;
	cin >> sign;
	while( cin >> tmp && 'E' != tmp ) 
		if('.' != tmp)cof.push_back(tmp);
	cin >> pointPos;
	cout << ('+' == sign ? "" : "-");
	pointPos += 1;
	if( pointPos > 0 )
	{//小数点右移
		for(int i = 0; i < pointPos && i < cof.size(); ++i) cout << cof[i];
		if( pointPos < cof.size() )
		{
			cout << '.';
			for( int i = pointPos; i < cof.size(); ++i ) cout << cof[i];
		}
		else if( pointPos > cof.size() )
		{
			for(int i = cof.size(); i < pointPos; ++i) cout << 0;
		}
	}
	else
	{//小数点左移
		cout << "0.";
		while( pointPos++ ) cout << 0;
		for( int i = 0; i < cof.size(); ++i ) cout << cof[i];
	}
	cout << endl;
	return 0;
}