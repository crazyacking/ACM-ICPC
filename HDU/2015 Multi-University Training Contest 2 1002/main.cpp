/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-23-18.23
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

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      int n, m, x, y;
      while( cin >> n >> m >> x >> y )
      {
            int max1, max2, max3, max4, maxn;
            max1 = max2 = max3 = max4 = maxn = 0;
            max1 = min( min( n - x + 1, x ), m - y );
            max2 = min( min( n - x + 1, x ), y - 1 );
            max3 = min( min( m - y + 1, y ), n - x );
            max4 = min( min( m - y + 1, y ), x - 1 );
            maxn = max( max( max1, max2 ), max( max3, max4 ) );
//            if(n<m) swap(n,m),swap(x,y);
//            maxn=min(max(x-1,n-x), min(m-y+1,y));
            if( ( m == n ) && ( m % 2 == 1 ) )
            {
                  if( ( x == y ) && x == ( ( m + 1 ) / 2 ) )
                  {
                        cout << m / 2 << endl;
                        continue;
                  }
                  cout << max( maxn, ( m + 1 ) / 2 ) << endl;
                  continue;
            }
            int minn = min( n, m );
            cout << max( maxn, ( minn + 1 ) / 2 ) << endl;
      }
      return 0;
}
/*

*/
