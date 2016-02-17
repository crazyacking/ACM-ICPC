/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-13.10
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
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<vector<int>> res;
        int si=nums.size();
        if(si<4) return res;
        std::sort(nums.begin(),nums.end());
        int target_3,target_2;
        int low,high;
        for(int i=0;i<si;++i)
        {
            target_3=target-nums[i];
            for(int j=i+1;j<si;++j)
            {
                target_2=target_3-nums[j];
                low=j+1;
                high=si-1;
                while(low<high)
                {
                    int two_sum=nums[low]+nums[high];
                    if(two_sum<target_2)
                        ++low;
                    else if(two_sum>target_2)
                        --high;
                    else
                    {
                        vector<int> quadruplet(4,0);
                        quadruplet[0]=nums[i];
                        quadruplet[1]=nums[j];
                        quadruplet[2]=nums[low];
                        quadruplet[3]=nums[high];
                        res.push_back(quadruplet);
                        while(low<high && nums[low]==quadruplet[2]) ++low;
                        while(low<high && nums[high]==quadruplet[3]) --high;
                    }
                }
                while(j+1<si && nums[j+1]==nums[j]) ++j;
            }
            while(i+1<si && nums[i+1]==nums[i]) ++i;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    int n,target;
    while(cin>>n>>target)
    {
        vector<int> ve;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        auto ans=solution.fourSum(ve,target);
        for(auto p1:ans)
        {
            for(auto p2:p1)
                cout<<p2<<" ";
            cout<<endl;
        }
    }
    return 0;
}
/*

*/
