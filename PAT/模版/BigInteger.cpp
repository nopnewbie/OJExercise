/*
	模版:大整数类
	Date:2016年2月2日 13:37:01
*/
#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
struct BigInteger
{
	static const int BASE = 1e8;
	static const int WIDTH = 8;
	bool negative;
	vector<int> s;
//	BigInteger operator - (const BigInteger &b);
	BigInteger operator = (const string &str);
//	BigInteger operator + (const BigInteger &b);
	bool operator < (const BigInteger &b) const;

	BigInteger(long long num = 0):negative(false){*this = num;}
	BigInteger operator = (long long num)
	{
		negative = ( (num < 0) ? true : false);
		num = (negative ? -num : num);
		s.clear();
		do
		{
			s.push_back(num % BASE);
			num /= BASE;
		}while(num);
		return *this;
	}
};

BigInteger	operator - (const BigInteger &a, const BigInteger &b);
BigInteger	operator + (const BigInteger &a ,const BigInteger &b);

BigInteger	operator + (const BigInteger &a ,const BigInteger &b) 
{
	BigInteger c;
	c.s.clear();
	if(a.negative != b.negative)
	{
		BigInteger d;
		if(a < b) 
		{//异号加法转换为同号减法
			c = b;	
			d = a;	d.negative = false;
		}
		else
		{
			d = b; d.negative = false;
		}
		c = c - d;
		while(!c.s.back()) c.s.pop_back();
		return c;
	}
	for(int i = 0, g = 0; ; ++i)
	{
		if(!g && i >= a.s.size() && i >= b.s.size())  break;
		int x = g;
		if(i < a.s.size() ) x += a.s[i];
		if(i < b.s.size()) x += b.s[i];
		c.s.push_back(x % BigInteger::BASE);
		g = x / BigInteger::BASE;
	}
	while(!c.s.back()) c.s.pop_back();
	return c;
}

BigInteger	operator - (const BigInteger &a, const BigInteger &b)
{
	BigInteger c;
	if(a.negative != b.negative)
	{ //异号减法转为同号加法
		c = b;
		if(a < b)
		{//*this < 0, b >= 0
			c.negative = true;
		}
		else
		{//*this >= 0, b < 0
			c.negative = false;
		}
		c = a + c;
		while(!c.s.back()) c.s.pop_back();
		return c;
	}
	c.s.clear();
	for(int i = 0, g = 0; ; ++i)
	{
		if(!g && i >= a.s.size() && i >= b.s.size()) break;
		int x = g;
		if(i < a.s.size() ) x += a.s[i];
		if(i < b.s.size() ) x -= b.s[i];
		c.s.push_back(abs(x % BigInteger::BASE));
		g = x / BigInteger::BASE;
		c.negative = (g > 0 ? false : true);
	}
	while(!c.s.back()) c.s.pop_back();
	return c;
}

BigInteger	BigInteger::operator = (const string &str)
{
	s.clear();
	string ss;
	if('-' == str.front()) { negative = true; ss = string(str.begin()+1, str.end());}
	else ss = str;
	int x, len = (ss.length() - 1) / WIDTH + 1;
	for(int i = 0; i < len; ++i)
	{
		int end = ss.length() - i * WIDTH;
		int start = max(0, end - WIDTH);
		sscanf(ss.substr(start, end - start).c_str(), "%d", &x);
		s.push_back(x);
	}
	return *this;
}

bool BigInteger::operator < (const BigInteger &b) const
{
	if( negative && b.negative )
	{
		if(s.size() != b.s.size()) return s.size() >= b.s.size();
		else return !(s < b.s);
	}
	else if(!negative && !b.negative)
	{
		if(s.size() != b.s.size()) return s.size() < b.s.size();
		else return s < b.s;
	}
	else return negative;
}

ostream& operator << (ostream &out, const BigInteger &x)
{
	out << (x.negative ? "-" : "") << x.s.back();
	for(int i = x.s.size() - 2; i >= 0; --i)
	{
		char buf[BigInteger::WIDTH + 1];
		sprintf(buf, "%08d", x.s[i]);
		for(int j = 0; j < strlen(buf); ++j) out << buf[j];
	}
	return out;
}

istream& operator >> (istream &in, BigInteger &x)
{
	string s;
	if(!(in >> s)) return in;
	x = s;
	return in;
}

int main()
{
	BigInteger a, b(9223372036854775807), c(0), d;
	a = "-9223372036854775808";
	d = a + b;
	cout <<  a << " + " << b << " = " << d << " > " << c << " is " << ( (( c < d ) ) ? "true" : "false"  ) << endl;
	return 0;
}