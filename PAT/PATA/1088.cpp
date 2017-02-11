/*
	PAT(A):1088. Rational Arithmetic (20)
	Date:2016Äê1ÔÂ21ÈÕ 17:13:55
*/
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
#define LOCAL
long long GCD(long long a, long long b)
{
	long long big = a > b ? a : b;
	long long small = a < b ? a : b;
	while( small )
	{
		long long tmp = small;
		small = big % small;
		big = tmp;
	}
	return big;
}
struct Ration
{
	long long k, a, b ;
	bool isNeg, inf ;
	Ration():k(0),a(0),b(0),isNeg(false), inf(false){}
	Ration( long long _a, long long _b ): k(0),a(0),b(0),isNeg(false), inf(false)
	{
		if( _b ) 
		{
			if((_a < 0 && _b > 0) || (_a > 0 && _b < 0)) { isNeg = true; _a = abs(_a); _b = abs(_b);}
			k = _a / _b;	
			_a -=  k*_b;
			int gcd = GCD(_a, _b);
			a = _a / gcd;	b = _b / gcd;
		}
		else inf = true;
	}
	void display()
	{
		if( inf ) { cout << "Inf"; return; }
		if(isNeg) cout << "(-";
		if(a % b)
		{
			if(k) cout << k << ' ';
			cout << a << '/' << b;
		}
		else	cout << k;
		if(isNeg) cout << ')';
	}
};
int main()
{
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	vector<Ration> ans(4);
	long long a, b, c, d;
	scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
	Ration n1(a, b), n2(c, d);
	ans[0] = Ration(a * d + b * c, b * d);
	ans[1] = Ration(a * d - b * c, b * d);
	ans[2] = Ration(a * c,  b * d);
	ans[3] = Ration( a * d, b * c );
	n1.display(); cout << " + "; n2.display(); cout << " = "; ans[0].display(); cout << endl;
	n1.display(); cout << " - "; n2.display(); cout << " = "; ans[1].display(); cout << endl;
	n1.display(); cout << " * "; n2.display(); cout << " = "; ans[2].display(); cout << endl;
	n1.display(); cout << " / "; n2.display(); cout << " = "; ans[3].display(); cout << endl;
	return 0;
}