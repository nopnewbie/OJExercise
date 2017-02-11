/*
	最大连续子序列
*/
#define DEBUG

#include<iostream>
#include<fstream>

const int maxn = 10000 + 10;
int k;
int a[maxn], dp[maxn];

inline void input() 
{
    for (int i = 0; i < k; ++i)
        scanf("%d", a + i);
}

inline void init()
{
    dp[0] = a[0];
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    
    while (~scanf("%d", &k) && k)
    {
        input();
        init();

        int begin = a[0], end = a[k - 1], maxSum = a[0], currentBegin = a[0];
        for (int i = 1; i < k; ++i)
        {
            if (dp[i - 1] + a[i] > a[i])
                dp[i] = dp[i - 1] + a[i];
            else
            {
                dp[i] = a[i];
                currentBegin = a[i];
            }
                
            if (dp[i] > maxSum)
            {
                maxSum = dp[i];
                begin = currentBegin;
                end = a[i];
            }
        }
        if (maxSum < 0)  printf("0 %d %d\n", a[0], a[k - 1]);
        else printf("%d %d %d\n", maxSum, begin, end);

    }
    return 0;
}
