#define DEBUG
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void percolateDown(vector<int> &vi, int rootPos, int heapSize)
{
    int maxChild, i;
    int tmp = vi[rootPos];
    for (i = rootPos; i * 2 + 1 < heapSize; i = maxChild)
    {
        maxChild = i * 2 + 1;
        if (maxChild + 1 < heapSize && vi[maxChild] < vi[maxChild + 1])
            ++maxChild; // 指向最大孩子
        if (tmp < vi[maxChild])
            vi[i] = vi[maxChild];
        else
            break;
    }
    vi[i] = tmp;
}

void buildHeap(vector<int> &vi, int begin, int end)
{
    for (int i = (end - 1) / 2; i >= 0; --i)
    {
        percolateDown(vi, i, end);
    }
}

void heapSort(vector<int> &vi)
{
    buildHeap(vi, 0, vi.size());
    for (int size = vi.size()-1; size > 0; --size)
    {
        swap(vi[0], vi[size]);
        percolateDown(vi, 0, size);
    }
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
        int tmp;
        while (n--)
        {
            scanf("%d", &tmp);
            vi.push_back(tmp);
        }
        heapSort(vi);
        if (!vi.empty())
        {
            auto iter = vi.cbegin();
            printf("%d", *iter++);
            while (iter != vi.cend())
            {
                printf(" %d", *iter++);
            }
            puts("");
        }
    }
    return 0;
}