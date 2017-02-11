/*
	PAT(A):1085. Perfect Sequence (25)
	Started: 2016-12-18 11:26:48
	Finished: 2016-12-18 11:51:30
	Time consuption: 25min
*/

#define DEBUG

#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 10e5 + 10;
long long num[maxn];
long long n, p;

long long binarySearch(long long l, long long r)
{
    long long mid;
    const long long val = p*num[l];
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (num[mid] > val)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%lld %lld", &n, &p))
    {
        for (long long i = 0; i < n; ++i)
        {
            scanf("%lld", num + i);
        }
        sort(num, num + n);

        long long ans = 1;
        for (long long i = 0; i < n; ++i)
        {
            if (ans > n - i) break;
            /*long long left = i + 1, right = n;
            while (left < right)
            {
                long long mid = left + (right - left) / 2;
                long long tmp = num[i] * p;
                if (num[mid] > tmp)
                {
                    right = mid;
                }
                else
                {
                    left = mid + 1;
                }
            }*/
           // long long left = binarySearch(i, n);
            long long left = upper_bound(num + i + 1, num + n, num[i] * p) - num;
            ans = max(ans, left - i);
        }

        printf("%lld\n", ans);

    }
    return 0;
}