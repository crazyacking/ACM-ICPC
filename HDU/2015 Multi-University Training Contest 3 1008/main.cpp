/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-07-28-16.05
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
int ll, rr;
bool build( int l, int r )
{
//      cout<<l<<" "<<r<<endl;
      if( ll == l && rr == r ) return true;
      if( l == r ) return false;
      int mid = ( l + r ) >> 1;
      if( build( l, mid ) )return true;
      if( build( mid + 1, r ) ) return true;
      return false;
}

int main()
{
      while( cin >> ll >> rr )
      {
//            build(ll,rr);
            if(ll>rr) swap(ll,rr);
            for( int i = 0; 1; ++i )
            {
                  if( i > 1000 )
                  {
                        puts( "-1" );
                        break;
                  }
                  if( build( 0, i ) )
                  {
                        cout << i << endl;
                        break;
                  }
            }
      }
      return 0;
}
