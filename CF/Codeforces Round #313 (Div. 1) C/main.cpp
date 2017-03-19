/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-22-23.43
* Time: 0MAXMS
* MAXMemory: 137KB
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
#define mod 1000000007
#define  Ulong long unsigned long long
using namespace std;

const int MAXN = 200005;
long long h, w, n, ans;
long long q1[MAXN], q2[MAXN], f[MAXN];
struct point
{
      int x, y;
      friend bool operator<( point x1, point y1 )
      {
            if( x1.x != y1.x )return x1.x < y1.x;
            return x1.y < y1.y;
      }
} a[MAXN];

long long quick_pow( long long x, long long y )
{
      long long ans = 1;
      while( y )
      {
            if( y & 1 )ans = ( ans * x ) % mod;
            y >>= 1;
            x = ( x * x ) % mod;
      }
      return ans;
}

int main() {
      cin >> h >> w >> n;
      for( int i = 1; i <= n; i++ )
            cin >> a[i].x >> a[i].y;
      for( int i = 0; i < MAXN; ++i )
            q1[i] = q2[i] = f[i] = 0;
      q1[0] = q2[0] = 1;
      sort( a + 1, a + n + 1 );
      for( int i = 1; i <= h + w; ++i )
            q1[i] = q1[i - 1] * i % mod;
      q2[h + w] = quick_pow( q1[h + w], mod - 2 );
      for( int i = h + w - 1; i >= 1; i-- )
            q2[i] = q2[i + 1] * ( i + 1 ) % mod;
      ans = q1[h + w - 2] * q2[h - 1] % mod * q2[w - 1] % mod;
      for( int i = 1; i <= n; i++ )
      {
            f[i] = q1[a[i].x + a[i].y - 2] * q2[a[i].x - 1] % mod * q2[a[i].y - 1] % mod;
            for( int j = 1; j < i; j++ )
                  if( a[j].x <= a[i].x && a[j].y <= a[i].y )
                        f[i] -= f[j] * q1[a[i].x + a[i].y - a[j].x - a[j].y] % mod * q2[a[i].x - a[j].x] % mod * q2[a[i].y - a[j].y] % mod;
            f[i] = ( f[i] % mod + mod ) % mod;
            ans = ans - f[i] * q1[h + w - a[i].y - a[i].x] % mod * q2[h - a[i].x] % mod * q2[w - a[i].y] % mod;
      }
      ans = ( ans % mod + mod ) % mod;
      cout << ans << endl;
      return 0;
}
