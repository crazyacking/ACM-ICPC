/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-02-20.44
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

const int maxn = 505;

int n, m;
bool lk[maxn][maxn];
int mk[maxn];
bool vis[maxn];

bool dfs(int cur)
{
      for(int i = 1; i <= n; ++i)
      {
            if(lk[cur][i] && !vis[i])
            {
                  vis[i] = true;
                  if(mk[i] == 0 || dfs(mk[i]))
                  {
                        mk[i] = cur;
                        return true;
                  }
            }
      }
      return false;
}

int solve()
{
      memset(mk, 0, n+1);
      int tmp = 0;
      for(int i = 1; i <= n; ++i)
      {
            memset(vis, false, n+1);
            if(dfs(i)) ++tmp;
      }
      return tmp/2;
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(cin >> n >> m)
      {
            for(int i = 1; i <= n; ++i)
            {
                  memset(lk[i]+1, false, n);
            }
            for(int i = 0; i < m; ++i)
            {
                  int u, v; cin >> u >> v;
                  lk[u][v] = true;
                  lk[v][u] = true;
            }
            cout << solve() << endl;
      }
      return 0;
}
