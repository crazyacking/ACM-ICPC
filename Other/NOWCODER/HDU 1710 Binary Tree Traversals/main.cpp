/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-03-22.24
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
vector<int> pr;
vector<int> in;
vector<int> ans;
void work(int a,int b,int n,bool flag)
{
      if(n==1)
      {
            ans.push_back(pr[a]);
            return;
      }
      else if(n<=0)
            return ;
      int i=0;
      for(;pr[a]!=in[b+i];++i);
      work(a+1,b,i,false);
      work(a+1+i,b+1+i,n-i-1,false);
      ans.push_back(pr[a]);
}
int main()
{
      while(cin>>n)
      {
            pr.clear();
            in.clear();
            ans.clear();
            int tmp;
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  pr.push_back(tmp);
            }
            for(int i=0;i<n;++i)
            {
                  cin>>tmp;
                  in.push_back(tmp);
            }
            work(0,0,n,true);
            for(int i=0;i<n;++i)
            {
                  if(!i) cout<<ans[i];
                  else cout<<" "<<ans[i];
            }
            cout<<endl;
      }
      return 0;
}
