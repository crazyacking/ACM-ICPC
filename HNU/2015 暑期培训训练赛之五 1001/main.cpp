/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-08-13.52
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
const int MAXN=205;
int n,m;

void scan(int &x)
{
      x=0;
      char c=getchar();
      while(!(c>='0' && c<='9'  || c=='-')) { c=getchar(); }
      bool pos=1;
      if(c=='-')
      {
            pos=0; c=getchar();
      }
      while(c>='0' && c<='9')
      {
            x=x*10+c-'0'; c=getchar();
      }
      if(!pos) { x=-x; }
}
void scan2(int &x,int &y) { scan(x),scan(y);}
void scan3(int &x,int &y,int &z) { scan(x),scan(y),scan(z); }
/**************************************END     define***************************************/

struct Tra
{
      int x,y,p,k;
      int x1,x2,y1,y2;
      int xd,yd;
}d[MAXN];

struct Line
{
      int pos,flag;
} Li[2*MAXN];
int cnt;
bool cmp(Line a,Line b)
{
      return a.pos<b.pos;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d",&m))
      {
            scan(n);
            for(int i=1;i<=n;++i)
            {
                  int x,y,p,k;
                  scan(x),scan(y),scan(p),scan(k);
                  d[i].x=x,d[i].y=y,d[i].p=p,d[i].k=k;
                  if(k==0)
                  {
                        d[i].x1=x,d[i].x2=x+p;
                        d[i].y1=y-p,d[i].y2=y;
                        d[i].xd=x+p,d[i].yd=y;
                  }
                  else if(k==1)
                  {
                        d[i].x1=x,d[i].x2=x+p;
                        d[i].y1=y,d[i].y2=y+p;
                        d[i].xd=x+p,d[i].yd=y;
                  }
                  else if(k==2)
                  {
                        d[i].x1=x,d[i].x2=x-p;
                        d[i].y1=y,d[i].y2=y+p;
                        d[i].xd=x,d[i].yd=y+p;
                  }
                  else
                  {
                        d[i].x1=x,d[i].x2=x-p;
                        d[i].y1=y-p,d[i].y2=y;
                        d[i].xd=x,d[i].yd=y-p;
                  }
            }
            int ans=0;
            for(int yi=0;yi<m;++yi)
            {
                  int from ,to ,t,xt;
                  cnt=0;
                  for(int i=1;i<=n;++i)
                  {
                        if(d[i].y1<=yi&&yi+1<=d[i].y2)
                        {
                              if(d[i].k<=1) from=to=d[i].x>d[i].x2?d[i].x2:d[i].x;
                              else from=to=d[i].x1>d[i].x2?d[i].x1:d[i].x2;

                              t=abs(d[i].yd-yi);
                              xt=d[i].xd-t;
                              from=from<xt?from:xt;
                              to=to>xt?to:xt;

                              t=abs(d[i].yd-(yi+1));
                              xt=d[i].xd-t;
                              from=from<xt?from:xt;
                              to=to>xt?to:xt;

                              from=from>0?from:0;
                              from++;
                              to=to<m?to:m;
                              cnt++;
                              Li[cnt].pos=from;
                              Li[cnt].flag=+1;

                              cnt++;
                              Li[cnt].pos=to+1;
                              Li[cnt].flag=-1;
                        }
                  }
                  cnt++;
                  Li[cnt].pos=m+1;
                  sort(Li+1,Li+1+cnt,cmp);
                  int lastpos=1,num=0;
                  for(int i=1;i<=cnt;)
                  {
                        if(num&1) ans+=Li[i].pos-lastpos;
                        lastpos=Li[i].pos;
                        int ti=i;
                        while(ti<=cnt&&Li[ti].pos==Li[i].pos)
                        {
                              num+=Li[ti].flag;
                              ti++;
                        }
                        i=ti;
                  }
            }
            printf("%d\n",ans);
      }
      return 0;
}
/*

*/
