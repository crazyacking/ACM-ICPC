/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-17-16.33
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
    bool isValid(string s)
    {
        stack<char> sta;
        for(auto p:s)
        {
            if(p=='(' || p=='{' || p=='[')
                sta.push(p);
            //
            else if(p==')')
            {
                char tp=sta.top();
                sta.pop();
            }
            else if(p=='}')
            {

            }
            else
            {

            }

        }
    }
};

int main()
{

    return 0;
}
/*

*/
