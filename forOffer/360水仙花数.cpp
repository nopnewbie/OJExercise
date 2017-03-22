/*
	360水仙花数
*/
#define DEBUG

#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 10;
bool t[maxn];
int m, n;

inline bool isOk(const int x)
{
    int a = x % 10;
    int b = x / 10 % 10;
    int c = x / 100;

    return x == (a*a*a + b*b*b + c*c*c);
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    for (int i = 101; i < 999; ++i)
    {
        t[i] = isOk(i);
    }
    while (~scanf("%d%d", &m, &n))
    {
        bool flag = false;
        for (int i = m; i <= n; ++i)
        {
            if (t[i])
            {
                if (flag)
                    printf(" %d", i);
                else
                    printf("%d", i);
                flag = true;
            }
        }
        if (!flag)
            printf("no");
        puts("");
    }

    return 0;
}