#define DEBUG
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 1000 + 10;
int pre[maxn], in[maxn], lch[maxn], rch[maxn];
int n;

int rebuild(int l, int r, int &cnt)
{
    if (l >= r) return -1;

    const int root = pre[cnt];
    int i;
    for (i = l; i < r && in[i] != root; ++i);
    if (l < i) lch[root] = rebuild(l, i, ++cnt);
    if (i + 1 < r) rch[root] = rebuild(i + 1, r,  ++cnt);
    return root;
}


void BFS(int root)
{
    queue<int> q;
    vector<int> ans;
    q.push(root);
    while (!q.empty())
    {
        int r = q.front();
        q.pop();
        ans.push_back(r);
        if (lch[r] > -1) q.push(lch[r]);
        if (rch[r] > -1) q.push(rch[r]);
    }
    
    if (!ans.empty())
    {
        printf("%d", ans.front());
        for (auto iter = ans.cbegin() + 1; iter != ans.end(); ++iter)
            printf(" %d", *iter);
        puts("");
    }
}

int main(int argc, char * * argv) 
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; ++i)
            scanf("%d", pre + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", in + i);

        memset(lch, -1, sizeof(lch));
        memset(rch, -1, sizeof(rch));

        int cnt = 0;
        int root = rebuild(0, n, cnt);
        BFS(root);
    }
    return 0;
}