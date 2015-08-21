/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-20-12.03
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
#define  ULL unsigned long long
using namespace std;

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
            scanf("%d%d%d",&n,&m,&p);
            init(p);
            printf("%d\n",(int)Lucas(n,m,p));
      }
     return 0;
}

//
//long long gcd(long long a,long long b)
//{
//      return !b?a:gcd(b,a%b);
//}
//
//long long lcm(long long a,long long b)
//{
//      return a*b/gcd(a,b);
//}
//
//
//int main()
//{
//      ios_base::sync_with_stdio(false);
//      cin.tie(0);
//      int t;
//      scanf("%d",&t);
//      while(t--)
//      {
//            LL N;
//            scanf("%lld",&N);
//            LL ans=0;
//            init(100010);
//            for(LL i=0;i<=N;++i)
//            {
//                  cout<<Lucas(N,i,1000)<<endl;
////                  ans=lcm(ans,Lucas(N,i,1000000007));
//            }
////            printf("%lld\n",ans%1000000007);
//      }
//
//      return 0;
//}
///*
//
//*/
