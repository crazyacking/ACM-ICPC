/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-12.08
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

long long Quickpow(long long a,long long b,long long m) {
      long long ans=1;
      while(b) {
            if(b&1) { ans=(ans*a)%m,b--; }
            b/=2,a=a*a%m;
      }
      return ans;
}

int main() {
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int t,x;
      cin>>t;
      while(t--) {
            cin>>x; cout<<((Quickpow(2,x-1,1000000007)-1)%1000000007)<<endl;
      }
      return 0;
}
/*

*/
