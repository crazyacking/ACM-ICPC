/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-15-15.08
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
    int reverse(int x)
    {
        bool isNeg(x<0?1:0);
        int64_t xx;
        if(x<0) xx=-1*(int64_t)x;
        else xx=(int64_t)x;
        int64_t ret=0;
        while(xx)
        {
            int tmp=xx%10;
            xx/=10;
            ret=ret*10+tmp;
        }
        if(ret>INT_MAX)
            return 0;
        if(isNeg)
            ret=-ret;
        return ret;
    }
};

int main()
{
    cout<<LLONG_MAX<<endl;
    Solution solution;
    int x;
    while(cin>>x)
    {
        cout<<solution.reverse(x)<<endl;
    }
    return 0;
}
