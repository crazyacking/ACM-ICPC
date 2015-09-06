/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-05-16.43
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

long long Quickpow(long long a,long long b,long long m) {
      long long ans=1;
      while(b) {
            if(b&1) { ans=(ans*a)%m,b--; }
            b/=2,a=a*a%m;
      }
      return ans;
}

int n;
int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t;
      scanf("%d",&t);
      while(t--)
      {
            scanf("%d",&n);
            vector<int> ve;
            for(int i=1;i<=n;++i)
            {

            }
      }
      return 0;
}
/*

*/
