/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-06-19.05
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
    bool isMatch(string s, string p)
    {
        int star_=-1,ts;
        int ss(0),pp(0);
        while(ss<s.length())
        {
            if(s[ss]==p[pp] || p[pp]=='?')
            {
                ++ss,++pp;
                continue;
            }
            if(p[pp]=='*')
            {
                star_=pp++,ts=ss;
                continue;
            }
            if(star_!=-1)
            {
                pp=star_+1,ss=++ts;
                continue;
            }
            return false;
        }
        while(p[pp]=='*')
            ++pp;
        return (pp==p.length());
    }
};

int main()
{
    string s1,s2;
    while(cin>>s1>>s2)
    {
        Solution solution;
        bool res=solution.isMatch(s1,s2);
        if(res)
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}
/*

*/
