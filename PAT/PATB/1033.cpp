/*
	PAT(B):1033. 旧键盘打字(20)
	Date: 2016年1月31日 13:54:50
*/
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<algorithm>
#include<fstream>
using namespace std;

bool isBad[128] = {false};

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	string badKey, str, ans;
	getline(cin, badKey); 
	getline(cin, str);
	for(int i = 0; i < badKey.size(); ++i ) isBad[toupper(badKey[i])] = isBad[tolower(badKey[i])] = true;
	for(int i = 0; i < str.size(); ++i)
		if(isBad[str[i]] || ( ( isupper(str[i]) && isBad['+'] ) ) || '+' == str[i] ) continue;
		else	putchar(str[i]);
	putchar('\n');
	return 0;
}