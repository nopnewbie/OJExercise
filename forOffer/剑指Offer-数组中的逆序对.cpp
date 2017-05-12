class Solution {
    static const int mod = 1000000007;
    int mergeSort(vector<int> &vi, int l, int r, int *tmp)
    {
        if (l >= r)
            return 0;
        
        int mid = l + (r - l) / 2;
        int cnt =  (mergeSort(vi, l, mid, tmp) % mod + mergeSort(vi, mid + 1, r, tmp) % mod) % mod;
        
        int lb = l, rb = mid + 1, pos = l;
        while (lb <= mid && rb <= r)
        {
            if (vi[lb] < vi[rb])
                tmp[pos++] = vi[lb++];
            else // 保证所有元素不同,故不需考虑相等情况
            {
                cnt = (cnt + mid - lb + 1) % mod;
               	tmp[pos++] = vi[rb++];
            }
        }
        
        while (lb <= mid)
        {
            tmp[pos++] = vi[lb++];
        }
        while (rb <= r)
        {
            tmp[pos++] = vi[rb++];
        }
        
        while (l <= r)	// copy back
        {
            vi[l] = tmp[l];
            ++l;
        }
        return cnt;
    }
public:
    int InversePairs(vector<int> data) {
        if (data.size() < 2)
            return 0;
        int *tmp = new int[data.size()];
        int ans = mergeSort(data, 0, data.size()-1, tmp);
        delete[] tmp;
        return ans;
    }
};