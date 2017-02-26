#define DEBUG

#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 30000 + 10;
const int maxm = 5000 + 10;
int grade[maxn];
int n, m;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 1; i <= n; ++i)  
            scanf("%d", grade + i);

        for (int i = 0; i < m; ++i)
        {
            char ch;
            int a, b;
            scanf(" %c%d%d", &ch, &a, &b);
            if ('Q' == ch)
            {
                if (a > b) swap(a, b);
                int maxGrade = grade[a];
                for (int j = a + 1; j <= b; ++j)
                    maxGrade = max(maxGrade, grade[j]);
                printf("%d\n", maxGrade);

            }
            else if ('U' == ch)
            {
                grade[a] = b;
            }
        }
    }
    return 0;
}