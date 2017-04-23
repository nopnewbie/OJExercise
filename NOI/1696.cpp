/*	
	NOI:1696:逆波兰表达式
	栈练习题
	Start: 2016年2月20日 15:52:53
	Finished:2016年2月20日 18:53:11
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<stack>
#include<fstream>
#include<string>
#include<sstream>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	string s;
	while( getline(cin, s) )
	{
		char str[100] = {0};
		stack<double> num;
		stack<string> in;
		stringstream line(s);
		while(line >> s) in.push(s);
		while( !in.empty() )
		{
			sscanf(in.top().c_str(), "%s", str);
			in.pop();
			if( isdigit(str[0]) )	num.push( atof(str) );
			else
			{
				double a = num.top(); num.pop();
				double b = num.top(); num.pop();
				switch(str[0])
				{
				case '+':	
					num.push(a + b);	break;
				case '-':
					num.push(a - b);		break;
				case '*':
					num.push(a * b);		break;
				case '/':
					num.push(a / b);		break;
				}
			}
		}
		printf("%f\n", num.top());
	}
	return 0;
}