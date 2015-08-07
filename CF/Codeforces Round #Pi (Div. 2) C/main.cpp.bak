/*
* this code is made by crazyacking
* Verdict: Accepted
* Submission Date: 2015-08-06-00.47
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
#define  MAXN 200005
using namespace std;
int b[MAXN],a[MAXN],c[MAXN],n,k;
vector<int> p[MAXN];
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      while( ~scanf("%d %d",&n,&k))
      {
            for( int i = 0; i < n; ++i ) {scanf("%d",&a[i]); b[i] = c[i] = a[i]; p[i].clear();}
            sort( b,b+n );
            int now = unique( b,b+n )-b;

            for( int i = 0; i < n; ++i ){a[i] = lower_bound( b,b+now,a[i] ) - b; p[a[i]].push_back( i );}

            long long ans = 0,l = 0;

            for( int i = 1; i < n - 1; ++i )
            {
                  if( c[i]*( (long long) k ) > (int)(1e9) ) continue;

                  if( c[i]%k )continue;

                  int x1 = c[i]/k,x2 = c[i]*k;
                  x1 = lower_bound( b,b+now,x1 ) - b;

                  if( x1 < 0||x1==now )continue;

                  if( b[x1] != c[i]/k )continue;

                  x2 = lower_bound( b,b+now,x2 ) - b;

                  if( x2 < 0||x2==now )continue;

                  if( b[x2] != c[i]*k )continue;

                  long long a1 = 0,a2 = 0;
                  l = lower_bound( p[x1].begin(),p[x1].end(),i ) - p[x1].begin();

                  if( l <= 0 )continue;

                  a1 = l;
                  l = lower_bound( p[x2].begin(),p[x2].end(),i+1 ) - p[x2].begin();

                  if( l==p[x2].size() )continue;

                  a2 = p[x2].size() - l;
                  ans += a1*a2;
            }
            printf("%lld\n",ans);

      }

      return 0;
}




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

int M=1000000000;
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      int n,k;
      while(~scanf("%d %d",&n,&k))
      {
            int arr[n];
            for(int i=0;i<n;++i)
            {
                  scanf("%d",&arr[i]);
            }
            map<LL,LL> c1,c2;
            for(int i=0;i<n;++i)
            {
                  c1[arr[i]]=0,c2[arr[i]]=0;
            }
            LL ans=0;
            for(int i=n-1;i>=0;--i)
            {
                  LL v=arr[i];
                  v*=k;
                  if(c2.find(v)!=c2.end())
                  {
                        ans+=c2[v];
                        c2[arr[i]]+=c1[v];
                  }
                  c1[arr[i]]+=1;
            }
            cout<<ans<<endl;
      }
      return 0;
}

