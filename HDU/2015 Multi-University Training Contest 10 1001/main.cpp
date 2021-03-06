/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-21-15.17
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

const int NN=1000010;
bool v[NN];
int p[NN],num;
void makePrime()
{
      int i,j;
      num=-1;
      for(i=2; i<NN; ++i)
      {
            if(!v[i]) { p[++num]=i; }
            for(j=0; j<=num && i*p[j]<NN; ++j)
            {
                  v[i*p[j]]=true;
                  if(i%p[j]==0) { break; }
            }
      }
}
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      makePrime();
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            LL ans=1;
            for(int i=0; i<=num; ++i)
            {
                  for(LL t=p[i]; t<=n; t*=p[i])
                  {
                        if((n+1)%t!=0)
                              ans=ans*p[i]%mod;
                  }
            }
            printf("%lld\n",ans);
      }
      return 0;
}
/*

*/
