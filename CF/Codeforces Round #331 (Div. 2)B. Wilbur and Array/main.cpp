/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Submission Date: 2015/3/25
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
const double eps(1e-8);;
const LL MAXN=200010;
LL b[MAXN];
int main()
{
      LL n;
      while(~scanf("%I64d",&n))
      {
            for(LL i=0;i<n;++i)
                  scanf("%I64d",&b[i]);
            LL now=b[0];
            LL step=abs(b[0]);
            for(LL i=1;i<n;++i)
            {
                  if(now!=b[i])
                  {
                        step+=abs(now-b[i]);
                        now=b[i];
                  }
            }
            printf("%I64d\n",step);
      }
      return (0);
}
/*

*/
