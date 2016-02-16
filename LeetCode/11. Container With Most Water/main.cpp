/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-16-09.42
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
/*
// Time Limit Exceeded
class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        if(height.size()<=1)
            return 0;
        vector<int> frontIdx;
        frontIdx.push_back(0);
        auto ret=0;
        for(auto i=1;i<height.size();++i)
        {
            for(auto idx:frontIdx)
            {
                ret=max(ret,min(height[idx],height[i])*(i-idx));
            }
            auto endIdx=*frontIdx.rbegin();
            if(height[i]>height[endIdx])
                frontIdx.push_back(height[i]);
        }
        return ret;
    }
};
*/

//for(int i=0;i<n;++i)
//    for(int j=i+1;j<n;++j)
//        ...

class Solution
{
public:
    int maxArea(vector<int>& height)
    {
        int si=height.size();
        int low=0,high=si-1;
        int ret=0;
        while(low<high)
        {
            ret=max(ret,min(height[low],height[high])*(high-low));
            if(height[low]<height[high])
                ++low;
            else
                --high;
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    auto n=0;
    while(cin>>n)
    {
        vector<int> ve;
        for(int i=0; i<n; ++i)
        {
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        cout<<solution.maxArea(ve)<<endl;
    }
    return 0;
}
