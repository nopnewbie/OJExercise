/*
	HOJ:1800.Flying to the Mars
	Date: 2016年2月14日 19:58:58
	Ps: No map!!!
*/
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

const int tableSize  = 6007;
int hs[tableSize], cnt[tableSize];
int ans;

inline unsigned elf_hash(const char *key_str)
{
	unsigned long h = 0, g;
	while( *key_str )
	{
		h = (h << 4) + *key_str++;
		g = h & 0xf0000000L;
		if(g) h ^= g >> 24;
		h &= ~g;
	}
	return h;
}
inline void hashit(const char *key_str)
{
	unsigned k, t;
	while('0' == *key_str) ++key_str;
	k = elf_hash(key_str);
	t = k % tableSize;
	while(hs[t] != k && hs[t] != -1)	//处理冲突,找到元素或空位
		t = (t + 1) % tableSize;
	if(hs[t] < 0) {hs[t] = k; cnt[t] = 1;}
	else if( ++cnt[t] > ans) ans = cnt[t];
}

int main()
{
#define LOCAL
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n;
	while( ~scanf("%d", &n) )
	{
		memset(hs, -1, sizeof(hs));
//		memset(cnt, -1, sizeof(cnt));
		char level[100] = {0};
		for(ans = 1 ; n; --n)
		{
			scanf("%s", level);
			hashit(level);
		}
		printf("%d\n", ans);
	}
	return 0;
}