/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-24-08.09
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
using namespace std;
int n, m, ans;
int time[10], online[10], offonline[10];
struct edge
{
      int u, v;
} e[30];

void DFS( int x )
{
      if( x == m + 1 )
      {
            ans++;
            return;
      }
      int u = e[x].u;
      int v = e[x].v;
      if( online[u] && online[v] )
      {
            online[u]--;
            online[v]--;
            DFS( x + 1 );
            online[u]++;
            online[v]++;
      }
      if( offonline[u] && offonline[v] )
      {
            offonline[u]--;
            offonline[v]--;
            DFS( x + 1 );
            offonline[u]++;
            offonline[v]++;
      }
      return ;
}

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      int t;
      cin >> t;
      while( t-- )
      {
            ans = 0;
            memset( time, 0, sizeof( time ) );
            memset( e, 0, sizeof( e ) );
            memset( online, 0, sizeof( online ) );
            memset( offonline, 0, sizeof( offonline ) );
            cin >> n >> m;
            for( int i = 1; i <= m; ++i )
            {
                  cin >> e[i].u >> e[i].v;
                  time[e[i].u]++, time[e[i].v]++;
            }
            bool f = true;
            for( int i = 1; i <= n; ++i )
            {
                  online[i] = offonline[i] = time[i] / 2;
                  if( time[i] & 1 )
                  {
                        f = false;
                        break;
                  }
            }
            if( !f )
            {
                  cout << 0 << endl;
                  continue;
            }
            DFS( 1 );
            cout << ans << endl;
      }
      return 0;
}
/*

*/
