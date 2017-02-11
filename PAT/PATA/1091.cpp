/*
	PAT(A):1091. Acute Stroke (30)
	Date: 2016年2月23日 15:39:30
	Finished: 2016年2月23日 18:28:17
*/
#include<iostream>
#include<queue>
using namespace std;

int m, n, l, t, ans;
int Map[61][1287][129];
bool inq[61][1287][129];
int X[] = {-1, 1, 0, 0, 0, 0};
int Y[] = {0, 0, -1, 1, 0, 0};
int Z[] = {0, 0, 0, 0, -1, 1};
struct Node
{
	int x, y, z;
	Node(int _x = 0, int _y = 0, int _z = 0):x(_x), y(_y), z(_z){}
};

bool judge(int x, int y, int z)
{
	if(x >= 0 && x < l && y >= 0 && y < m && z >= 0 && z < n)
		return !inq[x][y][z] && Map[x][y][z];
	else return false;
}

int bfs(int x, int y, int z)
{
	queue<Node> q;
	q.push(Node(x, y, z));
	inq[x][y][z] = true;
	int pix = 0;
	while(!q.empty())
	{
		Node u = q.front(); q.pop();
		++pix;
		for(int i = 0; i < 6; ++i)
		{
			int newX = u.x + X[i];
			int newY = u.y + Y[i];
			int newZ = u.z + Z[i];
			if(judge(newX, newY, newZ))
			{
				q.push(Node(newX, newY, newZ));
				inq[newX][newY][newZ] = true;
			}
		}
	}
	return pix >= t ? pix : 0;
}

int main()
{
#define LOCAL
#ifdef LOCAL
	freopen("F:\\input.txt", "r", stdin);
#endif
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int i = 0; i < l; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < n; ++k) scanf("%d", &Map[i][j][k]);
	for(int i = 0; i < l; ++i)
		for(int j = 0; j < m; ++j)
			for(int k = 0; k < n; ++k) if(!inq[i][j][k] && Map[i][j][k])
			{
				ans += bfs(i, j , k);
			}
	printf("%d\n", ans);
	return 0;
}