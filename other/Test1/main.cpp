/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-03-15.46
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

const LL MAXN=10+(LL)1e6;
LL a,n,ans,cnt;
LL p[MAXN];

LL rongchi(LL n)
{
      LL rup=(1<<cnt),su,tmp,ans=0;
      for(LL i=1;i<rup;++i)
      {
            su=0,tmp=1;
            for(LL j=0;j<cnt;++j)
            {
                  if((1<<j)&i)
                  {
                        tmp*=p[j];
                        su++;
                  }
            }
            if(su&1) ans+=n/tmp;
            else ans-=n/tmp;
      }
      return ans;

}

LL solve(LL a,LL n)
{
      cnt=0;
      LL up=int(sqrt(a)+1e-5);
      for(LL i=2;i<=up;++i)
      {
            if(!(a%i))
            {
                  while(!(a%i)) { a/=i; }
                  p[cnt++]=i;
            }
      }
      if(a>1) p[cnt++]=a;
      return rongchi(n);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(cin>>a>>n)
      {
            if(a&1) cout<<((n+1)/2+solve(a,(n/2)))<<endl;
            else cout<<solve(a,n)<<endl;
      }
      return 0;
}
/*

*/
