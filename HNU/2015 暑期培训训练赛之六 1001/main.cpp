/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-09-16.10
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
using namespace std;

void scan(int &x)
{
      x=0;
      char c=getchar();
      while(!(c>='0' && c<='9'  || c=='-')) { c=getchar(); }
      bool flag=1;
      if(c=='-')
      {
            flag=0; c=getchar();
      }
      while(c>='0' && c<='9')
      {
            x=x*10+c-'0'; c=getchar();
      }
      if(!flag) { x=-x; }
}
void scan2(int &x,int &y) { scan(x),scan(y);}
void scan3(int &x,int &y,int &z) { scan(x),scan(y),scan(z); }
/**************************************END     define***************************************/
const int MAXN=50010;
int n,x,y,w,h,f[MAXN],area[MAXN],answer[MAXN];
struct L {
      int x,l,r,id;
      L(int a,int b,int c,int d) : x(a), l(b), r(c), id(d) {}
      bool operator <(const L &a) const { return x==a.x? l<a.l:x<a.x;}
};
vector<L> L1,L2;
int Find(int x) { return f[x]==x?x:f[x]=Find(f[x]); }

void work(int si,vector<L> &LL) {
      int a,b,j=1;
      for(int i=0; i<si; i=j,++j) {
            while(j<si && LL[j].x == LL[i].x) ++j;
            int li = LL[i].r,id=LL[i].id;
            for(int k=i+1; k<j; ++k) {
                  if(LL[k].l<=li) {
                        a=Find(id),b=Find(LL[k].id);
                        if(a!=b) f[a]=b;
                  }
                  if(LL[k].r>li) li=LL[k].r,id=LL[k].id;
            }
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d",&n))
      {
            L1.clear(),L2.clear();
            for(int i=0; i<n; ++i)
            {
                  scan2(x,y),scan2(w,h);
                  L1.push_back(L(x,y,y+h,i));
                  L1.push_back(L(x+w,y,y+h,i));
                  L2.push_back(L(y,x,x+w,i));
                  L2.push_back(L(y+h,x,x+w,i));
                  f[i]=i,area[i]=w*h,answer[i]=0;
            }
            sort(L1.begin(),L1.end());
            sort(L2.begin(),L2.end());
            work(L1.size(),L1);
            work(L2.size(),L2);
            int ans=INT_MIN;
            for(int i=0; i<n; ++i) { answer[Find(i)]+=area[i]; }
            for(int i=0; i<n; ++i) ans=max(ans,answer[i]);
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
