#include<stdio.h>
#include<string.h>
void makeNext( const char P[], int next[] )
{
      int q, k;
      int m = strlen( P );
      next[0] = 0;
      for( q = 1, k = 0; q < m; ++q )
      {
            while( k > 0 && P[q] != P[k] )
                  k = next[k - 1];
            if( P[q] == P[k] )
            {
                  k++;
            }
            next[q] = k;
      }
}

int kmp( const char P[], const char T[], int next[] )
{
      int n, m;
      int i, k;
      m = strlen( P );
      n = strlen( T );
      makeNext( P, next );
      for( i = 0, k = 0; i < n; ++i )
      {
            while( k > 0 && P[k] != T[i] )
                  k = next[k - 1];
            if( P[k] == T[i] )
            {
                  k++;
            }
            if( k == m )
            {
                  printf( "Pattern appear start with index:%d\n", ( i - m + 1 ) );
            }
      }
}

int main()
{
      int i;
      int next[20] = {0};
      char P[] = "boxbox";
      char T[] = "ababoxbafdboxboxsss";
      printf( "%s\n", P );
      printf( "%s\n", T );
      // makeNext(P,next);
      kmp( P, T, next );
      for( i = 0; i < strlen( P ); ++i )
      {
            printf( "%d ", next[i] );
      }
      printf( "\n" );
      return 0;
}
