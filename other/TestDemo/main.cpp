#include<iostream>
#include<cassert>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 300005;
const int M = 20005;
char ch[N + M];
int dp[M], trie[N][26], fail[N], word[N], pos[M], sz, Q[N], flag[N];
inline void chkmax( int &a, const int b ) {if( a < b )a = b;}
void ins( int s )
{
      for( int p = 0; ch[s]; s++ )
      {
            int x = ch[s] - 'a';
            if( trie[p][x] == 0 )
            {
                  ++sz;
                  memset( trie[sz], 0, sizeof( trie[sz] ) );
                  word[sz] = 0;
                  trie[p][x] = sz;
            }
            p = trie[p][x];
      }
}
void ac()
{
      int head = 0, tail = 0;
      for( int i = 0; i < 26; i++ ) if( trie[0][i] )
            {
                  fail[trie[0][i]] = 0;
                  Q[tail ++] = trie[0][i];
            }
      while( head < tail )
      {
            int u = Q[head++], v;
            for( int i = 0; i < 26; i++ )
                  if( v = trie[u][i] )
                  {
                        fail[v] = trie[fail[u]][i];
                        Q[tail++] = v;
                  }
                  else trie[u][i] = trie[fail[u]][i];
      }
}
void cal( int now )
{
      int p = 0, v = 0;
      for( int s = pos[now]; s < pos[now + 1]; s++ )
      {
            int x = ch[s] - 'a', t = ( p = trie[p][x] );
            while( t )
            {
                  if( word[t] ) chkmax( v, dp[flag[word[t]]] );
                  t = fail[t];
            }
      }
      dp[now] += v;
      word[p] = p;
      flag[p] = now;
}
int main()
{
      int test = 0;
      cin >> test;
      for( int _ = 1; _ <= test; _++ )
      {
            int n;
            sz = 0;
            scanf( "%d", &n );
            pos[0] = 0;
            memset( trie[0], 0, sizeof( trie[0] ) );
            for( int i = 0; i < n; i++ )
            {
                  scanf( "%s%d", ch + pos[i], &dp[i] );
                  pos[i + 1] = pos[i] + strlen( ch + pos[i] );
                  ins( pos[i] );
            }
            ac();
            int ans = 0;
            for( int i = 0; i < n; i++ )
            {
                  if( dp[i] > 0 )
                        cal( i );
                  chkmax( ans, dp[i] );
            }
            printf( "Case #%d: %d\n", _, ans );
      }
      return 0;
}