/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-16-17.21
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
    vector<vector<int> > threeSum(vector<int>& nums)
    {
        int si=nums.size();
        set<int> se;
        for(auto p:nums)
            se.insert(p);
        int t1,t2;
        vector<vector<int> > ret;
        for(int i=0;i<si;++i)
        {
            for(int j=i+1;j<si;++j)
            {
                se.erase(nums[i]);
                se.erase(nums[j]);
                if(se.find(-1*(nums[i]+nums[j]))!=se.end())
                {
                    vector<int> tv;
                    tv.push_back(nums[i]);
                    tv.push_back(nums[j]);
                    tv.push_back(-1*(nums[i]+nums[j]));
                    sort(tv.begin(),tv.end());
                    ret.push_back(tv);
                }
                se.insert(nums[i]);
                se.insert(nums[j]);
            }
        }
        cout<<"size1:"<<ret.size()<<endl;
        sort(ret.begin(),ret.end());
        unique(ret.begin(),ret.end());
        vector<vector<int> > ::iterator it1,it2;

        cout<<"size2:"<<ret.size()<<endl;
        puts("===============begin================Program Run Here !=============================");
        for(auto p1:ret)
        {
            for(auto p2:p1)
            {
                cout<<p2<<" ";
            }
            cout<<endl;
        }
        puts("================end===============Program Run Here !=============================");

        return ret;
    }
};

int main()
{
    Solution solution;
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
        vector<vector<int> > ans;
        ans=solution.threeSum(ve);
        for(auto p1:ans)
        {
            for(auto p2:p1)
            {
                cout<<p2<<" ";
            }
            cout<<endl;
        }
        cout<<"End."<<endl;
    }
    return 0;
}
