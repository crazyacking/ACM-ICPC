/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-16-19.52
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
#define eps 1e-14
#define  LL __int64
#define  ULL unsigned __int64
using namespace std;
const int MAXN=10+(int)1e5;
LL n,pw,vw[MAXN],pf[MAXN],vf[MAXN],th[MAXN];
double tmp,t;
double cal(double& w)
{
      tmp=w*pw;
      for(int i=0;i<n;++i)
      {
            t=th[i]-w*vw[i];
            if(t<=0) continue;
            tmp+=(t)*pf[i]*1./vf[i];
      }
      return tmp;
}

double work(double l,double r)
{
      double mid,mmid;
      int st=100;
      while(st--)
      {
            mid=(l+r)/2;
            mmid=(mid+r)/2;
            if(cal(mid)-cal(mmid)>eps)
                  l=mid;
            else r=mmid;
      }
      return l;
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(scanf("%I64d",&n),n)
      {
            scanf("%I64d",&pw);
            for(int i=0;i<n;++i)
            {
                  scanf("%I64d %I64d %I64d %I64d",&vw[i],&pf[i],&vf[i],&th[i]);
            }
            double val=work(0,200);
            printf("%.6lf\n",cal(val));
      }
      return 0;
}
/*

*/


