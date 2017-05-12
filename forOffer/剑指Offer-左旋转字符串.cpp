class Solution {
    void reverse(string &str, int l, int r)
    {
        while (l < r)
        {
            swap(str[l], str[r]);
            ++l, --r;
        }
    }
public:
    string LeftRotateString(string str, int n) {
        reverse(str, 0, str.size() - 1);
        reverse(str, 0, str.size() - 1 - n);
        reverse(str, str.size() - n, str.size() - 1);
        return str;
    }
};