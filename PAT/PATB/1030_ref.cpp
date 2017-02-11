#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
double v[100005];
int r[10];
int main()
{
	freopen("F:\\input.txt", "r", stdin);
    int n,maxx=0;
    double p;
    scanf("%d%lf",&n,&p);
    for(int i=0;i<n;++i)
        scanf("%lf",&v[i]);
    sort(v,v+n);
    for(int i=0;i<n; i++)
        for(int j=i+maxx-1; j<n; j++)
        {
            if(v[i]*p<v[j])
                break;
            if(j-i+1>maxx)
                maxx =j-i+1;
        }
    printf("%d\n",maxx);
    return 0;
}