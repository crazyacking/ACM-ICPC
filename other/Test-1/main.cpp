/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-09-21-21.28
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

const int MOD=1000000007;
int main()
{
      int a=1,b=3,c;
      for(int i=1;;++i)
      {
            if(a==0 && b==1)
            {
                  printf("%d\n",i);
                  break;
            }
            c=(3*b+a)%MOD;
            a=b;
            b=c;
      }
      return 0;
}
/*

*/
