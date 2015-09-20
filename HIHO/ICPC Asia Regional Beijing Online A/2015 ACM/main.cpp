/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-20-11.34
* Time: 0MS
* Memory: 137KB
*/
/*

Mean:


题目是以一个点为中心，暴力每个点，计算其他点到它的距离，二分
*/

#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath> o
#include <climits>
#include <map>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-10);

struct point
{
      double x,y;
} p[200];

int t,n,m;

double q[200];

double dist(point a,point b)
{
      return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
      scanf("%d",&t);
      while(t--)
      {
            int ans=INT_MAX;
            scanf("%d %d",&n,&m);
            for(int i=1; i<=n; ++i)
            {
                  scanf("%lf %lf",&p[i].x,&p[i].y);
            }
            for(int i=1; i<=n; ++i)
            {
                  for(int j=1; j<=n; ++j)
                  {
                        q[j]=dist(p[i],p[j]);
                  }
                  sort(q+1,q+1+n);
                  int tmp=ceil(q[m]);
                  if(fabs(q[m]-tmp)<=eps) ++tmp;
                  if(fabs(tmp-0)<=eps) ++tmp;
                  if(m!=n)
                  {
                        if(q[m+1]<=tmp+eps)
                              tmp=INT_MAX;
                  }
                  ans=min(ans,tmp);
            }
            if(ans==INT_MAX)
                  printf("-1\n");
            else printf("%d\n",ans);
      }
      return 0;
}
/*

*/
