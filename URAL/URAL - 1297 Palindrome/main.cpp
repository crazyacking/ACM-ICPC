// Memory   Time
// 1347K     0MS
// by : Snarl_jsb
// 2014-09-24-20.34
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<climits>
#include<cmath>
#define N 1234<<1
#define LL long long
using namespace std;
int num[N];
char str[N];

namespace Suf
{
int sa[N], rank[N], height[N];
int wa[N], wb[N], wv[N], wd[N];
int cmp( int *r, int a, int b, int l )
{
      return r[a] == r[b] && r[a + l] == r[b + l];
}
void da( int *r, int n, int m )   //  参数:*r---str转化为int型后的数组  n----数组长度  m---元素的范围
{
      int i, j, p, *x = wa, *y = wb, *t;
      for( i = 0; i < m; i ++ ) wd[i] = 0;
      for( i = 0; i < n; i ++ ) wd[x[i] = r[i]] ++;
      for( i = 1; i < m; i ++ ) wd[i] += wd[i - 1];
      for( i = n - 1; i >= 0; i -- ) sa[-- wd[x[i]]] = i;
      for( j = 1, p = 1; p < n; j *= 2, m = p )
      {
            for( p = 0, i = n - j; i < n; i ++ ) y[p ++] = i;
            for( i = 0; i < n; i ++ ) if( sa[i] >= j ) y[p ++] = sa[i] - j;
            for( i = 0; i < n; i ++ ) wv[i] = x[y[i]];
            for( i = 0; i < m; i ++ ) wd[i] = 0;
            for( i = 0; i < n; i ++ ) wd[wv[i]] ++;
            for( i = 1; i < m; i ++ ) wd[i] += wd[i - 1];
            for( i = n - 1; i >= 0; i -- ) sa[-- wd[wv[i]]] = y[i];
            for( t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i ++ )
                  x[sa[i]] = cmp( y, sa[i - 1], sa[i], j ) ? p - 1 : p ++;
      }
}
void calcHeight( int *r, int n )       //  求height数组
{
      int i, j, k = 0;
      for( i = 1; i <= n; i ++ ) rank[sa[i]] = i;
      for( i = 0; i < n; height[rank[i ++]] = k )
      {
            for( k ? k -- : 0, j = sa[rank[i] - 1]; r[i + k] == r[j + k]; k ++ );
      }
}
}
using namespace Suf;
int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
//    freopen("C:\\Users\\ASUS\\Desktop\\cin.cpp","r",stdin);
//    freopen("C:\\Users\\ASUS\\Desktop\\cout.cpp","w",stdout);
      while( ~scanf( "%s", str ) )
      {
            int len = strlen( str );
            for( int i = 0; i < len; ++i )
                  num[i] = str[i];
            int len1 = len;
            num[len] = 1;
            for( int i = len - 1; i >= 0; --i )
                  num[++len] = str[i];
            num[++len] = 0;
            da( num, len + 1, 250 );
            calcHeight( num, len );
            int maxx = 1;
            int start = 0;
            int l, r;
            for( int i = 1; i <= len; ++i )
            {
                  l = min( sa[i], sa[i - 1] );
                  r = max( sa[i], sa[i - 1] );
                  if( ( l < len1 && r > len1 ) && ( l + height[i] ) == ( len - r ) )
                  {
                        if( height[i] > maxx )
                        {
                              maxx = height[i];
                              start = l;
                        }
                        else if( height[i] == maxx )
                        {
                              start = min( start, l );
                        }
                  }
            }
            for( int i = start, j = 0; j < maxx; ++i, ++j )
                  printf( "%c", num[i] );
            puts( "" );
      }
      return 0;
}
