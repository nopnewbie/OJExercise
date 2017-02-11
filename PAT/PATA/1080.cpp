/*
	PAT(A):1080. Graduate Admission (30)
	Date: 2016年2月16日 09:01:35
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

int n, m, k;

struct Stu
{
	int id, ge, gi, final_grade;
	Stu(){}
	Stu(int _id, int e, int i):id(_id), ge(e), gi(i), final_grade((ge + gi) / 2){}
	bool operator < (const Stu &rhs) const
	{
		if(final_grade != rhs.final_grade) return final_grade > rhs.final_grade;
		else return ge > rhs.ge;
	}
};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	cin >> n >> m >> k;
	vector<int> quota(m);
	for(int i = 0; i < m; ++i) cin >> quota[i];
	vector<vector<Stu>> admitted(m);	//各学校录取的学生
	vector<vector<int>> prefer_school(n);	//各个学生的志愿
	vector<bool> valid(n, false);		//考生是否已经被录取
	vector<Stu> stu(n);
	for(int i = 0; i < n; ++i)
	{
		cin >> stu[i].ge >> stu[i].gi;
		stu[i].id = i;
		stu[i].final_grade = stu[i].ge + stu[i].gi;
		prefer_school[i].resize(k);
		for(int j = 0, choice; j < k; ++j) cin >> prefer_school[i][j];
	}
	sort(stu.begin(), stu.end());
	for(int i = 0; i < n; ++i)
	{
		if(valid[stu[i].id]) continue;	//该考生已经被录取
		for(int j = 0; j < k; ++j)
		{
			auto sch_no = prefer_school[stu[i].id][j];	//报考学校编号
			auto &school = admitted[prefer_school[stu[i].id][j]];	//报考院校实际录取情况
			if(school.size() < quota[sch_no]) { school.push_back(stu[i]); valid[stu[i].id] = true;	break;}
			else if(quota[sch_no] && //学校有招录名额
				(school.empty() || /*第i个考生的第j志愿学校没招到人时*/
				( stu[i].final_grade == school.back().final_grade 
				&& stu[i].ge == school.back().ge)	) )
				// 第i个考生的第j志愿学校之前招到的人和该考生同排名则继续招录
			{
				school.push_back(stu[i]);	valid[stu[i].id] = true;	break;
			}
		}
	}
	for(int i = 0; i < m; ++i)
	{
		if(admitted[i].empty()) cout << endl;
		else
		{
			sort(admitted[i].begin(), admitted[i].end(), [](const Stu &a, const Stu &b){ return a.id < b.id;});
			cout << admitted[i].front().id;
			for(auto j = 1; j < admitted[i].size(); ++j) cout << " " << admitted[i][j].id;
			cout << endl;
		}
	}
	return 0;
}