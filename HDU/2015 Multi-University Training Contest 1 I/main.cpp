/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-22-11.22
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
#define  LL long long
#define  ULL unsigned long long
#define rep(i,n) for(int i=0;i<n;++i)
using namespace std;

const int N = 100010,D=20;
int st[N], ori[N], dfs_clock;
vector<pair<int, int> > G[N];
int shortcut[D][N], dep[N];
int *fa;
int get_lca( int a, int b )
{
      if( dep[a] < dep[b] )
            swap( a, b );
      for( int i = D - 1; ~i; --i )
      {
            if( dep[a] - dep[b] >> i & 1 )
                  a = shortcut[i][a];
      }
      if( a == b ) return a;
      for( int i = D - 1; ~i; --i )
      {
            if( shortcut[i][a] != shortcut[i][b] )
            {
                  a = shortcut[i][a];
                  b = shortcut[i][b];
            }
      }
      return fa[a];
}

int dis[N];
void dfs( int u, int father )
{
      st[u] = ++dfs_clock;
      ori[dfs_clock] = u;
      vector<pair<int, int> > :: iterator it;
      for( it = G[u].begin(); it != G[u].end(); ++it )
      {
            int v = ( *it ).first;
            int w = ( *it ).second;
            if( v == father )continue;
            fa[v] = u;
            dep[v] = dep[u] + 1;
            dis[v] = dis[u] + w;
            dfs( v, u );
      }
}


void prepare( int n )
{
      for( int j = 1; j < D; ++j )
      {
            rep( i, n )
            {
                  int &res = shortcut[j][i];
                  res = shortcut[j - 1][i];
                  if( ~res ) res = shortcut[j - 1][res];
            }
      }
}


set<int> nodes;
int get_dis( int a, int b )
{
      return dis[a] + dis[b] - 2 * dis[get_lca( a, b )];
}


int add( int u )
{
      if( !nodes.empty() )
      {
            set<int>::iterator low, high;
            low = nodes.lower_bound( st[u] );
            high = low;
            if( low == nodes.end() || low == nodes.begin() )
            {
                  low = nodes.begin();
                  high = nodes.end();
                  high--;
            }
            else low--;
            int x = ori[*low];
            int y = ori[*high];
            int res = get_dis( x, u ) + get_dis( y, u ) - get_dis( x, y );
            return res;
      }
      return 0;
}

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      int T, n, q, u, v, w;
      scanf( "%d", &T );
      rep( cas, T )
      {
            scanf( "%d %d", &n, &q );
            rep( i, n ) G[i].clear();
            dfs_clock = 0;
            rep( i, n - 1 )
            {
                  scanf( "%d %d %d", &u, &v, &w );
                  u--;
                  v--;
                  G[u].push_back( make_pair( v, w ) );
                  G[v].push_back( make_pair( u, w ) );
            }
            fa = shortcut[0];
            fa[0] = -1;
            dfs( 0, -1 );
            prepare( n );
            nodes.clear();
            printf( "Case #%d:\n", cas + 1 );
            int ans = 0;
            while( q-- )
            {
                  int op;
                  scanf( "%d %d", &op, &u );
                  u--;
                  if( op == 1 )
                  {
                        if( nodes.find( st[u] ) == nodes.end() )
                        {
                              ans += add( u );
                              nodes.insert( st[u] );
                        }
                  }
                  else
                  {
                        if( nodes.find( st[u] ) != nodes.end() )
                        {
                              nodes.erase( st[u] );
                              ans -= add( u );
                        }
                  }
                  printf( "%d\n", ans >> 1 );
            }
      }
      return 0;
}
/*

*/
