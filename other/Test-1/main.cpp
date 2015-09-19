#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 131;
typedef long long LL;

LL Pow_Mod(LL a, LL b, LL p)
{
    LL ret = 1;
    while(b)
    {
        if(b & 1) ret = (ret * a) % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void Exgcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if(b == 0) { d = a, x = 1, y = 0; }
    else { Exgcd(b,a%b,d,y,x); y -= x * (a / b); }
}
///////////////////////////// Lucas
LL Fac[maxn], Inv[maxn];

void Init(LL n)
{
    Fac[0] = 1;
    for(LL i = 1; i < n; ++i) Fac[i] = Fac[i-1] * i % n;
    Inv[n-1] = Pow_Mod(Fac[n-1], n-2, n);
    for(LL i = n-2; i >= 0; --i) Inv[i] = Inv[i+1] * (i + 1) % n;
}

LL C(LL m, LL n, LL p)
{
    if(n > m || m < 0 || n < 0) return 0;
    return (Fac[m] * Inv[n]) % p * Inv[m-n] % p;
}

LL Lucas(LL m, LL n, LL p)
{
    if(n == 0) return 1;
    return Lucas(m/p, n/p, p) * C(m%p, n%p, p) % p;
}
//////////////////////////////////
LL Ai[maxn], Pi[maxn];

LL mul(LL a, LL b, LL p)
{
    a = (a % p + p) % p;
    b = (b % p + p) % p;
    LL ret = 0;
    while(b)
    {
        if(b & 1) ret = (ret + a)  % p;
        b >>= 1;
        a <<= 1;
        a %= p;
    }
    return ret;
}

LL China(int n, LL *a, LL *m)
{
    LL x, y, d, M = 1;
    LL ret = 0;
    for(int i = 1; i <= n; ++i) M = M * m[i];
    for(int i = 1; i <= n; ++i)
    {
        LL w = M / m[i];
        /*  Wa  */
//        y = Pow_Mod(w, m[i]-2, m[i]);
        Exgcd(m[i],w,d,d,y) ;
        ret = (ret + mul(a[i], mul(y, w, M), M)) % M;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL m, n; int k;
        scanf("%lld%lld%d", &m, &n, &k);
        for(int i = 1; i <= k; ++i)
        {
            scanf("%llu",&Pi[i]);
            Init(Pi[i]);
            Ai[i] = Lucas(m,n,Pi[i]);
        }
        LL ans = China(k,Ai,Pi);
        printf("%lld\n",ans);
    }
}
