#define DEBUG

#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

struct Record
{
    string fullName;
    int lineNo;
    int count = 1;

    Record(const string& name, const int _lineNo) :fullName(name), lineNo(_lineNo) {}


    bool operator==(const Record& rhs) const 
    {
        return fullName == rhs.fullName && lineNo == rhs.lineNo;
    }

    

};



string fileName;
int lineNo;

inline string simplifyName(const string &name)
{
    auto it = name.find_last_of('\\');
    if (string::npos == it)
        return name;
    else
    {
        return name.substr(it + 1);
    }
}

inline string shortenName(const string &name)
{
    int offset = name.size() > 16 ? name.size() - 16 : 0;
    return name.substr(offset);
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    vector<Record> records;
    while (cin >> fileName >> lineNo)
    {

        Record tmp(simplifyName(fileName), lineNo);
        auto it = find(records.begin(), records.end(), tmp);
        if (it == records.end())
            records.push_back(tmp);
        else
            ++it->count;
    }

    stable_sort(records.begin(), records.end(), [](const Record& lhs, const Record& rhs) ->bool
    {
        return lhs.count > rhs.count;
    });

    for (int i = 0; i < 8 && i < records.size(); ++i)
    {
        const auto& r = records[i];
        cout << shortenName(r.fullName) << " " << r.lineNo << " " << r.count << endl;
    }
    return 0;
}