/*
	PAT(A):1033. To Fill or Not to Fill (25)
	Date: 2016年2月17日 13:29:09
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

const int maxn = 30000 + 10;
struct Station
{
	double price, dist;
	bool operator < (const Station &rhs)const {return dist < rhs.dist;}
};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	double cmax, d, davg;
	int n;
	cin >> cmax >> d >> davg >> n;
	vector<Station> sta(n + 1);
	sta[n].dist = d; sta[n].price = 0;	//目的地视为油价为零的加油站
	for(int i = 0; i < n; ++i)
	{
		cin >> sta[i].price >> sta[i].dist;
	}
	sort(sta.begin(), sta.end() );
	if(sta[0].dist) puts("The maximum travel distance = 0.00");
	else
	{
		double farthest = cmax * davg;	//加满油可以到的最远距离
		int now = 0;	//当前位置
		double cost = 0, left = 0;
		for(auto end = now + 1; now < sta.size(); end = now + 1 )
		{
			auto mini_sta = end;
			bool flag = true;
			while(end < sta.size() && sta[end].dist <= sta[now].dist + farthest)
			{
				if(sta[end].price < sta[now].price)
				{//有比当前油站更便宜的油站
					flag = false;
					cost += ((sta[end].dist - sta[now].dist - left) /  davg) * sta[now].price;
					now = end;
					left = 0;
					break;
				}
				mini_sta = sta[end].price <= sta[mini_sta].price ? end : mini_sta;
				++end;
			}
			if(now == sta.size() - 1)
			{
				printf("%.2lf\n", cost);	break;
			}
			else if(end == now + 1)
			{
				printf("The maximum travel distance = %.2lf\n", sta[now].dist + farthest);	break;
			}
			else if(flag)//没有比当前油站更便宜的油站, 开往后续站中最便宜的站
			{
				cost += (cmax - left / davg) * sta[now].price;
				left = farthest - sta[mini_sta].dist + sta[now].dist;
				now = mini_sta;
			}
		}
	}
	return 0;
}