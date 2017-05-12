#define DEBUG
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <fstream>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int ans, cnt = 0;
        for (auto i : numbers) {
            if (!cnt) {
                ans = i;
                cnt = 1;
            }
            else if (ans == i) {
                ++cnt;
            }
            else {
                --cnt;
            }
        }
        cnt = 0;
        for (auto i : numbers) {
            if (i == ans) ++cnt;
        }
        return cnt > numbers.size()/2 ? ans : 0;
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