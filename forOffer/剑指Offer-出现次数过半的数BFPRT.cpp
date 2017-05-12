/*
    BFPRT�㷨: ��֤�����ȶ�ΪO(n)
    1. ��Ԫ��ÿ5����Ϊһ�飬���ڲ��ţ����һ����ܲ���5��Ԫ�أ�
    2. ȡÿС�����λ���������λ������mArr.
    3. ȡ��λ���������λ�����൱��ȡmArr�ĵ�mArr.size()/2 ��������ʿ��Եݹ�
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
        int size = (end - begin) / 5 + offset;    // ��λ�����鳤��
        for (int i = 0; i < size; ++i)
        {
            int l = begin + i * 5, r = min(end, l + 5);
            insertSort(vi, l, r);
            mArr.push_back(vi[(l + r) / 2]);
        }
        return select(mArr, 0, size, size / 2 - 1); // ѡȡ��λ���������λ��
    }

    // ��vi[begin, end) �������к�λ���±�k�ĵ�Ԫ��, �����k+1С��Ԫ��
    int select(vector<int> &vi, int begin, int end, int k) 
    {
        if (begin == end - 1) 
            return vi[begin];

        int pivot = medianOfMedians(vi, begin, end);       // ��λ������λ����Ϊ��Ԫ
        auto bound = Partition(vi, begin, end, pivot);     // �Ӽ�����
        if (k >= bound.first && k <= bound.second)
        {
            return pivot;
        }
        else if (k < bound.first)
            return select(vi, begin, bound.first, k);   // ���
        else
            return select(vi, bound.second + 1, end, k); // �ұ�
    }

    pair<int, int> Partition(vector<int> &vi, int begin, int end, int pivot)
    {
        int small = begin - 1;  // [begin, small] ��Ϊ��pivotС��Ԫ��
        int cur = begin;        // (small, cur] ֮���Ԫ�ص���pivot
        int big = end;          // [big, end)֮���Ԫ�ؾ�����pivot
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