/*
	²Î¿¼
	PAT(A)1016. Phone Bills (25)
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct record
{
    char user[21];
    int month,day,hour,minute,flag;
}rec[1010];
 
int toll[24];
 
bool cmp(record a,record b)
{
    if(strcmp(a.user,b.user)!=0) return strcmp(a.user,b.user)<0;
    else if(a.month!=b.month) return a.month<b.month;
    else if(a.day!=b.day) return a.day<b.day;
    else if(a.hour!=b.hour) return a.hour<b.hour;
    else if(a.minute!=b.minute) return a.minute<b.minute;
    else return a.flag<b.flag;
}
 
void getMoney(int on,int off,int& time,int& money)
{
    record temp=rec[on];
    while(temp.day<rec[off].day||temp.hour<rec[off].hour||temp.minute<rec[off].minute)
    {
        time++;
        money+=toll[temp.hour];
        temp.minute++;
        if(temp.minute>=60)
        {
            temp.minute=temp.minute%60;
            temp.hour++;
            if(temp.hour>=24)
            {
                temp.hour=temp.hour%24;
                temp.day++;
            }
        }
    }
}
 
int main()
{
    for(int i=0;i<24;i++)
        scanf("%d",&toll[i]);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char temp[10];
        scanf("%s %d:%d:%d:%d %s",rec[i].user,&rec[i].month,&rec[i].day,&rec[i].hour,&rec[i].minute,temp);
        if(strcmp(temp,"on-line")==0)
            rec[i].flag=0;
        else
            rec[i].flag=1;
    }
    sort(rec,rec+n,cmp);
    int on=0,off,next;
    while(on<n)
    {
        int needprint=0;
        next=on;
        while(next<n&&strcmp(rec[on].user,rec[next].user)==0)
        {
            if(needprint==0&&rec[next].flag==0)
            {
                needprint=1;
            }
            else if(needprint==1&&rec[next].flag==1)
                needprint=2;
            next++;
        }
        if(needprint<2)
        {
            on=next;
            continue;
        }
        int totalmoney=0;
        printf("%s %02d\n",rec[on].user,rec[on].month);
        while(on<next)
        {
            while(on<next-1&&!(rec[on].flag==0&&rec[on+1].flag==1))
                on++;
            off=on+1;
            if(off==next)
            {
                on=next;
                break;
            }
            printf("%02d:%02d:%02d %02d:%02d:%02d",rec[on].day,rec[on].hour,rec[on].minute,rec[off].day,rec[off].hour,rec[off].minute);
            int time=0,money=0;
            getMoney(on,off,time,money);
            printf(" %d $%.2f\n",time,money/100.0);
            totalmoney+=money;
            on=off+1;
        }
        printf("Total amount: $%.2f\n",totalmoney/100.0);
    }
}