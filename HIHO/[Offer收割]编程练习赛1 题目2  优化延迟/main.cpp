/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-06-14.47
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

using namespace std;
const int M = 10+int(1e5);
long long Q;
int N,p[M];
bool check(int x)
{
    int now = 0;
    long long currentPos = 0;
    priority_queue<int> q;
    for(int i = 1; i < x; ++i)
        q.push(p[i]);
    for(int i = x; i <= N; ++i)
    {
        q.push(p[i]);
        long long t = q.top();
        q.pop();
        ++now;
        currentPos += t*now;
    }
    if(currentPos > Q) return false;
    while(!q.empty())
    {
        long long t = q.top();
        q.pop();
        ++now;
        currentPos += t*now;
    }
    return (currentPos <= Q);
}

int main()
{
    cin >> N >> Q;
    for(int i = 1; i <= N; ++i)
        cin >> p[i];
    int l = 1,r = N+1;
    while(l < r)
    {
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(l > N) l = -1;
    printf("%d\n",l);
    return 0;
}

