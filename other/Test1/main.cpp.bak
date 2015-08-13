/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-13-22.58
* Time: 0MS
* Memory: 137KB
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
#define  ULL unsigned long long
using namespace std;

typedef long long ll;
ll gcd(ll a,ll b)
{
    return b==0?a:gcd(b,a%b);
}
struct fs
{
    ll a,b;
    fs(){}
    fs(ll a,ll b)
    {
        this->a=a;
        this->b=b;
    }
    fs operator +(fs one)
    {
        ll t1=a*one.b+b*one.a,t2=b*one.b,t=gcd(t1,t2);
        return fs(t1/t,t2/t);
    }
    fs operator -(fs one)
    {
        ll t1=a*one.b-b*one.a,t2=b*one.b;
        if(t1<0)
            t1=-t1;
        ll t=gcd(t1,t2);
        return fs(t1/t,t2/t);
    }
    fs operator *(fs one)
    {
        ll t1=a*one.a,t2=b*one.b,t=gcd(t1,t2);
        return fs(t1/t,t2/t);
    }
    bool operator <(fs one)
    {
        return a*one.b<b*one.a;
    }
};
fs ans[3];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        if(h>=12)
            h-=12;
        fs a=(fs(s,3600)+fs(m,60)+fs(h,1))*fs(5,1);
        fs b=fs(m,1)+fs(s,60);
        fs c=fs(s,1);
        ans[0]=(a-b)*fs(6,1);
        ans[1]=(a-c)*fs(6,1);
        ans[2]=(b-c)*fs(6,1);
        for(int i=0;i<3;i++)
            if(fs(180,1)<ans[i])
                ans[i]=fs(360,1)-ans[i];
        for(int i=0;i<3;i++)
        {
            if(ans[i].a==0)
                putchar('0');
            else if(ans[i].b==1)
                cout<<ans[i].a;
            else
                cout<<ans[i].a<<"/"<<ans[i].b;
            putchar(' ');
        }
        puts("");
    }
    return 0;
}
