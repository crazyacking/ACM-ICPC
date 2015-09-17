/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-16-23.44
* Time: 0MS
* Memory: 137KB
贪心
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

long long a[400005];
long long as[400005];
long long n,m,k;
long long ans_mx;
int main()
{
      scanf("%I64d %I64d %I64d",&n,&m,&k);
      long long p=1;
      long long i;
      for(i=0; i<n; i++)
      {
            scanf("%I64d",&a[i]);
      }
      for(i=0; i<m; i++) p*=k;
      for(i=0; i<n; i++) as[i]=a[i]*p;
      long long item=0;
      for(i=0; i<n; i++)
      {
            as[i]|=item;
            item|=a[i];
      }
      item=0;
      for(i=n-1; i>=0; i--)
      {
            as[i]=as[i]|item;
            item=item|a[i];
      }
      ans_mx=0;
      for(i=0; i<n; i++)
            ans_mx=max(ans_mx,as[i]);
      printf("%I64d\n",ans_mx);
      return 0;
}
