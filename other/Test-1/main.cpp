#include<bits/stdc++.h>
#define LL long long

using namespace std;

const LL N = 500010;
LL n, q, a[N], dp[N], cnt[N], m = 500000;
bool vis[N];
vector<LL> d[N];

int main()
{
      LL i, j, k;
      dp[1] = 1;
      for(j = 1; j <= m; ++j)
      {
            d[j].push_back(j);
            for(i = j + j; i <= m; i += j)
                  d[i].push_back(j), dp[i] -= dp[j];
      }
      puts("-----------------------------------------------------------------");
      for(int i=0;i<20;++i)
      {
            int si=d[i].size();
            printf("d[%2d]:---dp[i]=%2d   || \t",i,dp[i]);
            for(int j=0;j<si;++j)
            {
                  printf("%LLd ",d[i][j]);
            }
            puts("");
      }
      puts("-----------------------------------------------------------------");

      cin>>n>>q;
      for(i = 1; i <= n; ++i) cin>>a[i];
      LL ans = 0;
      while(q--)
      {
            cin>>i;
            for(LL y : d[a[i]]) ans += dp[y] * (cnt[y]++);
            cout<<ans<<"\n";
      }
      return 0;
}
