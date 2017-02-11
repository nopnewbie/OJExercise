/*
	PAT(A):1108. Finding Average (20)
	Date:2016年3月15日 23:17:46
	Finished: 2016年3月16日 10:26:40
	正则表达式
*/
#include<iostream>
#include<regex>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	int n;
	cin >> n;
	regex pattern("-?([[:digit:]]*)(\\.?)([[:digit:]]{0,2})");
	string str;
	double sum = 0, d;
	int cnt = 0;
	smatch result;
	for (int i = 0; i < n; ++i)
	{
		cin >> str;
		if (regex_match(str, result, pattern))
		{
			sscanf(str.c_str(), "%lf", &d);
			if (d <= 1000 && d >= -1000)
			{
				sum += d;	++cnt;
			}
			else  printf("ERROR: %s is not a legal number\n", str.c_str());
		}
		else  printf("ERROR: %s is not a legal number\n", str.c_str());
	}
	if (!cnt) puts("The average of 0 numbers is Undefined");
	else if (1 == cnt) printf("The average of 1 number is %.2lf\n", sum);
	else printf("The average of %d numbers is %.2lf\n", cnt, sum / cnt);
	return 0;
}