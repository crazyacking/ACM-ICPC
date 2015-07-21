#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <set>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define rd(a) scanf("%d",&a)
#define rdd(a,b) scanf("%d %d",&a,&b)
#define rdt(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define ms(a,b) memset(a,b,sizeof a)
#define pb push_back
#define LD long double
#define ll long long
#define Maxn 0x7fffffff
#define exp 1e-10
#define lson (x<<1,l,mid)
#define rson (x<<1|1,mid+1,r)

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;
const int INF = 200009;
const int mod = ( int ) 1e9 + 7;
ll n, r;
int T;

int get(ll x,int k){
      ll l=2,r=(ll)(sqrt(x)+0.000001);
      while(l<=r){
            ll mid=(l+r)/2;
            if(k*log(mid)<log(x)) l=mid+1;
            else r=mid-1;
      }
      return l-1;
}
int check(ll x){
      ll t=x;
      for(int i=2;i<=r;++i){
            if(x>=(1LL<<i)){
                  t=t-get(x,i)+1;
            }
      }
      return t-n;
}
int main()
{
      scanf( "%d", &T );
      while( T-- )
      {
            scanf("%I64d %I64d",&n,&r);
            ll l=2,r=n*2;
            while(l<=r){
                  ll mid=(l+r)/2;
                  int k=check(mid-1);
                  if(k<=0) l=mid+1;
                  else r=mid-1;
            }
           printf("%I64d\n",l-1);
      }
      return 0;
}
