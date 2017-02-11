/*
	PAT(B):1031. 查验身份证(15)
	Date: 2016年1月31日 11:54:37
*/
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>
#include<cctype>
using namespace std;
const int weight[] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char z[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
#define LOCAL
#ifdef LOCAL
#define cin fin
	ifstream fin("F:\\input.txt");
	freopen("F:\\input.txt", "r", stdin);
#endif
	int n;
	bool allpass = true;
	string id;
	for( cin >> n; n; --n)
	{
		int _z = 0;
		cin >> id;
		for( int i = 0; i < 17; ++i )
		{
			if( isdigit(id[i]) )
			{
				_z = ( _z + weight[i] * (id[i] - '0') ) % 11;
			}
			else
			{
				allpass = false;
				cout << id << endl;
				_z = -1;	break;
			}
		}
		if( _z >= 0 && z[_z % 11] != id.back() ) { cout << id << endl; allpass = false;}
	}
	if(allpass) cout << "All passed" << endl;
	return 0;
}