/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-31-08.55
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
#define  LL long long
#define  ULL unsigned long long
using namespace std;

struct point
{
      int x,y;
      int from;
      point(){;}
      point(int a,int b,int f){x=a,y=b,from=f;}
};
struct dis_point
{
public:
      int dis;
      int x,y;
      int from;
      bool operator < (dis_point a) const
      {
            return dis<a.dis;
      }
      dis_point(int d,int a,int b,int f)
      {
            dis=d,x=a,y=b,from=f;
      }
      dis_point(){;}
};
int n,m;
int cnt[1010];
char G[1010][1010],ans[1010][1010];
set<dis_point> se;
queue<dis_point> q;
int si;

void pre()
{
      if(G[0][0]=='1')
      {
            q.push( dis_point( abs(n+m),0,0,1) );
            si=1;
            return;
      }
      else
      {
            queue<point> q1;
            q1.push(point(0,0,-1));
            point now;
            while(!q1.empty())
            {
                  now=q1.front(); q1.pop();
                  if(G[now.x+1][now.y]=='0')
                  {
                        q1.push(point(now.x+1,now.y,-1));
                  }
                  else
                  {
                        se.insert(dis_point( abs(n-now.x+1)+abs(m-now.y),now.x+1,now.y,-1));
                  }
                  if(G[now.x][now.y+1]=='0')
                  {
                        q1.push(point(now.x,now.y+1,-1));
                  }
                  else
                  {
                        se.insert(dis_point(  abs(n-now.x) + abs(m-now.y+1), now.x,now.y+1 ,-1 ));
                  }
            }
      }

      while(!q.empty()) q.pop();
      set<dis_point>::iterator it=se.begin(),tm=se.begin();
      ++it;
      int cnt=0;
      for(;it!=se.end();++it,++tm)
      {
            if((*it).dis == (*tm).dis )
            {
                  q.push( dis_point( (*tm).dis,(*tm).x,(*tm).y,cnt++) );
            }
            else
            {
                  q.push( dis_point( (*tm).dis,(*tm).x,(*tm).y,cnt++) );
                  break;
            }
      }
      si=q.size();
}

void bfs()
{
      for(int i=0;i<1010;++i) memset(ans[i],0,sizeof ans[i]);
      memset(cnt,0,sizeof cnt);
      dis_point now;
      while(!q.empty())
      {
            now=q.front();q.pop();
            ans[now.from][cnt[now.from]++]=G[now.x][now.y];
            if(now.x+1<n && now.y<m)
            {
                  q.push(dis_point(abs(n-now.x-1) + abs(m-now.y),now.x+1,now.y,now.from));
            }
            if(now.x<n && now.y+1<m)
            {
                  q.push(dis_point(abs(n-now.x) + abs(m-now.y-1),now.x,now.y+1,now.from));
            }
      }
      for(int i=0;i<si;++i)
      {
            for(int j=0;ans[i][j];++j)
            {
                  putchar(ans[i][j]);
            }
            puts("");
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
            scanf("%d %d",&n,&m);
            for(int i=0;i<n;++i) scanf("%s",G[i]);

            for(int i=0;i<n;++i)
            {
                  puts(G[i]);
            }
            pre();
            printf("si= %d\n",si);
            if(si==0)
            {
                  puts("");
                  continue;
            }
            bfs();
      }
      return 0;
}
/*

*/
