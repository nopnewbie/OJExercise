/*
    BFPRT算法: 保证划分稳定为O(n)
    1. 将元素每5个分为一组，组内插排（最后一组可能不满5个元素）
    2. 取每小组的中位数，组成中位数数组mArr.
    3. 取中位数数组的中位数，相当于取mArr的第mArr.size()/2 大的数。故可以递归
*/

#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <fstream>
#include <utility>
using namespace std;

class Solution {

    int medianOfMedians(vector<int> &vi, int begin, int end) 
    {
        vector<int> mArr;
        int offset = (end - begin) % 5 == 0 ? 0 : 1;
        int size = (end - begin) / 5 + offset;    // 中位数数组长度
        for (int i = 0; i < size; ++i)
        {
            int l = begin + i * 5, r = min(end, l + 5);
            insertSort(vi, l, r);
            mArr.push_back(vi[(l + r) / 2]);
        }
        return select(mArr, 0, size, size / 2 - 1); // 选取中位数数组的中位数
    }

    // 求vi[begin, end) 升序排列后位于下标k的的元素, 即求第k+1小的元素
    int select(vector<int> &vi, int begin, int end, int k) 
    {
        if (begin == end - 1) 
            return vi[begin];

        int pivot = medianOfMedians(vi, begin, end);       // 中位数的中位数作为主元
        auto bound = Partition(vi, begin, end, pivot);     // 子集划分
        if (k >= bound.first && k <= bound.second)
        {
            return pivot;
        }
        else if (k < bound.first)
            return select(vi, begin, bound.first, k);   // 左边
        else
            return select(vi, bound.second + 1, end, k); // 右边
    }

    pair<int, int> Partition(vector<int> &vi, int begin, int end, int pivot)
    {
        int small = begin - 1;  // [begin, small] 均为比pivot小的元素
        int cur = begin;        // (small, cur] 之间的元素等于pivot
        int big = end;          // [big, end)之间的元素均大于pivot
        while (cur < big)
        {
            if (vi[cur] < pivot)
                swap(vi[++small], vi[cur++]);
            else if (vi[cur] > pivot)
                swap(vi[--big], vi[cur]);
            else ++cur;
        }
        return {small+1, big - 1};
    }

    void insertSort(vector<int> &vi, int begin, int end)
    {
        for (int i = begin + 1 , j; i < end; ++i) 
        {
            int tmp = vi[i];
            for (j = i; j > begin; --j)
            {
                if (vi[j - 1] > tmp)
                    vi[j] = vi[j-1];
                else
                    break;
            }
            vi[j] = tmp;
        }
    }

public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty()) return 0;
        if (numbers.size() < 2) return numbers[0];

        int cand = select(numbers, 0, numbers.size(), numbers.size() / 2 - 1);
        int cnt = 0;
        for (auto i : numbers)
            if (i == cand) ++cnt;
        return cnt > numbers.size() / 2 ? cand : 0;
    }
};


int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    int n;
    while (~scanf("%d", &n)) {
        vector<int> vi;
        for (int i = 0, d; i < n; ++i) {
            scanf("%d", &d);
            vi.push_back(d);
        }

        Solution solution;
        printf("result= %d\n", solution.MoreThanHalfNum_Solution(vi));
        sort(vi.begin(), vi.end());
        for (auto i : vi) {
            printf("%d ", i);
        }
        puts("");
    }
	return 0;
}