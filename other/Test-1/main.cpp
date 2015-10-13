#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define pf push_front
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define LL long long
#define se second
const int N = 200005;
const int Mod = ( int ) 1e9 + 7;

int T1[N], T2[N], T3[N];
int main()
{
    freopen( "lca.in", "r", stdin );
    freopen( "lca.out ", "w", stdout );
    int n, m;
    while( scanf( "%d", &n ) == 1 && n ) {
        for( int i = 1, x, y; i <= n; ++i ) {
            scanf( "%d %d", &x, &y );
            T1[i]=x!=0;
        }
        scanf( "%d", &m );
        for( int i = 1, x, y; i <= m; ++i ) {
            scanf( "%d %d", &x, &y );
            T2[i]=x!=0;
        }
        n = min( n, m );
        int k = 1;
        for( int i = 0; i < n; ++i ) {
            T3[i]=0;
            if( T1[i] != T2[i] ) {
                break;
            }
            if( T1[i] == T2[i] && T1[i] != 0 ) {
                T3[i]=1;
                k += 2;
            }
        }
        printf( "%d\n", k );
        int t=1;
        for( int i = 1; i <= k; ++i ) {
            if(T3[i]){
                  printf( "%d %d\n", t+1, t+2 );
                  t+=2;
            }
            else
                  printf( "0 0\n" );
        }
    }
    return 0;
}
