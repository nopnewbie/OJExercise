/*	
	NOI:6263:布尔表达式
	栈练习题
	Start: 2016年2月20日 18:53:27
	Finished: AC!!! 
    !Caution: 像下面这样的用法会使得迭代器失效
        for(auto it = line.begin(); it != line.end(); ++it)
            if(' ' == *it )line.erase(it);
*/
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<stack>
#include<map>
#include<algorithm>
#include<queue>
using namespace std;

map<char, int> priority;
struct Node
{
	bool isop;
	int value;
	char op;
	Node(bool flag = false, int v = 0, char p = 0):isop(flag), value(v), op(p){}
};
queue<Node> q;

void getRePolish(string &str)
{
	stack<Node> stk;	//运算符栈
	for(unsigned i = 0; i < str.size(); )
	{
		Node tmp;
		if('V' == str[i] || 'F' == str[i])
		{
			tmp.isop = false;
			tmp.value = 'V' == str[i] ? 1 : 0;
			q.push(tmp);
			++i;
		}
		else if('(' == str[i]) 
		{
			stk.push(Node(true, 0, '('));
			++i; 
		}
		else if(')' == str[i])
		{
			while(!stk.empty() && stk.top().op != '(') 
            { 
                q.push(stk.top()); 
                stk.pop();
            }
			stk.pop();
			++i;
		}
		else	//符号 | & !
		{
			tmp.isop = true;
			tmp.op = str[i++];
            if(tmp.op != '!' || (!stk.empty() && stk.top().op != '!'))
			    while(!stk.empty() && priority[stk.top().op] >= priority[tmp.op])
                { 
                    q.push(stk.top()); 
                    stk.pop(); 
                }
			stk.push(tmp);
		}
	}
	while(!stk.empty()) 
    { 
        q.push(stk.top()); 
        stk.pop(); 
    }
}

bool calc()
{
	stack<int> stk; //操作数栈
	while(!q.empty() && !q.front().isop) 
    { 
        stk.push(q.front().value); 
        q.pop(); 
    }
	while(!q.empty())
	{
		Node cur = q.front();	q.pop();
		if(cur.isop)	//运算符
		{
			char op = cur.op;
			int a = 0, b = 0;
			if('!' == op)
			{
				b = stk.top(); stk.pop();
				stk.push(!b);
			}
			else
			{
				b = stk.top();	stk.pop();
				a = stk.top();	stk.pop();
				if('&' == op) stk.push(a & b);
				else stk.push(a | b);
			}
		}
		else	stk.push(cur.value);
	}
	return stk.empty() ? false : stk.top();
}

int main()
{
	freopen("F:\\input.txt", "r", stdin);
	string line;
	priority['|'] = 1;
	priority['&'] = 2;
	priority['!'] = 3;
	while( getline(cin, line) )
	{
		while(!q.empty()) q.pop();
        //for (auto it = line.find(' ', 0); it != string::npos; it = line.find(' ', 0))
        //    line.erase(it, 1);
        line.erase(remove(line.begin(), line.end(), ' '), line.end());

		getRePolish(line);
		cout << (calc() ? 'V' : 'F') << endl;
	}
	return 0;
}