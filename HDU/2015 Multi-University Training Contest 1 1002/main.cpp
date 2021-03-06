/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-21-21.38
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
      int Cas;
      cin >> Cas;
      while( Cas-- )
      {
            int n, k, tmp;
            cin >> n >> k;
            vector<int> v;
            for( int i = 0; i < n; ++i )
            {
                  cin >> tmp;
                  v.push_back( tmp );
            }
            multiset<pair<int, int> > q1, q2;
            int l = 0, r = 0;
            LL ans = 0;
            while( r < n )
            {
                  q1.insert( make_pair( v[r], r ) ), q2.insert( make_pair( -v[r], r ) );
                  while( -( *q1.begin() ).first - ( *q2.begin() ).first >= k )
                  {
                        q1.erase( make_pair( v[l] , l ) ), q2.erase( make_pair( -v[l], l ) );
                        l++;
                  }
                  ans += r - l + 1;
                  r++;
            }
            cout << ans << endl;
      }
      return 0;
}
/*

*/
