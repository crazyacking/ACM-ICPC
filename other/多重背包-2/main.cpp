/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-07-00.25
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

const int MAXN=300;
int a[MAXN*MAXN],b[MAXN*MAXN];
int dp[MAXN][MAXN];// 90000*90000 爆内存
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n,p,q;
            memset(dp,0,sizeof dp);
            scanf("%d %d %d",&n,&p,&q);
            ++p,++q;
            for(int i=0;i<p;++i)
                  scanf("%d",&a[i]);
            for(int i=0;i<q;++i)
                  scanf("%d",&b[i]);
            int tmp=0;
            for(int i=0;i<q;++i)
            {
                  if(a[0]==b[i])
                      tmp++;
                  dp[0][i]=tmp;
            }
            tmp=0;
            for(int j=0;j<p;++j)
            {
                  if(a[j]==b[0])
                        tmp++;
                  dp[j][0]=tmp;
            }
            for(int i=1;i<p;++i)
            {
                  for(int j=0;j<q;++j)
                  {
                        if(a[i]==b[j])
                              dp[i][j]=dp[i-1][j-1]+1;
                        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                  }
            }
            printf("%d\n",dp[p-1][q-1]);
      }
      return 0;
}
/*

*/
