/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-11-23.37
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
#include <climits>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=200;
int a[MAXN];
int main()
{
      int n,m,tmp;
      while(cin>>n>>m)
      {
            for(int i=0;i<MAXN;++i) a[i]=INT_MAX;
            for(int i=0;i<n;++i)
            {
                  for(int j=0;j<m;++j)
                  {
                        cin>>tmp;
                        a[i]=min(a[i],tmp);
                  }
            }
            int ans=INT_MIN;
            for(int i=0;i<n;++i)
                  ans=max(ans,a[i]);
            cout<<ans<<endl;
      }
      return 0;
}
