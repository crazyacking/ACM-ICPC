/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-02-15-18.27
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
        if(p.empty())
            return s.empty();

        if(p[1]=='*')
            return isMatch(s,p.substr(2))
                    || (!s.empty() && (s[0]==p[0] || '.'==p[0]) && isMatch(s.substr(1),p));
        else
            return !s.empty() && (s[0]==p[0] || '.' == p[0]) && isMatch(s.substr(1),p.substr(1));
    }
};

int main()
{
    return 0;
}


class Solution
{
public:
    bool isMatch(string s, string p)
    {
        if (p.empty()) // if p is empty, then s also is empty.
            return s.empty();

        // x* matches empty string or at least one character: x* -> xx*
        // *s is to ensure s is non-empty
        if (p[1]=='*')
            return (isMatch(s, p.substr(2)) ||  (!s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p)));
        else
            return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
    }
};
