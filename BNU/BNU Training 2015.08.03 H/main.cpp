/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-02.13
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

typedef long long ll;
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      int n,k,a;
      while(~scanf("%d %d",&n,&k))
      {
            map<ll,ll> dp[4];
            for(int i=1;i<=n;++i)
            {
                  scanf("%d",&a);
                  if(a%k==0)
                  {
                        dp[3][a]+=dp[2][a/k];
                        dp[2][a]+=dp[1][a/k];
                  }
                  dp[1][a]++;
            }
            ll ans=0;
            for(map<ll,ll> :: iterator it=dp[3].begin();it!=dp[3].end();++it)
            {
                  ans+=it->second;
            }
            printf("%lld\n",ans);
      }
      return 0;
}
/*

*/
