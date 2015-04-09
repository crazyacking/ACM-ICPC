ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
const int N=111111,M=111111;
int l,m,n,t;
char s[N];
ll jc[N],v[N],sum[N],inv[N];
ll C(int x,int y){
    if(y==-1)return 0;
    if(y>x)return 0;
    return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
#ifdef LOCAL
    freopen("C.in","r",stdin);//freopen("C.out","w",stdout);
#endif
    scanf("%d%d",&n,&m);scanf("%s",s+1);rep(i,1,n)v[i]=s[i]-'0';
    jc[0]=1;rep(i,1,n)jc[i]=jc[i-1]*i%mod;
    rep(i,0,n)inv[i]=powmod(jc[i],mod-2);
    rep(i,1,n)sum[i]=(sum[i-1]+v[i])%mod;
    ll ans=0,chen=1;
    rep(i,1,n){
        ans=(ans+(C(n-1-i,m-1)*sum[n-i]%mod+C(n-i,m)*v[n-i+1]%mod)*chen%mod)%mod;
        chen=chen*10%mod;
    }printf("%d\n",int(ans));
    return 0;
}
