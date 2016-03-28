/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-27-13.59
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
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int sta=n-1;
    for(int i=n-1;i>=0;--i)
    {
        if(i==n-1);
        else
        {
            if(a[i]<a[i+1])
                sta=i;
            else
            {
                sta=i;
                break;
            }
        }
    }
    for(int i=0;i<=sta;++i)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
/*

*/
