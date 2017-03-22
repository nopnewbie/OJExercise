#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int cnt[10];
int digit[10];

int count(const int n, const int x)
{
    int lo = 0, hi, curDigit, page = n;
    int ans = 0;
    for (int i = 1; i <= n; i *= 10) 
    {
        hi = page / i / 10;
        curDigit = page % (i * 10) / i;
        lo = page % i;

        if (!x) --hi;

        if (x > curDigit)
        {
            ans += hi * i;
        }
        else if (x < curDigit)
        {
            ans += (hi + 1) * i;
        } 
        else if (x == curDigit)
        {
            ans += hi * i + lo + 1;
        }

    }
    return ans;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < 9; ++i)
        {
            int ans = count(n, i);
            printf("%d ", ans);
        }
        printf("%d\n", count(n, 9));

    }

	return 0;
}