/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-29-09.55
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

const int MAXN=100010;
int a[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      scanf("%d",&n);
      for(int i=0;i<n;++i)
      {
            scanf("%d",&a[i]);
      }
      int ans=1;
      int cnt=1;
      for(int i=0;i<n-1;++i)
      {
            if(a[i]<=a[i+1])
            {
                ++cnt;
            }
            else
            {
                  ans=max(ans,cnt);
                  cnt=1;
            }
      }
      ans=max(ans,cnt);
      printf("%d\n",ans);
      return 0;
}
/*

*/
