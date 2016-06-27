
#include <bits/stdc++.h>

#define FOR(i,b,e) for(int i=(b); i <= (e); ++i)
#define FORD(i,b,e) for(int i=(b); i >= (e); --i)
#define SIZE(c) (int) (c).size()
#define FORE(i,c) FOR(i,0,SIZE(c)-1)
#define FORDE(i,c) FORD(i,SIZE(c)-1,0)
#define PB push_back
#define MP make_pair
#define ST first
#define ND second

using namespace std;

typedef long long int LLI;
typedef pair < int , int > PII;
typedef pair < LLI , LLI > PLL;

typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < PII > VP;
typedef vector < LLI > VL;
typedef vector < PLL > VPL;

typedef vector < VI > VVI;
typedef vector < VL > VVL;
typedef vector < VB > VVB;
typedef vector < VP > VVP;

const int MOD = 1000000007;
const int INF = 1000000001;
const LLI LLINF = 1000000000000000001LL;

/*************************************************************************/

void dfs(int v, VVI &G, VI &par, VI &sub, VI &ans) {
    int heavy = -1;

    for (int u : G[v]) {
        dfs(u, G, par, sub, ans);
        sub[v] += sub[u];

        if (heavy == -1 || sub[u] > sub[heavy]) {
            heavy = u;
        }
    }

    if (heavy != -1 && 2 * sub[heavy] > sub[v]) {
        ans[v] = ans[heavy];

        while (2 * sub[ans[v]] < sub[v]) {
            ans[v] = par[ans[v]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;

    VVI G(n);
    VI par(n,-1);

    FOR(i,1,n-1) {
        cin >> par[i]; par[i]--;

        G[par[i]].PB(i);
    }

    VI sub(n,1), ans(n);
    FOR(i,0,n-1) ans[i] = i;

    dfs(0, G, par, sub, ans);

    while (q--) {
        int v;
        cin >> v; v--;

        cout << 1 + ans[v] << '\n';
    }

    return 0;
}

/*************************************************************************/
