/*
	PAT(A):1098. Insertion or Heap Sort (25)
	Date: 2016年3月2日 14:46:19
	Finished: 2016年3月2日 23:19:01
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

const int maxn = 100 + 10;
int n;
vector<int> a, b;

int isInsert()
{
	int i = 1, len;
	//while(i >= 0 && b[i] == a[i]) --i;
	//len = i + 1;
	//while(i > 0 && b[i - 1] <= b[i] ) --i;
	/*上面的方法判断插排2号测试点过不了
		考虑序列: 2 1 3 5
					 1 2 3 5
		这是是插排经历一趟(或者2,3,4趟)以后的结果则下面的判断其实是有问题的。
	*/
	while(i < n && b[i - 1] <= b[i]) ++i;
	len = i;
	while(i < n && b[i] == a[i]) ++i;
	if(i < n) return -1;
	else return len;
}

void PorcDown(int x, int size)
{
	int tmp = a[x];
	for(int child; (child = 2 * x + 1) < size; x = child )
	{
		if(child + 1 < size && a[child] < a[child + 1]) ++child;
		if(tmp < a[child]) a[x] = a[child];
		else	break;
	}
	a[x] = tmp;
}

void HeapSort()
{
	bool flag = false;
	for(int i = (n - 1) / 2; i >= 0; --i)
		PorcDown(i, n);
	for(int i = n - 1; i > 0; --i)
	{
		swap(a[0], a[i]);
		PorcDown(0, i);
		if(flag)
		{
			printf("%d", a[0]);
			for(int i = 1; i < n; ++i) printf(" %d", a[i]);
			puts("");
			break;
		}
		if(a == b)	flag = true;
	}
}
int main()
{
	freopen("F:\\input.txt", "r", stdin);
	while(~scanf("%d", &n))
	{
		a.resize(n);	b.resize(n);
		for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for(int i = 0; i < n; ++i) scanf("%d", &b[i]);
		int len = isInsert();
		if(len > -1)
		{
			puts("Insertion Sort");
			sort(a.begin(), a.begin() + len + 1);
			printf("%d", a[0]);
			for(int i = 1; i < n; ++i) printf(" %d", a[i]);
			puts("");
		}
		else
		{
			puts("Heap Sort");
			HeapSort();
		}
	}
	return 0;
}