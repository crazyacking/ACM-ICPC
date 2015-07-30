/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-19.01
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

int T, a, b;
int f[1000009][10];
const int NN = 1000005;
int p[NN];
bool v[NN];
void cntPrimeNum()
{
      for( int i = 2; i < NN; ++i )
      {
            if( !v[i] )
                  for( int j = i; j < NN; j += i )
                  {
                        v[j] = true;
                        ++p[j];
                  }
      }
}

int main()
{
      cntPrimeNum();
      for( int i = 1; i < NN; ++i )
            for( int j = 7; j > 0; --j )
                  if( p[i] == j ) f[i][j] = 1;
      for( int i = 1; i <= 1000000; ++i )
            for( int j = 1; j <= 7; ++j )
                  f[i][j] += f[i - 1][j];
      scanf( "%d", &T );
      while( T-- )
      {
            int ans = 1;
            scanf( "%d %d", &a, &b );
            for( int i = 7; i > 0; --i )
            {
                  if( f[b][i] - f[a - 1][i] > 1 )
                  {
                        ans = i;
                        break;
                  }
            }
            printf( "%d\n", ans );
      }
      return 0;
}
