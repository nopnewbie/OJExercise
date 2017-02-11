/*
	PAT(A):1113. Integer Set Partition (25)
	Date:2016年3月14日 21:32:15
	Finished: 2016年3月15日 09:55:57
	Noet: 随机化算法会因为rand()而超时， 本题直接sort就可以。完全没有考到快排的思想
*/
#include<iostream>
#include<vector>
#include<cmath>
#include<ctime>
#include<algorithm>
using namespace std;

int randSelect(int *a, int left, int right)
{
	int p = (double)rand() / RAND_MAX * (right - left) + left;
	swap(a[left], a[p]);
	int tmp = a[left];
	while(left < right)
	{
		while(left < right && a[right] > tmp) --right;
		a[left] = a[right];
		while(left < right && a[left] <= tmp) ++left;
		a[right] = a[left];
	}
	a[left] = tmp;
	return left;	//主元最终所在位置
}

void randPartion(int *a, int left, int right, int k)
{
	if(left >= right) return;
	int p = randSelect(a, left, right);
	int m = p - left + 1;
	if(m == k) return;
	else if(m < k) randPartion(a, p + 1, right, k - m);
	else randPartion(a, left, p - 1, k);
}

const int maxn = 1e5 + 10;
int num[maxn];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	srand((unsigned)time(NULL));
	int n, sum = 0, sum2 = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)	{ scanf("%d", num + i); sum += num[i];}
	randPartion(num, 0, n - 1, n / 2);
	for(int i = 0; i < n / 2; ++i) sum2 += num[i];
	printf("%d %d\n", n - n / 2 * 2, sum - sum2 - sum2);
	return 0;
}