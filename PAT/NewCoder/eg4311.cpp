/*
	参考答案: 牛客网PAT
		Rational Sum (20)
		Date: 2016年1月4日09:01:19
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

char s[111];

long long gcd(long long x,long long y) 
{
    return y?gcd(y, x % y):x;
}

int main() {
long long a = 0, b = 1; //a / b
int n;
    for (scanf("%d",&n);n;--n) {
        scanf("%s",s);
        char *t = strstr(s,"/");
        if (t) {
            *t = ' ';
        }
        long long c, d;
        sscanf(s,"%lld%lld",&c,&d);
        // a / b + c / d
        long long aa = a * d + b * c;
        long long bb = b * d;
        long long g = gcd((aa < 0)?(-aa):aa, bb);
        a = aa / g;
        b = bb / g;
    }
    long long x = a / b, y = a % b;
    if (y == 0) {
        printf("%lld\n",x);
    }
    else {
        if (x) {
            printf("%lld ",x);
        }
        printf("%lld/%lld\n",y,b);
    }
    return 0;
}