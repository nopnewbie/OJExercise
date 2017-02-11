/*
	PAT(A):1057. Stack (30)
	Date: 2016年3月7日 11:42:44
	Finished: 2016年3月7日 19:59:51
*/
#include<iostream>
#include<stack>
#include<cmath>
using namespace std;

const int maxn = 1e5 + 10;
const int block_size = 316;
int table[maxn], block[317];

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	stack<int> stk;
	char op[11];
	int n;
	scanf("%d", &n);
	for(int i = 0, key; i < n; ++i)
	{
		scanf("%s", op);
		if('u' == op[1])	//push
		{
			scanf("%d", &key);
			stk.push(key);
			++table[key];
			++block[key / block_size];
		}
		else if('o' == op[1]) //pop
		{
			if(stk.empty()) puts("Invalid");
			else
			{
				printf("%d\n", stk.top());
				--table[stk.top()];
				--block[stk.top() / block_size];
				stk.pop();
			}
		}
		else if('e' == op[1])
		{
			if(stk.empty()) puts("Invalid");
			else 
			{
				int mid = (stk.size() + 1) / 2;
				int pos = -1, sum = 0;
				while(sum < mid) sum += block[++pos];
				sum -= block[pos];
				for(int i = pos * block_size, end = (pos + 1) * block_size; i < end; ++i)
				{
					sum += table[i];
					if(sum >= mid)
					{
						printf("%d\n", i);
						break;
					}
				}
			}
		}
	}
	return 0;
}