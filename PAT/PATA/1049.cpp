/*
	PAT(A):1049. Counting Ones (30)
	Date: 2016年2月27日 13:39:11
	Finished:2016年2月28日 10:58:20
*/
#include<iostream>
using namespace std;


int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n;
	scanf("%d", &n);
	int ans = 0, a = 1;
	int left, right = 0, now = 0;
	while(n / a)
	{
		left = n / a / 10;
		now = n / a % 10;
		right = n % a;
		if(now == 0) ans += left * a;
		else if(now == 1) ans += left * a + right + 1;
		else ans += (left + 1) * a ;
		a *= 10;
	}
	printf("%d\n", ans);
	return 0;
}

