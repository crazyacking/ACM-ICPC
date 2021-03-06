/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-31-08.20
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

const int MAXN=1000050;
double a[MAXN],b[MAXN],c[MAXN];
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
            for(int i=0;i<n;++i)
            {
                  scanf("%lf",&a[i]);
                  if(i)
                  {
                        b[i]=a[i]-a[i-1];
                        if(a[i-1]>1e-7)
                              c[i]=a[i]/a[i-1];
                  }
            }
            int ans=1,l=1,r=1;
            for(int i=2;i<n;++i)
            {
                  if(b[i]==b[i-1]) l++; else l=1;
                  if(c[i]==c[i-1]) r++; else r=1;
                  ans=max(ans,max(l,r));
            }
            printf("%d\n",min(ans+1,n));
      }
      return 0;
}
/*

*/
