#define DEBUG

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <map>
using namespace std;

bool t[128];
string s;



int main()
{
#ifdef DEBUG
	freopen("F:\\input.txt", "r", stdin);
#endif
    while (cin >> s)
    {
        memset(t, false, sizeof(t));
        int ans = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (t[s[i]])
                continue;
            t[s[i]] = true;
            ++ans;
        }
    }
	return 0;
}

