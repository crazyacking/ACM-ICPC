#include <iostream>
#include <cstdio>
#include <utility>
#include <queue>
using namespace std;

const int MAXN = 1000010;
vector<int> G[MAXN];
priority_queue <pair<int,int> > pq;

int l[MAXN];
long long ans;

void bfs(int rt)
{
      while(!pq.empty())
      {
            int u=pq.top().second,x=-pq.top().first;
            pq.pop();
            ans+=(long long)x*pq.size();
            for(int i=0; i<G[u].size(); ++i)
            {
                  int v=G[u][i];
                  pq.push(make_pair(-l[v],v));
            }
      }
}

vector<int> ve;
int main()
{
      int n;
      scanf("%d", &n);
      int u,st;
      for(int i = 0; i < n; ++i)
      {
            scanf("%d %d", &l[i], &u);
            if(u!=-1)
                  G[u].push_back(i);
            else ve.push_back(i);
      }
      long long answer=0;
      for(int i=0;i<ve.size();++i)
      {
            while(!pq.empty()) pq.pop();
            ans=0;
            pq.push(make_pair(-l[ve[i]],ve[i]));
            bfs(ve[i]);
            answer+=ans;
      }
      printf("%lld\n",answer);
      return 0;
}


