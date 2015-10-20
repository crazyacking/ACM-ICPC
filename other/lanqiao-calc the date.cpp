//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-16-15.13
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
using namespace std;

int y,m,d;
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool compare(int y1,int m1,int d1,int y2,int m2,int d2) // true: y2>=y1
{
        if(y1!=y2) return y1>y2;
        if(m1!=m2) return m1>m2;
        if(d1!=d2) return d1>d2;
        return 1;
}
bool isLeapYear(int y)
{
        return (y%400==0 || (y%4==0 && y%100!=0));
}
int getGap(int sy,int sm,int sd,int ey,int em,int ed,int flag)
{
//        cout<<sy<<" "<<sm<<" "<<sd<<" "<<ey<<" "<<em<<" "<<ed<<endl
        int day=0;
        //the day of year
        for(int i=sy+1;i<ey;++i)
        {
                day+=(isLeapYear(i)?366:365);
        }
        //the day of month
        int ssm=(sy==ey?sm:1);
        for(int i=ssm;i<em;++i)
        {
                if(i==2)
                {
                        day+=isLeapYear(ey)?29:28;
                }
                else day+=mon[i];
        }
        //the day of date
        if(sy==ey)
        {
                day+=ed-sd;
        }
        //sub the day of start year
        else
        {
                // calc the day of start year(shen yu,to add)
                int sYear=0;
                for(int i=sm;i<=12;++i)
                {
                        if(i==2)
                        {
                                sYear+=isLeapYear(sy)?29:28;
                        }
                        else sYear+=mon[i];
                }
                sYear-=sd;

                day+=ed;
                day+=sYear;
        }
        return day;
}

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
//      freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//      freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);
        while(cin>>y>>m>>d)
        {
                if(compare(y,m,d,2011,11,11)) // later
                {
                        int gap=getGap(2011,11,11,y,m,d,0);
                        gap%=7;
                        gap+=5;
                        gap%=7;
                        if(gap==0) cout<<7<<endl;
                        else cout<<gap<<endl;
                }
                else // before
                {
                        int gap=getGap(y,m,d,2011,11,11,1);
                        gap=(gap-5)%7;
                        int tmp=7-gap;
                        tmp%=7;
                        if(tmp==0) cout<<7<<endl;
                        else cout<<tmp<<endl;
                }
        }
        return 0;
}
/*

*/
