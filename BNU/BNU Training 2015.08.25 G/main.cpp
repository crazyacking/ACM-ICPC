#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD=123457;
ll a[5][210];
vector<ll> s[MOD];

inline void add(ll x)
{
      ll tem=x>0?x:-x;
      s[tem%MOD].push_back(x);
}

inline bool Find(ll x)
{
      ll tem=x>0?x:-x;
      for(auto &k:s[tem%MOD]){
            if(k==x) return 1;
      }
      return 0;
}
int main()
{
      int T;
      scanf("%d",&T);
      while(T--)
      {
            int n;
            for(int i=0;i<MOD;++i){
                  s[i].clear();
            }
            scanf("%d",&n);
            for(int i=0;i<5;i++)
                  for(int j=0;j<n;j++)
                        scanf("%I64d",&a[i][j]);
            set<ll>st[2];
            for(int i=0;i<n;i++)
                  for(int j=0;j<n;j++)
                        st[0].insert(a[0][i]+a[1][j]);
            for(int i=0;i<n;i++)
                  for(int j=0;j<n;j++){
                        add(a[3][i]+a[4][j]);
                  }
            set<ll>::iterator it;
            bool flag=0;
            for(it=st[0].begin();!flag&&it!=st[0].end();it++)
                  for(int i=0;!flag&&i<n;i++)
                        if(Find(-(*it+a[2][i])))
                              flag=1;
            if(flag)
                  puts("Yes");
            else
                  puts("No");
      }
      return 0;
}
