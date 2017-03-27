#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

struct Frac
{
    static int gcd(int x, int y)
    {
        return y == 0 ? x : gcd(y, x%y);
    }

    Frac(int _p, int _q) 
    {
        int d = gcd(_p, _q);
        p = _p / d;
        q = _q / d;
    }
    int p, q;
    bool operator<(const Frac &rhs) const
    {
        return p*rhs.q - q * rhs.p < 0;
    }
    bool operator==(const Frac &rhs) const
    {
        return p*rhs.q == q * rhs.p;
    }
};

int w, x, y, z;
set<Frac> nums;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d%d%d", &w, &x, &y, &z))
    {
        nums.clear();
        for (int p = w; p <= x; ++p)
        {
            for (int q = y; q <= z; ++q)
            {
                nums.insert({ p,q });
            }
        }
        printf("%u\n", nums.size());
    }
	return 0;
}