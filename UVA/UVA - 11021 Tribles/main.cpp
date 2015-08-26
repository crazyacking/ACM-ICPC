/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-26-20.36
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=1010;
double p[MAXN],dp[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      for(int Cas=1;Cas<=t;++Cas)
      {
            int n,k,m;
            scanf("%d %d %d",&n,&k,&m);
            for(int i=0;i<n;++i)
                  scanf("%lf",&p[i]);
            dp[0]=p[0];
            for(int i=1;i<m;++i)
            {
                  dp[i]=0.;
                  for(int j=0;j<n;++j)
                  {
                        dp[i]+=p[j]*pow(dp[i-1],j);
                  }
            }
            printf("Case #%d: %.7f\n",Cas,pow(dp[m-1],k));

      }
      return 0;
}
/*

*/
