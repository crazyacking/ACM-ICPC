/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-07-20.59
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

class Solution
{
public:
    int mySqrt(int x)
    {
        if(x <= 1) return x;
        int left = 1, right = x;
        while(left < right)
        {
            int mid = (left+right)>>1;
            if(mid <= x / mid)
                left = mid + 1;
            else
                right = mid;
        }
        return left - 1;
    }
};

int main()
{
    int64_t n;
    while(cin>>n)
    {
        Solution solution;
        cout<<solution.mySqrt(n)<<endl;
    }
    return 0;
}
/*

*/
