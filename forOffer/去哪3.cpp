#define DEBUG
#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

typedef string Node;

struct Edge
{
    Node from, to;
    int dist;
};

const int INF = 100000;
map<Node, vector<Edge>> G;
map<Node, int> dist;
set<Node> nodes;
set<Node> vis;
string src, des;

bool isConnect(const Node &u, const Node &v)
{
    int cnt = max(u.size(), v.size());
    for (size_t i = 0; i < u.size() && v.size(); ++i)
    {
        if (u[i] == v[i])
            --cnt;
    }
    return cnt <= 1;
}

int bfs()
{
    vis.clear();
    queue<Node> q;
    q.push(src);
    for (const auto &n : nodes) dist[n] = INF;
    dist[src] = 1;
    while (!q.empty())
    {
        Node u = q.front();
        q.pop();
        const auto &edges = G[u];
        for (const auto &e : edges)
        {
            const Node &v = e.to;
            if (vis.find(v) != vis.end()) continue;
            vis.insert(v);
            q.push(v);
            dist[v] = min(dist[v], dist[u] + e.dist);
        }
    }
    return dist[des];
}

int main(int argc, char * * argv) 
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    cin >> src >> des;
    nodes.insert(src), nodes.insert(des);
    
    string str;
    while (cin >> str) nodes.insert(str);
    for (const auto &i : nodes)
        for (const auto &j : nodes)
        {
            if (i == j || !isConnect(i, j)) continue;
            G[i].push_back({ i,j,1 });
        }

    printf("%d\n", bfs());
    return 0;
}