/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-20-19.43
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
#define inf 0x3f3f3f3f
const char tab = 0;
const int max_next = 128;
int idx;
struct trie
{
      struct trie *fail;
      struct trie *next[max_next];
      int isword;
      int index;
      trie()
      {
            isword = 0;
            index = 0;
            memset( next, NULL, sizeof next );
            fail = NULL;
      }
};
int rev[256];
trie *que[100005], ac[100005];
int head, tail;

trie *New()
{
      trie *temp = &ac[idx];
      for( int i = 0; i < max_next; i++ )temp->next[i] = NULL;
      temp->fail = NULL;
      temp->isword = 0;
      temp->index = idx++;
      return temp;
}
void Insert( trie *root, char *word, int len )
{
      trie *t = root;
      for( int i = 0; i < len; i++ )
      {
            if( t->next[word[i]] == NULL )
                  t->next[word[i]] = New();
            t = t->next[word[i]];
      }
      t->isword++;
}

void acbuild( trie *root )
{
      int head = 0, tail = 0;
      que[tail++] = root;
      root->fail = NULL;
      while( head < tail )
      {
            trie *temp = que[head++], *p;
            for( int i = 0; i < max_next; i++ )
            {
                  if( temp->next[i] )
                  {
                        if( temp == root )temp->next[i]->fail = root;
                        else
                        {
                              p = temp->fail;
                              while( p != NULL )
                              {
                                    if( p->next[i] )
                                    {
                                          temp->next[i]->fail = p->next[i];
                                          break;
                                    }
                                    p = p->fail;
                              }
                              if( p == NULL )temp->next[i]->fail = root;
                        }
                        if( temp->next[i]->fail->isword )temp->next[i]->isword++;
                        que[tail++] = temp->next[i];
                  }
                  else if( temp == root )temp->next[i] = root;
                  else temp->next[i] = temp->fail->next[i];
            }
      }
}
void del( trie *root )
{
      for( int i = 0; i < max_next; i++ )
            if( root->next[i] )del( root->next[i] );
      free( root );
}

int dp[205][205];
int solve( char *word, int len, trie *root )
{
      trie *r = root;
      int ans = 0;
      for( int i = 0; i < len; i++ )
      {
            if( r->next[word[i]]->isword )r = root, ans++;
            else r = r->next[word[i]];
      }
      return ans;
}
char word[10005];
int main()
{
      int n, cas = 1, m;
      while( scanf( "%d%d", &n, &m ) != EOF )
      {
            getchar();
            if( n == 0 && m == 0 )break;
            idx = 0;
            trie *root = New();
            for( int i = 1; i <= n; i++ )
            {
                  gets( word );
                  Insert( root, word, strlen( word ) );
            }
            acbuild( root );
            int ans = 0;
            while( m-- )
            {
                  gets( word );
                  ans += solve( word, strlen( word ), root );
            }
            printf( "%d\n", ans );
      }
      return 0;
}
