#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXN 105
using namespace std;
int n,sum[MAXN],dp[MAXN][MAXN];
int main()
{
      sum[0]=0;
      while(~scanf("%d",&n),n)
      {
            int tmp;
            for(int i=1; i<=n; ++i)
            {
                  scanf("%d",&tmp);
                  dp[i][i]=tmp;
                  sum[i]=sum[i-1]+tmp;
            }
            for(int k=1; k<n; ++k) // 区间长度
            {
                  for(int i=1; i+k<=n; ++i) // 开始位置
                  {
                        dp[i][i+k]=sum[i+k]-sum[i-1]; // 即：sum(i,i+k)
                        for(int p=i; p<i+k; ++p)
                              dp[i][i+k]=max(sum[i+k]-sum[i-1]-dp[p+1][i+k],dp[i][i+k]);
                        for(int p=i+k; p>i; --p)
                              dp[i][i+k]=max(sum[i+k]-sum[i-1]-dp[i][p-1],dp[i][i+k]);
                  }
            }
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<n;++j)
                  {
                        printf("%d ",dp[i][j]);
                  }
                  puts("");
            }
            printf("%d\n",dp[1][n]-(sum[n]-dp[1][n]));
      }
      return 0;
}
