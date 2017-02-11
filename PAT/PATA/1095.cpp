/*
	PAT(A):1095. Cars on Campus (30)
	Date: 2016年2月16日 13:28:06
*/
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#include<fstream>
using namespace std;

struct Record
{
	int time, status;	//时间是从00:00:00开始的秒数, status: 0表out, 1表in
	Record():time(0), status(0){}
	Record(int hh, int mm, int ss, string st):time(hh*3600 + mm*60 + ss), status("in" == st ? 1 : 0){}
	bool operator < (const Record &rhs)const	{ return time < rhs.time; }
};


int cars_no[24*3600];

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	map<string, vector<Record>> cars_rec;	//车辆信息
	map<string, int> pk_time;
	char plate_no[10], status[10];
	int n, m, hh, mm, ss;
	for(scanf("%d%d", &n, &m); n; --n)
	{
		scanf("%s %d:%d:%d %s", plate_no, &hh, &mm, &ss, status);
		cars_rec[plate_no].push_back(Record(hh, mm, ss, status));
	}
	for(auto it = cars_rec.begin(); it != cars_rec.end(); ++it)	
	{
		sort(it->second.begin(), it->second.end());	//每辆车按时间排序
		for(auto j = it->second.begin(); j != it->second.end() - 1; ++j)
		{
			if(j->status && !(j+1)->status) 
			{
				++cars_no[j->time];
				--cars_no[(j+1)->time];
				pk_time[it->first] += (j+1)->time - j->time;
			}
		}
	}
	vector<pair<string, int>>ans(pk_time.begin(), pk_time.end());
	sort(ans.begin(), ans.end(), [](const pair<string, int> &a, const pair<string, int> &b )->bool
	{
		if(a.second != b.second) return a.second > b.second;
		else return a.first < b.first;
	});
	for(int i = 0, pre = 0, now = 0, sum = 0; i < m; ++i, pre = now + 1)
	{
		scanf("%d:%d:%d", &hh, &mm, &ss);
		now = hh*3600 + mm*60 + ss;	//利用前缀数组和查询时间递增来避免从头计算,否则超时
		for(int j = pre; j <= now; ++j) sum += cars_no[j];
		printf("%d\n", sum);
	}
	printf("%s ", ans[0].first.c_str());
	for(auto i = 1; i < ans.size() && ans[i].second == ans[i - 1].second; ++i )	
		printf("%s ", ans[i].first.c_str());
	printf("%02d:%02d:%02d\n", ans[0].second / 3600, ans[0].second % 3600 / 60, ans[0].second % 60 );
	return 0;
}