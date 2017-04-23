/*
    NOI:6263.布尔表达式求值
    Time: 2016年10月10日 21:27:18
    Ps: 直接求值
*/
#include<iostream>
#include<string>
#include<stack>
using namespace std;

string line;

bool calc()
{
    return false;
}

void removeSpace()
{
    for (auto i = line.begin(); i != line.end(); ++i)
        if (' ' == *i) line.erase(i);
}

int main()
{
    while (getline(cin, line))
    {
        
        cout << (calc() ? 'V' : 'F') << endl;
    }
    return 0;
}