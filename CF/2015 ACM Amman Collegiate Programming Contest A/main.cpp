#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#define ll long long
using namespace std;
vector<int> E[200005], C[200005];
int f[200005][2];
int vis[200005];
int n, m;
int dfs ( int u )
{
    int ok = vis[u];
    int s = 0, m = 0, k = 0;
    for ( int i = 0; i < E[u].size(); ++i ) {
        int v = E[u][i], c = C[u][i];
        int has = dfs ( v );
        if ( has ) {
            s += f[v][1] + c;
            if ( m < (f[v][1] + c-f[v][0])) {
                m = f[v][1] + c-f[v][0];
            }
            ok = has;
        }
    }
    f[u][1] = s;
    f[u][0] = s - m;
    return ok;
}
int main()
{
    scanf ( "%d %d", &n, &m );
    for ( int i = 1, u, v, w; i < n; ++i ) {
        scanf ( "%d %d %d", &u, &v , &w );
        E[u].push_back ( v );
        C[u].push_back ( w );
    }
    for ( int i = 1, k; i <= m; ++i ) {
        scanf ( "%d", &k );
        vis[k] = 1;
    }
    dfs ( 1 );
    printf ( "%d\n", f[1][0] );
    return 0;
}

