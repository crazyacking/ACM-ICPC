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
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-20-17.15
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-10);

int n,m;
struct point
{
      double x,y;
}p[120];
double calc_dis(point a,point b)
{
      return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dis[210];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            cin>>n>>m;
            for(int i=1;i<=n;++i)
                  cin>>p[i].x>>p[i].y;
            int ans=INT_MAX;
            for(int i=1;i<=n;++i)
            {
                  for(int j=1;j<=n;++j)
                        dis[j]=calc_dis(p[i],p[j]);
                  sort(dis+1,dis+1+n);
                  int tmp=ceil(dis[m]);
                  if(fabs(tmp-dis[m])<=eps) ++tmp;
                  if(fabs(tmp-0)<=eps) ++tmp;
                  if(m!=n && dis[m+1]<=tmp+eps) tmp=INT_MAX;
                  ans=min(ans,tmp);
            }
            if(ans==INT_MAX) puts("-1");
            else printf("%d\n",ans);

      }
      return 0;
}
/*

*/
