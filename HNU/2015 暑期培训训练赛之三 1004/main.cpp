#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <set>
#define lson x<<1
#define rson x<< 1 | 1
using namespace std;

const int N = 100009;

struct node
{
      int k, a, b, id;
      double r;
} f[N];

int n, A, B;
double na, nb;
double use[N];

bool cmp( node x, node y )
{
      return x.r > y.r;
}

int main()
{
      while( scanf( "%d %d %d", &n, &A, &B ) != EOF )
      {
            for( int i = 1; i <= n; ++i )
            {
                  scanf( "%d %d %d", &f[i].k, &f[i].a, &f[i].b );
                  if( f[i].b != 0 )     f[i].r = f[i].a * 1. / f[i].b;
                  else f[i].r = 0x7fffffff;
                  f[i].id = i;
                  use[i] = 0;
            }
            sort( f + 1, f + 1 + n, cmp );
            na = 0, nb = B;
            for( int i = 1; i <= n; ++i )
            {
                  if( nb >= f[i].k * f[i].b )
                  {
                        nb -= f[i].k * f[i].b;
                        na += f[i].a * f[i].k;
                        use[f[i].id] = f[i].k;
                  }
                  else
                  {
                        double t = nb / f[i].b;
                        na += f[i].a * t;
                        nb -= f[i].b * t;
                        use[f[i].id] = t;
                        break;
                  }
            }
            if( na >= A )
            {
                  printf( "%.9f %.9f\n", na, B - nb );
                  for( int i = 1; i <= n; ++i )
                  {
                        printf( "%.9f%c", use[i], i == n ? '\n' : ' ' );
                  }
            }
            else
            {
                  puts( "-1 -1" );
            }
      }
      return 0;
}
