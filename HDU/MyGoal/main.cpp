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
int b[1000100];
bool v[1000100];
int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
//      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);
      int t;
      scanf( "%d",&t );
      while( t-- )
      {
            memset( v,0,sizeof v );
            LL n,m;
            scanf( "%I64d %I64d",&n,&m );
            LL sum=( 1+n )*n/2;
            if( sum%m==0 )
            {
                  puts( "YES" );
                  LL e=sum/m,s=0,cnt=0,num=0;
                  for( int i=n; i>=1; --i )
                  {
                        if( v[i]==0 )
                        {
                              s+=i;
                              b[num++]=i;
                              v[i]=1;

                              if( s==e )
                              {
                                    printf( "%d ",num );
                                    for( int j=0; j<num; ++j )
                                    {
                                          printf( j!=num-1?"%d ":"%d\n",b[j] );
                                    }
                                    s=0;
                                    num=0;
                              }
                              else
                              {
                                    LL gap=e-s;
                                    if( gap<=n )
                                    {
                                          if( v[gap]==0 )
                                          {
                                                s+=gap;
                                                b[num++]=gap;
                                                v[gap]=1;

                                                if( s==e )
                                                {
                                                      printf( "%d ",num );
                                                      for( int j=0; j<num; ++j )
                                                      {
                                                            printf( j!=num-1?"%d ":"%d\n",b[j] );
                                                      }
                                                      s=0;
                                                      num=0;
                                                }
                                          }
                                    }
                              }
                        }
                        else continue;
                  }
            }
            else puts( "NO" );
      }

      return 0;
}
/*

*/
