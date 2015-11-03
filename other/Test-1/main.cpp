#pragma comment(linker, "/STACK:640000000")
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<cmath>
#include<string>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<vector>
#include<bitset>
#include<algorithm>

#define pb push_back
#define ppb pop_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define bit __builtin_popcountll
#define sqr(x) (x) * (x)
#define forit(it,S) for(__typeof((S).begin()) it = (S).begin(); it != (S).end(); it++)

using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-9;
const double pi = acos(-1.0);

const int maxv = (int)1e7 + 10;
const int maxn = 750;

char str[maxv];
int term[maxv];
int to[maxv][2];
int link[maxv],slink[maxv];

int n;
int mt[maxn];
bool used[maxn];
bool take[maxn];
bool match[maxn];
string s[maxn];
int len[maxn];
int fre = 1;
bool g[maxn][maxn];

bool dfs(int v)
{
      if(used[v]) return false;
      used[v] = true;
      for(int i = 0; i < n; i++) if(g[v][i])
            {
                  if(mt[i] == -1 || dfs(mt[i]))
                  {
                        mt[i] = v;
                        return true;
                  }
            }
      return false;
}

void go(int v)
{
      if(used[v]) return;
      used[v] = true;
      for(int i = 0; i < n; i++) if(g[v][i])
            {
                  take[i] = true;
                  go(mt[i]);
            }
}

void add(string &s, int id)
{
      int n = sz(s);
      int cur = 0;
      for(int i = 0; i < n; i++)
      {
            if(to[cur][s[i]] == -1)
            {
                  to[cur][s[i]] = fre++;
            }
            cur = to[cur][s[i]];
      }
      term[cur] = id;
}

void build()
{
      queue<int> q;
      q.push(0);
      while(!q.empty())
      {
            int v = q.front(); q.pop();
            for(int i = 0; i < 2; i++) if(to[v][i] != -1)
                  {
                        q.push(to[v][i]);
                        if(v == 0) continue;
                        int u = link[v];
                        while(u && to[u][i] == -1) u = link[u];
                        if(to[u][i] != -1) u = to[u][i];
                        link[to[v][i]] = u;
                        if(term[link[to[v][i]]] != -1)
                        {
                              slink[to[v][i]] = link[to[v][i]];
                        }
                        else
                        {
                              slink[to[v][i]] = slink[link[to[v][i]]];
                        }
                  }
      }
}

int main()
{
#ifdef LOCAL
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
#endif

      cin >> n;

      memset(term,-1,sizeof(term));
      memset(to,-1,sizeof(to));
      for(int i = 0; i < n; i++)
      {
            scanf("%s",str);
            s[i] = str;
            len[i] = sz(s[i]);
            for(int j = 0; j < len[i]; j++)
            {
                  s[i][j] -= 'a';
            }
            add(s[i],i);
      }

      build();

      for(int i = 0; i < n; i++)
      {
            int cur = 0;
            for(int j = 0; j < len[i]; j++)
            {
                  cur = to[cur][s[i][j]];
                  int v = slink[cur];
                  if(v) g[i][term[v]] = true;
                  if(term[cur] != -1) g[i][term[cur]] = true;
            }
      }

      for(int k = 0; k < n; k++)
      {
            for(int i = 0; i < n; i++)
            {
                  for(int j = 0; j < n; j++)
                  {
                        g[i][j] |= g[i][k] & g[k][j];
                  }
            }
      }
      for(int i = 0; i < n; i++)
      {
            g[i][i] = false;
      }

      memset(mt,-1,sizeof(mt));

      for(int i = 0; i < n; i++)
      {
            memset(used,false,sizeof(used));
            match[i] = dfs(i);
      }

      memset(used,false,sizeof(used));
      for(int i = 0; i < n; i++) if(!match[i])
            {
                  go(i);
            }
      memset(used,false,sizeof(used));
      for(int i = 0; i < n; i++) if(mt[i] != -1)
            {
                  if(take[i])
                  {
                        used[i] = true;
                  }
                  else
                  {
                        used[mt[i]] = true;
                  }
            }

      vector<int> ans;

      for(int i = 0; i < n; i++) if(!used[i])
            {
                  ans.pb(i);
            }
      cout << sz(ans) << endl;
      for(int i = 0; i < sz(ans); i++)
      {
            cout << ans[i] + 1 << " ";
      }

      return 0;
}
