#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long a[20];

long long mc[20][20];

long long dp[(1<<18)+5][20];

int main()
{
      scanf("%d%d%d", &n, &m, &k);
      for(int i=0; i<n; i++)
      {
            scanf("%I64d", &a[i]);
      }
      int tmp_x, tmp_y, tmp_c;
      for(int i=0; i<k; i++)
      {
            scanf("%d%d%I64d", &tmp_x, &tmp_y, &tmp_c);
            mc[tmp_x-1][tmp_y-1] = tmp_c;
      }
      long long ans = 0;
      memset(dp, 0, sizeof(dp));
      for(int i=0; i<n; i++)
      {
            dp[1<<i][i] = a[i];
      }
      for(int s=0; s<(1<<n); s++)
      {
            int _cnt = 0;
            for(int i=0; i<n; i++)
            {
                  if((s & (1 << i)) == 0) continue; _cnt++;
                  for(int j=0; j<n; j++)
                  {
                        if((s & (1 << j)) != 0) continue;
                        int _s = s | (1 << j);
                        dp[_s][j] = max(dp[_s][j], dp[s][i] + a[j] + mc[i][j]);
                  }
            }
            if(_cnt == m) for(int i=0; i<n; i++)
                        if((s & (1 << i)) != 0) ans = max(ans, dp[s][i]);
      }
      // for (int i=0; i<(1<<n); i++) {
      //  for (int j=0; j<n; j++) {
      //      printf("%d ", dp[i][j]);
      //  }printf("\n");
      // }
      printf("%I64d\n", ans);
      return 0;
}
