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
{//s是本段起始点前驱
	stack<int> st ;
	int p = s, pne ;
	for(int i = 0; i < len; ++i) 
	{
		p = a[p].pne ;
		st.push(p) ;
	}
	pne = a[p].pne ;	//记录本段链表的后继,即下一段链表的起始
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
	{//并非所有节点都在链表上,故链表长度不一定为n
		cin >> addr >> x >> pn ;
		a[addr].data = x ; a[addr].pne = pn; 
	}
	for( pn = st; pn > -1; pn = a[pn].pne ) ++len ;
	a[MAXN].pne = st ; //头结点比较方便
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

