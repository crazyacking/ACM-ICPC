//  Memory   Time
//  1347K     0MS
//   by : Snarl_jsb
//   2015-03-20-21.15
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1000010
#define LL long long
using namespace std;
LL exp_mod(LL a, LL b, LL p) {
    LL res = 1;
    while(b != 0) {
        if(b&1) res = (res * a) % p;
        a = (a*a) % p;
        b >>= 1;
    }
    return res;
}

LL Comb(LL a, LL b, LL p) {
    if(a < b)   return 0;
    if(a == b)  return 1;
    if(b > a - b)   b = a - b;

    LL ans = 1, ca = 1, cb = 1;
    for(LL i = 0; i < b; ++i) {
        ca = (ca * (a - i))%p;
        cb = (cb * (b - i))%p;
    }
    ans = (ca*exp_mod(cb, p - 2, p)) % p;
    return ans;
}

LL Lucas(int n, int m, int p) {
     LL ans = 1;
     while(n&&m&&ans) {
        ans = (ans*Comb(n%p, m%p, p)) % p;
        n /= p;
        m /= p;
     }
     return ans;
}

int main()
{
    int n, m, p;
    while(~scanf("%d%d%d", &n, &m, &p))
    {
        printf("%lld\n", Lucas(n, m, p));
    }
    return 0;
}
