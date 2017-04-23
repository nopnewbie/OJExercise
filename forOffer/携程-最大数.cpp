#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 50 + 10;
int f[maxn];

void init()
{
    memset(f, 0, sizeof(f));
    f[0] = 1;
    f[1] = 1;
 //   f[2] = 2;
}

int maxNum(int k) 
{
    init();
    for (int i = 1; i <= k; ++i)
    {
        for (int j = k; j >= i; --j)
            f[j] = max(f[j - i] * i, f[j]);
    }
    return f[k];
}

int main() 
{
    freopen("F:\\input.txt", "r", stdin);
    int res;
    int _k;
    scanf("%d", &_k);
    res = maxNum(_k);
    printf("%d\n", res);
    return 0;
}