#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#define ll long long
using namespace std;

const int N = 100009;
typedef pair<int, int> ii;
set<ii> a, b;
int g[N];
int T, n, k;
ll ans;
int main()
{
      scanf( "%d", &T );
      while( T-- )
      {
            ans = 0;
            a.clear();
            b.clear();
            scanf( "%d %d", &n, &k );
            for( int i = 1; i <= n; ++i )
            {
                  scanf( "%d", &g[i] );
            }
            int l = 1, r = 1;
            while( r <= n )
            {
                  a.insert( make_pair( g[r], r ) );
                  b.insert( make_pair( -g[r], r ) );
                  while( - ( *b.begin() ).first  - ( *a.begin() ).first >= k )
                  {
                        a.erase( make_pair( g[l], l ) );
                        b.erase( make_pair( -g[l], l ) );
                        ++l;
                  }
                  ans = ( ans + r - l + 1 );
                  ++r;
            }
            cout << ans << "\n";
      }
      return 0;
}
