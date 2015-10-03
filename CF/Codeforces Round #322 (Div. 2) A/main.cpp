/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-03-21.20
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n,m;
      cin>>n>>m;
      if(n>m) swap(n,m);
      cout<<n<<" "<<(m-n)/2<<endl;

      return 0;
}
/*

*/
