/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-19-17.45
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
    int divide(int dividend, int divisor)
    {
        if(!divisor || (dividend==INT_MIN && divisor==-1))
            return INT_MAX;
        bool sign=(dividend<0)^(divisor<0);
        long long dvd=labs(dividend);
        long long dvs=labs(divisor);
        int res=0;
        while(dvd>=dvs)
        {
            long long tmp=dvs,multiple=1;
            while(dvd>=(tmp<<1))
            {
                tmp<<=1;
                multiple<<=1;
            }
            dvd-=tmp;
            res+=multiple;
        }
        return sign?-res:res;
    }
};

int main()
{
    Solution solution;
    int a,b;
    while(cin>>a>>b)
    {
        cout<<solution.divide(a,b)<<endl;
    }
    return 0;
}
/*

*/
