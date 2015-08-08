/*
* this code is made by cralineyacking
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
struct Data
{
      int x,y,p,k;
      int sx,ex,sy,ey;
      int dx,dy;
}d[MAXN];

struct Z
{
      int line,v;
} line[2*MAXN];
int cnt;
bool comp(const Z a,const Z b)
{
      return a.line<b.line;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d",&m))
      {
            scanf("%d",&n);
            for(int i=1;i<=n;++i)
            {
                  int x,y,p,k;
                  scanf("%d %d %d %d",&d[i].x,&d[i].y,&d[i].p,&d[i].k);
                  x=d[i].x,y=d[i].y,p=d[i].p,k=d[i].k;
                  if(k==0)
                  {
                        d[i].sx=x,d[i].ex=x+p;
                        d[i].sy=y-p,d[i].ey=y;
                        d[i].dx=x+p,d[i].dy=y;
                  }
                  else if(k==1)
                  {
                        d[i].sx=x,d[i].ex=x+p;
                        d[i].sy=y,d[i].ey=y+p;
                        d[i].dx=x+p,d[i].dy=y;
                  }
                  else if(k==2)
                  {
                        d[i].sx=x,d[i].ex=x-p;
                        d[i].sy=y,d[i].ey=y+p;
                        d[i].dx=x,d[i].dy=y+p;
                  }
                  else
                  {
                        d[i].sx=x,d[i].ex=x-p;
                        d[i].sy=y-p,d[i].ey=y;
                        d[i].dx=x,d[i].dy=y-p;
                  }
            }
            int ans=0;
            for(int yi=0;yi<m;++yi)
            {
                  int from ,to ,t,dd;
                  cnt=0;
                  for(int i=01;i<=n;++i)
                  {
                        if(d[i].sy<=yi&&yi+1<=d[i].ey)
                        {
                              if(d[i].k<=1) from=to=min(d[i].x,d[i].ex);
                              else from=to=max(d[i].sx,d[i].ex);
                              t=abs(d[i].dy-yi);
                              dd=d[i].dx-t;
                              from=min(from,dd);
                              to=max(to,dd);

                              t=abs(d[i].dy-(yi+1));
                              dd=d[i].dx-t;
                              from=min(from,dd);
                              to=max(to,dd);

                              from=max(from,0);
                              to=min(to,m);
                              from+=1;
                              to+=1;
                              cout<<from<<"->"<<to+1<<endl;
                        }
                  }
            }
                  cnt++;
                  line[cnt].line=m+1;
                  sort(line+1,line+1+cnt,comp);
                  int lastline=1,num=0;
                  for(int i=1;i<=cnt;)
                  {
                        if(num&1) ans+=line[i].line-lastline;
                        lastline=line[i].line;
                        int ti=i;
                        while(ti<=cnt&&line[ti].line==line[i].line)
                        {
                              num+=line[ti].v;
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
