#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

const double zero = 10e-7;

struct Point
{
    double x, y, w;
};

inline bool equal(double a, double b)
{
    return abs(a - b) < zero;
}

inline double lineLen(const Point &a, const Point &b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

inline double area(const Point & a, const Point & b, const Point & c)
{
    double lenAB = lineLen(a, b);
    double lenAC = lineLen(a, c);
    double lenBC = lineLen(b, c);
    double p = (lenAB + lenBC + lenAC) / 2;
    return sqrt(p*(p - lenAB) * (p - lenAC) * (p - lenBC));
}

inline bool inTriAngle(const Point &a, const Point &b, const Point &c, const Point &p)
{
    double s = area(a, b, c);
    double s1 = area(a, b, p);
    double s2 = area(a, c, p);
    double s3 = area(b, c, p);
    return abs(s - s1 - s2 - s3) <= zero;
}

inline double calc(const Point *const pt)
{
    const Point &a = pt[0], &b = pt[1], &c = pt[2] , &d = pt[3];
    double u, v;
    if (equal(c.y, a.y))
    {
        u = (d.x - a.x) / (b.x - a.x);
    }
    else
    {
        u = (d.x - a.x - (d.y - a.y) / (c.y - a.y)) / (b.x - a.x - (b.y - a.y) / (c.y - a.y));
    }

    if (equal(b.y, a.y))
    {
        v = (d.x - a.x) / (c.x - a.x);
    }
    else
    {
        v = (d.x - a.x - (d.y - a.y)) / (b.y - a.y) / (c.x - a.x - (b.y - a.y) / (b.y - a.y));
    }

    double w = a.w + b.w + c.w;
    return ((1 - u - v)*a.w + u*b.w + v*c.w) / w;
}

int main()
{
#ifdef DEBUG
	freopen("F:\\input.txt", "r", stdin);
#endif
    Point pt[4];
    for (int i = 0; i < 3; ++i)
        scanf("%lf%lf%lf", &pt[i].x, &pt[i].y, &pt[i].w);
    scanf("%lf%lf", &pt[3].x, &pt[3].y);

    if (inTriAngle(pt[0], pt[1], pt[2], pt[3]))
    {
        printf("%.2lf\n", calc(pt));
    }
    else
        puts("-1");
    
	return 0;
}

