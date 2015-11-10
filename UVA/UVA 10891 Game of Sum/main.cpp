/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-08-20.49
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


typedef pair<int, int> P;
struct edge
{
      int to, cap, cost, rev;
};

int V;
vector<edge> G[50200];
int h[50200], dist[50200];
int prevv[50200], preve[50200];

void addEdge(int from, int to, int cap, int cost)
{
      G[from].push_back((edge) {to, cap, cost, G[to].size()});
      G[to].push_back((edge) {from, 0, -cost, G[from].size() - 1});
}

int minCostFlow(int s, int t, int f)
{
      int res = 0;
      fill(h, h + V, 0);
      while(f > 0)
      {
            priority_queue<P, vector<P>, greater<P> > pq;
            fill(dist, dist + V, 1000000000);
            dist[s] = 0; pq.push(P(0, s));
            while(!pq.empty())
            {
                  P p = pq.top(); pq.pop();
                  int v = p.second;
                  if(dist[v] < p.first) continue;
                  for(int i = 0; i < G[v].size(); i++)
                  {
                        edge &e = G[v][i];
                        if(e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                        {
                              dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                              prevv[e.to] = v;
                              preve[e.to] = i;
                              pq.push(P(dist[e.to], e.to));
                        }
                  }
            }

            if(dist[t] == 1000000000) return (-1);
            for(int v = 0; v < V; v++) h[v] += dist[v];

            int d = f;
            for(int v = t; v != s; v = prevv[v])
            {
                  d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * h[t];
            for(int v = t; v != s; v = prevv[v])
            {
                  edge &e = G[prevv[v]][preve[v]];
                  e.cap -= d;
                  G[v][e.rev].cap += d;
            }
      }
      return (res);
}

int getDist(string s, string t)
{
      int dp[32][32];
      for(int i = 0; i <= s.size(); i++) dp[i][0] = i;
      for(int i = 0; i <= t.size(); i++) dp[0][i] = i;

      for(int i = 1; i <= s.size(); i++)
            for(int j = 1; j <= t.size(); j++)
                  dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1),
                                 dp[i - 1][j - 1] + (s[i - 1] != t[j - 1]));
      return (dp[s.size()][t.size()]);
}

int main()
{
      int N, M;
      vector<string> S, T;
      map<string, int> c;
      scanf("%d %d", &N, &M);
      getchar();
      string ss;
      char str[1024], *p;
      for(int i = 0; i < N; i++)
      {
            gets(str);
            p = strtok(str, " \n");
            while(p != NULL)
            {
                  ss=string(p);
                  S.push_back(ss);
                  c[ss]++;
                  p = strtok(NULL, " \n");
            }
      }

      sort(S.begin(), S.end());
      S.erase(unique(S.begin(), S.end()), S.end());

      for(int i = 0; i < M; i++)
      {
            char st[1024];
            scanf("%s", st);
            T.push_back((string)st);
      }
      sort(T.begin(), T.end());
      T.erase(unique(T.begin(), T.end()), T.end());
      V = S.size() + T.size() + 2;
      for(int i = 0; i < S.size(); i++)
      {
            addEdge(0, i + 1, 1, 0);
            for(int j = 0; j < T.size(); j++)
            {
                  addEdge(i + 1 , S.size() + j + 1, 1, c[S[i]] * getDist(S[i], T[j]));
                  if(!i) addEdge(S.size() + j + 1, S.size() + T.size() + 1, 1, 0);
            }
      }

      printf("%d\n", minCostFlow(0, S.size() + T.size() + 1, S.size()));

      return (0);
}
