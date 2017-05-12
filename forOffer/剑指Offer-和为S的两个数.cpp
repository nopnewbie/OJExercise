class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        int l = 0, r = array.size() - 1;
        while (l < r)
        {
            if (array[l] + array[r] == sum)
                return {array[l], array[r]};
            else if (array[l] + array[r] > sum )
                --r;
            else 
                ++l;
        }
        return {};
    }
};