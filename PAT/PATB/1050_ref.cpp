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

	if(N==1)	//��ֻ����һ����ʱֱ�����
	{
		cout<<A[0]<<endl;
		return 0;
	}

	sort(A,A+N,CMP);	//����
	int m=N,n=1;
	calculate(m,n,N);	//ȷ���к���

	int **B;			
	B=new int*[m+1];		//���붯̬��ά���飬Ҫ��ʵ�ʾ����һ�к�һ�У���ֹ����ķ����ת�ж�
	for(int row=0;row<m+1;row++)	//��������Ĵ�С��Ҳ���ǻᷢ���δ������һ�����Ե㡣
	{
		*(B+row)=new int[n+1];
		for(int col=0;col<n+1;col++)
		{
			*(*(B+row)+col)=0;
		}
	}

	int direct[]={2,-1,-2,1},d=2,posD=0;	//���Ʒ���ģ�2-���ң�-1-���£�-2-����1-���ϡ�
	int x=0,y=0,posA=0;
	
	while(true)
	{
		if(B[x][y]!=0 || (x==m||x<0) || (y==n||y<0) )//�����ת�������߽������һ�����Ѿ�
		{			    //������ˡ�����Լ�ģ��һ��˳ʱ�����������������ˡ�
			posD++;
			switch(d)		//֮ǰ�Ѿ������߽�һ���ˣ�����Ҫ����һ����
			{
			case -1:x--;y--;break;
			case 2: y--;x++;break;
			case 1: x++;y++;break;
			case -2:y++;x--;break;
			}
			d=direct[posD%4];
		}
		B[x][y]=A[posA];posA++;	//����ά����������ݡ�
		if(posA==N)
		{
			break;
		}
		switch(d)	//һֱ�������趨�ķ������ߺ���䡣
		{
		case -1:x++;break;
		case 2: y++;break;
		case 1: x--;break;
		case -2:y--;break;
		}
	}

	for(int h=0;h<m;h++)	//��ӡ���
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
