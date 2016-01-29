/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2015-01-29-14.24
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

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
            int cnt=0;
            vector<int> ans;
            multimap<int,int> mp;
            for(auto p:nums)
                  mp.insert(make_pair(p,cnt++));
            for(auto p:mp)
            {
                  if(mp.count(target-p.first)>0)
                  {
                        multimap<int,int>::iterator it1,it2;
                        if((p.first==target-p.first)&&(mp.count(p.first)==2))
                        {
                              it1=mp.find(p.first);
                              ans.push_back((*it1).second+1);
                              mp.erase(it1);
                              it2=mp.find(p.first);
                              ans.push_back((*it2).second+1);
                              break;
                        }
                        it1=mp.find(p.first);
                        it2=mp.find(target-p.first);
                        ans.push_back((*it1).second+1);
                        ans.push_back((*it2).second+1);
                        break;
                  }
            }
            sort(ans.begin(),ans.end());
            return ans;
    }
};

int main()
{
      int n;
      while(cin>>n)
      {
            vector<int> ve;
            for(int i=0,tmp;i<n;++i)
            {
                  cin>>tmp;
                  ve.push_back(tmp);
            }
            int target;
            cin>>target;
            Solution a;
            vector<int> ans=a.twoSum(ve,target);
            for(auto p : ans)
                  cout<<p<<endl;
      }
      return 0;
}
