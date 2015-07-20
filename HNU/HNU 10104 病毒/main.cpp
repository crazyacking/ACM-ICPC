#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#define N 105
#define maxn 30005
using namespace std;
typedef long long ll;
const int mod = 100000;

const int max_next = 2;

int next[maxn][max_next], fail[maxn], num[maxn], siz;

int newnode()
{
      for( int i = 0; i < max_next; i++ )
            next[siz][i] = 0;
      fail[siz] = num[siz] = 0;
      return siz++;
}
void init()
{
      siz = 0;
      newnode();
}
void Insert( char *s, int len )
{
      int p = 0;
      for( int i = 0; i < len; i++ )
      {
            int &x = next[p][s[i] - '0'];
            p = x ? x : x = newnode();
      }
      num[p]++;

}

void acbuild()
{
      queue<int>Q;
      Q.push( 0 );
      while( !Q.empty() )
      {
            int temp = Q.front(); Q.pop();
            for( int i = 0; i < max_next; i++ )
            {
                  int v = next[temp][i];
                  if( v == 0 ) next[temp][i] = next[fail[temp]][i];
                  else Q.push( v );
                  if( temp != 0 )fail[v] = next[fail[temp]][i];
                  if( num[next[fail[temp]][i]] )num[next[temp][i]]++;
            }
      }
}
int vis[maxn];
bool dfs( int now )
{
      vis[now] = 1;
      for( int j = 0; j < max_next; j++ )
      {
            if( num[next[now][j]] )continue;
            if( vis[next[now][j]] == 1 )return true;
            if( vis[next[now][j]] == 0 && dfs( next[now][j] ) )return true;
      }
      vis[now] = -1;
      return false;
}

char word[30005];
int main()
{
      int n, L;
      while( scanf( "%d", &n ) != EOF )
      {
            init();
            while( n-- )
            {
                  scanf( "%s", word );
                  Insert( word, strlen( word ) );
            }
            acbuild();
            memset( vis, 0, sizeof vis );
            bool ans = false;
            for( int i = 0; i < siz; i++ )
                  if( !vis[i] && dfs( i ) )
                  {
                        ans = true;
                        break;
                  }
            if( ans )puts( "TAK\n" );
            else puts( "NIE\n" );
      }
      return 0;
}
