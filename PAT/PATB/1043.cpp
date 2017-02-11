/*
	PAT(B):1043. 输出PATest(20)
	Date: 2016年2月2日 20:21:01
*/
#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
using namespace std;

int cnt[128] = {0};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string str;
	cin >> str;
	for(size_t i = 0; i < str.size(); ++i) ++cnt[str[i]];
	str.clear();
	while(cnt['P'] || cnt['A'] || cnt['T'] || cnt['e'] || cnt['s'] || cnt['t'])
	{
		if(cnt['P']) { str.push_back('P'); --cnt['P']; }
		if(cnt['A']) { str.push_back('A'); --cnt['A']; }
		if(cnt['T']) { str.push_back('T'); --cnt['T']; }
		if(cnt['e']) { str.push_back('e'); --cnt['e']; }
		if(cnt['s']) { str.push_back('s'); --cnt['s']; }
		if(cnt['t']) { str.push_back('t'); --cnt['t']; }
	}
	cout << str << endl;
	return 0;
}