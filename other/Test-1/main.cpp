/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-01-07-09.46
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

const int MAXN=15010;
struct N
{
    double x;
    int p;
} a[MAXN];
int b[MAXN];

int cmp(N a,N b)
{
    return a.x<b.x;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        memset(b,0,sizeof(b));
        for(int i=0; i<n; i++)
            scanf("%d%d",&a[i].x,&a[i].p);
        sort(a,a+n,cmp);
        int s=0;
        for(int i=0; i<n; i++)
        {
            s+=a[i].p;
            b[i]=s;
        }
        int mid=s/2,w;
        for(int i=0; i<n; i++)
        {
            if(b[i]>=mid)
            {
                w=i;
                break;
            }
        }
        printf("%d\n",a[w].x);
    }
    return 0;
}
