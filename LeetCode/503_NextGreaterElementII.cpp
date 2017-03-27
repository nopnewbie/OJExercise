#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        map<int, int> mp;
        stack<int> stk;
        size_t size = nums.size() << 1;
        for (size_t i = 0; i < size; ++i)
        {
            auto idx = i % nums.size();
            while (!stk.empty() && nums[idx] > nums[stk.top()])
            {
                mp[stk.top()] = nums[idx];
                stk.pop();
            }
            stk.push(idx);
        }
        for (size_t i = 0; i < nums.size(); ++i)
        {
            auto nextG = mp.find(i);
            if (nextG == mp.end())
                nums[i] = -1;
            else
                nums[i] = nextG->second;
        }
        return nums;

    }
};

int main()
{
    freopen("F:\\input.txt", "r", stdin);
    vector<int> vi{ 1,2,1 };
    for (auto i : Solution().nextGreaterElements(vi))
    {
        cout << i << " ";
    }
    return 0;
}