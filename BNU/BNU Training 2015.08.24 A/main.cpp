/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-24-12.14
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
#define  ULL unsigned LL
using namespace std;

LL gcd(LL a,LL b)
{
      return !b?a:gcd(b,a%b);
}

LL lcm(LL a,LL b)
{
      return a*b/gcd(a,b);
}

int main()
{
      LL a,b;
      int t;
      cin>>t;
      for(int cas=1;cas<=t;++cas)
      {
            scanf("%I64d%I64d",&a,&b);
            while(gcd(a,b)!=1)
                  a/=gcd(a,b);
            if(a-1==0)
                  printf("Case #%d: YES\n",cas);
            else printf("Case #%d: NO\n",cas);

      }
      return 0;
}
/*

*/
