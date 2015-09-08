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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);
const int MAXN=10+2*(int)1e4;

int fa[MAXN],dis[MAXN];
int findset(int x)
{
      if(x==fa[x]) return x;
      else //x不是直接指向根节点，需要将x合并路径直接指向根节点
      {
            int root=findset(fa[x]);//要合并x到根节点的路径，需要先合并fa[x]到根节点的路径
            dis[x]+=dis[fa[x]];//x到根节点的距离 = x到fa[x]的距离 + fa[x]到根节点的距离
            return fa[x]=root;//合并x到根节点的路径
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            for(int i=0; i<=n; ++i)
                  fa[i]=i,dis[i]=0;
            char s[10];
            while(scanf("%s",s),s[0]!='O')
            {
                  int u,v;
                  if(s[0]=='E')
                  {
                        scanf("%d",&v);
                        findset(v);//首先合并路径
                        printf("%d\n",dis[v]);
                  }
                  else
                  {
                        scanf("%d %d",&u,&v);
                        fa[u]=v;
                        dis[u]=abs(u-v)%1000;
                  /*
                        也可以在这合并，但是注意需要先合并v(u的父节点),在合并u
                        具体参看白书P193
                        findset(v);
                        findset(u);
                  */
                  }
            }
      }
      return 0;
}
/*

*/
