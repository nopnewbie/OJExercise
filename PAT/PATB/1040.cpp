/*
	PAT(B):1040. 有几个PAT（25）
	Date: 2016年2月1日 20:32:52
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
const int Mod = 1000000007;
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	string s; 
	vector<int> p, a;
	cin >> s;
	for(int i = s.size() - 1,  cnt_a = 0, cnt_t = 0; i >= 0; --i)
	{
		switch(s[i])
		{
			int u;
		case 'P':
			u = (p.empty() ? 0 : p.back());
			if(!a.empty()) 
			{	
				for(auto j = a.end() - cnt_a; j != a.end(); ++j)	
					u = (u + *j) % Mod;
			}
			p.push_back(u);
			cnt_a = 0;
			break;
		case 'A':
			cnt_a = (cnt_t + cnt_a) % Mod;
			cnt_t = 0;
			break;
		case 'T':
			++cnt_t;
			break;
		}	
	}
	int ans = 0;
	for(int i  = 0; i < p.size(); ++i) ans = (ans + p[i]) % Mod;
	cout << ans << endl;
	return 0;
}
