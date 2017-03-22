#define DEBUG

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

typedef pair<int, int> PII;
map<int, PII> memMap;
int handler = 0;
int n, m;

void delOp(const int handler)
{
    if (handler < 1)
    {
        cout << "ILLEGAL_OPERATION" << endl;
        return;
    }

    const auto iter = memMap.find(handler);
    if (iter == memMap.end())
    {
        cout << "ILLEGAL_OPERATION" << endl;
    }
    else
    {
       memMap.erase(iter);
    }
}

struct cmp
{
    bool operator()(const pair<int, PII> &lhs, const pair<int, PII> &rhs)
    {
        return lhs.second.first < rhs.second.first;
    }
};

void defOp()
{
    vector<pair<int, PII>> block2Handler(memMap.cbegin(), memMap.cend());
    sort(block2Handler.begin(), block2Handler.end(), cmp());
    int preBlockEnd = 1;
    for (const auto &item : block2Handler)
    {
        const int h = item.first;
        int curBlockBegin = item.second.first, curBlockEnd = item.second.second;
        int len = curBlockEnd - curBlockBegin;
        memMap[h].first = preBlockEnd;
        memMap[h].second = preBlockEnd + len;
        preBlockEnd += len;
    }
}

void newOp(const int memSize)
{
    if (memSize < 0 || memSize > m)
    {
        cout << "NULL" << endl;
        return;
    }

    bool flag = false;

    if (memMap.empty())
    {
        memMap.emplace(++handler, PII(1, 1 + memSize));
        flag = true;
    }
    else
    {
        vector<pair<int, PII>> memBlock(memMap.cbegin(), memMap.cend());
        sort(memBlock.begin(), memBlock.end(), cmp());

        int preBlockEnd = 1;
        for (const auto &block : memBlock)
        {
            int h = block.first;
            int len = block.second.first - preBlockEnd;
            if (len >= memSize)
            {
                flag = true;
                memMap.emplace(++handler, PII(preBlockEnd, preBlockEnd + memSize));
                break;
            }
            preBlockEnd = block.second.second;
        }
        if (!flag && memSize <= m + 1 - preBlockEnd)
        {
            flag = true;
            memMap.emplace(++handler, PII(preBlockEnd, preBlockEnd + memSize));
        }
    }

    if (flag)
        cout << handler << endl;
    else
        cout << "NULL" << endl;

}

void processOperation(const string &op)
{
    if ("del" == op)
    {
        int handler;
        cin >> handler;
        delOp(handler);
    }
    else if ("def" == op)
    {
        defOp();
    } 
    else
    {
        int memSize;
        cin >> memSize;
        newOp(memSize);
    }
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    
    while (cin >> n >> m)
    {
        memMap.clear();
        handler = 0;
        string op;
        for (int i = 0; i < n; ++i)
        {
            cin >> op;
            processOperation(op);
        }
    }

    return 0;
}