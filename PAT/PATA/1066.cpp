/*
	PAT(A): 1066. Root of AVL Tree (25)
*/
#include<iostream>
#include<fstream>

using namespace std ;

typedef struct AvlNode
{
	int data ;
	int height ;
	AvlNode *lchild, *rchild ;
} *AvlTree, *Position ;

int Height( AvlTree &T ) ;
bool isBalanced( AvlTree & T ) ;
AvlTree RR( AvlTree &T ) ;
AvlTree RL( AvlTree &T ) ;
AvlTree LL( AvlTree &T ) ;
AvlTree LR( AvlTree &T ) ;
AvlTree Insert( AvlTree &T, int x ) ;

int N ;
int main()
{
#define cin fin
	ifstream fin( "F:\\input.txt" ) ;
	cin >> N ;
	AvlTree T = NULL ;
	int x ;
	for( int i = 0; i < N; ++i )
	{
		cin >> x ;	
		T = Insert( T, x ) ;
	}
	cout << T->data << endl ;
	return 0 ;
}

int Height( AvlTree &T )
{
	return T == NULL ? -1 : T->height ;
}

bool isBalanced( AvlTree &T )
{
	return abs( Height( T->lchild ) - Height( T->rchild ) ) < 2 ;
}

AvlTree RR( AvlTree &T )
{//失衡发生在右子树的右子树上
	AvlTree rc = T->rchild ;
	T->rchild = rc->lchild ;
	rc->lchild = T ;
	T->height = max( Height(T->lchild), Height(T->rchild) ) + 1 ;
	rc->height = max( Height(rc->lchild), Height(rc->rchild) ) + 1 ;
	return rc ;
}

AvlTree LL( AvlTree &T )
{//失衡发生在左子树的左边
	AvlTree lc = T->lchild ;
	T->lchild = lc->rchild ;
	lc->rchild = T ;
	T->height = max( Height(T->lchild), Height(T->rchild) ) + 1 ;
	lc->height = max( Height(lc->lchild), Height(lc->rchild) ) + 1 ;
	return lc ;
}

AvlTree RL( AvlTree &T )
{//失衡发生在右子树的左边
	T->rchild = LL( T->rchild ) ;
	return RR( T ) ;
}

AvlTree LR( AvlTree &T )
{//失衡发生在左子树的右边
	T->lchild = RR( T->lchild ) ;
	return LL( T ) ;
}

AvlTree Insert( AvlTree &T, int x )
{
	if( T == NULL )
	{
		T = new AvlNode ;	T->data = x ;
		T->lchild =  T->rchild = NULL ;
		T->height = 0 ;
	}
	else
	{
		if( x < T->data )
		{//插入左子树
			T->lchild = Insert( T->lchild, x ) ;
			if( ! isBalanced( T ) )	//失衡
			{
				if( x < T->lchild->data )	//插在了左子树的左边
					T = LL( T ) ;
				else
					T = LR( T ) ;
			}
		}
		else if( x > T->data )
		{//插入右子树
			T->rchild = Insert( T->rchild, x ) ;
			if( ! isBalanced( T ) )	//失衡
			{
				if( x > T->rchild->data )	//插在了右子树的右边
					T = RR( T ) ;
				else
					T = RL( T ) ;
			}
		}
		//否则说名该节点已经存在
	}
	T->height = max( Height( T->lchild ), Height( T->rchild ) ) + 1 ;
	return T ;
}