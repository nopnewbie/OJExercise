/*
	PAT(A):1044. Shopping in Mars (25)
	Started:  2016-12-19 11:34:51
	Finished: 2016-12-19 12:17:52
	Time consuption: 43min
*/
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define DEBUG
const int maxn = 10e5 + 10;
int a[maxn];
int n, m;

struct Node
{
    int begin, end;
    int remain;
    Node(int b, int e, int r) :begin(b), end(e), remain(r) {}
};

vector<Node> ans;

void read()
{
    a[0] = 0;
    for (int i = 1, tmp; i <= n; ++i)
    {
        scanf("%d", &tmp);
        a[i] = a[i - 1] + tmp;
    }
}

Node binarySearch(const int lowerBound, const int upperBound, const int val)
{
    int l = lowerBound, r = upperBound, mid;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        if (a[mid] - a[lowerBound - 1] >= val)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return Node(lowerBound, l, a[l] - a[lowerBound-1] - val);
}

void solve()
{
    ans.clear();
    for (int i = 1; i <= n; ++i)
    {
        Node d = binarySearch(i, n, m);
        if (d.remain < 0) continue;

        if (ans.empty())
            ans.push_back(d);
        else if ( ans.back().remain > d.remain)
        {
            ans.clear();
            ans.push_back(d);
        }
        else if (ans.back().remain == d.remain)
        {
            ans.push_back(d);
        }
    }
    for (const auto i : ans)
    {
        printf("%d-%d\n", i.begin, i.end);
    }
}


int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d%d", &n, &m))
    {
        read();
        solve();
    }
    return 0;
}