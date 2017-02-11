#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int main()
{
	void calculate(int &m,int &n,int N);
	bool CMP(int a,int b);
	int N;
	int A[10002];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
	}

	if(N==1)	//当只输入一个数时直接输出
	{
		cout<<A[0]<<endl;
		return 0;
	}

	sort(A,A+N,CMP);	//排序
	int m=N,n=1;
	calculate(m,n,N);	//确定行和列

	int **B;			
	B=new int*[m+1];		//申请动态二维数组，要比实际矩阵大一行和一列，防止下面的方向调转判断
	for(int row=0;row<m+1;row++)	//超过矩阵的大小，也就是会发生段错误，最后一个测试点。
	{
		*(B+row)=new int[n+1];
		for(int col=0;col<n+1;col++)
		{
			*(*(B+row)+col)=0;
		}
	}

	int direct[]={2,-1,-2,1},d=2,posD=0;	//控制方向的，2-向右，-1-向下，-2-向左，1-向上。
	int x=0,y=0,posA=0;
	
	while(true)
	{
		if(B[x][y]!=0 || (x==m||x<0) || (y==n||y<0) )//方向调转，碰到边界或者下一个数已经
		{			    //填过数了。大家自己模拟一下顺时针螺旋这个过程理解了。
			posD++;
			switch(d)		//之前已经超过边界一格了，所以要回退一步。
			{
			case -1:x--;y--;break;
			case 2: y--;x++;break;
			case 1: x++;y++;break;
			case -2:y++;x--;break;
			}
			d=direct[posD%4];
		}
		B[x][y]=A[posA];posA++;	//往二维数组填充数据。
		if(posA==N)
		{
			break;
		}
		switch(d)	//一直往上面设定的方向行走和填充。
		{
		case -1:x++;break;
		case 2: y++;break;
		case 1: x--;break;
		case -2:y--;break;
		}
	}

	for(int h=0;h<m;h++)	//打印结果
	{
		for(int l=0;l<n;l++)
		{
			cout<<B[h][l];
			if(l!=n-1)
			{
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}

void calculate(int &m,int &n,int N)
{
	int a=m,b,c;
	while(true)
	{
		a--;
		b=N%a;
		c=N/a;
		if(b==0)
		{
			if(a<c)
			{
				break;
			}
			m=a;
			n=c;
		}
	}
}

bool CMP(int a,int b)
{
	if(a>b){return true;}
	else{return false;}
}
