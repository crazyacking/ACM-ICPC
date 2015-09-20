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
      point(){}
      point(double x,double y):x(x),y(y){}
}p[120];
double calc_dis(point a,point b)
{
      return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double max_dis(int k)
{
      double ret=-1.;
      for(int i=0;i<n;++i)
      {
            if(i!=k)
                  ret=max(ret,calc_dis(p[i],p[k]));
      }
      return ret;
}

int cal(double r,int k)
{
      int ret=1;
      for(int i=0;i<n;++i)
      {
            if(i!=k && calc_dis(p[i],p[k])<r)
                  ++ret;
      }
      return ret;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            cin>>n>>m;
            double x,y;
            for(int i=0;i<n;++i)
            {
                  cin>>x>>y;
                  p[i]=point(x,y);
            }
            double l,r;
            int ans=INT_MAX;
            for(int i=0;i<n;++i)
            {
                  l=0.;
                  r=max_dis(i);
                  int step=100;
                  while(step--)
                  {
                        double mid=(l+r)/2;
                        if(cal(mid,i)<m)
                              l=mid;
                        else r=mid;
                  }
                  int tmp=ceil(l);
                  if(fabs(l-tmp)<=eps || fabs(tmp-0)<=eps) ++tmp;
                  ans=min(ans,tmp);
            }
            printf("%d\n",ans);

      }
      return 0;
}
/*

*/
