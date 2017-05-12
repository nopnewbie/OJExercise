class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ans;
        int small = 1, big = 2, tmp = small + big;
        
        while (small < big && small < sum / 2 + 1 && big < sum)
        {
            if (tmp == sum)
            {
                vector<int> vi;
                for (int i = small; i <= big; ++i)
                    vi.push_back(i);
                ans.push_back(vi);
                
                tmp -= small++;
            }
            else if (tmp > sum)
                tmp -= small++;
            else
                tmp += ++big;
        }
        return ans;
    } 
};