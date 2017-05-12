#include <iostream>
using namespace std;

class Solution {
    int getSpecNum(char* str)
    {
        int cnt = 0;
        while (str && *str != '\0')
        {
            if (*str++ == ' ')
                ++cnt;
        }
        return cnt;
    }
public:
    void replaceSpace(char *str, int length) {
        int expandedLen = strlen(str) + 1 + 2 * getSpecNum(str);
        for (int i = strlen(str) + 1, j = expandedLen; i >= 0; --i)
        {
            if (str[i] != ' ')
                str[j--] = str[i];
            else
            {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%%';
            }
        }
    }
};

int main ()
{
    char str[100] = "We are Happy.";
    Solution s;
    puts(str);
    s.replaceSpace(str, 100);
    puts(str);

    return 0;
}