/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-15.44
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
const int MAXN=10+(int)1e5;
LL a[MAXN],sum[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            int n;
            scanf("%d",&n);
            memset(sum,0,sizeof sum);
            for(int i=1;i<=n;++i)
            {
                  scanf("%I64d",&a[i]); sum[i]+=sum[i-1]+a[i];
            }
            LL ans=0,tmp;
            for(int i=1;i<=n;++i)
            {
                  for(int j=i;j<=n;++j)
                  {
                        tmp=(log(sum[j]-sum[i-1])/log(2)+1)*(i+j);
                        printf("%lld ",(LL)(log(sum[j]-sum[i-1])/log(2)+1.000001));
                        ans+=tmp;
                  }
                  puts("");
            }
            puts("");
            puts("- - - - - - - - - - - Program Run Here ! - - - - - - - - - - - - ");

//            printf("%I64d\n",ans);
      }
      return 0;
}
/*

*/
