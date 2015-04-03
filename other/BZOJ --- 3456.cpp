#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=130050, fN=N<<2;
const ll mo=1004535809;
ll G[35], nG[35];
int rev[fN];
ll ipow(ll a, int b) { ll x=1; for(; b; b>>=1, (a*=a)%=mo) if(b&1) (x*=a)%=mo; return x; }
void fft(ll *a, int n, int f) {
    for(int i=0; i<n; ++i) if(i<rev[i]) swap(a[i], a[rev[i]]);
    int now=-1;
    for(int m=2; m<=n; m<<=1) {
        int mid=m>>1; ++now;
        ll wn=G[now]; if(f) wn=nG[now];
        for(int i=0; i<n; i+=m) {
            ll w=1;
            for(int j=0; j<mid; ++j) {
                ll u=a[i+j], v=a[i+j+mid]*w%mo;
                a[i+j]=(u+v)%mo;
                a[i+j+mid]=(u-v+mo)%mo;
                (w*=wn)%=mo;
            }
        }
    }
}
ll tmp[fN];
void getinv(ll *A, ll *B, int n) {
    if(n==1) { B[0]=ipow(A[0], mo-2); return; }
    getinv(A, B, (n+1)>>1);
    int len=1, bl=-1, nn=(n<<1)-1;
    for(; len<nn; len<<=1, ++bl);
    for(int i=1; i<len; ++i) rev[i]=(rev[i>>1]>>1)|(((ll)i&1)<<bl);
    for(int i=0; i<n; ++i) tmp[i]=A[i]; for(int i=n; i<len; ++i) tmp[i]=0;
    fft(tmp, len, 0); fft(B, len, 0);
    for(int i=0; i<len; ++i) B[i]=B[i]*((2-tmp[i]*B[i]%mo+mo)%mo)%mo;
    fft(B, len, 1); ll nN=ipow(len, mo-2);
    for(int i=0; i<n; ++i) (B[i]*=nN)%=mo; for(int i=n; i<len; ++i) B[i]=0;
}
ll ni[N], p[N], A[fN], B[fN], nA[fN];
int main() {
    int n;
    scanf("%d", &n);
    if(n<=2) { puts("1"); return 0; }
 
    int len=1, bl=-1, nn=((n+1)<<1)-1;
    for(; len<nn; len<<=1, ++bl);
    G[bl]=ipow(3, (mo-1)/len); nG[bl]=ipow(G[bl], mo-2);
    for(int i=bl-1; i>=0; --i) G[i]=G[i+1]*G[i+1]%mo, nG[i]=nG[i+1]*nG[i+1]%mo;
    ni[1]=1; p[1]=1; p[0]=1;
    for(int i=2; i<=n; ++i) ni[i]=((-(mo/i)*ni[mo%i])%mo+mo)%mo;
    for(int i=2; i<=n; ++i) p[i]=p[i-1]*ni[i]%mo;
    A[0]=1, B[0]=0;
    ll last=1, C=1;
    for(int i=1; i<=n; ++i) A[i]=last*p[i]%mo, B[i]=last*p[i-1]%mo, last=last*((C<<=1)%=mo)%mo;
    getinv(A, nA, n+1);
    for(int i=1; i<len; ++i) rev[i]=(rev[i>>1]>>1)|(((ll)i&1)<<bl);
    fft(nA, len, 0); fft(B, len, 0);
    for(int i=0; i<len; ++i) (B[i]*=nA[i])%=mo;
    fft(B, len, 1); ll nN=ipow(len, mo-2);
    for(int i=0; i<=n; ++i) (B[i]*=nN)%=mo;
    ll pp=1;
    for(int i=2; i<=n; ++i) (pp*=(i-1))%=mo, (B[i]*=pp)%=mo;
    printf("%lld\n", B[n]);
    return 0;
}