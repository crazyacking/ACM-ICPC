/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-19-17.22
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

const LL MAXN=5000050;
int A[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL t;
      scanf("%d",&t);
      for(LL Cas=1; Cas<=t; ++Cas)
      {
            LL n,a,b;
            scanf("%I64d %I64d %I64d",&n,&a,&b);
            for(LL i=0; i<n; ++i)
            {
                  scanf("%d",&A[i]);
            }
            LL fr_pos=-1,bk_pos=-1;
            LL fr=LLONG_MIN,bk=LLONG_MIN;
            for(LL i=0; i<n; ++i)
            {
                  LL tmp=a*A[i]*A[i];
                  if(tmp>fr)
                  {
                        fr=tmp;
                        fr_pos=i;
                  }
            }
            for(LL i=0; i<n; ++i)
            {
                  if(i!=fr_pos)
                  {
                        LL tmp=b*A[i];
                        if(tmp>bk)
                        {
                              bk=tmp;
                        }
                  }
            }
            LL ans1=fr+bk;
            fr=bk=LLONG_MIN;
            for(LL i=0; i<n; ++i)
            {
                  LL tmp=bk*A[i];
                  if(tmp>bk)
                  {
                        bk=tmp;
                        bk_pos=i;
                  }
            }
            for(LL i=0; i<n; ++i)
            {
                  if(i!=bk_pos)
                  {
                        LL tmp=a*A[i]*A[i];
                        if(tmp>fr)
                        {
                              fr=tmp;
                        }
                  }
            }
            LL ans2=fr+bk;
            LL ans=max(ans1,ans2);
            printf("Case #%d: %I64d\n",Cas,ans);
      }
      return 0;
}
/*

*/
