/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-29-22.46
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

int m[10];
int judge( int a, int b )
{
      if( a > 100000 )
            return 0;
      memset( m, 0, sizeof( m ) );
      if( b < 10000 )
      {
            m[0];
            m[a % 10] = 1;
            a = a / 10;
      }
      while( b )
      {
            m[b % 10] = 1;
            b = b / 10;
      }
      int sum = 0;
      for( int j = 0; j < 10; j++ )
            sum += m[j];
      return sum == 10;
}
int main()
{
      int n, k = 0;
      while( scanf( "%d", &n ) == 1 && n )
      {
            if( k > 0 )puts(""); k++; //输出格要求
            int flag = 1;
            for( int i = 1234; i < 1000000; i++ )
            {
                  if( judge( n * i, i ) )
                  {
                        printf( "%d / %05d = %d\n", i * n, i, n );
                        flag = 0;
                  }
            }
            if( flag ) printf( "There are no solutions for %d.\n", n );
      }
      return 0;
}
