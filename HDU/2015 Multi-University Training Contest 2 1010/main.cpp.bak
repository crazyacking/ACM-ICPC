/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-23-13.17
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
const int MAXN = 500050;
bool s[MAXN];
int n, m, k, a[MAXN];
int peo[MAXN], bot[MAXN];

class node
{
public:
      int sl, sr;
      bool operator < ( node a ) const { return  sl == a.sl ? sr < a.sr : sl < a.sl; }
};
multiset<pair<int, node> > se; // int---min(s[i],s[i-1])    node.sl---s[i-1]   node.sr--- s[i]

int main()
{
//      ios_base::sync_with_stdio( false );
//      cin.tie( 0 );
      while( ~scanf( "%d %d %d", &n, &m, &k ) )
      {
            se.clear();
            for( int i = 1; i <= n; ++i )
            {
                  scanf( "%d", &a[i] );
                  peo[i] = bot[i] = 0;
                  s[i] = false;
            }
            node tm;
            peo[0] = m;
            bool win = true;
            int now_pos = -1, pre_pos = -500010;
            for( int i = 0; i < n; ++i )
            {
                  if( i != 0 )
                  {
                        peo[i] = peo[i - 1];
                        bot[i] = bot[i - 1] + k;
                  }
                  if( peo[i] - a[i + 1] > 0 )
                  {
                        /**< cout << "ok,enough" << endl; */
                        peo[i] -= a[i + 1];
                  }
                  else
                  {
                        peo[i] += bot[i];
                        bot[i] = 0;
                        s[i] = 1;
                        now_pos = i;
                        tm.sl = pre_pos, tm.sr = now_pos;
                        /**< cout << "pre:" << pre_pos << "  now:" << now_pos << endl; */
                        if( pre_pos >= 1 )
                              se.insert( make_pair( ( int ) abs( now_pos - pre_pos ) , ( node ) tm ) );
                        pre_pos = i;
                        peo[i] -= a[i + 1];
                        if( peo[i] <= 0 )
                        {
                              win = 0; // can't win
                              break;
                        }
                  }
            }
            if( ! win )
            {
                  puts( "Poor Hero!" );
                  continue;
            }
            int yu = peo[n - 1];
            multiset<pair<int, node> > ::iterator it = se.begin();
            int gap, sl, sr;
            bool flag = true;
            while( yu > 0 )
            {
                  it = se.begin();
                  gap = ( *it ).first;
                  tm = ( *it ).second;
                  sl = tm.sl;
                  sr = tm.sr;
                  if( sl <= 0 ) break;
                  se.erase( make_pair( gap, tm ) );
                  if( flag )
                  {
                        flag = !flag;
                        yu -= k;
                        s[sl] = 0;
                        sl--;
                        s[sl] = 1;
                  }
                  else
                  {
                        flag = !flag;
                        yu -= k;
                        s[sr] = 0;
                        sr--;
                        s[sr] = 1;
                  }
                  gap = sr - sl;
                  tm.sl = sl, tm.sr = sr;
                  se.insert( make_pair( gap, tm ) );
            }
            it = se.begin();
            gap = ( *it ).first;
            tm = ( *it ).second;
            int T = gap;
            int num = 0;
            for( int i = 0; i < MAXN; ++i )
            {
                  if( s[i] ) num++;
            }
            if( num <= 1 )
            {
                  puts( "Poor JRY!" );
                  continue;
            }
            cout << T << endl;
            cout << num << endl;
            for( int i = 0; i < MAXN; ++i )
                  if( s[i] ) cout << i << " ";
            cout << endl;
      }
      return 0;
}
/*

*/
