/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-26-20.14
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
#define  LL __int64
#define  ULL unsigned long long
using namespace std;
const int MAXN = 2500050;
char s[MAXN];
int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      int t;
      scanf( "%d", &t );
      while( t-- )
      {
            int n;
            scanf( "%d", &n );
            getchar();
            char ch;
            scanf( "%s", s );
            int rp[125], cnt[125];
            memset( rp, -1, sizeof rp );
            for(int i=0;i<n;++i)
            {
                  rp[s[i]]=i;
            }
            sort(s,s+n);
//            memset( cnt, 0, sizeof cnt );
//            for( int i = 0; i < n; ++i ) cnt[s[i]]++, rp[s[i]] = rp[s[i]] > i ? rp[s[i]] : i;
            LL ans1 = 0, ans2 = 0;
//            for( int i = 0; i < n; ++i ) ans1 += ( rp[s[i]] - i ) * 5;
//            for( int i = 0; i < 125; ++i ) ans2 += cnt[i] * ( cnt[i] - 1 ) * 5 / 2;
            if( ans1 > ans2 )  printf( "%I64d\n", ans1 - ans2 );
            else puts( "0" );
      }
      return 0;
}
/*

*/
