/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-29-20.55
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

int n,m,k;
int sa[20];
int ad[20][20];
LL dp[(1<<18)+5][20];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cin>>n>>m>>k;
      for(int i=0; i<n; ++i)
            cin>>sa[i];
      int u,v,d;
      while(k--)
      {
            cin>>u>>v>>d;
            ad[u-1][v-1]=d;
      }
      memset(dp,0,sizeof dp);
      for(int i=0; i<n; ++i)
      {
            dp[1<<i][i]=sa[i];
      }
      long long ans=0;
      int tot=1<<n;
      for(int s=0; s<tot; ++s) // 枚举总状态数
      {
            int cnt=0;
            for(int i=0; i<n; ++i) // 在已选定的菜中，选一道菜i出来在j前面吃
            {
                  if((s&(1<<i))==0)
                        continue;
                  ++cnt;
                  for(int j=0; j<n; ++j) // 从未选定的菜中选一道出来，在i后面吃
                  {
                        if((s&(1<<j))!=0)
                              continue;
                        int ss=s|(1<<j);
                        dp[ss][j]=max(dp[ss][j],dp[s][i]+sa[j]+ad[i][j]);
                  }
            }
            if(cnt==m)
            {
                  for(int i=0; i<n; ++i)
                  {
                        if((s&(1<<i))!=0)
                              ans=max(ans,dp[s][i]);
                  }
            }
      }
      cout<<ans<<endl;
      return 0;
}
/*

*/
