/*
	PAT(A):1024. Palindromic Number (25)
	Date: 2016年2月29日 10:48:33
	Finished:
*/
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string add(const string &a, const string &b)
{
	string x(a), y(b);
	reverse(x.begin(), x.end());
	reverse(y.begin(), y.end());
	int carry = 0, i, tmp;
	string ans;
	for(i = 0; i < x.size() && i < y.size(); ++i)
	{
		tmp = x[i] - '0' + y[i] - '0' + carry;
		carry = tmp / 10;
		tmp %= 10;
		ans.push_back(tmp + '0');
	}
	while(i < x.size()) 
	{
		if(carry) 
		{
			x[i] = carry + x[i] - '0';
			carry = x[i] / 10;
			x[i] = x[i] % 10 + '0';
		}
		ans.push_back(x[i++]);
	}
	while(i < y.size()) 
	{
		if(carry) 
		{
			y[i] = carry + y[i] - '0' ;
			carry = y[i] / 10;
			y[i] = y[i] % 10 + '0';
		}
		ans.push_back(y[i++]);
	}
	if(carry) ans.push_back(carry + '0');
	while(ans.size() > 1 && '0' == ans.back() ) ans.pop_back();
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	long long n, k, cnt = 0, tmp;
	char buf[20];
	string s1, s2;
	scanf("%lld %lld", &n, &k);
	sprintf(buf, "%lld", n);
	s1 = buf;
	s2 = s1;
	reverse(s2.begin(), s2.end() );
	while(s2.size() > 1 && '0' == s2.back()) s2.pop_back();
	while(cnt < k && s1 != s2)
	{
		s1 = add(s1, s2);
		s2 = s1;
		reverse(s2.begin(), s2.end());
		while(s2.size() > 1 && '0' == s2.back()) s2.pop_back();
		++cnt;
	}
	printf("%s\n%lld\n", s1.c_str(), cnt);
	return 0;
}