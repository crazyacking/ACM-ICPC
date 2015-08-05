#include<bits/stdc++.h>
#define sz(x)  ((int)x.size())

using namespace std;
typedef long long LL;
const int N=200*1000+100;

LL n,a[N],k;
map<LL,LL>m,mp;
LL ans;
int main()
{
      freopen("C:\\Users\\crazyacking\\Desktop\\cin.txt","r",stdin);
      //freopen("C:\\Users\\crazyacking\\Desktop\\cout.txt","w",stdout);

      while(cin>>n>>k)
      {
            for(int i=0;i<n;++i)
            {
                  cin>>a[i];
                  m[a[i]]++;
            }
            for(int i=0;i<n;++i)
            {
                  m[a[i]]--;
                  if(a[i]%k==0)
                        ans+=mp[a[i]/k]*m[a[i]*k];
                  mp[a[i]]++;
            }
            cout<<ans<<endl;
      }
      return 0;
}
