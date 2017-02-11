/*
	PAT(A):1037. Magic Coupon (25)
	Date: 2016年2月18日 21:03:57
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

const int base = 1e9;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int nc, np;
	cin >> nc;
	vector<long long> cp(nc);
	for(int i = 0; i < nc; ++i)	cin >> cp[i];
	cin >> np;
	vector<long long> pd(np);
	for(int i = 0; i < np; ++i) cin >> pd[i];
	sort(cp.begin(), cp.end());
	sort(pd.begin(), pd.end());
	long long ans = 0;
	for(int i = 0; i < cp.size() && i < pd.size() && pd[i] <= 0 && cp[i] <= 0; ++i )
	{		
		ans += cp[i] * pd[i];
	}
	for(int i = cp.size() - 1, j = pd.size() - 1; i >= 0 && j >= 0 && cp[i] > 0 && pd[j] > 0; --i, --j)
	{		
		ans += cp[i] * pd[j];
	}
	printf("%lld\n", ans);
	return 0;
}