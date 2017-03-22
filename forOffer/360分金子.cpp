/*
	分金子
*/
#define DEBUG

#include <iostream>
using namespace std;

int n;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        int t;
        for (int i = 0; i < n; ++i)
        {
            int sum = 0, half = 0, d;
            scanf("%d", &t);
            for (int j = 0; j < t; ++j)
            {
                scanf("%d", &d);
                sum += d;
                if (j & 1)
                    half += d;
            }
            int biger = half > (sum - half) ? half : (sum - half);
            printf("Case #%d: %d %d\n", i + 1, biger, sum - biger);
        }
    }

    return 0;
}