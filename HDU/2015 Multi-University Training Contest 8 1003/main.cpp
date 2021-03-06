/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-14-15.28
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
#define mod 258280327
#define  ULL unsigned long long
using namespace std;

const int N=1000020,M=200020;
LL g[N];
int pri[N],tot;
bool isnot[N];

void get_prime()
{
      isnot[0]=isnot[1]=1;
      g[0]=0,g[1]=1;
      for(int i=2;i<N;++i)
      {
            if(!isnot[i])
            {
                  pri[tot++]=i;
                  g[i]=2;
            }
            for(int j=0;pri[j]*i<N && j<tot;++j)
            {
                  isnot[pri[j]*i]=1;
                  if(i%pri[j])
                  {
                        g[i*pri[j]]=g[i]*g[pri[j]];
                        if(g[i*pri[j]]>=mod)
                              g[i*pri[j]]%=mod;
                  }
                  else
                  {
                        g[i*pri[j]]=g[i];
                        break;
                  }
            }
      }

      for(int i=0;i<20;++i)
      {
            printf("%2d : %d\n",i,g[i]);
      }
}

void add(int &x,int y)
{
      x+=y;
      if(x>=mod) x-=mod;
}
int t[N],f[N];

void init()
{
      for(int i=1;i<N;++i)
      {
            for(int j=1;j*i<N;++j)
                  add(t[i*j],(int)g[j-1]);
      }
      f[1]=1;
      for(int i=2;i<N;++i)
      {
            f[i]=f[i-1]+(2*i-1);
            if(f[i]>=mod) f[i]-=mod;
            add(f[i],-t[i-1]);
      }
}
int s[N];

void solve()
{
      get_prime();
      init();
      for(int i=1;i<N;++i)
      {
            s[i]=s[i-1]+f[i];
            if(s[i]>=mod)
                  s[i]-=mod;
      }
}

int main()
{
      solve();
      int Cas;
      scanf("%d",&Cas);
      while(Cas--)
      {
            int n;
            scanf("%d",&n);
            printf("%d\n",s[n]);
      }

      return 0;
}
/*

*/
