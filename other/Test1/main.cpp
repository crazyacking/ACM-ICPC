/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-11-02.16
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
const int MAXN=1000010;
const int INF=0x3f3f3f3f;
const double eps(1e-8);


struct Point
{
      int x,y,id;
} p[MAXN];


bool cmp(Point a,Point b)
{
      if(a.x != b.x)return a.x<b.x;
      else return a.y<b.y;
}


struct BIT
{
      int min_val,pos;
      void init()
      {
            min_val=INF;
            pos=-1;
      }
} bit[MAXN<<2];


struct Edge
{
      int u,v,d;
} edge[MAXN<<2];


bool cmpedge(Edge a,Edge b)
{
      return a.d<b.d;
}


int tot,F[MAXN];
int Find(int x)
{
      if(F[x]==-1)return x;
      else return F[x]=Find(F[x]);
}


void addedge(int u,int v,int d)
{
      edge[tot].u=u;
      edge[tot].v=v;
      edge[tot++].d=d;
}


int lowbit(int x)
{
      return x&(-x);
}


void update(int i,int val,int pos)
{
      while(i>0)
      {
            if(val<bit[i].min_val)
            {
                  bit[i].pos=pos;
                  bit[i].min_val=val;
            }
            i-=lowbit(i);
      }
}


int query(int i,int m)
{
      int min_val=INF,pos=-1;
      while(i<=m)
      {
            if(bit[i].min_val<min_val)
            {
                  min_val=bit[i].min_val;
                  pos=bit[i].pos;
            }
            i+=lowbit(i);
      }
      return pos;
}


int dis(Point a,Point b)
{
      return abs(a.x-b.x)+abs(a.y-b.y);
}


int a[MAXN];
void MST_work(int n,Point p[])
{
      tot=0;
      for(int dir=0; dir<4; dir++)
      {
            if(dir==1 || dir==3)
            {
                  for(int i=0; i<n; i++)
                  {
                        swap(p[i].x,p[i].y);
                  }
            }
            else if(dir==2)
            {
                  for(int i=0; i<n; i++)
                  {
                        p[i].x=-p[i].x;
                  }
            }
            sort(p,p+n,cmp);
            for(int i=0; i<n; i++)
                  a[i]=p[i].y-p[i].x+2000001;
            for(int i=1; i<=4000001; i++)
                  bit[i].init();
            for(int i=n-1; i>=0; i--)
            {
                  int pos=a[i];
                  int ans=query(pos,4000001);
                  if(ans!=-1)
                        addedge(p[i].id,p[ans].id,dis(p[i],p[ans]));
                  update(pos,p[i].x+p[i].y,i);
            }
      }
}


struct EList
{
      int to,next;
} Edge[MAXN<<1];
int tol,head[MAXN];
void addE(int u,int v)
{
      Edge[tol].to=v;
      Edge[tol].next=head[u];
      head[u]=tol++;
}

int Scan()
{
    char ch;
    while((ch=getchar())<'0' || ch>'9');
    int res=ch-'0';
    while((ch=getchar())>='0' && ch<='9')
        res=res*10+ch-'0';
    return res;
}
void print(int x)
{
//      if(x<0) {printf("-"); x=-x;}
      if(x>9) print(x/10);
      putchar(x%10+'0');
}
/**************************************END     define***************************************/
char s[15];
void Print(int x)
{
      int now=0;
      while(x)
      {
            s[now++]=x%10+'0';
            x/=10;
      }
      for(int i=now-1; i>=0; i--)putchar(s[i]);
      putchar(' ');
}
void dfs(int u,int fa)
{
      for(int i=head[u]; i!=-1; i=Edge[i].next)
      {
            if(Edge[i].to==fa)continue;
            dfs(Edge[i].to,u);
      }
      Print(u+1);
}
int main()
{
      int n;
      n=Scan();
      for(int i=0; i<n; i++)
      {
            p[i].x=Scan();
            p[i].y=Scan();
            p[i].id=i;
      }
      MST_work(n,p);
      sort(edge,edge+tot,cmpedge);
      memset(F,-1,sizeof(F));
      int dif=n;
      memset(head,-1,sizeof(head));
      for(int i=0; i<tot; i++)
      {
            int u=edge[i].u;
            int v=edge[i].v;
            int t1=Find(u);
            int t2=Find(v);
            if(t1!=t2)
            {
                  F[t1]=t2;
                  addE(u,v);
                  addE(v,u);
                  dif--;
                  if(dif==1)break;
            }
      }
      dfs(0,-1);
      return 0;
}
