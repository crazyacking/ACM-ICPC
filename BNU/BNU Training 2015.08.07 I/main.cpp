/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-07-13.22
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
const int MAXN=100+( int )1e5;
int N,K;
int fu[MAXN],lin[MAXN];
char ans[MAXN];

int lowbit( int x )
{
      return x&( -x );
}

void add( int pos,int num,int a[] )
{
      while( pos<MAXN )
      {
            a[pos]+=num;
            pos+=lowbit( pos );
      }
}


int query( int en,int a[] )
{
      int sum=0;
      while( en>0 )
      {
            sum+=a[en];
            en-=lowbit( en );
      }
      return sum;
}

int main()
{
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      while( ~scanf( "%d %d",&N,&K ) )
      {
            memset( fu,0,sizeof fu );
            memset( lin,0,sizeof lin );
            int t;
            for( int i=1; i<=N; ++i )
            {
                  scanf( "%d",&t );
                  if( t<0 ) add( i,1,fu );
                  else if( t==0 ) add( i,1,lin );
            }
            int cnt=0;
            while( K-- )
            {
                  char ch;
                  getchar();
                  scanf( "%c",&ch );
                  int a,b;
                  scanf( "%d %d",&a,&b );
                  if( ch=='C' )
                  {
                        int f=query( a,fu )-query( a-1,fu );
                        int l=query( a,lin )-query( a-1,lin );
                        if( b==0 )
                        {
                              if( f>0 ) add( a,-1,fu );
                              if( l<=0 ) add( a,1,lin );
                        }
                        if( b>0 )
                        {
                              if( f>0 ) add( a,-1,fu );
                              if( l>0 ) add( a,-1,lin );
                        }
                        if( b<0 )
                        {
                              if( f<=0 ) add( a,1,fu );
                              if( l>0 ) add( a,-1,lin );
                        }
                  }
                  else
                  {
                        int l1=query( a-1,lin );
                        int l2=query( b,lin );
                        int l=l2-l1;
                        if( l>0 )
                        {
                              ans[cnt++]='0';
                              continue;
                        }
                        int f1=query( a-1,fu );
                        int f2=query( b,fu );
                        int f=f2-f1;
                        if( f%2 )
                        {
                              ans[cnt++]='-';
                              continue;
                        }
                        ans[cnt++]='+';
                  }
            }
            ans[cnt]='\0';
            puts( ans );
      }
      return 0;
}
/*

*/
