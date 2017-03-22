/*
	42. Trapping Rain Water
*/
#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 3)
            return 0;

        int lMax = height.front(), rMax = height.back(), sum = 0;
        auto lIter = height.cbegin(), rIter = --height.cend();
        while (lIter + 1 != rIter)
        {
            if (lMax <= rMax)
            {
                sum += max(0, lMax - *(lIter + 1));
                lMax = max(lMax, *++lIter);
            }
            else
            {
                sum += max(0, rMax - *(rIter - 1));
                rMax = max(rMax, *--rIter);
            }
        }
        return sum;
    }
};

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    int i;
    vector<int> vi;
    while (cin >> i)
    {
        vi.push_back(i);
    }
    cout << Solution().trap(vi) << endl;

    return 0;
}