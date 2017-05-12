class Solution {

private:
  	bool divide(const vector<int> &vi, int l, int r)
    {
        if (l >= r) 
            return true;
        
        const int root = vi[r];
        int lEnd = l;
        while (lEnd < r && vi[lEnd] < root)	// 从左至右找到首个大于等于根的元素下标
            ++lEnd;
        for (int i = lEnd; i < r; ++i)	// [lEnd, r)之间的元素应该是右子树
            if (vi[i] < root)
                return false;
        return divide(vi, l, lEnd - 1) && divide(vi, lEnd, r - 1);
    }

public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return sequence.empty() ? false : divide(sequence, 0, sequence.size() - 1);
    }
};