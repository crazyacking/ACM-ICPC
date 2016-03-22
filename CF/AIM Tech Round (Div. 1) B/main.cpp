/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-22-21.49
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

int gcd(int a, int b)
{
    return b?gcd(b, a%b):a;
}
int in[1000001], n, a, b;
std::set<int> primes;
void addP(int x)
{
    for(int i=2; x>1 && i <= x/i; i++)
    {
        if(x%i == 0)
        {
            primes.insert(i);
            while(x%i==0) x/=i;
        }
    }
    if(x!=1) primes.insert(x);
}
long long solve(int P)
{
    long long ans = 0, t=0;
    int i, j, i1, j1;
    for(i=1; i<=n && in[i]%P == 0; i++);
    for(j=n; j>=1 && in[j]%P == 0; j--);
    if(i>j) return 0;
    ans = 1ll*a*(j-i+1);
    if(in[i]%P == 1 || in[i]%P == P-1) for(i1=i+1; i1<=n && in[i1]%P==0; i1++);
    else i1 = i;

    if(in[j]%P == 1 || in[j]%P == P-1) for(j1=j-1; j1>=1 && in[j1]%P==0; j1--);
    else j1 = j;

    if(i<=j1) t = 1ll*a*(j1-i+1) + b;
    else t = b;
    if(ans > t) ans = t;

    if(i1<=j) t = 1ll*a*(j-i1+1) + b;
    else t = b;
    if(ans > t) ans = t;

    return ans;
}
int main()
{
    int i;
    scanf("%d%d%d", &n, &a, &b);
    for(i=1; i<=n; i++) scanf("%d", in+i);
    addP(in[1]);
    addP(in[2]);
    addP(in[n]);
    addP(in[n-1]);
    long long min = 1000000000000000000ll;
    for(int p: primes)
    {
        long long t = solve(p);
        if(min > t) min = t;
    }
    printf("%lld", min);
    return 0;
}


/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-22-21.49
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
const int MN = 1000000+1;

int N;
ll A[MN];
ll a,b;

ll gcd(ll a,ll b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

map<ll, ll> D[MN];
map<ll, ll> D2[MN];
map<ll,ll> D3[MN];
ll ans = 1e18;

void push(map<ll,ll> &D,ll g,ll v)
{
    if(g==1)return;
    if(D.find(g)==D.end() || D[g]>v)
    {
        D[g]=v;
    }
}

int main()
{
    scanf("%d%lld%lld",&N,&a,&b);
    ans = (N-1)*a;
    for(int i=0; i<N; i++)scanf("%lld",&A[i]);
    D[0][A[0]]=0;
    D[0][A[0]-1]=b;
    D[0][A[0]+1]=b;
    for(int i=1; i<N; i++)
    {
        for(auto &p:D[i-1])
        {
            push(D[i],gcd(p.first,A[i]),p.second);
            push(D[i],gcd(p.first,A[i]-1),p.second+b);
            push(D[i],gcd(p.first,A[i]+1),p.second+b);
        }
    }
    for(int i=0; i<N; i++)
    {
        for(auto &p:D[i])if(p.first!=1)
            {
                if(ans>p.second+(N-1-i)*a)
                {
                    ans=p.second+(N-1-i)*a;
                }
            }
    }
    D2[N-1][A[N-1]]=0;
    D2[N-1][A[N-1]-1]=b;
    D2[N-1][A[N-1]+1]=b;
    for(int i=N-2; i>=0; i--)
    {
        for(auto &p:D2[i+1])
        {
            push(D2[i],gcd(p.first,A[i]),p.second);
            push(D2[i],gcd(p.first,A[i]-1),p.second+b);
            push(D2[i],gcd(p.first,A[i]+1),p.second+b);
        }
    }
    for(int i=0; i<N; i++)
    {
        for(auto &p:D2[i])if(p.first!=1)
            {
                if(ans>p.second+i*a)
                {
                    ans=p.second+i*a;
                }
            }
    }
    for(int i=N-1; i>=0; i--)
    {
        D3[i]=D2[i];
        if(i<N-1)
        {
            for(auto &p:D3[i+1])
            {
                push(D3[i],p.first,p.second+a);
            }
        }
        else
        {
            push(D3[i],0,a);
        }
    }
    for(int i=0; i<N-1; i++)
    {
        for(auto &p1:D[i])if(p1.first!=1)
            {
                for(auto &p2:D3[i+1])if(p2.first!=1)
                    {
                        if(gcd(p1.first,p2.first)==1)continue;
                        if(ans>p1.second+p2.second)
                        {
                            ans=p1.second+p2.second;
                        }
                    }
            }
    }
    printf("%lld\n",ans);
    return 0;
}

//*/

/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-22-21.49
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

#include <bits/stdc++.h>

#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ll long long

using namespace std;

typedef pair<int,int> pii;
typedef map<int,int> bstii;
typedef set<int> bsti;

const int M = 50000;
const int MAXN = 1000006;
const ll oo = 1e16;

bool nt[M+10];
int A[MAXN], N, P2, P1;
ll f[MAXN][2], C[MAXN], kq;

void nhap()
{
    scanf("%d%d%d", &N, &P1, &P2);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
    }
}

void prep()
{
    memset(nt, 1, sizeof(nt));
    nt[0] = 0;
    nt[1] = 0;
    for(int i=2; i*i<=M; i++)
    {
        if (nt[i])
        {
            for(int j=i; i*j<=M; j++)
            {
                nt[i*j] = 0;
            }
        }
    }
}

void rev()
{
    for(int i=1; i<=N/2; i++)
    {
        int t = A[i];
        A[i] = A[N-i+1];
        A[N-i+1] = t;
    }
}

void cal(int st)
{
    int v = A[1];
    vector <int> P;
    for(int i=2; i<=M; i++)
    {
        if (i*i>A[1] || i>v)
            break;

        if (nt[i])
        {
            if (v%i == 0)
            {
                while (v%i == 0)
                {
                    v /= i;
                }
                P.pb(i);
            }
        }
    }
    if (v > 1)
    {
        P.pb(v);
    }
    // cout<<P.size()<<endl;

    for(int k=0; k<P.size(); k++)
    {
        int pr = P[k];
        ll res = P1*1ll*(N-1);
        C[N+1] = 0;
        for(int i=N; i>=1; i--)
        {
            if (A[i]%pr == 0)
            {
                C[i] = C[i+1];
            }
            else
            {
                if ((A[i] - 1)%pr == 0 || (A[i] + 1)%pr == 0)
                {
                    C[i] = min(oo, C[i+1] + P2);
                }
                else C[i] = oo;
            }
        }
        f[1][1] = 0;
        f[1][0] = oo;
        res = min(res, C[2]);
        for(int i=2; i<=N; i++)
        {
            if (A[i]%pr == 0)
            {
                f[i][1] = f[i-1][1];
            }
            else
            {
                if ((A[i] - 1)%pr == 0 || (A[i] + 1)%pr == 0)
                {
                    f[i][1] = min(oo, f[i-1][1] + P2);
                }
                else f[i][1] = oo;
            }
            f[i][0] = min(f[i-1][0], f[i-1][1]) + P1;
            res = min(res, min(f[i][0], f[i][1]) + C[i+1]);
        }
        kq = min(kq, res+st);
    }
}

void tinh()
{
    if (N == 1)
    {
        return ;
    }
    kq = oo;
    cal(0);
    //  cout<<kq<<endl;
    A[1]--;
    cal(P2);
    A[1] += 2;
    cal(P2);
    A[1]--;
    // cout<<kq<<endl;

    rev();

    cal(0);
    A[1]--;
    cal(P2);
    A[1] += 2;
    cal(P2);
    A[1]--;
}

int main()
{
    //freopen("test.inp","r",stdin);
    nhap();
    prep();
    tinh();
    cout<<kq<<endl;
    return 0;
}


//看看会不会爆int!
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define mkp make_pair
#define ite iterator
#define fi first
#define se second
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)

const int maxn = 1000100;
int n, x, y, a[maxn], tk;
ll ans = 1LL << 60, f[maxn], g[maxn];

void figure(int k, int tt){
	memset(f, 127, sizeof(f));
	memset(g, 127, sizeof(g));
	f[tk] = g[tk] = 0;
	ll tm = 0;
	for(int j = tk + 1; j <= n; j++){
		int t = a[j] % k;
		if(t <= 1 || t == k - 1){
			f[j] = f[j - 1] + y * (t != 0);
			g[j] = g[j - 1] + y * (t != 0);
		}
		tm = min(tm + x, f[j]);
		g[j] = min(g[j], tm);
	}
	ans = min(ans, g[n] + tt);
}

void work(){
	int li = (int)sqrt(a[1] + 1);
	for(int i = 1; i <= n; i++) if(a[i]) { tk = i; break; }
	int num = a[tk];
	for(int i = 2; i <= li; i++)
		if(num % i == 0){
			while(num % i == 0) num /= i;
			figure(i, 0);
		}
	if(num > 1) figure(num, 0);
	num = a[tk] + 1;
	for(int i = 2; i <= li; i++)
		if(num % i == 0){
			while(num % i == 0) num /= i;
			figure(i, y);
		}
	if(num > 1) figure(num, y);
	if(a[tk] <= 2) return;
	num = a[tk] - 1;
	for(int i = 2; i <= li; i++)
		if(num % i == 0){
			while(num % i == 0) num /= i;
			figure(i, y);
		}
	if(num > 1) figure(num, y);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
#endif
	scanf("%d%d%d", &n, &x, &y);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	work();
	reverse(a + 1, a + n + 1);
	work();
	ans = min(ans, (ll)y * n);
	cout << ans << endl;
  return 0;
}
/*
                   _ooOoo_
                  o8888888o
                  88" . "88
                  (| -_- |)
                  O\  =  /O
               ____/`---'\____
             .'  \\|     |//  `.
            /  \\|||  :  |||//  \
           /  _||||| -:- |||||-  \
           |   | \\\  -  /// |   |
           | \_|  ''\---/''  |   |
           \  .-\__  `-`  ___/-. /
         ___`. .'  /--.--\  `. . __
      ."" '<  `.___\_<|>_/___.'  >'"".
     | | :  `- \`.;`\ _ /`;.`/ - ` : | |
     \  \ `-.   \_ __\ /__ _/   .-` /  /
======`-.____`-.___\_____/___.-`____.-'======
                   `=---='
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
         佛祖保佑       永无BUG
*/
