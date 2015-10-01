/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-01-08.59
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
LL mod=10007;
LL dp[50010];
LL d[50010];

int main()
{
      LL h=0;
      for(int i=0;i<s.length();i++)
            h=(h*10+s[i]-'0')%mod;
      cout<<h<<endl;
      int n,m,k;
      while(scanf("%d%d%d",&n,&m,&k)!=EOF)
      {
            k>>=1;
            for(int i=1; i<=m; i++)
            {
                  int t=k-i;
                  dp[i]=dp[i-1];
                  if(t>0)
                  {
                        if(n<=t)
                              dp[i]+=LL(1+n)*n/2;
                        else
                              dp[i]+=LL(1+t)*t/2+(n-t)*t;
                  }
                  d[i]=d[i-1]+dp[i];
                  dp[i]%=mod;
                  d[i]%=mod;
            }
            cout<<d[m]<<endl;
      }
      return 0;
}
/*

*/
