class Solution {
    int upbound(const vector<int> &vi, int k)
    {
        int l = 0, r = vi.size(), mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            if (vi[mid] <= k)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    
    int lowbound(const vector<int> &vi, int k)
    {
        int l = 0, r = vi.size(), mid;
        while (l  < r)
        {
            mid = l + (r - l) / 2;
            if (vi[mid] < k)
                l = mid + 1;
            else 
                r = mid;
        }
        return l;
    }
    
public:
    int GetNumberOfK(vector<int> data ,int k) {
        return upbound(data, k) - lowbound(data, k);
    }
};