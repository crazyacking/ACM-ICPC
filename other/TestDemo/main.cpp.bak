/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-19-10.29
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

const int M = 6000005;
class node
{
public:
      bool flag;
      node *fail, *next[26];
      node()
      {
            flag = false;
            fail = NULL;
            memset( next, NULL, sizeof next );
      }
};
node *root;
queue<node*> q;
char s[M], str[M];

void Insert( char *str ) // build Trie-Tree
{
      node *p = root;
      int i = 0, index;
      while( str[i] )
      {
            index = str[i] - 'A';
            if( p->next[index] == NULL )
                  p->next[index] = new node();
            p = p->next[index];
            ++i;
      }
      p->flag = true;
}

void build_ac_automation( node *root ) // build fail ptr
{
      root->fail = NULL;
      while( !q.empty() ) q.pop();
      q.push( root );
      while( !q.empty() )
      {
            node *temp = q.front(); q.pop();
            node *p = NULL;
            for( int i = 0; i < 26; ++i )
            {
                  if( temp->next[i] != NULL )
                  {
                        if( temp == root ) temp->next[i]->fail = root;
                        else
                        {
                              p = temp->fail;
                              while( p != NULL )
                              {
                                    if( p->next[i] != NULL )
                                    {
                                          temp->next[i]->fail = p->next[i];
                                          break;
                                    }
                                    p = p->fail;
                              }
                              if( p == NULL ) temp->next[i]->fail = root;
                        }
                        q.push( temp->next[i] );
                  }
            }
      }
}


int query( node *root )  // mathing and count
{
      node *p = root;
      int i = 0, ans = 0, index;
      while( str[i] )
      {
            index = str[i] - 'A';
            while( p->next[index] == NULL && p != root )
                  p = p->fail;
            p = p->next[index];
            if( p == NULL )
                  p = root;
            node *temp = p;
            while( temp != root && temp->flag )
            {
                  ans++;
                  temp->flag = false;
                  temp = temp->fail;
            }
            i++;
      }
      return ans;
}


inline void build_str( char *s )
{
      int len = strlen( s ), cnt = -1;
      for( int i = 0; i < len; ++i )
      {
            if( s[i] >= 'A' && s[i] <= 'Z' )
            {
                  str[++cnt] = s[i];
                  continue;
            }
            if( s[i] == '[' )
            {
                  ++i;
                  int num = 0;
                  for( ; s[i] >= '0' && s[i] <= '9'; ++i )
                  {
                        num = num * 10 + ( s[i] - '0' );
                  }
                  char ch = s[i];
                  ++i;
                  for( int j = 1; j <= num; ++j )
                        str[++cnt] = ch;
            }
      }
      str[++cnt] = '\0';
}


int main()
{
//      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
//      freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);
      ios_base::sync_with_stdio( false );
      cin.tie( 0 );
      int Cas;
      scanf( "%d", &Cas );
      while( Cas-- )
      {
            root = new node();
            int n;
            scanf( "%d", &n );
            while( n-- )
            {
                  scanf( "%s", s );
                  Insert( s );
            }
            build_ac_automation( root );
            scanf( "%s", s );
            build_str( s );
            int ans = query( root );
            strrev( str );
            ans += query( root );
            printf( "%d\n", ans );
      }
      return 0;
}
/*

*/
