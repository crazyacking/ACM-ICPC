/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-08-13.39
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

const int MAXN=20010;
int a[MAXN],b[MAXN],r[MAXN],t[MAXN*3],n;
struct buff
{
      int v,id;
      buff(){}
      buff(int v,int id):v(v),id(id){}
      bool operator<(const buff& a)const
      {
            return v<a.v;
      }
}ar[MAXN];

int lowbit(int x)
{
      return x&(-x);
}

void add(int x)
{
      while(x<=n)
      {
            t[x]+=1;
            x+=lowbit(x);
      }
}
int query(int x)
{
      int ans=0;
      while(x>0)
      {
            ans+=t[x];
            x-=lowbit(x);
      }
      return ans;
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int T,v;
      scanf("%d",&T);
      while(T--)
      {
            memset(b,0,sizeof b);
            memset(r,0,sizeof r);
            memset(t,0,sizeof t);
            scanf("%d",&n);
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&v);
                  ar[i]=buff(v,i+1);
            }
            sort(ar,ar+n);
            for(int i=0;i<n;++i)
                  a[ar[i].id]=i+1;
            for(int i=1;i<=n;++i)
            {
                  b[i]=query(a[i]);
                  add(a[i]);
            }
            memset(t,0,sizeof t);
            for(int i=n;i>=1;--i)
            {
                  r[i]=query(a[i]);
                  add(a[i]);
            }
            LL ans=0;
            for(int i=2;i<n;++i)
                  ans+=b[i]*(n-i-r[i])+(i-b[i]-1)*r[i];
            printf("%lld\n",ans);

      }
      return 0;
}
/*

*/
