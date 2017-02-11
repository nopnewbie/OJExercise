/*
	PAT(A):1116. Come on! Let's C (20)
	Started: 2016-12-17 15:48:25
	Finished: 2016-12-17 16:32:25
	Time consuption: 42min
*/

#define DEBUG

#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>

using namespace std;

const int maxn = 10000 + 10;
int n;

struct Data
{
    bool isChecked = false;
    int rank;
    Data(int r = 0) :isChecked(false), rank(r) {}
    
    bool operator < (Data &rhs) const
    {
        return rank < rhs.rank;
    }
};

map<int, Data> idRank;

bool p[maxn];

void init()
{
    idRank.clear();
}

void initPrimeTable()
{
    memset(p, true, sizeof(p));

    int cnt = ceil(sqrt(maxn));
    for (int i = 2; i <= cnt; ++i)
    {
        if (p[i])
        {
            for (int j = i * i; j <= n; j += i)
                p[j] = false;
        }
    }
}

bool isPrime(int x)
{
    return p[x];
}

void read()
{
    int id;
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", &id);
        idRank[id] = Data(i);
    }
}

void query()
{
    int k, id;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i)
    {
        scanf("%d", &id);
      /*  try   // exception catching is time-consuming
        {
            auto &data = idRank.at(id);
            if (data.isChecked)
            {
                printf("%04d: Checked\n", id);
            }
            else if (1 == data.rank)
            {
                printf("%04d: Mystery Award\n", id);
            }
            else if (isPrime(data.rank))
            {
                printf("%04d: Minion\n", id);
            }
            else
            {
                printf("%04d: Chocolate\n", id);
            }
            data.isChecked = true;

        }
        catch (out_of_range e)
        {
            printf("%04d: Are you kidding?\n", id);
        }*/
        auto it = idRank.find(id);
        if (it != idRank.end())
        {
            auto &data = it->second;
            if (data.isChecked)
            {
                printf("%04d: Checked\n", id);
            }
            else if (1 == data.rank)
            {
                printf("%04d: Mystery Award\n", id);
            }
            else if (isPrime(data.rank))
            {
                printf("%04d: Minion\n", id);
            }
            else
            {
                printf("%04d: Chocolate\n", id);
            }
            data.isChecked = true;
        }
        else
        {
            printf("%04d: Are you kidding?\n", id);
        }
    }
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG

    while (~scanf("%d", &n))
    {
        initPrimeTable();

        init();

        read();
        query();
    }
    return 0;
}