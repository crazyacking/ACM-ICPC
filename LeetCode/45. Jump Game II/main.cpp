/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights steperved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-08-14.52
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
    int jump(vector<int>& nums)
    {
        int i(0), j(1), steps(0), N(nums.size());
        while(j < N)
        {
            int endj = min(nums[i]+i, N);
            while(j < =endj)
            {
                if(nums[j] + j > nums[i] + i)
                    i = j;
                j++;
            }
            steps++;
        }
        return steps;
    }
};

// this is my TLE code :(
//class Solution
//{
//public:
//    int jump(vector<int>& nums)
//    {
//        queue<pair<int,int>> que; // pos,step
//        int res=INT_MAX;
//        que.push(make_pair(0,0));
//        while(!que.empty())
//        {
//            pair<int,int> top=que.front();
//            que.pop();
//            if(top.first>=nums.size()-1)
//                res=min(res,top.second);
//            for(int i=1;i<=nums[top.first] && i+top.first<=nums.size();++i)
//            {
//                que.push(make_pair(top.first+i,top.second+1));
//            }
//        }
//        return res;
//    }
//};


int main()
{
    int n;
    while(cin>>n)
    {
        vector<int> ve;
        for(int i=0; i<n; ++i)
        {
            int tempVal;
            cin>>tempVal;
            ve.push_back(tempVal);
        }
        Solution solution;
        int ans=solution.jump(ve);
        cout<<ans<<endl;
    }
    return 0;
}
/*

*/
