/*
	PAT(A):1032. Sharing (25)
	Date: 2016年2月21日 20:08:41
	Finished: 最后一组大数据量错误,不明所以
*/
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

const int maxn = 1e5 + 10;
struct node
{
	char ch;
	int next;
}link[maxn];

int main()
{
//#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int addr1, addr2, n;
	vector<int> vad1, vad2;
	string s1, s2;
	scanf("%d%d%d", &addr1, &addr2, &n);
	if(addr1 == -1 || addr2 == -1){puts("-1"); return 0;}
	for(int i = 0, ad, nxt; i < n; ++i)
	{
		char ch;
		scanf("%d %c %d", &ad, &ch, &nxt);
		link[ad].ch = ch;
		link[ad].next = nxt;
	}
	for(int now = addr1; now > -1; now = link[now].next)
	{
		vad1.push_back(now);
		s1.push_back(link[now].ch);
	}
	for(int now = addr2; now > -1; now = link[now].next)
	{
		vad2.push_back(now);
		s2.push_back(link[now].ch);
	}
	int i = s1.size() - 1,		j = s2.size() - 1;
	while(i >= 0 && j >= 0 && s1[i] == s2[j]) {--i; --j;}
	if(i == s1.size() - 1 && j == s2.size() - 1) puts("-1");
	else	printf("%05d\n", vad1[++i]);
	return 0;
}