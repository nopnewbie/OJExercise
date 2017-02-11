/*
	PAT(A):1073. Scientific Notation (20)
	Date: 2016年2月27日 14:31:02
	Finished: 2016年2月27日 15:02:36
*/
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	freopen("F:\\input.txt", "r", stdin);
	ifstream fin("F:\\input.txt");
#endif
	char sign;
	string str, ans;
	int exp;
	getline(cin, str);
	sign= str[0];
	sscanf(str.c_str() + str.find('E') + 1, "%d", &exp);
	if(exp < 0) for(int i = exp; i < 0; ++i) ans.push_back('0');
	for(auto i = 1; i < str.size() && str[i] != 'E'; ++i) if(str[i] != '.') ans.push_back(str[i]);
	if(exp > 0) for(auto i = ans.size() - 1; i < exp; ++i) ans.push_back('0');
	if('-' == sign) printf("-");
	printf("%c",ans[0]); 
	if(exp < 0)
	{
		putchar('.');
		for(unsigned i = 1; i < ans.size(); ++i) putchar(ans[i]);
	}
	else
	{
		unsigned i = 1;
		for(; i <= exp; ++i) printf("%c", ans[i]);
		if(i < ans.size()) putchar('.');
		while(i < ans.size()) printf("%c", ans[i++]);
	}
	return 0;
} 