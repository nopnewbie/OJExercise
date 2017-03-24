#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int n;
char s[20];
int d[20];

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        sprintf(s, "%d", n);
        int len = strlen(s);
        if (len < 2)
        {
            puts("NO");
            continue;
        }
        int cntZero = 0;
        d[0] = 1;
        for (int i = 0; i < len; ++i)
        {
            if ('0' == s[i]) ++cntZero;
            d[i] = (s[i] - '0') * (i ? d[i-1] : 1);
            
        }
        if (cntZero == 1)
            puts("NO");
        else if (cntZero > 1)
            puts("YES");
        else
        {
            bool flag = true;
            for (int i = 0; i < len-1; i++)
            {
                if ((d[i] * d[i]) == d[len - 1])
                {
                    puts("YES");
                    flag = false;
                    break;
                }
            }
            if (flag) puts("NO");
        }
    }
	return 0;
}