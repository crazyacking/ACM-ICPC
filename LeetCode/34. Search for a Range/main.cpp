/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-01-22.03
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
    vector<int> searchRange(vector<int>& nums, int target)
    {
        vector<int> ret;
        int len=nums.size();
        int low=0,high=len-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(target<nums[mid])
                high=mid-1;
            else if(target>nums[mid])
                low=mid+1;
            else
            {
                int frontIndex=mid,backIndex=mid;
                while(frontIndex-1>=0 && nums[frontIndex]==nums[frontIndex-1])
                    --frontIndex;
                while(backIndex+1<len && nums[backIndex]==nums[backIndex+1])
                    ++backIndex;
                ret.push_back(frontIndex);
                ret.push_back(backIndex);
                return ret;
            }
        }
        ret.push_back(-1);
        ret.push_back(-1);
        return ret;
    }
};

int main()
{
    Solution solution;
    int n,k;
    while(cin>>n>>k)
    {
        vector<int> ve;
        for(int i=0;i<n;++i)
        {
            int tempVal;
            cin>>tempVal;
            ve.push_back(tempVal);
        }
        ve=solution.searchRange(ve,k);
        for(auto p:ve)
            cout<<p<<endl;
    }
    return 0;
}
/*

*/
