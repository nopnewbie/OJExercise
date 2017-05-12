class Solution {
public:
    static vector<int> vi;
    int GetUglyNumber_Solution(int index) {
    	
        if (index <= 5)
            return vi[index - 1];
        int i, j , k;
        while (vi.size() < index)
        {
            for (auto x : vi)
                if ((i = x * 2) > vi.back())
                    break;

            for (auto x : vi)
                if ((j = x * 3) > vi.back())
                    break;

            for (auto x : vi)
                if ((k = x * 5) > vi.back())
                    break;
            vi.push_back(min(i, min(j, k)));
    	}
        return vi[index - 1];
    }
};

vector<int> Solution::vi{1,2,3,4,5};

/*
	若x为丑数，当且仅当 x = (2^a)(3^b)(5^c), 其中a,b,c均为正整数
	保存丑数序列,不断生成下一个丑数，具体规则为：
	1. 分别找到序列中 x2, x3, x5 后大于序列中最大丑数的三个数i,j,k。
	   可以保证i,j,k均为丑数。
	2. i,j,k中最小值即为下一个丑数。
*/