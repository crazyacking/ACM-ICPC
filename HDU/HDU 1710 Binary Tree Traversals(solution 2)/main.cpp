/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-04-20.09
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

int n;
vector<int> pr; // pre Order
vector<int> in; // in Order
vector<int> po; // post Order

void getPostOrder(int a,int b,int n,bool flag)
{
      if(n==1)
      {
            po.push_back(pr[a]);
            return;
      }
      else if(n<=0)
            return;
      int i=0;
      for(;pr[a]!=in[b+i];++i);
      getPostOrder(a+1,b,i,false);
      getPostOrder(a+i+1,b+i+1,n-i-1,false);
      po.push_back(pr[a]);
}

int main()
{
      while(cin>>n)
      {
            pr.clear();
            in.clear();
            po.clear();
            for(int i=0;i<n;++i)
            {
                  int tmp;
                  cin>>tmp;
                  pr.push_back(tmp);
            }
            for(int i=0;i<n;++i)
            {
                  int tmp;
                  cin>>tmp;
                  in.push_back(tmp);
            }

            getPostOrder(0,0,n,true);
            for(int i=0;i<n;++i)
            {
                  if(i<n-1)
                        cout<<po[i]<<" ";
                  else cout<<po[i]<<endl;
            }
      }
      return 0;
}
