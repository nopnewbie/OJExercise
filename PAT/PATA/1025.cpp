/*
	PAT(A):1025. PAT Ranking (25)
	Date: 2016年2月15日 18:01:38
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct	 Stu
{
	string id;
	int grade, frk, lno, lrk;
	Stu(){}
	Stu(string _id, int g, int no):id(_id), grade(g), lno(no){}
	bool operator < (const Stu &rhs) const 
	{
		if(grade != rhs.grade) return grade > rhs.grade;
		else return id < rhs.id;
	}
};

int main()
{
#define LOCAL
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin);
#endif
	vector<Stu> record;
	int n, k, sum = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &k);
		sum += k;
		char id[15];
		for(int j = 0, g; j < k; ++j)
		{
			scanf("%s%d", id, &g);
			record.push_back(Stu(id, g, i));
		}
		sort(record.end() - k, record.end());
		record[record.size() - k].lrk = 1;
		for(auto j = record.size() - k + 1; j < record.size(); ++j)
		{
			record[j].lrk = (record[j].grade == record[j - 1].grade) ?  record[j - 1].lrk : j - record.size() + k + 1;
		}
	}
	sort(record.begin(), record.end());
	record[0].frk = 1;
	for(auto i = 1; i < record.size(); ++i)
		record[i].frk = (record[i].grade == record[i - 1].grade) ? record[i - 1].frk : (i + 1);
	printf("%d\n", record.size());
	for(auto i = 0; i < record.size(); ++i)	
		printf("%s %d %d %d\n", record[i].id.c_str(), record[i].frk, record[i].lno, record[i].lrk);
	return 0;
}