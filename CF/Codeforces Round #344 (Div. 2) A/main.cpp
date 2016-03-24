#include <bits/stdc++.h>
#define pb push_back
#define f first
#define s second
#define mp make_pair
#define sz(a) int((a).size())
#ifdef _WIN32
#  define I64 "%I64d"
#else
#  define I64 "%lld"
#endif
#define fname "."
#define pi pair < int, int >

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int MAX_N = (int)1e5 + 123;
const double eps = 1e-6;
const int inf = (int)1e9 + 123;

using namespace std;

ll n;
ll a[1005], b[1005];

int main()
{
#ifdef Nick
    freopen(fname"in","r",stdin);
    freopen(fname"out","w",stdout);
#endif
    ll ans = -1;
    cin >> n;
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (ll i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (ll l = 1; l <= n; l++)
    {
        ll aa = 0, bb = 0;
        for (int r = l; r <= n; r++)
        {
            aa |= a[r];
            bb |= b[r];
            ans = max(ans, aa + bb);
        }
    }
    cout << ans;
    return 0;
}
