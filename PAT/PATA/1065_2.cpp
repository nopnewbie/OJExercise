/*
	PAT(A):1065. A+B and C (64bit) (20)
	Date: 2016年2月3日 15:21:19
	思路:高精度大数
*/
#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;

struct BigInteger
{
	static const int cBase = 1e8;
	static const int cWidth = 8;
	vector<int> s;
	bool negative;
	BigInteger(long long num = 0): negative(false){ *this = num; }
	BigInteger operator = (long long num)
	{
		s.clear(); negative = false;
		if(num < 0) { negative = true; num = -num;}
		do
		{
			s.push_back(num % cBase);
			num /= cBase;
		}
		while(num);
		return *this;
	}
	
	BigInteger operator = (const string & str)
	{
		string ss;
		s.clear(); negative = false;
		if('-' == str.front())  { negative = true; ss = string(str.begin() + 1, str.end());}
		else ss = str;
		int len = (ss.size() - 1) / cWidth + 1;
		for(int i = 0; i < len; ++i  )
		{
			int end = ss.size() - cWidth * i;
			int start = max(0, end - cWidth);
			int x;
			sscanf(ss.substr(start, end).c_str(), "%08d" , &x);
			s.push_back(x);
		}
		return *this;
	}

	bool operator < (const BigInteger &b) const
	{
		if(negative != b.negative) return negative;
		else	if(negative) // 均为负数
		{
			if(s.size() != b.s.size()) return s.size() > b.s.size();
			else //位数相等
			{
				for(int i = s.size() - 1; i >= 0; --i)
					if(s[i] != b.s[i])	return s[i] > b.s[i];
				return false;	//相等时返回false
			}
		}
		else
		{//均为正数
			if(s.size() != b.s.size()) return s.size() < b.s.size();
			else //位数相等
			{
				for(int i = s.size() - 1; i >= 0; --i)
					if(s[i] != b.s[i])	return s[i] < b.s[i];
				return false;
			}
		}
	}
};

BigInteger operator + (const BigInteger &a, const BigInteger &b);
BigInteger operator - (const BigInteger &a, const BigInteger &b);

BigInteger operator + (const BigInteger &a, const BigInteger &b)
{
	BigInteger c, d;
	if(a.negative != b.negative)	//异号相加, 转为同号相减
	{
		if(a.negative)//a<0
		{
			c = b;	d = a;	
		}
		else
		{
			c = a;	d = b;
		}
		d.negative = false;
		c = c - d;
		while(!c.s.back() && c.s.size() > 1) c.s.pop_back();
	}
	else	//同号相加
	{
		c.negative = a.negative;
		c.s.clear();
		for(int i = 0, g = 0; ; ++i)
		{
			int x = g;
			if(!g && i >= a.s.size() && i >= b.s.size()) break;
			if(i < a.s.size()) x += a.s[i];
			if(i < b.s.size()) x += b.s[i];
			c.s.push_back(x % BigInteger::cBase);
			g = x / BigInteger::cBase;
		}
	}
	return c;
}

BigInteger operator - (const BigInteger &a, const BigInteger &b)
{
	BigInteger c, d;
	if(a.negative != b.negative)	//异号相减, 转为同号相加
	{
		if(a.negative)//a<0
		{
			c = a; d = b;
		}
		else
		{
			c = b; d = a;
		}
		c.negative = false;
		c = c + d;
		while(!c.s.back() && c.s.size() > 1) c.s.pop_back();
	}
	else	//同号减
	{
		c.s.clear();
		c.negative = a < b;
		for(int i = 0, g = 0; ; ++i)
		{
			int x = g;
			if(!g && i >= a.s.size() && i >= b.s.size()) break;
			if(i < a.s.size()) x += a.s[i];
			if(i < b.s.size()) x -= b.s[i];
			c.s.push_back( abs(x) % BigInteger::cBase);
			g = x / BigInteger::cBase;
		}
	}
	return c;
}

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n;
	string a, b, c;
	BigInteger A, B, C, D;
	cin >> n;
	for(int i = 1; i <= n; ++i )
	{
		cin >> a >> b >> c;
		A = a;	
		B = b;
		C = c;	
		D = A + B;
		cout << "Case #"<< i <<": " << (C < D ? "true" : "false") << endl;;
	}
	return 0;
}