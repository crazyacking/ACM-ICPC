/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-08.50
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
    int threeSumClosest(vector<int>& nums, int target)
    {
        int si=nums.size();
        if(si<3) return 0;
        if(si==3) return (nums[0]+nums[1]+nums[2]);
        int64_t res=INT_MAX,low,high,sum,tsum;
        sort(nums.begin(),nums.end());

        for(int i=0;i<si;++i)
        {
            low=i+1;
            high=si-1;
            tsum=target-nums[i];
            while(low<high)
            {
                sum=(nums[i]+nums[low]+nums[high]);
                if(abs(target-res)>abs(target-sum))
                    res=sum;

                if(nums[low]+nums[high]<tsum)
                    ++low;
                else if(nums[low]+nums[high]>tsum)
                    --high;
                else
                    return target;
            }
        }
        return (int)res;
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
        int ans=solution.threeSumClosest(ve,target);
        cout<<ans<<endl;
    }
    return 0;
}
