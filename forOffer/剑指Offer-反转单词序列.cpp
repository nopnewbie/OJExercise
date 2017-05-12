class Solution {
    void reverse(string &str, int l, int r)
    {
        while (l < r)
        {
            swap(str[l], str[r]);
            ++l;
            --r;
        }
    }
public:
    string ReverseSentence(string str) {
        reverse(str, 0, str.size() - 1);
        int l = 0, i = 0;
        while (i < str.size())
        {
            if (str[i] == ' ')
            {
                reverse(str, l, i - 1);
                l = i + 1;
            }
            ++i;
        }
        reverse(str, l, i - 1);	// 末尾非空格的特殊处理
        return str;
    }
};