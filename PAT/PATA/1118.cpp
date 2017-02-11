/*
	PAT(A):1118. Birds in Forest (25)
	Started: 2016年12月16日 17:31:10
	Finished: 2016年12月16日 18:51:39
	Time consuption: 1h20m
*/

#define DEBUG

#include<cstdio>
#include<cstring>
#include<set>

using namespace std;

const int maxn = 10e4 + 10;

int n, q;
int myset[maxn];
set<int> birds;

void init()
{
    memset(myset, -1, sizeof(myset));
    birds.clear();
}

int find(int x)
{
    return (myset[x] < 0)? x : (myset[x] = find(myset[x]));
}

bool isOnSameTree(int x, int y)
{
    return find(x) == find(y);
}

void merge(int x, int y)
{
    int root1 = find(x);
    int root2 = find(y);
    
    if (root1 != root2)
    {
        if (myset[root1] <= myset[root2]) //root1孩子多
        {
            myset[root1] += myset[root2];
            myset[root2] = root1;
        }
        else
        {
            myset[root2] += myset[root1];
            myset[root1] = root2;
        }
    }
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
        {
            int k, tmp, root;
            scanf("%d", &k);
            for (int j = 0; j < k; ++j)
            {
                scanf("%d", &tmp);

                birds.insert(tmp);

                if (j)
                {
                    merge(root, tmp);
                }
                else
                {
                    root = tmp;
                }
            }
        }

        int treeNum = birds.size(), birdNum = birds.size();
        for (int i = 0; i < maxn; ++i)
        {
            if (myset[i] > 0)
                --treeNum;
        }
        printf("%d %d\n", treeNum, birdNum);

        scanf("%d", &q);
        for (int j = 0; j < q; ++j)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            if (isOnSameTree(x, y))
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }

    }
    return 0;
}