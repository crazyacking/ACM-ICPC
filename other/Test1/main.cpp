/*
* this code is made by crazyacking
* Verdict: Accepted
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
int dp[105][105];
int map[105][105];

int main()
{
      int i,j,n,i1,i2,sum,temp,mx,res;
      while(scanf("%d",&n)!=EOF)
      {
            for(i=1; i<=n; i++)
                  for(j=1; j<=n; j++)
                        scanf("%d",&map[i][j]);
            memset(dp,0,sizeof(dp));
            for(j=1; j<=n; j++)
                  for(i=1; i<=n; i++)
                        dp[j][i]=dp[j][i-1]+map[i][j];
            res=0;
            for(i1=1; i1<=n; i1++)
                  for(i2=i1; i2<=n; i2++)
                  {
                        mx=sum=0;
                        for(j=1; j<=n; j++)
                        {
                              sum+=dp[j][i2]-dp[j][i1-1];
                              if(sum>=0)
                              {
                                    if(sum>=mx) mx=sum;
                              }
                              else sum=0;
                        }
                        if(mx>=res) res=mx;
                  }
            printf("%d\n",res);
      }
      return 0;
}
