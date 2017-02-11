#define DEBUG

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>

using namespace std;

const int MAXN = 101;
int k;
int cnt[128];
bool isStucked[128];
bool isGotten[128];

void init()
{
    for (int i = 0; i < 128; ++i)
    {
        isGotten[i] = false;
        isStucked[i] = true;
        cnt[i] = MAXN;
    }
}


int main()
{
#ifdef DEBUG
#define cin fin
    ifstream fin("F:\\input.txt");
#endif
    string inStr;
    while (cin >> k)
    {
        init();
        cin.get();  //吃掉首行空格
        getline(cin, inStr);
        //统计字符连续出现次数
        int cntChar = 1;
        char priorChar = inStr[0]; //题目已保证字符串非空
        for (unsigned i = 1; i < inStr.size(); ++i)
        {
            if (priorChar == inStr[i])
            {
                ++cntChar;
            }
            else
            {
                if (cntChar < k || (cntChar % k))
                    isStucked[priorChar] = false;
                cntChar = 1;
                priorChar = inStr[i];
            }
        }
        if (cntChar < k || (cntChar % k))
            isStucked[priorChar] = false;

        string ansChars, ansStr;
        for (unsigned i = 0; i < inStr.size();)
        {
            ansStr.push_back(inStr[i]);
            if (isStucked[inStr[i]])
            {
                if (!isGotten[inStr[i]]) //未添加过,则添加之
                {
                    ansChars.push_back(inStr[i]);
                    isGotten[inStr[i]] = true;
                }
                i += k; //移动到非重复的后一位字符
            }
            else
            {
                ++i;
            }
        }

        cout << ansChars << endl << ansStr << endl;

    }
	return 0;
}