/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-30-22.55
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

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int seed = 10;
const int MAXN = 1e5+6;
const ULL MOD = (1e9+9);
char str[MAXN];
ULL s[10][MAXN],p[MAXN];
void pre()
{
      int i,j;
      p[0]=1;
      for(i=1; i<MAXN; i++)
            p[i]=p[i-1]*seed%MOD;
      for(i=0; i<=9; i++)
      {
            s[i][1]=i;
            for(j=2; j<=100000; j++)
            {
                  s[i][j]=s[i][j-1]*seed+i;
                  s[i][j]%=MOD;
            }
      }
}
struct node
{
      ULL v;
      int len;
      node() {}
      node(ULL v,int l) :v(v),len(l) {}
};
ULL tree[MAXN<<2];
struct segtree
{
      int lazy[MAXN<<2];
      void pushdown(int l,int r,int rt)
      {
            if(lazy[rt]>=0)
            {
                  int m=(l+r)>>1;
                  lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
                  tree[rt<<1]=s[lazy[rt]][m-l+1];
                  tree[rt<<1|1]=s[lazy[rt]][r-(m+1)+1];
                  lazy[rt]=-1;
            }
      }
      void pushup(int l,int r,int rt)
      {
            tree[rt]=tree[rt<<1]*p[(r-l+1)>>1]+tree[rt<<1|1];
            tree[rt]%=MOD;
      }
      void build(int l,int r,int rt)
      {
            lazy[rt]=-1;
            if(l==r)
            {
                  tree[rt]=str[l]-'0';
                  return ;
            }
            int m=(l+r)>>1;
            build(lson);
            build(rson);
            pushup(l,r,rt);
      }
      void update(int L,int R,int v,int l,int r,int rt)
      {
            if(L<=l && r<=R)
            {
                  tree[rt]=s[v][r-l+1];
                  lazy[rt]=v;
                  return ;
            }
            pushdown(l,r,rt);
            int m=(l+r)>>1;
            if(L<=m)
                  update(L,R,v,lson);
            if(R>m)
                  update(L,R,v,rson);
            pushup(l,r,rt);
      }
      node query(int L,int R,int l,int r,int rt)
      {
            if(L<=l && r<=R)
                  return node(tree[rt],r-l+1);
            pushdown(l,r,rt);
            int m=(l+r)>>1;
            node p1(-1,-1),p2(-1,-1);
            if(L<=m)
                  p1=query(L,R,lson);
            if(R>m)
                  p2=query(L,R,rson);
            pushup(l,r,rt);
            if(p1.len==-1)
                  return p2;
            if(p2.len==-1)
                  return p1;
            return node((p1.v*p[p2.len]+p2.v)%MOD,p1.len+p2.len);
      }
} T;

int main()
{
      pre();
      int n,m,k,tp,x,y,v;
      scanf("%d%d%d%s",&n,&m,&k,str+1);
      T.build(1,n,1);
      m+=k;
      while(m--)
      {
            scanf("%d%d%d%d",&tp,&x,&y,&v);
            if(tp==1)
                  T.update(x,y,v,1,n,1);
            else
            {
                  if((y-x+1)<=v)
                  {
                        puts("YES");
                        continue ;
                  }
                  node temp1=T.query(x,y-v,1,n,1);
                  node temp2=T.query(x+v,y,1,n,1);
                  temp1.v==temp2.v?puts("YES"):puts("NO");
            }
      }
      return 0;
}
