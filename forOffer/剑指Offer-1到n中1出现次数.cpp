class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
    	const int num = n;
        int div = 1, mod = 1;
        int cnt = 0;
        while (n)
        {
            int left = num / div / 10;
            int curDigit = num /  div % 10;
            int right = num % mod;
            
            if (curDigit > 1)
                cnt += (left + 1) * div;
            else if (curDigit == 1)
                cnt += left * div + right + 1;
            else 
                cnt += left * div;
                
            mod *= 10;
            div *= 10;
            n /= 10;
        }
        
        return cnt;
    }
};

/*
	分别统计每一位上"1"出现的次数。可将数字分成三个部分。
	某位左侧代表这个循环体出现了几次，右侧代表这个体中1出现了多少遍，如:30143:
	由于3>1,则个位上出现1的次数为(3014+1)*1
	由于4>1,则十位上出现1的次数为(301+1)*10
	由于1=1，则百位上出现1次数为(30+0)*100+(43+1)
	由于0<1，则千位上出现1次数为(3+0)*1000
*/