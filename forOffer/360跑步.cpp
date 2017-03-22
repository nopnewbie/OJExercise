/*
	360跑步
*/
#define DEBUG

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = 3.1415926;
const double zero = 10e-7;
double l, r;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (cin >> l >> r)
    {
        const double c = 2 * PI * r;
        while (l > c + zero)
            l -= c;
        const double ang = l / r;
        double x1 = r * cos(ang);
        double y1 = r * sin(ang);

        printf("%.3lf %.3lf\n%.3lf %.3lf\n", x1, -y1, x1, y1);
    }
    return 0;
}