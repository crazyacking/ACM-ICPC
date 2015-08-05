/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-04-21.25
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

int main() {
      long long t,n,m,z,l,ans,tmp;
      cin>>t;
      while(t--) {
            ans=tmp=0;
            cin>>n>>m>>z>>l;
            for(int i=1; i<=n; ++i) { ans^=(tmp+tmp); tmp=(tmp*m+z)%l;}
            cout<<ans<<endl;
      }
      return 0;
}
