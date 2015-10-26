/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-10-26-21.35
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
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

const int MAXN=100010;
long long r[MAXN],o[MAXN],b[MAXN],a[MAXN];
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
            scanf("%lld%lld",&r[i],&o[i]);
            for(int i=0;i<n;i++)
            {
                a[i]=r[i];
                b[i]=r[i]-o[i];
            }
            sort(b,b+n,cmp);
            long long mx=0x3fff;
            long long ans=0;
            for(int i=0;i<n;i++)
            {
                ans-=a[i];
                if(ans<mx)
                  mx=ans;
                  ans+=b[i];
            }
            cout<<(-mx)<<endl;
    }
    return 0;
}
