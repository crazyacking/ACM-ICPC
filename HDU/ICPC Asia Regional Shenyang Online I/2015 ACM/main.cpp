/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-19-12.12
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



LL aa[1000050];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL t;
      scanf("%lld",&t);
      for(LL Cas=1; Cas<=t; ++Cas)
      {
            LL n,a,b;
            scanf("%lld %lld %lld",&n,&a,&b);
            LL min_abs=INT_MAX;
            LL max_abs=INT_MIN;
            map<int,long long> mp;
            int min_pos=-1;
            int max_pos=-1;
            for(LL i=0; i<n; ++i)
            {
                  scanf("%lld",&aa[i]);
                  if(abs(aa[i])<min_abs)
                  {
                        min_abs=abs(aa[i]);
                        min_pos=i;
                  }
                  if(abs(aa[i])>max_abs)
                  {
                        max_abs=abs(aa[i]);
                        max_pos=i;
                  }
            }
            mp.insert()
            sort(aa,aa+n);

            while(i==n-1 ||j==n-1)
            {
                  n--;
            }
            if(n>=2)
            {
                  ve.push_back((LL)aa[n-1]);
                  ve.push_back((LL)aa[n-2]);
            }
            ve.push_back((LL)aa[n-1]);
            ve.push_back((LL)aa[n-2]);
            ve.push_back((LL)aa[0]);
            ve.push_back((LL)aa[1]);
            long long ans=LLONG_MIN;
            for(LL i=0; i<6; ++i)
            {
                  for(LL j=0; j<6; ++j)
                  {
                        if(i!=j)
                        {
                              ans=max(ans,a*ve[i]*ve[i]+b*ve[j]);
                              ans=max(ans,a*ve[j]*ve[j]+b*ve[i]);
                        }
                  }
            }
            printf("%lld\n",ans);
      }
      return 0;
}
/*

*/
