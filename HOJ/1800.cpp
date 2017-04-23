/*
	HOJ:1800.Flying to the Mars
	Date: 2016年2月14日 18:38:40
*/
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n;
	while(~scanf("%d", &n))
	{
		unordered_map<string, int> myMap;
		char level[35] = {0};
		for(int i = 0; i < n; ++i) 
		{
			scanf("%s", level);
			char *pch = level;
			while('0' == *pch) ++pch;
			++myMap[pch];
		}
		int ans = 1;
		for(auto i = myMap.begin(); i != myMap.end(); ++i )
			if(ans < i->second) ans = i->second;
		printf("%d\n", ans);
	}
	return 0;
}