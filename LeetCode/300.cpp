/*
	LeetCode: 300. Longest Increasing Subsequence
	Time: 2017-03-17 16:39:20
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> h;
        h.reserve(nums.size());
        
        for (auto i : nums) {
            auto iter = lower_bound(h.begin(), h.end(), i);
            if (iter == h.end()) {
                h.push_back(i);
            }
            else {
                *iter = i;
            }
        }

        return h.size();
    }
};

int main()
{
    freopen("F:\\input.txt", "r", stdin);
    vector<int> vi;
    int i;
    while (cin >> i)
    {
        vi.push_back(i);
    }
    cout << Solution().lengthOfLIS(vi) << endl;

    return 0;
}