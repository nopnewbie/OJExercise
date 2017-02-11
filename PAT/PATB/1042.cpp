/*
	PAT(B):1042. 字符统计(20)
	Date: 2016年2月2日 20:12:24
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int cnt[26] = {0};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string str;
	getline(cin, str);
	for(size_t i = 0; i < str.size(); ++i) if(isalpha(str[i])) ++cnt[tolower(str[i]) - 'a'];
	int pos = 0;
	for(int i = 1; i < 26; ++i) if(cnt[i] > cnt[pos]) pos = i;
	cout << (char)(pos + 'a') << " " << cnt[pos] << endl;
	return 0;
}