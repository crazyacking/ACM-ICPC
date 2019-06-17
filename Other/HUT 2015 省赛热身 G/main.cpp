#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int dp[2][101];
int a[101];
int main()
{
      int T;
      scanf("%d\n",&T);
      while(T--)
      {
           int n;
           scanf("%d",&n);
           for(int i=0;i<n;i++)
                  scanf("%d",a+i);
            for(int i=0;i<n;i++)
            {
                  dp[0][i]=1;
                  for(int j=0;j<i;j++)
                        if(a[j]>a[i])
                              dp[0][i]=max(dp[0][i],dp[0][j]+1);
            }
            for(int i=n-1;i>-1;i--)
            {
                  dp[1][i]=1;
                  for(int j=n-1;j>i;j--)
                        if(a[j]>a[i])
                              dp[1][i]=max(dp[1][i],dp[1][j]+1);
            }
            int ans=1;
            for(int i=0;i<n;i++)
                  if(dp[0][i]>1&&dp[1][i]>1)
                        ans=max(ans,dp[0][i]+dp[1][i]-1);
            if(ans<3)
            {
                  puts("SAD");
                  continue;
            }
            puts("HAPPY");
            printf("%d\n",n-ans);
      }
    return 0;
}
