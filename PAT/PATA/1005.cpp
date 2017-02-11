/*
	PAT(A): 1005.Spell It Right (20)
*/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
#include<string>

using namespace std ;
int main()
{
	const string num[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" } ;
	vector<int> n ;
	int sum = 0 ;
	string str ;
	cin >> str ;
	for_each(str.begin(), str.end(), [&sum](char d){sum += d-'0';} ) ;
	do
	{
		n.push_back(sum%10) ;
		sum/=10 ;
	}while(sum) ;
	reverse(n.begin(), n.end()) ;
	cout << num[n[0]] ;
	for_each(n.begin()+1, n.end(), [&num](int i){ cout << ' ' << num[i] ; }) ;
	cout << endl ;
	return 0 ;
}