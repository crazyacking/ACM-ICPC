#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <set>
#include <map>
#define ll long long
using namespace std;
int n, m, sc;
vector<int> p[1009];
int dou[1009], sum[1009][1009];
int f[1009];
map<string, int> id;
string s;
int main()
{
      while( cin >> n >> m )
      {
            if( n == 0 && m == 0 ) return 0;
            memset( dou, 0, sizeof dou );
            memset( sum, 0, sizeof sum );
            for( int i = 1; i <= m; ++i ) p[i].clear();
            sc = 0;
            id.clear();
            for( int i = 1; i <= m; ++i )
            {
                  cin >> s;
                  if( id.find( s ) == id.end() )
                  {
                        id[s] = ++sc;
                  }
                  f[i] = id[s];
//                  cout<<f[i]<<endl;
                  for( int j = 1, k; j <= n; ++j )
                  {
                        cin >> k;
                        p[k].push_back( i );
                        if( ++sum[i][k] > 1 ) dou[k] = 1;
                  }
            }
            int ans = 0;
            for( int i = 1; i <= m; ++i )
            {
                  if( dou[i] || p[i].size() != n )
                  {
                        ++ans;
                        continue;
                  }
                  for( int j = 0; j < p[i].size(); ++j )
                  {
                        int a = p[i][j];
                        if( f[a] == f[i] )
                        {
                              ++ans;
                              break;
                        }
                  }
            }
            if( ans == 0 )
            {
                  cout << "NO PROBLEMS FOUND\n";
            }
            else if( ans == 1 )
            {
                  cout << "1 PROBLEM FOUND\n";
            }
            else
            {
                  cout << ans << " PROBLEMS FOUND\n";
            }
      }
      return 0;
}

