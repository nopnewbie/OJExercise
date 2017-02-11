/*
	PAT(B):1044. 火星数字(20)
	Date: 2016年1月31日 19:56:51
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
#include<cctype>
#include<cstring>
using namespace std;
  
const string lowDigit[] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
const string highDigit[] = {"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string, int> str2num;
map<int, string>num2str;
void init()
{
	for(int i = 0; i < 13; ++i)
	{
		num2str[i] = lowDigit[i];
		num2str[i * 13] = highDigit[i];
		str2num[lowDigit[i]] = i;
		str2num[highDigit[i]] = i * 13;
	}
	for( int i = 1; i < 13; ++i )
		for( int j = 1; j < 13; ++j )
		{
			string s = highDigit[i] + " " + lowDigit[j];
			num2str[i * 13 + j] = s;
			str2num[s] = i * 13 + j;
		}
}
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	init();	//打表
	int n;
	string str_num;
	for(cin >> n, cin.get(); n; --n)
	{
		int num = 0;
		getline(cin, str_num);
		if( isdigit(str_num[0]) )
		{
			char cStr[4] = {0};
			for( int i = 0; i < 4 && i < str_num.size(); ++i) cStr[i] = str_num[i];
			sscanf(cStr, "%d", &num);
			cout << num2str[num] << endl;
		}
		else	cout << str2num[str_num] << endl;
	}
	return 0;
}