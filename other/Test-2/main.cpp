/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-13-11.08
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

/** Lucas
 * p必须是小于100010的质数
 */
using namespace std;
long long F[100010];
void init(long long p)
{
      F[0] = 1;
      for(int i = 1; i <= p; i++)
            F[i] = F[i-1]*i%p;
}
long long inv(long long a,long long m)
{
      if(a == 1)return 1;
      return inv(m%a,m)*(m-m/a)%m;
}
long long Lucas(long long n,long long m,long long p)
{
      long long ans = 1;
      while(n&&m)
      {
            long long a = n%p;
            long long b = m%p;
            if(a < b)return 0;
            ans = ans*F[a]%p*inv(F[b]*F[a-b]%p,p)%p;
            n /= p;
            m /= p;
      }
      return ans;
}

int main()
{
      int T;
      int n,m,p;
      scanf("%d",&T);
      while(T--)
      {
            scanf("%d%d",&n,&m);
            p=131;
            init(p);
            printf("%d\n",(int)Lucas(n,m,p));
      }
     return 0;
}
