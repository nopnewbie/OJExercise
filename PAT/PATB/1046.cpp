/*
	PAT(B):1046. 划拳(15)
	Date: 2016年2月4日 23:16:43
*/
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;

int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin 
	ifstream fin("F:\\input.txt");
#endif
	int n, x, xx, y, yy, cnt_x = 0, cnt_y = 0;
	for(cin >> n; n; --n)
	{
		cin >> x >> xx >> y >> yy;
		int z = x + y;
		if(xx == z && yy != z) ++cnt_y;	//甲赢,乙喝酒
		if(xx != z && yy == z) ++cnt_x;	//反之
	}
	cout << cnt_x << " " << cnt_y << endl;
	return 0;
}