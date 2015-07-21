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
vector<int> pos[10009],a[10009];
int n;
ll ans=0;
void init(){
      for(int i=1;i<=10000;++i) pos[i].clear();
      ans=0;
}

void make(int x){
      set<int> p;
      set<int>::iterator it;
      for(int i=0;i<sz(a[x]);++i){
            for(int j=0;j<sz(pos[a[x][i]]);++j )
            p.insert(pos[a[x][i]][j]);
      }
      for(int i=0;i<sz(pos[x]);++i){
             it=p.find(pos[x][i]);
             int a,b;
             if(it==p.begin()) a=1;
             else {
                  --it;
                  a=(*it)+1;
                  ++it;
             }
             if((++it)==p.end()) b=n;
             else{
                  b=(*it)-1;
             }
             ans=(ans+(pos[x][i]-a+1)*(b-pos[x][i]+1))%mod;
      }
}
int main()
{
      for(int i=1;i<=10000;++i){
            for(int j=i;j<=10000;j+=i){
                  a[j].pb(i);
            }
      }
      while( scanf( "%d", &n ) != EOF )
      {
            init();
            for(int i=1,k;i<=n;++i){
                  scanf("%d",&k);
                  //k=i%10000;
                  pos[k].pb(i);
            }
            for(int i=1;i<=10000;++i){
                  if(sz(pos[i])){
                        make(i);
                  }
            }
            cout<<ans<<endl;
      }
      return 0;
}
