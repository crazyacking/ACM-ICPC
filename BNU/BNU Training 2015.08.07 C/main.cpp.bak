/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-07-22.19
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
const int MAXN=50010;
LL a[MAXN];
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      LL n;
      while(cin>>n)
      {
            for(int i=0;i<n;++i) cin>>a[i];
            LL ans=a[0],sum=0;
            for(int i=0;i<n;++i)
            {
                  sum+=a[i];
                  sum=max(sum,0LL);
                  ans=max(ans,sum);
            }
            cout<<ans<<endl;
      }
      return 0;
}
/*

*/
