/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-21-14.24
* Time: 0MS
* Memory: 137KB
*/
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define  LL long long
using namespace std;

const int MAXN=20050;
struct node
{
      int x,y,r;
      bool flag;
      bool operator < (node b) const
      {
            if(x==b.x) return y<b.y;
            return x<b.x;
      }
};

node no[MAXN];

void init(int n)
{
      for(int i=0;i<=n;++i)
      {
            no[i].flag=false;
      }
}

double get_d(int i,int j)
{
      double xx=fabs(no[i].x-no[j].x);
      double yy=fabs(no[i].y-no[j].y);
      return sqrt(xx*xx + yy*yy);
}

int main()
{
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            init(n);
            for(int i=0;i<n;++i)
            {
                  scanf("%d %d %d",&no[i].x,&no[i].y,&no[i].r);
            }
            sort(no,no+n);
            for(int i=0;i<n-1;++i)
            {
                  if(no[i].flag) continue;
                  for(int j=i+1;j<n;++j)
                  {
                        if(no[j].x>no[i].x+no[i].r)
                              break;
                        double d=get_d(i,j);
                        if(d<(double)abs(no[i].r-no[j].r))
                        {
                              no[j].flag=true;
                        }
                  }
            }

            for(int i=n-1;i>=1;--i)
            {
                  if(no[i].flag) continue;
                  for(int j=i-1;j>=0;--j)
                  {
                        if(no[j].x>no[i].x+no[i].r)
                        {
                              break;
                        }
                        double d=get_d(i,j);
                        if(d<(double)abs(no[i].r-no[j].r))
                        {
                              no[j].flag=true;
                        }
                  }

            }

            LL ans=0;
            for(int i=0;i<n;++i)
            {
                  if(!no[i].flag)
                        ans++;
            }
//            cout<<ans<<endl;
            if(ans%2==1)
            {
                  puts("Alice");
            }
            else puts("Bob");

      }
      return 0;
}
/*

*/
