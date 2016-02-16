/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-16-10.53
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
      int n;
      while(cin>>n)
      {
          vector<int> ve;
          for(int i=0;i<n;++i)
          {
              int tmp;
              cin>>tmp;
              ve.push_back(tmp);
          }
          cout<<*ve.rbegin()5<<endl;
          for(auto p:ve)
          {
              cout<<p<<endl;
          }
      }
      return 0;
}
