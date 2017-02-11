/*
	PAT(A): 1074.Reversing Linked List (25)
*/

#include<iostream>
#include<fstream>
#include<stack>

#define cin fin

using namespace std ;

int n, k , st;
const int MAXN = 100000 + 5 ;
struct Node
{
	int data ;
	int pre, pne ;
} a[MAXN];

int LinkReverse( int s, int len )
{//s�Ǳ�����ʼ��ǰ��
	stack<int> st ;
	int p = s, pne ;
	for(int i = 0; i < len; ++i) 
	{
		p = a[p].pne ;
		st.push(p) ;
	}
	pne = a[p].pne ;	//��¼��������ĺ��,����һ���������ʼ
	a[s].pne = st.top() ;		st.pop() ;
	while(!st.empty())
	{
		a[p].pne = st.top() ; st.pop() ; 
		p = a[p].pne ;
	}
	a[p].pne = pne ;
	return p ;
}

int main()
{
	int addr, x, pn, len = 0 ;
	ifstream fin("F:\\input.txt") ;
	cin >> st >> n >> k ;
	for( int i = 0 ; i < n; ++i )
	{//�������нڵ㶼��������,�������Ȳ�һ��Ϊn
		cin >> addr >> x >> pn ;
		a[addr].data = x ; a[addr].pne = pn; 
	}
	for( pn = st; pn > -1; pn = a[pn].pne ) ++len ;
	a[MAXN].pne = st ; //ͷ���ȽϷ���
	pn = MAXN ;
	for( int i = 0; i < len/k; ++i )
	{
		pn = LinkReverse(pn, k) ;
	}
	pn = a[MAXN].pne ;
	while( pn > -1 )
	{
		printf("%05d %d ", pn, a[pn].data ) ;
		if(a[pn].pne > -1) printf("%05d\n", a[pn].pne) ;
		else printf("%d\n", a[pn].pne) ;
		pn = a[pn].pne ;
	}
	return 0 ;
}

