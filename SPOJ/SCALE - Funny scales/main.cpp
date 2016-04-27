#include <cstdio>

#define REP( i, n ) \
	for ( int i = 0; i < (n); i++ )
#define REPD( i, n ) \
	for ( int i = (n) - 1; i >= 0; i-- )

const int MAXL = 100;

int N, X;
int A[MAXL], lenA;
int B[MAXL], lenB;
int dig[MAXL];

int main()
{

    scanf( "%d %d", &N, &X );

    for ( int i = 0; X != 0; i++ )
    {
        dig[i] += X % 3;
        if ( dig[i] > 1 )
        {
            dig[i + 1]++;
            dig[i] = dig[i] - 3;
        }
        X /= 3;
    }

    for ( int i = MAXL - 1; i >= 0; i-- )
    if ( dig[i] != 0 )
        if ( dig[i] == -1 )
            A[lenA++] = i + 1;
        else if ( dig[i] == +1 )
            B[lenB++] = i + 1;

    if ( A[0] > N || B[0] > N )
        printf( "-1\n" );
    else
    {
        for ( int i = lenA - 1; i >= 0; i-- )
        printf( i ? "%d " : "%d", A[i] );
        printf( "\n" );
        for ( int i = lenB - 1; i >= 0; i-- )
        printf( i ? "%d " : "%d", B[i] );
        printf( "\n" );
    }
    return 0;
}
