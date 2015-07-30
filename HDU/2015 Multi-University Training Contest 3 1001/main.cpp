/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-29-10.04
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

struct Node
{
      int has[2][2];
      long long ma[2][2];
} tre[100000 * 4];


Node Union( Node a, Node b )
{
      Node c;
      //首先 四种起始和终止情况可以直接继承于左儿子或右儿子的对应情况，取最大
      for( int i = 0; i <= 1; i++ )
            for( int j = 0; j <= 1; j++ )
            {
                  c.has[i][j] = a.has[i][j] | b.has[i][j];
                  if( a.has[i][j] && b.has[i][j] )
                        c.ma[i][j] = max( a.ma[i][j], b.ma[i][j] );
                  else if( a.has[i][j] )
                        c.ma[i][j] = a.ma[i][j];
                  else if( b.has[i][j] )
                        c.ma[i][j] = b.ma[i][j];
            }
      for( int i = 0; i <= 1; i++ )
            for( int j = 0; j <= 1; j++ )
                  for( int k = 0; k <= 1; k++ )
                        if( a.has[i][j] && b.has[!j][k] )
                              if( c.has[i][k] )
                                    c.ma[i][k] = max( c.ma[i][k], a.ma[i][j] + b.ma[!j][k] );
                              else
                                    c.has[i][k] = 1, c.ma[i][k] = a.ma[i][j] + b.ma[!j][k];
      return c;
}

void build( int num, int le, int ri )
{
      memset( tre[num].has, 0, sizeof( tre[num].has ) );
      if( le == ri )
      {
            int a;
            scanf( "%d", &a );
            tre[num].has[le % 2][le % 2] = 1;
            tre[num].ma[le % 2][le % 2] = a;
            return ;
      }
      int mid = ( le + ri ) / 2;
      build( num * 2, le, mid );
      build( num * 2 + 1, mid + 1, ri );
      tre[num] = Union( tre[num * 2], tre[num * 2 + 1] );
}

void update( int num, int le, int ri, int x, int y )
{
      if( le == ri )
      {
            memset( tre[num].has, 0, sizeof( tre[num].has ) );
            tre[num].has[le % 2][le % 2] = 1;
            tre[num].ma[le % 2][le % 2] = y;
            return ;
      }
      int mid = ( le + ri ) / 2;
      if( x <= mid )
            update( num * 2, le, mid, x, y );
      else
            update( num * 2 + 1, mid + 1, ri, x, y );
      tre[num] = Union( tre[num * 2], tre[num * 2 + 1] );
}

Node query( int num, int le, int ri, int x, int y )
{
      if( x <= le && y >= ri )
            return tre[num];
      int flag1 = 0, flag2 = 0;
      Node x1, x2;
      int mid = ( le + ri ) / 2;
      if( x <= mid )
            x1 = query( num * 2, le, mid, x, y ), flag1 = 1;
      if( y > mid )
            x2 = query( num * 2 + 1, mid + 1, ri, x, y ), flag2 = 1;
      if( flag1 == 0 )
            return x2;
      if( flag2 == 0 )
            return x1;
      return Union( x1, x2 );
}
int main()
{
      int T;
      cin >> T;
      while( T-- )
      {
            int n, m;
            cin >> n >> m;
            build( 1, 1, n );
            for( int i = 1; i <= m; i++ )
            {
                  int x, y, z;
                  scanf( "%d%d%d", &x, &y, &z );
                  if( x == 0 )
                  {
                        Node t = query( 1, 1, n, y, z );
                        long long ans;
                        int flag = 0;
                        for( int i = 0; i <= 1; i++ )
                              for( int j = 0; j <= 1; j++ )
                                    if( t.has[i][j] )
                                          if( flag == 0 ) ans = t.ma[i][j], flag = 1;
                                          else ans = max( ans, t.ma[i][j] );
                        cout << ans << endl;
                  }
                  else update( 1, 1, n, y, z );
            }
      }
      return 0;
}
