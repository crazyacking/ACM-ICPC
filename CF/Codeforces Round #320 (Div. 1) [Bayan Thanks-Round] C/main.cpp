/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-17-00.27
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
const double eps(1e-8);

const int MAXN=200050;
long long a[MAXN];
double b[MAXN];

long long n;
double now_max,now_min,mx,mn;
double calc(double x)
{
      for(int i=1;i<=n;++i)
            b[i]=a[i]*1.+x;
      now_max=now_min=0.0;
      mx=mn=0;
      for(int i=1;i<=n;++i)
      {
            now_max+=b[i];
            now_min+=b[i];
            if(now_max<=0) now_max=0;
            if(now_min>=0) now_min=0;
            mx=max(mx,now_max);
            mn=min(mn,now_min);
      }
      return max(mx,-mn);

}

double er_fen(double low,double high)
{
        double l=low,h=high;
        double mid=(l+h)/2,mmid=(mid+h)/2;
        double cmid=calc(mid),cmmid=calc(mmid);
        int max_step=110;
        for(int i=0;i<max_step;++i)
        {
                if(cmid>cmmid)
                        l=mid;
                else
                        h=mmid;
                mid=(l+h)/2,mmid=(mid+h)/2;
                cmid=calc(mid),cmmid=calc(mmid);
        }
        cout<<l<<endl;
        return calc(l);
}

int main()
{
      scanf("%I64d",&n);
      for(int i=1;i<=n;++i)
      {
            scanf("%I64d",&a[i]);
      }
      double ans=er_fen(-10100.0,10100.0);
      printf("%.10f\n",ans);
      return 0;
}
/*

*/
