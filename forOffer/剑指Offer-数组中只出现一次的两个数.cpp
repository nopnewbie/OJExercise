class Solution {
    int firstDigitOfOne(int x)
    {
        int cnt = 0;
        while (true)
        {
            if (x & 1)
                break;
            x >>= 1;
            ++cnt;    
        }
        return cnt;
    }
    
    int getPivot(const vector<int> &vi)
    {
        int x = vi.front();
        for (int i = 1; i < vi.size(); ++i)
        {
            x ^= vi[i];
        }
        int cnt = firstDigitOfOne(x);
        return 1 << cnt;
    }
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		const int pivot = getPivot(data);
        *num1 = *num2 = 0;
        for (auto i : data)
        {
            if (i & pivot) 
                *num1 ^= i;
            else 
                *num2 ^= i;
        }
    }
};

/*
	一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序找出这两个只出现一次的数字。
	如果题目改为只有一个数出现了一次，而其他数都出现了两次。那么题目很简单，全部数异或一遍就好了。
	有了上面的基础，本题就有了一种非常简单的方法。
	1. 首先，全部数异或一遍，得到结果。显然，因为只有两个数是只出现一遍，那么结果不为零，且就是这两个只出现一次的数的异或。
	2. 利用1中得到的结果，找出其第一个为1的位。如第n位为1。那么，以此为标准，将原来的数组的元素分为两组。一组第n位为1， 另一组第n位为0。这样就将两个不同的只出现了一次的数分开了。问题转化为简单版本。
*/