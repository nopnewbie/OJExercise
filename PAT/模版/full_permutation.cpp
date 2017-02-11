//full permutation of 1~n
#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> full_permutation;
vector<bool> flag;
void permu(int n, vector<int> &tmp)
{
	if(tmp.size() == n) full_permutation.push_back(tmp);
	else	for(int i = 1; i <= n; ++i)
	{
		if(!flag[i - 1])
		{
			tmp.push_back(i);
			flag[i - 1] = true;
			permu(n, tmp);
			flag[i - 1] = false;
			tmp.pop_back();
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	flag.resize(n, false);
	vector<int> num;
	permu(n, num);
	for(int i = 0; i < full_permutation.size(); ++i)
	{
		printf("%d", full_permutation[i][0]);
		for(int j = 1; j < n; ++j) printf(" %d", full_permutation[i][j]);
		puts("");
	}
	return 0;
}