#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#define LL long long
using namespace std;

int T, a, b;
int f[1000009][10];


const int NN=1000001;
bool v[NN];
int p[NN];
void makePrime()
{
      int i,j;
      for(i=2; i<NN; ++i)
      {
            if(!v[i])
            for(j=i; j<NN; j+=i)
            {
                  v[j]=true;
                  ++p[j];
            }
      }
}

int main()
{
      makePrime();
      for(int i=1;i<NN;++i)
      {
            for(int j=7;j>0;--j)
            {
                  if(p[i]==j)
                        f[i][j]=1;
            }
      }

      for( int i = 1; i <= 1000000; ++i )
            for( int j = 1; j <= 7; ++j )
                  f[i][j] += f[i - 1][j];
      scanf( "%d", &T );
      while( T-- )
      {
            int ans = 1;
            scanf( "%d %d", &a, &b );
            for( int i = 7; i >0; --i )
            {
                  int tem=f[b][i]-f[a-1][i];
                  if( f[b][i] - f[a - 1][i] > 1 )
                  {
                        ans = ( i );
                        break;
                  }
            }
            printf( "%d\n", ans );
      }
      return 0;
}
