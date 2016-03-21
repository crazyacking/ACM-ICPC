/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-02-08.49
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
    int searchInsert(vector<int>& nums, int target)
    {
        int len=nums.size();
        if(!len || target<=nums[0])
            return 0;
        if(target>nums[len-1])
            return len;
        int low=0,high=len-1;
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(target<nums[mid])
            {
                if(mid-1>=0 && target>nums[mid-1])
                    return mid;
                high=mid-1;
            }
            else if(target>nums[mid])
            {
                if(mid+1<len && target<nums[mid+1])
                    return mid+1;
                low=mid+1;
            }
            else
                return mid;
        }
        return 0;
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
        cout<<"pos="<<solution.searchInsert(ve,k)<<endl;
    }
    return 0;
}
/*

*/
