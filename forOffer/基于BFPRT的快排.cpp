#define DEBUG
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int select(vector<int>::iterator begin, vector<int>::iterator end, size_t kth);

void InsertSort(vector<int>::iterator begin, vector<int>::iterator end)
{
    for (auto i = begin + 1; i != end; ++i)
    {
        int tmp = *i;
        decltype(i) j = i;
        for (/*none*/ ; j != begin; --j)
        {
            if (*(j - 1) > tmp)
                *j = *(j - 1);
            else
                break;
        }
        *j = tmp;
    }
}


int getMedian(vector<int>::iterator begin, vector<int>::iterator end)
{
    InsertSort(begin, end);
    size_t mid = (end - begin) / 2;
    return *(begin + mid);
}

int getPivot(vector<int>::iterator begin, vector<int>::iterator end)
{
    size_t size = end - begin;
    if (size < 3) 
        return *begin;
    vector<int> mArr{ *begin, *(begin + size / 2), *(begin + size - 1) };
    InsertSort(mArr.begin(), mArr.end());
    return mArr[1];

    //if (begin + 1 == end)
    //    return *begin;

    //const static int SUB_SIZE = 5;
    //vector<int> mArr;
    //size_t size = (end - begin) / 5 + ((end - begin) % 5 != 0);
    //for (size_t i = 0; i < size; ++i)
    //{
    //    auto l = begin + i * 5, r = ((end - l) < 5 ? end : (l + 5));
    //    mArr.push_back(getMedian(l, r));
    //}
    //return select(mArr.begin(), mArr.end(), mArr.size() / 2 - 1);
}

pair<size_t, size_t> Partition(vector<int>::iterator begin, vector<int>::iterator end, int pivot)
{
    auto small = begin, cur = begin, big = end;
    while (cur != big)
    {
        if (*cur < pivot)
            swap(*small++, *cur++);
        else if (*cur > pivot)
            swap(*--big, *cur);
        else
            ++cur;
    }
    return { small - begin, big - begin };
}

int select(vector<int>::iterator begin, vector<int>::iterator end, size_t kth)
{
    if (begin + 1 == end)
        return *begin;

    int pivot = getPivot(begin, end);
    pair<size_t, size_t> bound = Partition(begin, end, pivot);
    if (kth >= bound.first && kth <= bound.second)
        return pivot;
    else if (kth < bound.first)
        return select(begin, begin + bound.first, kth);
    else
        return select(begin + bound.second, end, kth);
}

void QuickPass(vector<int>::iterator begin, vector<int>::iterator end)
{
    if (begin == end || begin + 1 == end)
        return;
    int pivot = getPivot(begin, end);
    pair<size_t, size_t> bound = Partition(begin, end, pivot);
    if (bound.first != 0)QuickPass(begin, begin + bound.first);
    if (bound.second != end - begin) QuickPass(begin + bound.second, end);
}

void QuickSort(vector<int>::iterator begin, vector<int>::iterator end)
{
    const static int INSERT_SIZE = 1000;
    size_t size = end - begin;
    if (size <= INSERT_SIZE)    // 规模太小，直接插排
        return InsertSort(begin, end);
    
    QuickPass(begin, end);
}


int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    int n;
    while (~scanf("%d", &n)) 
    {
        vector<int> vi;
        vi.reserve(n);
        int i;
        while (n--)
        {
            scanf("%d", &i);
            vi.push_back(i);
        }
        QuickSort(vi.begin(), vi.end());
        auto iter = vi.begin();
        if (iter != vi.end())
        {
            printf("%d", *iter++);
            while (iter != vi.end())
            {
                printf(" %d", *iter++);
            }
            puts("");
        }
    }
    return 0;
}