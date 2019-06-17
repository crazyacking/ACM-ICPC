/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-18-20.25
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
const int MAXN = 100010;
int a[MAXN];


LL Add( int l, int r )
{
      int ll = l, rr = r;
      bool flag = true;
      while( l < r )
      {
            if( a[l] != a[r] )
            {
                  flag = false;
                  break;
            }
            l++, r--;
      }
      LL ans = 0;
      if( flag )
      {
            for( int i = ll; i <= rr; ++i )
            {
                  ans += a[i];
            }
      }
      return ans;
}



int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      int n, m;
      while( ~scanf( "%d %d", &n, &m ) )
      {
            for( int i = 1; i <= n; ++i )
            {
                  scanf( "%d", &a[i] );
            }
            int l, r;
            while( m-- )
            {
                  scanf( "%d %d", &l, &r );
                  LL ans = 0;
                  for( int i = l; i <= r; ++i )
                  {
                        for( int j = i; j <= r; ++j )
                        {
                              ans += Add( i, j );
                        }
                  }
                  printf( "%lld\n", ans );
            }
      }
      return 0;
}
/*

*/
