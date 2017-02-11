#include<iostream>
#include<map>
#include<string>
#include<set>
#include<vector>
#include<utility>
using namespace std;

int main()
{
	multimap<string, string> family;
	string surname, name;
	while (cin >> name >> surname)	family.insert({ surname, name });
	for (auto &i : family) cout << i.first << "'s child " << i.second << endl;
	for (auto i = family.equal_range("Ma"); i.first != i.second; ++i.first) //family.erase(i.first);
		cout << i.first->second;
//	auto pos = family.equal_range("Ma");
//	family.erase(pos.first, pos.second);
	cout << "Now these families has been lefted." << endl;
	for (auto &i : family) cout << i.first << "'s child " << i.second << endl;
	return 0;
}