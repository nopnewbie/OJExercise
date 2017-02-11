/*
	PAT(A):1067. Sort with Swap(0,*) (25)
	Date: 2016年2月19日 10:26:16
*/
#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	unsigned n;
	scanf("%u", &n);
	int *vi = new int[n];
	for(auto i = 0; i < n; ++i) scanf("%d", vi + i);
	int ans = 0;
	for(auto i = 0; i < n; )
	{
		while(i < n && vi[i] == i) ++i;
		if(i == n) break;
		unsigned len = 0, x = i;
		bool	zero = false;
		while( x <n && vi[x] != x)
		{
			if(!vi[x]) zero = true;
			++len;
			unsigned tmp = vi[x];
			vi[x] = x;
			x = tmp;
		}
		if(zero) ans += len - 1;
		else ans += len + 1;
	}
	printf("%d\n", ans);
	return 0;
}

/*
	并不要真的去模拟交换过程。
	定理: N个数字的排列由若干个独立的环组成
	情况1: 环中只有一个元素。即A[i] == i。 有序，不必交换。
	情况2: 环中有零。记环的长度为len。 则要交换n-1次。
	情况2: 环中本来没有零。 此时要将零加入环中(需要一次额外的交换)。环长度变为len+1。
			 使新环有序要(len + 1) - 1 次交换。加上将零加入环中的那次交换一共要len+1次交换
*/