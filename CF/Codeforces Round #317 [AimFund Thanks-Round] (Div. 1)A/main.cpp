/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-23-01.40
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
LL a,b,c,l,gap;
int main()
{
      while(cin>>a>>b>>c>>l)
      {
            LL ans=1;
            for(LL i=1;i<=l;++i)
            {
                  ans+=i*(i+1)/2+i+1;
            }
            for(LL i=0;i<=l;++i)
            {
                  gap=max((a+b+i-c+1)/2,(LL)0);
                  if(gap<=i)
                        ans-=(i-gap+2)*(i-gap+1)/2;
                  gap=max((c+b+i-a+1)/2,(LL)0);
                  if(gap<=i)
                        ans-=(i-gap+2)*(i-gap+1)/2;
                  gap=max((a+c+i-b+1)/2,(LL)0);
                  if(gap<=i)
                        ans-=(i-gap+2)*(i-gap+1)/2;
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
