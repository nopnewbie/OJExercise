/*
	PAT(A):1036. Boys vs Girls (25)
	Date: 2016年3月5日 15:25:40
	Finished:
*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Stu
{
	string name, id;
	int grade;
	Stu(string na = "", string i = "", int g = 0):name(na), id(i), grade(g){}
	bool operator < (const Stu &rhs) const
	{
		return grade > rhs.grade;
	}
};
vector<Stu> M, F;
int n;

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	char a[11], b[11], sex;
	int scores;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
	{
		scanf("%s %c %s %d", a, &sex, b, &scores);
		if('M' == sex) M.push_back(Stu(a, b, scores));
		else F.push_back(Stu(a, b, scores));
	}
	sort(M.begin(), M.end());
	sort(F.begin(), F.end());
	if(F.empty()) puts("Absent");
	else printf("%s %s\n", F[0].name.c_str(), F[0].id.c_str());
	if(M.empty()) puts("Absent");
	else printf("%s %s\n", M.back().name.c_str(), M.back().id.c_str());
	if(F.empty() || M.empty()) puts("NA");
	else printf("%d\n", F[0].grade - M.back().grade);
	return 0;
}
