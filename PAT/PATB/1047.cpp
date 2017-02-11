/*
	PAT(B):1047. 编程团体赛(20)
	Date: 2016年2月4日 23:27:40
*/
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
#define LOCAL
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin);
#endif
	map<int, int> totalScore;
	int n, team, id, score;
	for(scanf("%d", &n); n; --n)
	{
		scanf("%d-%d %d", &team, &id, &score);
		totalScore[team] += score;
	}
	score = (*totalScore.begin()).second;	
	team = (*totalScore.begin()).first;
	for(auto i = totalScore.begin(); i != totalScore.end(); ++i)
		if((*i).second > score ) {score = (*i).second;	team = (*i).first;}
	cout << team << " " << score << endl;
	return 0;
}