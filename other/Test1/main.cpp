/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-23-02.20
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

int main()
{
      LL a[3],l;
      while(cin>>a[0]>>a[1]>>a[2]>>l)
      {
            sort(a,a+3);
            LL ans=0;
            for(LL i=0;i<=l;++i)
            {
                  LL k=a[2]+i-a[1]-a[0]+1;
                  if(k<=l-i)
                  {
                        ans+=((l-i+1)*(l-i+2))/2;
                        if(k>=0)
                              ans-=((k+1)*k)/2;
                  }
                  LL k1=a[2]+i+a[0]-a[1];
                  LL c1=max(k1,k);
                  if(c1<=l-i)
                  {
                        LL las=(l-i-c1)/2;
                        ans-=(c1+2-k1)*(las+1);
                        ans-=las*(las+1);
                        if(c1+2*las==l-i)
                              ans+=((l-i-k1)/2+1);
                  }
                  LL k2=a[2]+i+a[1]-a[0];
                  LL c2=max(k2,k);
                  if(c2<=l-i)
                  {
                        LL las=(l-i-c2)/2;
                        ans-=(c2+2-k2)*(las+1);
                        ans-=las*(las+1);
                        if(c2+2*las==l-i)
                              ans+=((l-i+k2)/2+1);
                  }
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
