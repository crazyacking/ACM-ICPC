/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-13-13.43
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

long long a[10000];
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int tmp;
      int cnt=0;
      while(~scanf("%d, ",&tmp))
      {
            a[cnt++]=tmp;
      }
      for(int i=0;i<cnt;++i)
      {
            LL sum=0;
            for(int j=0;j<i;++j)
            {
                  sum+=a[j];
            }
            printf("%lld,",sum);
      }


      return 0;
}
/*

*/
