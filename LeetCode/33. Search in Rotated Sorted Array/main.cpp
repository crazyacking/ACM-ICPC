/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-01-21.22
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
    int search(vector<int>& nums, int target)
    {
        int len=nums.size();
        int low1=0,high1=len-1,low2=0,high2=len-1;
        for(int i=1;i<len;++i)
        {
            if(nums[i]<nums[i-1])
            {
                high1=i-1,low2=i;
                break;
            }
        }
        if(high1==len-1 && low2==0)
            return isExist(nums,low1,high2,target);
        else
        {
            int idx1=isExist(nums,low1,high1,target);
            int idx2=isExist(nums,low2,high2,target);
            if(idx1==-1 && idx2==-1)
                return -1;
            else
                return idx1!=-1?idx1:idx2;
        }
    }

    int isExist(vector<int>& nums,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid=(low+high)>>1;
            if(target<nums[mid])
                high=mid-1;
            else if(target>nums[mid])
                low=mid+1;
            else return mid;
        }
        return -1;
    }
};

int main()
{
    Solution solution;
    int n,k;
    vector<int> ve;
    while(cin>>n>>k)
    {
        int tempVal;
        for(int i=0; i<n; ++i)
        {
            cin>>tempVal;
            ve.push_back(tempVal);
        }
        int ans=solution.search(ve,k);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
