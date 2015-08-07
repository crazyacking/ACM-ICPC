/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-12.46
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
#define  LL __int64
#define  ULL unsigned long long
using namespace std;
vector<int> out[20];
bool v[1000100];
int main()
{
      int t;
      scanf( "%d",&t );
      while( t-- )
      {
            memset( v,0,sizeof v );
            for( int i=1; i<=10; ++i ) out[i].clear();
            LL n,m;
            scanf( "%I64d %I64d",&n,&m );
            LL sum=( 1+n )*n/2;
            int k=n,cnt=0,flag=1;
            if(sum/m<n)
            {
                  puts("NO");
                  continue;
            }
            for( int i=1; i<=m; ++i )
            {
                  LL tem=0;
                  while( v[k] ) --k;
                  while( tem+k<sum/m )
                  {
                        out[i].push_back( k );
                        ++cnt;
                        tem+=k;
                        v[k]=1;
                        while( v[k] ) --k;
                  }
                  if( v[sum/m-tem] )
                  {
                        flag=0;
                        break;
                  }
                  else
                  {
                        v[sum/m-tem]=1;
                        out[i].push_back( sum/m-tem );
                        ++cnt;
                  }
            }
            bool ff=1;
            if( flag&&cnt==n )
            {
                  for(int i=1;i<=m;++i)
                  {
                        LL he=0;
                        for( int j=0; j<out[i].size(); ++j )
                        {
                              he+=out[i][j];
                        }
                        if(he<n)
                        {
                              ff=0;
                              break;
                        }
                  }
                  if(!ff)
                  {
                        puts("NO");
                        continue;
                  }
                  puts( "YES" );
                  for( int i=1; i<=m; ++i )
                  {
                        printf( "%d",out[i].size() );
                        for( int j=0; j<out[i].size(); ++j )
                        {
                              printf( " %d",out[i][j] );
                        }
                        puts( "" );
                  }
            }
            else { puts( "NO" ); }
      }
      return 0;
}
/*

*/
