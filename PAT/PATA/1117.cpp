/*
	PAT(A):1117. Eddington Number(25)
	Started: 2016-12-17 14:48:38
	Finished: 2016-12-17 20:29:35
	Time consuption: 1h20min
	ps: The description ''E days that one rides more than E miles' ' is too ambiguous, as well as the example!! The following example, show what this question really means:
		input:
		3
		3 3 5
		output should be:
		2
		but, actually,thery are 3 days rides more than 2 miles. orz.
*/

#define DEBUG

#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 10e5 + 10;
int num[maxn], bigger[maxn], self[maxn];
int n;

void init()
{
    memset(num, 0, sizeof(num));
    memset(bigger, 0, sizeof(bigger));
}

void readNum()
{
    int tmp;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        if (tmp > n) bigger[n]++;
        else num[tmp]++;
    }
}

void count()
{
    int i;
    for (i = n; i > 0; --i)
    {
        if (i != n)
        {
            bigger[i] = bigger[i + 1] + num[i + 1];
        }

        if (bigger[i] == i)
        {
            printf("%d\n", i);
            break;
        }
    }
    if (!i) puts("0");
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        init();
        readNum();
        count();
    }
    return 0;
}