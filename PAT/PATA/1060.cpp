/*
	PAT(A):1063. 1060. Are They Equal (25)
	Date: 2016年3月6日 20:52:01
	Finished: 2016年3月7日 11:06:33
*/
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string trans(const string &s, int n, int &exp)
{
	string str(s.rbegin(), s.rend());
	for(int i = str.size() - 1; i >= 0 && '0' == str[i]; --i) str.pop_back();
	//去前导零
	exp = 0;
	if(!str.empty())
	{
		if('.' == str.back())
		{//说明是0.xyz型
			str.pop_back();
			while(str.size() > 0 && '0' == str.back()) {--exp;	str.pop_back();}
		}
		else
		{//说明是abc.xyz型, 也可能没有小数点
			int i;
			for( i = str.size() - 1; i >= 0 && str[i] != '.'; --i, ++exp );
			if(i > 0) str.erase(str.begin() + i);
		}
	}
	if(str.empty()) 
	{
		str = "0";
		exp = 0;
	}
	reverse(str.begin(), str.end());
	string ans;
	for(int i = 0; i < n; ++i)
	{
		if(i < str.size()) ans += str[i];
		else ans += "0";
	}
	return ans;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, i = 0;
	string a, b;
	cin >> n >> a >> b;
	int exp1, exp2;
	a = trans(a, n, exp1);
	b = trans(b, n, exp2);
	if(a == b)	printf("YES 0.%s*10^%d\n", a.c_str(), exp1);
	else printf("NO 0.%s*10^%d 0.%s*10^%d\n", a.c_str(), exp1, b.c_str(), exp2);
	return 0;
}