/*
	PAT(B):1037. 在霍格沃茨找零钱（20）
	Date: 2016年2月1日 19:43:02
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin);
#endif
	int g1, g2, s1, s2, k1, k2, change;
	scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
	change = ((g2 - g1) * 17 + s2 - s1) * 29 + k2 - k1;
	printf("%d.%d.%d\n",change / 17 / 29, abs(change / 29 % 17), abs(change % 29));
	return 0;
}