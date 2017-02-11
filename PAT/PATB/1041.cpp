/*
	PAT(B):1041. 考试座位号(15)
	Date: 2016年2月2日 20:00:43
*/
#include<iostream>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

struct node
{
	string id;
	int no;
} stu[1010];

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input,txt","r", stdin);
#endif
	int n, x, y;
	string id;
	for(cin >> n; n; --n)
	{
		cin >> id >> x >> y;
		stu[x].id = id;
		stu[x].no = y;
	}
	for(cin >> n; n; --n)
	{
		cin >> x;
		cout << stu[x].id << " " << stu[x].no << endl;
	}
	return 0;
}