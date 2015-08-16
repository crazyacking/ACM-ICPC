/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-16-16.39
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
#define  LL __int64
#define  ULL unsigned __int64
using namespace std;
const LL mod = 1000000007;
LL inv[5000];
LL N,X,D;
void pre()
{
      inv[1] = 1;
      for(int i=2; i<5000; i++)
            inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}
int main()
{
      pre();
      while(scanf("%d %I64d %d",&N,&D,&X) && N)
      {
            LL ans = 0;
            for(int i=0; i*X<=N; i++)
            {
                  LL p = 1;
                  if(i <= D)
                  {
                        for(int j=1; j<=i; j++)
                        {
                              p = (D - j + 1) % mod * p % mod;
                              p = p * inv[j] % mod;
                        }
                  }
                  else p = 0;
                  for(int j=0; j<i; j++) p = (mod - p);
                  int shen = N - i*X;
                  for(int j=1; j<=shen; j++)
                  {
                        p = (D + shen - j + mod) % mod * p % mod;
                        p = p * inv[j] % mod;
                  }
                  ans = ans + p;
                  if(ans >= mod)
                        ans -= mod;
            }
            printf("%I64d\n",ans);
      }
      return 0;
}
