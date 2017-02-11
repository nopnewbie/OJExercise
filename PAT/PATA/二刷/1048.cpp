/*
	PAT(A):1048. Find Coins (25)
	Started:  2016-12-19 14:16:50
	Finished: 2016-12-19 14:49:25
	Time consuption: 33min
*/

#define DEBUG

#include<cstdio>
#include<algorithm>

using namespace std;
const int maxn = 10e5 + 10;
int a[maxn];
int n, m;
int b, e;

inline void read()
{
    for (int i = 0; i < n; ++i)
        scanf("%d", a + i);
}

inline int binarySearch(const int lowerBound, const int upperBound, int x)
{
    int l = lowerBound + 1, r = upperBound, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] == x)
            return a[mid];
        else if (a[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return -1;
}

inline void solve()
{
    b = e = -1;
    sort(a, a + n);
    for (int i = 0; i < n; ++i)
    {
        if (a[i] > m / 2)
            break;

        int target = m - a[i];
        int tmp = binarySearch(i, n - 1, target);
        if (tmp > 0)
        {
            b = a[i];
            e = tmp;
            break;
        }
    }

    if (b < 0 || e < 0)
        puts("No Solution");
    else
        printf("%d %d\n", b, e);
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d", &n, &m))
    {
        read();
        solve();
    }
    return 0;
}