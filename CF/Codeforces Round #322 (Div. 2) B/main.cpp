/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-21.27
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

const LL MAXN=1e5+10;
LL a[MAXN];
LL ans[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL n;
      scanf("%I64d",&n);
      for(LL i=0;i<n;++i)
      {
            scanf("%I64d",&a[i]);
      }
      LL mx=a[n-1]-1;
      for(LL i=n-1;i>=0;--i)
      {
            if(a[i]>mx)
            {
                  ans[i]=0;
            }
            else
            {
                  ans[i]=mx+1-a[i];
            }
            mx=max(mx,a[i]);
      }
      for(LL i=0;i<n;++i)
      {
            printf("%I64d ",ans[i]);
      }
      puts("");

      return 0;
}
/*

*/
