/**<

<2016今日头条后端开发在线笔试>

给定两个整数x和k,  x+y=x|y

*/

/**
* -----------------------------------------------------------------
* Copyright (c) 2016 crazyacking.All rights reserved.
* -----------------------------------------------------------------
*       Author: crazyacking
*       Date  : 2016-04-27-20.23
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
    long long x,k,y;
    while(cin>>x>>k)
    {
        int tmp=1;
        while(x)
        {
            long long low=(tmp-1)&k;
            long long high=k-low;
            if(x&1)
            {
                high<<=1;
            }
            k=high+low;
            tmp<<=1;
            x>>=1;
        }
        cout<<k<<endl;
    }
    return 0;
}
