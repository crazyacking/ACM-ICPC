/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-30-16.35
* Time: 0MS
* Memory: 137KB
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
const int MAXN=100010;
int n,h[MAXN],L[MAXN],R[MAXN];
int main()
{
    cin>>n;
    for(int i=1;i<=n;++i) scanf("%d",&h[i]);
    h[0]=h[n+1]=0;
    for(int i=1;i<=n;++i)L[i]=min(h[i],L[i-1]+1);
    for(int i=n;i;--i) R[i]=min(h[i],R[i+1]+1);
    int ans=0;
    for(int i=1;i<=n;++i) ans=max(ans,min(L[i],R[i]));
    cout<<ans<<endl;
    return 0;
}
