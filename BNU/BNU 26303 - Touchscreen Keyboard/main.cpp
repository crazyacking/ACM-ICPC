/**
 * -----------------------------------------------------------------
 * Copyright (c) 2016 crazyacking.All rights reserved.
 * -----------------------------------------------------------------
 *       Author: crazyacking
 *       Date  : 2016-03-17-16.15
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
using namespace std;
typedef long long(LL);
typedef unsigned long long(ULL);
const double eps(1e-8);

using namespace std;

const char * first = "qwertyuiop";
const char * second = "asdfghjkll";
const char * third = "zxcvbnm";

typedef struct
{
    char word[10002];
    int sum;
} CORRECT;

int PosInFirst( const char ch )
{
    for ( int i = 0 ; first[i] != '\0' ; i ++ )
    {
        if ( ch == first[i] )
            return i + 1;
    }
    return 0;
}

int PosInSecond( const char ch )
{
    for ( int i = 0 ; second[i] != '\0' ; i ++ )
    {
        if ( ch == second[i] )
            return i + 1;
    }
    return 0;
}

int PosInThird( const char ch )
{
    for ( int i = 0 ; third[i] != '\0' ; i ++ )
    {
        if ( ch == third[i] )
            return i + 1;
    }
    return 0;
}

int FindError( const char a, const char b )
{
    int n;
    int pos_a, pos_b;
    if ( (pos_a = PosInFirst(a)) )
    {
        if ( (pos_b = PosInFirst(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
        }
        else if ( (pos_b = PosInSecond(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
            n ++;
        }
        else if ( (pos_b = PosInThird(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
            n += 2;
        }
    }
    else if ( (pos_a = PosInSecond(a)) )
    {
        if ( (pos_b = PosInFirst(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
            n ++;
        }
        else if ( (pos_b = PosInSecond(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
        }
        else if ( (pos_b = PosInThird(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
            n ++;
        }
    }
    else if ( (pos_a = PosInThird(a)) )
    {
        if ( (pos_b = PosInFirst(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
            n += 2;
        }
        else if ( (pos_b = PosInSecond(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
            n ++;
        }
        else if ( (pos_b = PosInThird(b)) )
        {
            n = pos_b - pos_a;
            if (n < 0 )
                n = -n;
        }
    }
    else
        assert( false );
    return n;
}

bool cmp( const CORRECT & a, const CORRECT & b )
{
    if ( a.sum == b.sum )
    {
        if ( strcmp( a.word, b.word ) < 0 )
            return true;
        else
            return false;
    }
    else
        return a.sum < b.sum;
}

int main (void)
{
    int i, j;
    int n, m;
    char wrong[10002];
    CORRECT correct[16];
    scanf( "%d", &n );
    while ( n -- )
    {
        scanf( "%s%d", wrong, &m );
        for ( i = 0 ; i < m  ; i ++ )
        {
            correct[i].sum = 0;
            scanf( "%s", correct[i].word );
            for ( j = 0; correct[i].word[j] != '\0' ; j ++ )
                correct[i].sum += FindError( wrong[j], correct[i].word[j] );
        }
        sort( correct, correct+m, cmp );
        for ( i = 0 ; i < m  ; i ++ )
            printf( "%s %d\n", correct[i].word, correct[i].sum );
    }
    return 0;
}
