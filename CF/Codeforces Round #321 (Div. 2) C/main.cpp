/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-29-18.08
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

const int MAXN=100010;
int n,m,v[MAXN];
vector<int> ve[MAXN];

int ans=0;
void dfs(int x,int cats,int fa)
{
      if(cats>m) return;
      int si=ve[x].size();
      if(si==1 && x!=1) ++ans;
      for(int i=0;i<si;++i)
      {
            int now=ve[x][i];
            if(now!=fa) // 忽略回溯
            {
                  if(v[now])
                        dfs(now,cats+1,x);
                  else dfs(now,0,x);
            }
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      cin>>n>>m;
      for(int i=1;i<=n;++i)
            cin>>v[i];
      int s,e;
      for(int i=0;i<n-1;++i)
      {
            cin>>s>>e;
            ve[s].push_back(e);
            ve[e].push_back(s);
      }
      dfs(1,v[1],0);
      cout<<ans<<endl;
      return 0;
}
/*

*/
