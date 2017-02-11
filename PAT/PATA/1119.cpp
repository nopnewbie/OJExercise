#define DEBUG

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

const int maxn = 30 + 10;

struct Node
{
    int data, lch, rch;
    Node(int d = -1, int l = -1, int r = -1)
        :data(d), lch(l), rch(r) {}
} biTree[maxn];

int n;
int pre[maxn], post[maxn];
bool isUnique = true;


void init()
{
    isUnique = true;
    for (auto &i : biTree)
    {
        i.data = -1;
        i.lch = i.rch = -1;
    }
}

void inOrder(int rootPos, vector<int> &ans)
{
    if (biTree[rootPos].data < 0) return;

    if (biTree[rootPos].lch > -1)
        inOrder(biTree[rootPos].lch, ans);

    ans.push_back(biTree[rootPos].data);

    if (biTree[rootPos].rch > -1)
        inOrder(biTree[rootPos].rch, ans);
}

int rebuildTree(int preL, int preR, int postL, int postR, int &cnt)
{
    if (preL > preR || postL > postR)
        return -1;

    const int rootPos = cnt++;
    
    biTree[rootPos].data = pre[preL];
    ++preL, --postR;    //缩小范围
    if (preL > preR || postR < postL)
    {
        biTree[rootPos].lch = -1;
        biTree[rootPos].rch = -1;
        return rootPos;
    }

    if (pre[preL] == post[postR])   //只存在一棵子树,则不唯一
        isUnique = false;

    int postLchR = postL;
    for (; postLchR <= postR; ++postLchR)
    {
        if (post[postLchR] == pre[preL])
            break;
    }

    int preRchL = preL + postLchR - postL + 1;

    biTree[rootPos].lch = rebuildTree(preL, preRchL - 1, postL, postLchR, cnt);
    biTree[rootPos].rch = rebuildTree(preRchL, preR, postLchR + 1, postR, cnt);

    return rootPos;
}



int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    while (~scanf("%d", &n))
    {
        init();

        for (int i = 0; i < n; ++i)
            scanf("%d", pre + i);
        for (int i = 0; i < n; ++i)
            scanf("%d", post + i);

        int cnt = 0;
        rebuildTree(0, n - 1, 0, n - 1, cnt);

        vector<int> ans;
        inOrder(0, ans);

        if (ans.empty() || !isUnique)
        {
            puts("No");
        }
        else if (isUnique)
        {
            puts("Yes");
        }

        if(!ans.empty())
            printf("%d", ans[0]);
        for (size_t i = 1; i < ans.size(); ++i)
            printf(" %d", ans[i]);
        puts("");
    }

    return 0;
}