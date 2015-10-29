/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-27-08.23
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

const int MAXN=50010;
int a[MAXN<<1];
int n;
int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\in.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\out.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      while(~scanf("%d",&n))
      {
            LL sum=0;
            for(int i=0; i<n; ++i)
            {
                  scanf("%d",&a[i]);
                  sum+=a[i];
            }
            LL ans1=0,sum1=0;
            LL ans2=0,sum2=0;
            for(int i=0;i<n;++i)
            {
                  sum1+=a[i];
                  if(sum1<0)
                        sum1=0;
                  ans1=max(ans1,sum1);

                  sum2+=a[i];
                  if(sum2>0)
                        sum2=0;
                  ans2=min(ans2,sum2);
            }
            printf("%I64d\n",(LL)(max(ans1,sum-ans2)));
      }
      return 0;
}
/*

*/
