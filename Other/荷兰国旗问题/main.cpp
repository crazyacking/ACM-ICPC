/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-06-18.19
 */
#include <queue>
#include <cstdio>
#include <set>
#include <string>
#include <stack>
#include <cmath>
#include <climits>
#include <map>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);


class Solution
{
public:
    Solution(){};
    ~Solution(){};

    void Dutch_National_Flag_Problem(vector<int>& a)
    {
        int start=0,current=0,en=a.size()-1;
        while(current<=en)
        {
            if(a[current]==0)
                swap(a[current++],a[start++]);
            else if(a[current]==1)
                current++;
            else
                  swap(a[current],a[en--]);
        }
    }
protected:
private:
};

int main()
{
      srand((unsigned)time(NULL));
      Solution so;
      int n,tmp;
      while(cin>>n)
      {
            vector<int> ve;
            for(int i=0;i<n;++i)
            {
                  cout<<(tmp=rand()%3)<<" ";
                  ve.push_back(tmp);
            }
            cout<<endl;
            puts("------------------------------------");
            so.Dutch_National_Flag_Problem(ve);
            for(auto p:ve)
                  cout<<p<<" ";
            cout<<endl;
      }
      return 0;
}
