/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-22-08.50
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
const int MAXN = 10005, MAXX = 100005, mod = 1e9 + 7;
vector<int> divi[MAXN];
int a[MAXX], l[MAXX], r[MAXX], pos[MAXX], n;

void init()
{
      for( int i = 1; i <= 10000; ++i )
            for( int j = 1; j <= i; ++j )
                  if( !( i % j ) ) divi[i].push_back( j );
}

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      init();
      while( cin >> n )
      {
            for( int i = 0; i < n; ++i ) cin >> a[i];
            memset( l, -1, sizeof l );
            memset( r, 0x3f, sizeof r );
            memset( pos, -1, sizeof pos );
            for( int i = 0; i < n; ++i )
            {
                  int lef = -1;
                  for( int j = 0; j < divi[a[i]].size(); ++j )
                        lef = max( lef, pos[divi[a[i]][j]] );
                  pos[a[i]] = i;
                  l[i] = lef;
            }
            memset( pos, 0x3f, sizeof pos );
            for( int i = n - 1; i >= 0; --i )
            {
                  int rig = 0x3f3f3f3f;
                  for( int j = 0; j < divi[a[i]].size(); ++j )
                        rig = min( rig, pos[divi[a[i]][j]] );
                  pos[a[i]] = i;
                  r[i] = rig;
            }
            int ans = 0, L, R;
            for( int i = 0; i < n; ++i )
            {
                  if( l[i] == -1 ) L = i + 1;
                  else L = i - l[i];
                  if( r[i] == 0x3f3f3f3f ) R = n - i;
                  else R = r[i] - i;
                  ans = ( L * R % mod + ans ) % mod;
            }
            cout << ans << endl;
      }
      return 0;
}
/*

*/
