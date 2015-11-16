/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-16-08.37
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
const int INF=1000000;
const int MAXN=1000;

struct ArcType
{
      int c,f;
};
ArcType Edge[MAXN][MAXN];
int n,m;// n个点，m条边
int flag[MAXN];// -1:未标号   0:已标号，但未检查相邻结点   1：已标号，且已访问相邻结点
int Prev[MAXN];//上一个顶点
int zeng[MAXN];//增量


void ford_fulkerson()
{
      while(1)
      {
            memset(flag,0xff,sizeof flag);
            memset(Prev,0xff,sizeof Prev);
            queue<int> Q;
            Q.push(0);
            flag[0]=0;
            zeng[0]=INF; // S点可以流出无限多的流量
            while(!Q.empty())
            {
                  int now=Q.front();
                  Q.pop();
                  for(int i=0; i<n; ++i)
                  {
                        if(flag[i]==-1) // 未标号
                        {
                              if(Edge[now][i].f<Edge[now][i].c) // 正向流未满
                              {
                                    Prev[i]=now;
                                    flag[i]=0;
                                    zeng[i]=min(zeng[now],Edge[now][i].c-Edge[now][i].f);
                                    Q.push(i);
                              }
                              if(Edge[i][now].f>0) // 反向流大于0
                              {
                                    Prev[i]=-now;
                                    flag[i]=0;
                                    zeng[i]=min(zeng[now],Edge[i][now].f);
                                    Q.push(i);
                              }
                        }
                  }
                  flag[now]=1;
            } // end of while
            puts("-----------------------------------------------------------------");

            if(flag[n-1]==-1 || zeng[n-1]==0) // 汇点未获得标号，或者汇点的增量为0
            {
                  puts("-------**********----------------------------------------------------------");

                  break;
            }
            // 开始调整流量
            int k1=n-1,k2=abs(Prev[k1]);
            int a=zeng[k1];
            while(1)
            {
                  if(Edge[k2][k1].f<INF)
                        Edge[k2][k1].f+=a;
                  else
                        Edge[k1][k2].f-=a;
                  if(k2==0)
                        break;
                  k1=k2;
                  k2=abs(Prev[k1]);
            }// end of while
      }
      // output
      int maxFlow=0;
      for(int i=0; i<n; ++i)
      {
            for(int j=0; j<n; ++j)
            {
                  if(i==0 && Edge[i][j].f<INF) // 最大流也就是源点流出的流量
                        maxFlow+=Edge[i][j].f;
                  if(Edge[i][j].f<INF)
                        printf("%2d ->%2d:%2d\n",i,j,Edge[i][j].f);
            }
      }
      printf("%d\n",maxFlow);
}
int main()
{
      FILE* fp=freopen("C:\\Users\\crazyacking\\Desktop\\in.txt","r",stdin);
      if(fp==NULL)
            puts("open file error");

      while(cin>>n>>m)
      {
            for(int i=0; i<MAXN; ++i)
                  for(int j=0; j<MAXN; ++j)
                        Edge[i][j].c=-1,Edge[i][j].f=INF;
            int u,v,c,f;
            for(int i=0; i<m; ++i)
            {
                  cin>>u>>v>>c>>f;
                  Edge[u][v].c=c;
                  Edge[u][v].f=f;
            }
            ford_fulkerson();
      }
      return 0;
}
/*

*/
