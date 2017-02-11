/*
	PAT(A):1010. Radix (25)
	Started:  2016-12-18 17:27:35
	Finished: 
	Time consuption: 
*/

#define DEBUG

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

const long long INF = (1LL << 63) - 1;
int t[128];
string n1, n2;
int tag, radix;

void init()
{
    for (int i = '0'; i <= '9'; ++i)
        t[i] = i - '0';
    for (int i = 'a'; i <= 'z'; ++i)
        t[i] = i - 'a' + 10;
}

long long toNum(const string& str, long long r, const long long upperBound)
{
    int i = 0;
    long long ret = 0;
    for (i = 0; i < str.size() && '0' == str[i]; ++i);    // pass the front zeros.
        
    while (i < str.size())
    {
        ret = ret*r + t[str[i]];
        if (ret < 0 || ret > upperBound) return  -1;    //may overflow
        ++i;
    }
    return ret;
}

long long searchRadix(const string& str, const long long target, const long long lowerBound, const long long upperBound)
{
    long long left = lowerBound, right = upperBound, mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        auto dec = toNum(str, mid, upperBound);
        if (dec == target)
            return mid;
        else if (dec < 0 || dec > target)  //radix is too small
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int findLagestDigit(const string& str)
{
    int ret = 1;
    for (const auto ch : str)
        ret = max(ret, t[ch]);
    return ret;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    init();

    while (cin >> n1 >> n2 >> tag >> radix)
    {
        long long ans;
        long long target, low, high;
        if (1 == tag)
        {
            target = toNum(n1, radix, INF);
            low = findLagestDigit(n2) + 1;
            high = max(low, target);
            ans = searchRadix(n2, target, low, high);
        }
        else
        {
            target = toNum(n2, radix, INF);
            low = findLagestDigit(n1) + 1;
            high = max(low, target);
            ans = searchRadix(n1, target, low, high);
        }
        if (ans > 0)
            printf("%lld\n", ans);
        else
            puts("Impossible");
    }
    return 0;
}
