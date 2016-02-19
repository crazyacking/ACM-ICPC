/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-19-16.20
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
    int removeElement(vector<int>& nums, int val)
    {
        int cnt=0;
        for(int i=0;i<nums.size();++i)
            if(nums[i]==val)
                ++cnt;
            else
                nums[i-cnt]=nums[i];
        return (nums.size()-cnt);
    }
};

int main()
{
    Solution solution;
    int n,val;
    while(cin>>n>>val)
    {
        vector<int> ve;
        for(int i=0;i<n;++i)
        {
            int tmp;
            cin>>tmp;
            ve.push_back(tmp);
        }
        cout<<solution.removeElement(ve,val)<<endl;
    }
    return 0;
}
/*

*/
