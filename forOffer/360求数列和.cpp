/*
	求数列和
*/
#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxN = 10000 + 10;
const int maxM = 1000 + 10;
double num[maxM];
int n, m;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (~scanf("%d%d", &n, &m))
    {
        double sum = n;
        double pre = n;
        for (int i = 0; i < m-1; ++i)
        {
            double cur = sqrt(pre);
            sum += cur;
            pre = cur;
        }
        printf("%.2lf\n", sum);
    }
	return 0;
}