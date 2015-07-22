/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-22-15.56
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
long long t, n, r;
const int p[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67};
vector<int> rongchi;
void get_rongchi()
{
      rongchi.clear();
      for( int i = 0; p[i] <= r; ++i )
      {
            int si = rongchi.size();
            for( int j = 0; j < si; ++j )
            {
                  if( abs( p[i]*rongchi[j] ) <= 63 )
                        rongchi.push_back( -p[i]*rongchi[j] );
            }
            rongchi.push_back( p[i] );
      }
}

long long cal( long long x )
{
      if( x == 1 ) return 0;
      long long ans = x;
      for( int i = 0; i < rongchi.size(); ++i )
      {
            long long tmp = ( long long )( pow( x + 0.5 , 1.0 / abs( rongchi[i] ) ) ) - 1;
            if( rongchi[i] < 0 ) ans += tmp;
            else ans -= tmp;
      }
      return ans - 1;
}
long long solve()
{
      get_rongchi();
      long long ans = n;
      while( true )
      {
            long long tmp = cal( ans );
            if( tmp == n )break;
            ans += n - tmp;
      }
      return ans;
}

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      cin >> t;
      while( t-- )
      {
            cin >> n >> r;
            cout << solve() << endl;
      }
      return 0;
}
/*

*/
