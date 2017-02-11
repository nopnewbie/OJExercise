/*
	PAT(A):1109. Group Photo (25)
	Date: 2016年3月14日 11:41:53
	Finished: 
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct Stu
{
	string name;
	int height;
	bool operator < (const Stu &rhs)const 
	{
		if(height != rhs.height) return height < rhs.height;
		else return name > rhs.name;
	}
};

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, k, m;
	scanf("%d%d", &n, &k);
	m = n / k;	//前k - 1队的人数
	vector<Stu> stu(n);
	vector<vector<Stu>> row(k);
	char buf[10];
	for(int i = 0, h; i < n; ++i)
	{
		scanf("%s %d", buf, &h);
		stu[i].name = buf;
		stu[i].height = h;
	}
	sort(stu.begin(), stu.end());
	int cnt = n - 1, rem = n - (k - 1) * m;
	row[0].resize(rem);
	row[0][rem / 2] = stu[cnt--];
	for(int i = 0, left = rem / 2 - 1, right = rem / 2 + 1; i < rem - 1; ++i)
	{
		if(i & 1)//odd, to "left of the tallest", or in our view to right;
			row[0][right++] = stu[cnt--];
		else row[0][left--] = stu[cnt--];
	}
	for(int i = 1; i < k; ++i)
	{
		row[i].resize(m);
		row[i][m/2] = stu[cnt--];
		for(int j = 0, left = m / 2 - 1, right = m / 2 + 1; j < m - 1; ++j)
		{
			if(j & 1)//odd, to "left of the tallest", or in our view to right;
				row[i][right++] = stu[cnt--];
			else row[i][left--] = stu[cnt--];
		}
	}
	for(int i = 0; i < k; ++i)
	{
		printf("%s", row[i][0].name.c_str());
		for(int j = 1; j < row[i].size(); ++j)	printf(" %s", row[i][j].name.c_str());
		puts("");
	}
	return 0;
}
