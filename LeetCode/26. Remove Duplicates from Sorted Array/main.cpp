/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-19-15.57
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
    int removeDuplicates(vector<int>& nums)
    {
        auto endPtr=unique(nums.begin(),nums.end());
        return (endPtr-nums.begin());
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
        cout<<solution.removeDuplicates(ve)<<endl;
    }
    return 0;
}
/*

*/
