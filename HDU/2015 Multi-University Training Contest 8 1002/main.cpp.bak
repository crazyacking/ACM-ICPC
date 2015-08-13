/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-13-15.31
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
const int MAXN=10+(int)1e4;
LL a[MAXN];
long long gcd(long long a,long long b)
{
      return !b?a:gcd(b,a%b);
}

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      cin>>t;
      while(t--)
      {
            int n,q;
            cin>>n;
            for(int i=0; i<n; ++i)
                  cin>>a[i];
            cin>>q;
            while(q--)
            {
                  LL ans=0,l,r,tmp;
                  cin>>l>>r;
                  --l,--r;
                  for(int i=l; i<=r; ++i)
                  {
                        for(int j=i; j<=r; ++j)
                        {
                              tmp=a[i];
                              for(int sta=i+1,en=j; sta<=en; ++sta)
                                    tmp=gcd(tmp,a[sta]);
                              ans+=tmp;
                        }
                  }
                  cout<<ans<<endl;
            }
      }
      return 0;
}
/*

*/
