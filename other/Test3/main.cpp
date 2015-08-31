/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-30-21.21
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
#define Max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=1000010;
long long z[MAXN],f[MAXN],zz[MAXN],ff[MAXN];
int a[MAXN];
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

void print(int x)
{
      if(x>9) print(x/10);
      putchar(x%10+'0');
}
/**************************************END     define***************************************/
int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scan(n);
            for(int i=0;i<n;++i) scan(a[i]);
            long long sum=0,ans1=0,ans2=0,mx;
            for(int i=0;i<n;++i)
            {
                  sum+=a[i];
                  if(sum<0) sum=0;
                  ans1=Max(ans1,sum);
            }
            z[0]=a[0],f[n-1]=a[n-1];
            for(int i=1;i<n;++i)
                  z[i]=z[i-1]+a[i];
            zz[0]=Max(0LL,z[0]),ff[n-1]=Max(0LL,f[n-1]);
            mx=zz[0];
            for(int i=1;i<n;++i)
            {
                  mx=Max(z[i],mx);
                  zz[i]=mx;
            }
            for(int i=n-2;i>=0;--i)
                  f[i]=f[i+1]+a[i];
            mx=ff[n-1];
            for(int i=n-2;i>=0;--i)
            {
                  mx=Max(f[i],mx);
                  ff[i]=mx;
            }
            for(int i=0;i<n-1;++i)
            {
                  ans2=Max(ans2,zz[i]+ff[i+1]);
            }
            printf("%I64d\n",Max(ans1,ans2));
      }
      return 0;
}
/*

*/
