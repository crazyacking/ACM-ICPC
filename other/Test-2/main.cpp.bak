/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-10-22.47
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

const int MOD = 1000000007;
typedef long long LL;

int cnt=0;
int a[50];
LL n,inv;

// prime factor decomposition
void primeFactorization(int n)
{
      cnt=0;
      for(int i=2; i*i<=n; i++)
      {
            if(n%i==0)
            {
                  a[cnt++]=i;
                  while(n%i==0)
                        n/=i;
            }
      }
      if(n>1) a[cnt++]=n;
}

LL mulMod(LL a,LL b,LL m)
{
      LL ans = 0;
      while(b)
      {
            if(b&1)
            {
                  ans = (ans + a)%m;
                  b--;
            }
            b>>=1;
            a=a*2;
            if(a>n) a%=m;
      }
      return ans;
}

LL quickPow(LL a,LL b,LL m)
{
      LL ans = 1;
      while(b)
      {
            if(b&1)
            {
                  ans=mulMod(ans,a,m);
                  b--;
            }
            b>>=1;
            a=mulMod(a,a,m);
      }
      return ans;
}
// Exponential sum
LL f(LL n)
{
      LL ans=n;
      ans=(ans*(n+1))%MOD;
      ans=(ans*(2*n+1))%MOD;
      ans=(ans*((3*n*n+3*n-1)%MOD))%MOD;
      ans=(ans*inv)%MOD;
      return ans;
}

LL solve(LL n)
{
      primeFactorization(n);
      LL ans = 0;
      for(int i=1; i<(1<<cnt); i++)
      {
            LL tmp = 1;
            int tt = 0;
            for(int j=0; j<cnt; j++)
            {
                  if((1<<j)&i)
                  {
                        tmp=tmp*a[j];
                        tt++;
                  }
            }
            LL q=n/tmp;
            LL t = mulMod(mulMod(tmp,tmp,MOD),mulMod(tmp,tmp,MOD),MOD);
            if(tt&1)
                  ans=(ans+mulMod(f(q),t,MOD))%MOD;
            else
                  ans=(ans-mulMod(f(q),t,MOD)+MOD)%MOD;
      }
      return ans;
}

int main()
{
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%I64d",&n);
            if(n==1)
            {
                  puts("0");
                  continue;
            }
            inv = quickPow(30,MOD-2,MOD);
            LL tmp = f(n);
            LL ans = solve(n);
            ans=(tmp-ans+MOD)%MOD;
            printf("%I64d\n",ans);
      }
      return 0;
}
