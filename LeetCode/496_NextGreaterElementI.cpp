/*
	用stack记录前缀递减序列，遇到升序，则将这些递减序列全部弹出；
	并将他们的"NextGreaterNum"记录为升序数字。
	遍历一遍数组，即可得到答案。
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> stk;
        map<int, int> mp;
        for (const auto i : nums)
        {
            while (!stk.empty() && i > stk.top())
            {
                mp[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for (int i = 0; i < findNums.size(); ++i)
        {
            auto iter = mp.find(findNums[i]);
            findNums[i] = iter == mp.end() ? -1 : iter->second;
        }
        return findNums;
    }
};