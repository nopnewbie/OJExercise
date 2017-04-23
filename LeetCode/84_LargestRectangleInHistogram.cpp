#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
    int maxRect = 0;
    stack<int> idxStack;
    void updateMaxRect(int upperBound, const vector<int> &h)
    {
        int cur = 0, top = idxStack.top();
        idxStack.pop();
        if (idxStack.empty())
            cur = upperBound * h[top];
        else
        {
            cur = (upperBound - idxStack.top() - 1) * h[top];
        }
        maxRect = max(maxRect, cur);
    }
    void init() 
    {
        maxRect = 0;
        while (!idxStack.empty())
        {
            idxStack.pop();
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty()) return 0;
        init();
        for (int i = 0; i < heights.size(); )
        {
            while (i < heights.size() && (idxStack.empty() || heights[i] > heights[idxStack.top()]))
                idxStack.push(i++);
            while (i < heights.size() && !idxStack.empty() && heights[i] <= heights[idxStack.top()])
                updateMaxRect(i, heights);
            if (i < heights.size()) idxStack.push(i++);
        }
        while (!idxStack.empty())
            updateMaxRect(heights.size(), heights);
        return maxRect;
    }
};

int main()
{
    vector<int> vi{ 2,1,5,6,2,3 };
    Solution s;
    cout << s.largestRectangleArea(vi);
}