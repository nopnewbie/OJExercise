/*
	PAT(A):1022. Digital Library (30)
	Date: 2016年2月14日 09:33:49
*/
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	vector<multimap<string, string> > vmap(5);
	int n, m;
	for(cin >> n; n; --n)
	{
		string line, id;
		cin >> id;	cin.get();
		for(int i = 0; i < 5; ++i)
		{
			getline(cin, line);
			if(i != 2 ) 
			{
				vmap[i].insert( make_pair(line, id) );
			}
			else
			{
				char str[100], *pch, keyword[11];
				strcpy(str, line.c_str() );
				pch = strtok(str, " ");
				while(pch != NULL)
				{
					sprintf(keyword, "%s", pch);
					vmap[2].insert( make_pair(string(keyword), id) );
					pch = strtok(NULL, " ");
				}
			}
		}
	}
	for(cin >> m; m; --m)
	{
		int no;
		string s;
		cin >> no; cin.get(); cin.get();
		getline(cin, s);
		auto pos = vmap[no - 1].equal_range(s);
		cout << no << ": " << s << endl;
		vector<string> bookid;
		for(auto pos = vmap[no - 1].equal_range(s); pos.first != pos.second; ++pos.first ) bookid.push_back(pos.first->second);
		if(bookid.empty()) cout << "Not Found" << endl;
		else
		{
			sort(bookid.begin(), bookid.end());
			for(auto it = bookid.begin(); it != bookid.end(); ++it ) cout << (*it) << endl;
		}
	}
	return 0;
}