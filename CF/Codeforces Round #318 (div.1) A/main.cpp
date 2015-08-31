/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-30-09.26
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

int main()
{
      ios_base::sync_with_stdio(false);
      cin.tie(0);
      int n;
      scanf("%d",&n);
      int res=-1;
      while(n--)
      {
            int a;
            scanf("%d",&a);
            while(a%2==0) a/=2;
            while(a%3==0) a/=3;
            if(res==-1) res=a;
            if(res!=a)
            {
                  puts("No");
                  return 0;
            }
      }
      puts("Yes");
      return 0;
}
/*

*/
