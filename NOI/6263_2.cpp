/*
    NOI:6263.�������ʽ��ֵ
    Time: 2016��10��10�� 21:27:18
    Ps: ֱ����ֵ
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