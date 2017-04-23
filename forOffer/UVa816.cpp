#define DEBUG

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;

const string END = "END";
const int DC[] = { 0, 1, 0, -1 };
const int DR[] = { -1, 0, 1, 0 };

struct Node
{
    int r, c;
    int dir = 0;

    Node walk(int turn) const // 从当前状态向turn所代表的方向走,turn=0,1,2, 分别代表F,L,R
    {
        Node u;
        u.dir = dir;
        if (1 == turn) // 左转,逆时针
            u.dir = (dir + 3) % 4;
        if (2 == turn) // 右转,顺时针
            u.dir = (dir + 1) % 4;
        u.r = r + DR[u.dir];
        u.c = c + DC[u.dir];
        return u;
    }
    bool operator < (const Node &rhs) const
    {
        if (r != rhs.r) return r < rhs.r;
        else if (c != rhs.c) return c < rhs.c;
        else return dir < rhs.dir;
    }
};

Node src, des;
set<Node> nodes;
bool has_edge[11][11][4][3];
int dist[11][11][4];    // 起点到各点的最短距离
Node path[11][11][4];

inline bool isValid(const Node &node)
{
    return nodes.find(node) != nodes.cend();
}

inline void init()
{
    nodes.clear();
    memset(has_edge, false, sizeof(has_edge));
}

void print_path(Node node)
{
    vector<Node> p;
    for (;;)
    {
        p.push_back(node);
        if (dist[node.r][node.c][node.dir] == 0) break;
        node = path[node.r][node.c][node.dir];
    }
    p.push_back(src);

    for (int i = p.size() - 1, cnt = 0; i >= 0; --i)
    {
        if (cnt%10 == 0) printf("  (%d,%d)", p[i].r, p[i].c);
        else printf(" (%d,%d)", p[i].r, p[i].c);
        
        if (++cnt % 10 == 0)    puts("");
    }
    if (p.size() % 10) puts("");
}

void bfs(const Node &s, const Node &dest)
{
    queue<Node> q;
    q.push(s);
    memset(dist, -1, sizeof(dist)); // 初始化距离为无限大
    dist[s.r][s.c][s.dir] = 0;
    while (!q.empty())
    {
        const Node u = q.front(); q.pop();
        if (u.r == dest.r && u.c == dest.c) // 已经找到了到终点的最短路，不用再后续搜索了
        {
            print_path(u);
            return;
        }

        for (int i = 0; i < 3; ++i) // 向前，左,右三个方向尝试
        {
            Node v = u.walk(i);

            if (has_edge[u.r][u.c][u.dir][i] && isValid(v) && dist[v.r][v.c][v.dir] < 0)
            {
                dist[v.r][v.c][v.dir] = dist[u.r][u.c][u.dir] + 1;
                path[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    puts("  No Solution Possible");
}

inline int get_turn(const char turn)
{
    const static char p[] = "FLR";
    return strchr(p, turn) - p;
}

inline int get_dir(const char dir)
{
    const static char p[] = "NESW";
    return strchr(p, dir) - p;
}

int main()
{
#ifdef DEBUG
    freopen("F:\\input.txt", "r", stdin);
#endif // DEBUG
    string mazeName;
    while (cin >> mazeName)
    {
        if (mazeName == END) break;
        init(); // 初始化
        int r0, c0, r1, c1;
        char dir;
        cin >> r0 >> c0 >> dir >> r1 >> c1;
        src.r = r0, src.c = c0, des.r = r1, des.c = c1;
        src.dir = get_dir(dir);
        Node start = src.walk(0);
        
        for (int i = 0; i < 4; ++i)
        {
            des.dir = i;
            nodes.insert(des);
        }

        while (cin >> r0 && r0 != 0)
        {
            string sign;
            cin >> c0;
            Node n;
            n.r = r0, n.c = c0;
            while (cin >> sign && "*" != sign)
            {
                n.dir = get_dir(sign[0]);
                nodes.insert(n);    // 记录所有结点
                auto &egs = has_edge[n.r][n.c][n.dir];
                for (int i = 1; i < sign.size(); ++i)   // 记录通路
                    egs[get_turn(sign[i])] = true;
            }
        }
        puts(mazeName.c_str());
        bfs(start, des);

    }
	return 0;
}