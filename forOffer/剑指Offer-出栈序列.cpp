class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        stack<int> stk;
        int i = 0, j = 0;
      	while (i < pushV.size())
       	{
            if (pushV[i] == popV[j])
            {
                ++i;
                ++j;
            }
            else if (stk.empty() || stk.top() != popV[j])
            {
                stk.push(pushV[i++]);
            }
            else
	        {
                 while (!stk.empty() && j < popV.size() && stk.top() == popV[j])
                 {
                     stk.pop();
                     ++j;
                 }
            }
        }
        while (!stk.empty() && j < popV.size() && stk.top() == popV[j])
        {
            stk.pop();
            ++j;
        }
        return stk.empty();
    }
};