//  Memory   Time
//  1347K     0MS
//   by : crazyacking
//   2015-03-25-21.38
#include<map>
#include<queue>
#include<stack>
#include<cmath>
#include<cstdio>
#include<vector>
#include<string>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<iostream>
#include<algorithm>
#define MAXN 1000010
#define LL long long
using namespace std;


#define MAX 1005
const int INF = ( 1 << 29 );
char str[MAX];
int dp[MAX];
bool flag[MAX][MAX]; //flag[i][j]: 长度为i, 从str[j]开始有一段回文串
inline int min( int a, int b )
{
    return a < b ? a : b;
}
void init( int len )
{
    memset( flag, false, sizeof( flag ) );
    int i, j;
    for ( i = 1; i <= len; ++i ) { flag[1][i] = true; }
    if ( len == 1 ) { return ; }
    for ( i = 1; i <= len - 1; ++i )
        if ( str[i] == str[i + 1] ) {
            flag[2][i] =  true;
        }
    for ( i = 3; i <= len; ++i )
    {
        for ( j = 1; j <= len - i + 1; ++j )
        {
            if ( flag[i - 2][j + 1] && str[j] == str[j + i - 1] ) {
                flag[i][j] = true;
            }
        }
    }

    for(int i=1;i<=len;++i)
    {
            for(int j=1;j<=len;++j)
            {
                    printf("%d ",flag[i][j]?1:0);
            }
            puts("");
    }
}
int main()
{
// freopen("input.txt", "r", stdin);
    int caseNum, i, j;
    scanf( "%d", &caseNum );
    while ( caseNum-- )
    {
        scanf( "%s", str + 1 );
        int len = strlen( str + 1 );
        init( len );
        for ( i = 1; i <= len; ++i ) { dp[i] = INF; }
        dp[0] = 0;
        for ( i = 1; i <= len; ++i )
        {
            for ( j = 1; j <= i; ++j )
            {
                if ( flag[j][i - j + 1] )
                {
                    dp[i] = min( dp[i], dp[i - j] + 1 );
                }
            }
        }
        printf( "%d\n", dp[len] );
    }
    return 0;
}
