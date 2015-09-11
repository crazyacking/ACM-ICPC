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

char B[1<<15],*S=B,*T=B,ch;
#define getc() (S==T&&(T=(S=B)+fread(B,1,1<<15,stdin),S==T)?0:*S++)
int aa,bb; int F()
{
      while(ch=getc(),(ch<'0'||ch>'9')&&ch!='-'); ch=='-'?aa=bb=0:(aa=ch-'0',bb=1);
      while(ch=getc(),ch>='0'&&ch<='9')aa=aa*10+ch-'0'; return bb?aa:-aa;
}
#define N 100010
int n,swp,cnt,z[N]; long long ans;
#define swap(a,b) (swp=a,a=b,b=swp)
#define abs(x) (x>0?x:-(x))
#define max(a,b) (a>b?a:b)
#define cmax(x) (ans<x?ans=x:1)
struct P {int x,y,id,nx,ny;} p[N];
bool operator<(const P&a,const P&b) {return a.nx<b.nx||a.nx==b.nx&&a.ny<b.ny;}
class Graph
{
private:
      int et,la[N],ufs[N],tot;
      struct D
      {
            int x,y,v;
            bool operator<(const D&a)const {return v<a.v;}
      } d[N<<2];
      struct E {int to,v,nxt;} e[N<<1];
      int gf(int x) {return ufs[x]==x?x:ufs[x]=gf(ufs[x]);}
      void adde(int x,int y,int v)
      {
            e[++et]=(E) {y,v,la[x]},la[x]=et;
            e[++et]=(E) {x,v,la[y]},la[y]=et;
      }
public:
      Graph() {et=1;}
      void add(int x,int y,int v) {d[++tot]=(D) {x,y,v};}
      void make()
      {
            std::sort(d+1,d+1+tot);
            for(int i=1; i<=n; i++)ufs[i]=i; cnt=n;
            for(int i=1,x,y; i<=tot; i++)
                  if((x=gf(d[i].x))!=(y=gf(d[i].y)))
                  {
                        ufs[x]=y,cnt--,ans+=d[i].v,
                                            adde(d[i].x,d[i].y,d[i].v);
                  }
      }
} G;
struct D {int x,n;} d[N];
bool operator<(const D&a,const D&b) {return a.x<b.x;}
#define dis(i,j) (abs(p[i].x-p[j].x)+abs(p[i].y-p[j].y))
void ins(int i)
{
      for(int t=p[i].ny; t<=cnt; t+=t&-t)
            if(z[t]==0||p[z[t]].x+p[z[t]].y<p[i].x+p[i].y)z[t]=i;
}
int query(int i)
{
      int f=0;
      for(int t=p[i].ny; t>0; t-=t&-t)
            if(z[t]&&(f==0||p[z[t]].x+p[z[t]].y>p[f].x+p[f].y))f=z[t];
      return f;
}
void work()
{
      for(int i=1; i<=n; i++)p[i].nx=p[i].x-p[i].y,p[i].ny=p[i].y;
      std::sort(p+1,p+1+n);
      for(int i=1; i<=n; i++)d[i]=(D) {p[i].ny,i};
      std::sort(d+1,d+1+n); d[n+1].x=d[n].x; cnt=1;
      for(int i=1; i<=n; i++)
      {
            p[d[i].n].ny=cnt;
            if(d[i].x!=d[i+1].x)cnt++;
      }
      memset(z,0,sizeof(z));
      for(int i=1,j; i<=n; ins(i++))
            if(j=query(i))G.add(p[i].id,p[j].id,dis(i,j));
}
int main()
{
      n=F();
      for(int i=1; i<=n; i++)p[i]=(P) {F(),F(),i}; work();
      for(int i=1; i<=n; i++)swap(p[i].x,p[i].y); work();
      for(int i=1; i<=n; i++)p[i].y=-p[i].y; work();
      for(int i=1; i<=n; i++)swap(p[i].x,p[i].y); work(); G.make();
      printf("%lld\n",ans);
}
/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-11-15.31
* Time: 0MS
* Memory: 137KB
*/
