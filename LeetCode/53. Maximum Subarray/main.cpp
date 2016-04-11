/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-21-11.15
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
    int maxSubArray(vector<int>& nums)
    {
        if(!nums.size())
            return 0;
        int res=0,sum=0;
        int maxVal=INT_MIN;
        for(int i=0;i<nums.size();++i)
        {
            sum+=nums[i];
            if(sum<0)
                sum=0;
            maxVal=max(maxVal,nums[i]);
            res=max(res,sum);
        }
        if(maxVal<0) res=maxVal;
        return res;
    }
};

int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> nums(n);
        for(int i=0;i<n;++i)
            cin>>nums[i];
        Solution solution;
        int ans=solution.maxSubArray(nums);
        cout<<ans<<endl;
        cout<<"----------------------"<<endl;
    }
    return 0;
}
/*

*/
