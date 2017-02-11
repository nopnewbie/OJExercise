/*
	PAT(A):1108. Finding Average (20)
	Date: 2016年3月14日 09:55:15
	Finished: 2016年3月14日 11:41:16
*/
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

const double eps = 1e-6;

bool islegal(const string &str, double &d)
{
	int pos = 0, cnt = 0, dotPos = -1;
	if('-' == str[0]) ++pos;
	if(pos == str.size()) return false;
	for(int i = pos; i < str.size(); ++i)
	{
		if(!isdigit(str[i]) && str[i] != '.') return false;	//非数字，非小数点
		else if('.' == str[i] )
		{
			if(++cnt > 1) return false;	//小数点多于1
			dotPos = i;		//记录小数点位置
		}
	}
	if(dotPos > -1 && str.size() - 1 - dotPos > 2) return false;
	sscanf(str.c_str(), "%lf", &d);
	if(d <= 1000 && d >= -1000) return true;
	return false;
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n, cnt = 0;
	double d, sum = 0;
	string str;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)	
	{
		cin >> str;
		{
			if(islegal(str, d))	
			{
				sum += d;
				++cnt;
			}
			else	printf("ERROR: %s is not a legal number\n", str.c_str());
		}
	}
	if(!cnt) puts("The average of 0 numbers is Undefined");
	else
	{
		if(cnt > 1)printf("The average of %d numbers is %.2f\n",cnt, sum / cnt);
		else printf("The average of 1 number is %.2f\n",sum);
	}
	return 0;
}