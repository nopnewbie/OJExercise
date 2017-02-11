/*
众数问题，从m * n个数中找出出现多于一半的数——保证存在。
本质： 同时删掉两个不同的数，众数不变。 于是我们随便记录一个数x， 来一个数 y， 和x不同的话就把x ,y都扔了，相当于扔掉两个不同的数，和x相同的话，就把计数器加1。
所以操作简化为
（1） x出现次数的计数器加1
（2） x出现次数的计数器减1
ps:
	因为题目保证众数超过所有数的一半。假设众数为x，则将输入的数可以分为众数x和非众数y两类。因为x大于一半，所以同时扔掉一个x和y到最后必然剩下x。
*/

#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main() {
int m,n,answer;
    scanf("%d%d",&m,&n);
    for (int i = m * n, time = 0; i; --i) {
        int x;
        scanf("%d",&x);
        if (time == 0) {
            answer = x;
        }
        if (x == answer) {
            ++time;
        }
        else {
            --time;
        }
    }
    printf("%d\n",answer);
    return 0;
}