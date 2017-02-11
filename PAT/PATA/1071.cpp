/*
	PAT(A):1071. Speech Patterns (25)
	Date: 2016年2月14日 08:59:07
*/
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstring>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
#endif
	map<string, int> word_count;
	string line;
	getline(cin, line);
	for(unsigned i = 0; i < line.size(); )
	{
		string tmp;
		while(i < line.size() && ( isdigit(line[i]) || isalpha(line[i]) ) )
			tmp.push_back(tolower(line[i++]) );
		if(!tmp.empty()) ++word_count[tmp];
		while(i < line.size() && !isdigit(line[i]) && !isalpha(line[i]) ) ++i;
	}
	auto it_max = word_count.begin();
	for(auto i = word_count.begin(); i != word_count.end(); ++i)
	{
		if(i->second > it_max->second)  it_max = i;
	}
	cout << it_max->first << " " << it_max->second << endl;

	return 0;
}