#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;
vector<int> va, vb;
map<int, set<int>> hashtable;
set<int> ans;

int main()
{
    freopen("F:\\input.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
        va.clear();
        vb.clear();
        hashtable.clear();
        ans.clear();

        for (int i = 0, x; i < n; ++i)
        {
            scanf("%d", &x);
            va.push_back(x);
        }

        scanf("%d", &n);
        for (int i = 0, x; i < n; ++i)
        {
            scanf("%d", &x);
            vb.push_back(x);
            hashtable[x].insert(i);
        }

        for (auto x : va)
        {
            if (hashtable.find(x) != hashtable.end())
            {
                for (auto idx : hashtable[x])
                    ans.insert(idx);
            }
        }

        for (auto iter = ans.begin(); iter != ans.end(); ++iter)
        {
            if (iter != ans.begin())
                printf(" ");
            printf("%d", vb[*iter]);
        }
        puts("");
    }
    return 0;
}