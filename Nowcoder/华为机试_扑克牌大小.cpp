#define DEBUG

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    return 0;
}