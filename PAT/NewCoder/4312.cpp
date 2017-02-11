/*
	牛客网PAT
		Read Number in Chinese (25)
		Date: 2016年1月4日09:01:19
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<queue>
#define LOCAL

using namespace std ;

const string unit[] = {"", "Shi", "Bai", "Qian","Wan", "Shi", "Bai", "Qian","Yi"};
const string digit[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"} ;

int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt") ;
#endif
	string num ;
	while( cin >> num )
	{
		queue<string> ans ;
		reverse( num.begin(), num.end() ) ;
		if( num.back() == '-' ) 
		{	
			ans.push("Fu") ;
			num.pop_back() ;
		}
		int p, q ;	//p前一个非零元素位置, q当前非零元素位置
		for( p = num.size()-1; p >= 0 && num[p] == '0'; --p );
		p =  p > 0 ? p : 0 ;	//处理 输入为0的情况
		q = p;
		ans.push( digit[ num[ p ] - '0' ] ) ;
		ans.push( unit[ p ] ) ;
		while( q >= 0 )
		{
			for( q = p - 1; q >= 0 && num[q] == '0'; --q );
			if( q >= 0 )
			{
				if( p - q > 1) //不是相邻的两个非零元素
				{
					if( p == 8 && q < 8 && ans.back() != "Yi" ) ans.push("Yi") ;
					else if( p < 8 && p >= 4 && q < 4 && ans.back() != "Wan" ) ans.push( "Wan" ) ;
					if( (q != 7 && q != 3) || p - q >= 4 )	ans.push("ling") ;
				}
				ans.push( digit[ num[ q ] - '0' ] ) ;
				ans.push( unit[q] ) ;
				p = q ;
			}
		}
		cout << ans.front() ; ans.pop() ;
		for( ; !ans.empty() && ans.front() != "" ; ans.pop() ) cout << ' ' << ans.front() ;
		cout << endl ;
	}
	return 0 ;
}
