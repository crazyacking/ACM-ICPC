/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-11-16.35
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

int main()
{
    int64_t x1,y1,x2,y2,r;
    while(cin>>r>>x1>>y1>>x2>>y2)
    {
        long double dis=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
        long double a=dis/(2.*r);;;
        cout<<ceil(a)<<endl;
    }
    return 0;
}
/*

*/
