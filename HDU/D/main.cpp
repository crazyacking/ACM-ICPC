/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-16-22.46
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
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <cstring>
#define max(a,b) (a>b?a:b)
#define PI 3.1415926535898
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
const int MAXN=230;
double v[MAXN];



if(l>=l2&&l<=r2)
{
      flag=0;
      break;
}
else if(l>=l1&&l<=r1)
      sum++;
}
if(flag) ans=max(ans,sum);
agl+=(pi/1000);



int n;
const double g=9.8;
const double gap=PI/1000;
double h,l1,r1,l2,r2;
int work(int cnt)
{
      double th=cnt*gap;
      double dis;
      int ret=0;
      for(int i=0; i<n; ++i)
      {
            double dis=v[i]*sin(th)*(sqrt(v[i]*v[i]*cos(th)*cos(th)+2*g*h)-v[i]*cos(th))/g;
            if(dis>=l2 && dis<=r2)
            {
                  flag=0;
                  continue;
            }
            if(flag)
                  if((dis>=l1 && dis<=r1) && (!(dis>=l2 && dis<=r2)))
                        ret++;
      }
      return ret;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(scanf("%d",&n),n)
      {
            scanf("%lf %lf %lf %lf %lf",&h,&l1,&r1,&l2,&r2);
            if(l2<=l1 && r2>= r1)
            {
                  puts("0");
                  continue;
            }

            for(int i=0; i<n; ++i)
                  scanf("%lf",&v[i]);
            double th=0.0;
            int ans=-1;

            for(int i=1; i<1000; ++i)
            {
                  int tmp=work(i);
                  ans=max(ans,tmp);
            }
            printf("%d\n",ans);
      }
      return 0;
}
/*

*/



//      l=v[i]*sin(agl)*(sqrt(v[i]*v[i]*cos(agl)*cos(agl)+2*g*h)-v[i]*cos(agl))/g;
