/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-02-17.50
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m,k;
      while(~scanf("%d %d %d",&n,&m,&k))
      {
            int x=k>>1;
            int a_up=x-1;
            if(a_up>n) a_up=n;
            long long n1,n2,a1,ans=0;
            for(int a=1;a<=a_up;++a)
            {
                  int b_up=x-a;
                  if(b_up>m) b_up=m;
                  n1=n-a+1;
                  // calc n2
                  a1=m-b_up+1;
                  n2=(LL)b_up*a1+((LL)b_up*(b_up-1)/2);
                  ans+=(n1*n2);
            }
            printf("%lld\n",ans);
      }
      return 0;
}
/*

*/
