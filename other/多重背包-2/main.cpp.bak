for(int i=0; i<=m; ++i)
      dp[i]=INF;
dp[0]=0;
for(int i=0; i<n; ++i)
{
      for(int j=w[i]; j<=m; ++j)
      {
            if(dp[j]>dp[j-w[i]]+v[i])
                  dp[j]=dp[j-w[i]]+v[i];
      }
}
