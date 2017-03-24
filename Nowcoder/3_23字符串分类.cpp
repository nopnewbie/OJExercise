#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <set>
using namespace std;

set<string> st;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    string str;
    int n;
    while (cin >> n)
    {
        for (int i = 0; i < n; ++i)
        {
            cin >> str;
            sort(str.begin(), str.end(), [](const char a, const char b)->bool {return a < b; });
            st.insert(str);
        }
        cout << st.size() << endl;
    }
	return 0;
}