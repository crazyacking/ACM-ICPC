/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-22-20.10
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
#define mod 1000000007
#define  LL long long
#define  ULL unsigned long long
using namespace std;

const LL NN=10000010;
bool v[NN];
LL p[NN];
void makePrime()
{
      LL num=-1,i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            if(i>=sqrt(1000005000)) break;
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
//      for(int i=0;i<10;++i)
//      {
//            printf("%lld ",p[i]);
//      }
//      puts("");
      cout<<num<<endl;
      cout<<p[num]<<endl;
}
long long Quickpow(long long a,long long b,long long m) {
      long long ans=1;
      while(b) {
            if(b&1) { ans=(ans*a)%m,b--; }
            b/=2,a=a*a%m;
      }
      return ans;
}


LL cnt1[31610],cnt2[31610];
int main()
{
      makePrime();
      /**< 大于p[31610]的质数怎么办 */
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL t;
      scanf("%d",&t);
      while(t--)
      {
            LL n;
            scanf("%lld",&n);
            LL tmp=n;
            memset(cnt1,0,sizeof cnt1),memset(cnt2,0,sizeof cnt2);
            for(LL i=0;i<=3400&&tmp>1;++i)
            {
                  while(tmp%p[i]==0)
                  {
                        tmp/=p[i];
                        ++cnt1[i];
                  }
            }

            for(LL i=0;i<=3400;++i)
            {
                  LL t=p[i];
                  for(;t<=n;t*=p[i])
                  {
                        cnt2[i]+=(n)/t;
                  }
            }
            LL ans=0;
            for(LL i=0;i<=3400;++i)
            {

            }
            cout<<ans<<endl;
            ans+=n;
            printf("%lld\n",ans%mod);


      }
      return 0;
}
/*

*/
