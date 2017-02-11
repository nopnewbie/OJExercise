/*
	PAT(B):1029. 旧键盘(20)
	Date: 2016年1月30日 15:46:07
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
using namespace std;
bool isBad[128] = {false};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	string s1, s2;
	cin >> s1 >> s2;
	for(int i = 0; i < s1.size(); ++i) isBad[tolower(s1[i])] = isBad[toupper(s1[i])] = true;
	for(int i = 0; i < s2.size(); ++i) 
		if( isBad[tolower(s2[i])] || isBad[toupper(s2[i])] ) isBad[tolower(s2[i])] = isBad[toupper(s2[i])] = false;
	for(int i = 0; i < s1.size(); ++i) 
		if(isBad[s1[i]]) 
		{
			cout << (char)toupper(s1[i]);
			isBad[tolower(s1[i])] = isBad[toupper(s1[i])] = false;
		}
	cout << endl;
	return 0;
}