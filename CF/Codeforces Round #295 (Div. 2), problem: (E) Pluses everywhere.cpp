#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL maxn=1e5+5,Mod=1e9+7;
LL n,k,t10[maxn],ans=0,sum[maxn],fact[maxn];
short num[maxn];

inline void input(){
    string s;
    cin>>n>>k>>s;
    for(int i=0;i<n;i++) num[i]=s[i]-'0';
}

inline void precomputes(){
    t10[0]=1;
    for(int i=1;i<=n;i++) t10[i]=(t10[i-1]*10)%Mod;
    sum[0]=num[0];
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+num[i];
    fact[0]=fact[1]=1;
    for(int i=2;i<=n;i++) fact[i]=(fact[i-1]*i)%Mod;
}

inline LL power(LL a,LL b){
    if(!b) return 1;
    return (power((a*a)%Mod,b/2)*(b%2?a:1))%Mod;
}

inline LL choose(LL p,LL m){
    if(m<p) return 1;
    return (fact[m]*((power(fact[p],Mod-2)*power(fact[m-p],Mod-2))%Mod))%Mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    input();
    precomputes();
    for(int i=n-k-1;i>=0;i--){
        ans+=(((choose(k,n-i-1)*t10[i])%Mod)*num[n-i-1])%Mod;
        ans%=Mod;
    }
    for(int i=n-k-1;i>=0;i--){
        ans+=(((choose(k-1,n-i-2)*t10[i])%Mod)*sum[n-i-2])%Mod;
        ans%=Mod;
    }
    cout<<ans<<endl;
}
