/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-23-23.15
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
#define MAXN 40005
#define MOD 1000000007
#define  LL long long
#define  ULL unsigned long long
using namespace std;

LL ans;
int fac[40];
int numfac[40];

bool v[MAXN];
int p[MAXN];
void makePrime()
{
      int num=-1,i,j;
      for(i=2; i<MAXN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<MAXN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
}

int getFactor(int x)
{
      int num=0;
      memset(numfac,0,sizeof(numfac));
      for(int i=0; p[i]*p[i]<=x; ++i)
      {
            if(x%p[i]==0)
            {
                  while(x%p[i]==0)
                  {
                        x/=p[i];
                        ++numfac[num];
                  }
                  fac[num++]=p[i];
            }
      }
      if(x>1)
      {
            numfac[num]=1;
            fac[num++]=x;
      }
      return num;
}

void dfs(LL dep,LL k,LL si, LL tm)
{
      if(dep==si)
      {
            ans=(ans+k*tm/2LL)%MOD;
            return;
      }
      LL tmp=1,tt=1;
      for(int i=0; i<=numfac[dep]; ++i)
      {
            dfs(dep+1,k*tmp,si, tt * tm);
            tmp=tmp*fac[dep];
            if(i == 0) tt *= (fac[dep] - 1);
            else tt *= fac[dep];
      }
}

void scan(int &x)
{
      x=0;
      char c=getchar();
      while(!(c>='0' && c<='9'  | c=='-')) { c=getchar(); }
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

void print(int &a)
{
      if(a>9) print(a/10);
      putchar(a%10+'0');
}
/**************************************END     define***************************************/

int main()
{
      makePrime();
      int n,t,si;
      scan(t);
      while(t--)
      {
            ans=0;
            scan(n);
            si=getFactor(n);
            dfs(0,1,si, 1);
            ans = (ans + 1LL) * (LL)n;
            print(ans%MOD);
            putchar(10);
      }
      return 0;
}
