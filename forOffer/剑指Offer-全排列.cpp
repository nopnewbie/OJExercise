#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

class Solution {
    void permute(string &str, int cur, set<string> &out)
    {
        if (cur == str.size())
            out.insert(str);
        else
        {
            for (int i = cur; i < str.size(); ++i)
            {
                swap(str[i], str[cur]);
                permute(str, cur + 1, out);
                swap(str[i], str[cur]);
            }
        }
    }
public:
    vector<string> Permutation(string str) {
        if (str.empty())
            return vector<string>();
        set<string> ans;
        permute(str, 0, ans);
        return vector<string>(ans.begin(), ans.end());
    }
};

int main()
{
    Solution s;
    auto ans = s.Permutation("abc");
    for (const auto &s : ans )
    {
        cout << s << endl;
    }
    return 0;
}