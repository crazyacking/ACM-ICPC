/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-08-20.40
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

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string,vector<string>> mp;
        for(int i=0;i<strs.size();++i)
        {
            string _str=strs[i];
            sort(_str.begin(),_str.end());
            mp[_str].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto mp_ptr:mp)
        {
            vector<string> _res;
            for(auto _mp_ptr:mp_ptr.second)
            {
                _res.push_back(_mp_ptr);
            }
            sort(_res.begin(),_res.end());
            res.push_back(_res);
        }
        return res;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<string> strs(n);
        for(int i=0;i<n;++i)
            cin>>strs[i];
        Solution solution;
        auto ans=solution.groupAnagrams(strs);
        for(auto p1:ans)
        {
            for(auto p2:p1)
                cout<<p2<<" ";
            cout<<endl;
        }
    }
    return 0;
}
