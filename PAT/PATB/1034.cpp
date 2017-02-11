/*
	PAT(B):1034. 有理数四则运算(20)
	Date: 2016年1月31日 14:22:24
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int LCD( long long a, long long b )
{
	return b ? LCD(b, a % b) : a;
}

struct Ration
{
	long long k, a, b;
	bool negative, inf;
	Ration():k(0), a(0), b(0), negative(false), inf(false){}
	Ration( long long _a, long long _b ):k(0), a(0), b(0),negative(false), inf(false)
	{
		if( !(inf = _b ? false : true ) )
		{
			if( (_a > 0 && _b < 0) || (_a < 0 && _b > 0) )  negative = true;
			a = abs(_a); b = abs(_b);
			k = a / b;
			int lcd = LCD(a, b);
			a /= lcd;	b /= lcd;
			a -= k * b;
		}
	}
	void display()
	{
		if(inf) {cout << "Inf"; return;}
		cout << ( negative ? "(-": "" );
		if(k || ( b && !(a % b) ) ) cout << k;
		if(b && a % b) cout << (k ? " " : "") << a << "/" << b;
		cout << (negative ? ")": "");
	}
};
int main()
{
#define LOCAL
#ifdef LOCAL
#define LOCAL
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	long long a1, b1, a2, b2;
	scanf("%lld/%lld %lld/%lld", &a1, &b1, &a2, &b2);
	vector<Ration> ans(4);
	Ration x(a1, b1), y(a2, b2);
	ans[0] = Ration(  a1 * b2 + a2 * b1, b1 * b2);
	x.display(); cout << " + "; y.display(); cout << " = "; ans[0].display(); cout << endl;
	ans[1] = Ration(  a1 * b2 - a2 * b1, b1 * b2);
	x.display(); cout << " - "; y.display(); cout << " = "; ans[1].display(); cout << endl;
	ans[2] = Ration(  a1 * a2, b1 * b2);
	x.display(); cout << " * "; y.display(); cout << " = "; ans[2].display(); cout << endl;
	ans[3] = Ration(  a1 * b2 , b1 * a2);
	x.display(); cout << " / "; y.display(); cout << " = "; ans[3].display(); cout << endl;
	return 0;
}