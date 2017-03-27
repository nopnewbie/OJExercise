#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    stack<int> stk;
    string str;
    while (cin >> str)
    {
        int num1 = 0, num2 = 0, i = 0;
        char op;
        while (i < str.size() && isdigit(str[i]))
        {
            num1 = num1 * 10 + str[i++] - '0';
        }
        while (i < str.size())
        {
            num2 = 0;
            op = str[i++];
            while (i < str.size() && isdigit(str[i]))
            {
                num2 = num2 * 10 + str[i++] - '0';
            }
            switch (op)
            {
            case '+':
                num1 += num2;
                break;

            case '-':
                num1 -= num2;
                break;

            case '*':
                num1 *= num2;
                break;

            default:
                break;
            }
        }
        printf("%d\n", num1);
    }
	return 0;
}