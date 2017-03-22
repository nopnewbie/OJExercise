/*
	LeetCode: 354.Russian Doll Envelopes
	Time: 2017-03-16 22:45:43
*/
#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

class Solution 
{
    typedef pair<int, int> PII;
    
    vector<int> h;

    static bool sortOrder(const PII &lhs, const PII &rhs)
    {
        if (lhs.first != rhs.first)
        {
            return lhs.first < rhs.first;
        }
        else
        {
            return lhs.second > rhs.second;
        }
    }



public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) 
    {
        if (envelopes.size() < 2)
            return envelopes.size();

        h.clear();
        h.reserve(envelopes.size());

        sort(envelopes.begin(), envelopes.end(), sortOrder);

        for (const auto &item : envelopes)
        {
            auto it = lower_bound(h.begin(), h.end(), item.second);
            if (it != h.end())
            {
                if (item.second < *it)
                {
                    *it = item.second;
                }
            }
            else if (h.empty() || h.back() < item.second)
            {
                h.emplace_back(item.second);
            }
        }

        return h.size();
    }
};

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    vector<pair<int, int>> envelopes;
    int x, y;
    while (cin >> x >> y)
    {
        envelopes.emplace_back(x, y);
    }
    cout << Solution().maxEnvelopes(envelopes) << endl;

    return 0;
}

