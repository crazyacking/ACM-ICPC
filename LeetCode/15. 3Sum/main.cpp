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
        vector<vector<int> > ret;
        sort(nums.begin(),nums.end());
        int target,sum,low,high;
        for(int i=0;i<si;i++)
        {
            target=-nums[i];
            low=i+1;
            high=si-1;
            // not exist two active integet's sum greater than target
            if(target<0)
                break;

            while(low<high)
            {
                sum=nums[low]+nums[high];
                if(sum<target)
                    ++low;
                else if(sum>target)
                    --high;
                else
                {
                    vector<int> triple(3,0);
                    triple[0]=nums[i];
                    triple[1]=nums[low];
                    triple[2]=nums[high];
                    ret.push_back(triple);
                    while(low<high && triple[1]==nums[low]) ++low;
                    while(low<high && triple[2]==nums[high]) --high;
                }
            }
            while(i+1 < nums.size() && nums[i+1] == nums[i])
                ++i;
        }
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
                cout<<p2<<" ";
            cout<<endl;
        }
    }
    return 0;
}
