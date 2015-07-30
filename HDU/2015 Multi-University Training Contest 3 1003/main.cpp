#include <stdio.h>
#include <math.h>
int main()
{
      int t;
      double x1, x2, y1, y2, a, b, c;
      scanf( "%d", &t );
      while( t-- )
      {
            scanf( "%lf%lf%lf%lf", &x1, &y1, &x2, &y2 );
            a = sqrt( x1 * x1 + y1 * y1 );
            b = sqrt( x2 * x2 + y2 * y2 );
            c = sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) );
            printf( "%.2lf\n", 180 / 3.14159 * acos( ( a * a + b * b - c * c ) / ( 2 * a * b ) ) );
      }
      return 0;
}
