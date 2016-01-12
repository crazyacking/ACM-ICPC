/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-08-10.51
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

long long a, b, c;
long long x1, x2, y1, y2;
long long x, y;

long long exgcd(long long a, long long b)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        long long t = exgcd(b, a%b), s = x;
        x = y;
        y = s-(a/b)*y;
        return t;
    }
}

long long solve()
{
    scanf("%lld %lld %lld", &a, &b, &c);
    scanf("%lld %lld %lld %lld", &x1, &x2, &y1, &y2);
    c = -c;

    if(a == 0 && b == 0 && c != 0)
    {
        return 0;
    }
    if(a == 0 && b == 0 && c == 0)
    {
        return (x2-x1+1)*(y2-y1+1);
    }

    if(a == 0)
    {
        long long sign = 0;
        if(y1 <= c/b && y2 >= c/b && c%b == 0)
        {
            sign = 1;
        }
        return (x2-x1+1)*sign;
    }
    if(b == 0)
    {
        long long sign = 0;
        if(x1 <= c/a && x2 >= c/a && c%a == 0)
        {
            sign = 1;
        }
        return (y2-y1+1)*sign;
    }

    long long gcd = exgcd(a, b);
    long long ans = 0;

    if(c%gcd != 0)
    {
        return 0;
    }

    /* 求交集 */
    x = x*(c/gcd);
    y = y*(c/gcd);
    // 减小步长
    a /= gcd;
    b /= gcd;
    long long lx = (x1-x>0&&(x1-x)%b!=0)?
                   ((x1-x)/b+1):
                   ((x1-x)/b);
    long long rx = (x2-x<0&&(x2-x)%b!=0)?
                   ((x2-x)/b-1):
                   ((x2-x)/b);
    long long ly = (y-y2>0&&(y-y2)%a!=0)?
                   ((y-y2)/a+1):
                   ((y-y2)/a);
    long long ry = (y-y1<0&&(y-y1)%a!=0)?
                   ((y-y1)/a-1):
                   ((y-y1)/a);
    if(lx > rx)
    {
        swap(lx, rx);
    }
    if(ly > ry)
    {
        swap(ly, ry);
    }
    if(rx >= ly && ry >= lx)
    {
        ans = min(rx,ry)-max(lx,ly)+1;
    }
    return ans;
}

int main(int argc, char **argv)
{
    printf("%lld", solve());
    return 0;
}
