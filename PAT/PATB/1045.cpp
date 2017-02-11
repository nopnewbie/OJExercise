/*
	PAT(B):1045. 快速排序(25)
	Date: 2016年2月3日 22:44:46
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	int n;
	cin >> n;
	vector<int> num(n), bigLeft(n, 0), smallRight(n, 0), ans;
	for(int i = 0; i < n; ++i)
	{
		cin >> num[i];
		bigLeft[i] =	smallRight[i] = num[i];
	}
	for(int i = 1; i < n; ++i)
	{
		bigLeft[i] = bigLeft[i-1] > num[i] ? bigLeft[i - 1] : num[i];
		smallRight[n - 1 - i] = smallRight[n - i] < num[n - 1 - i] ? smallRight[n - i] : num[n - 1 - i];
	}
	for(int i = 0; i < n; ++i) if(bigLeft[i] <= num[i] && smallRight[i] >= num[i]) ans.push_back(num[i]);
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	if(!ans.empty()) 
	{
		cout << ans[0];
		for(int i = 1; i < ans.size(); ++i) cout << " " << ans[i];
	}
	cout << endl;
	return 0;
}