/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-15-12.09
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
#define  LL __int64
#define  ULL unsigned long long
using namespace std;
const LL MAXN=200010;
struct node
{
      LL v,c;
      bool operator <(const node&a) const
      {
            return v>a.v;
      }
} a[MAXN];
LL dp[MAXN][10];

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL Cas;
      scanf("%I64d",&Cas);
      while(Cas--)
      {
            LL n,k;
            scanf("%I64d %I64d",&n,&k);
            for(LL i=1; i<=n; ++i)
            {
                  scanf("%I64d %I64d",&a[i].v,&a[i].c);
            }
            sort(a+1,a+n+1);
            LL ans=0,val;
            memset(dp,0,sizeof dp);
            for(LL i=1; i<=n; ++i)
            {
                  val=a[i].v-a[i].c;
                  dp[i][0]=max(dp[i-1][0],val);
                  for(LL j=1; j<=k; ++j)
                  {
                        dp[i][j]=max(dp[i-1][j],min(dp[i-1][j-1]-a[i].c,val));
                  }
                  ans=max(ans,dp[i][k]);
            }
            printf("%I64d\n",ans);
      }
      return 0;
}
/*

*/
