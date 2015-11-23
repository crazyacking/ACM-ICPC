/*
* -----------------------------------------------------------------
* Copyright (c) 2015 crazyacking All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Verdict: Accepted
*       Submission Date: 2015-11-20-15.29
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
      int n;
      int x[4],y[4];
      while(cin>>n)
      {
            for(int i=0;i<n;++i)
                  cin>>x[i]>>y[i];
            bool flag=0;
            for(int i=0;i<n;++i)
            {
                  for(int j=i+1;j<n;++j)
                  {
                        if(x[i]!=x[j] && y[i]!=y[j])
                        {
                              cout<<abs(x[i]-x[j])*abs(y[i]-y[j])<<endl;;
                              flag=1;
                              break;
                        }
                  }
                  if(flag) break;
            }
            if(!flag) cout<<-1<<endl;
      }
      return 0;
}
/*

*/
