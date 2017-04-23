#define DEBUG
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int BASE = 26;
const int maxn = 100+5;
char s[maxn];
int t[128];

int main(int argc, char * * argv) 
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    for (int i = 'a'; i <= 'z'; ++i) t[i] = i - 'a';
    while (~scanf("%s", s))
    {
        int len = strlen(s);
        long long ans = 0;
        for (int i = 0; i < len; ++i)
        {
            ans = ans * BASE + s[i] - 'a';
        }
        printf("%lld\n", ans);
    }

    return 0;
}